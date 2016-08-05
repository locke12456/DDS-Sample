//----------------------------------------------------------------
//
//-- Filename: device.c
//
//-- $Date: 2011/08/30 15:22:34 $
//-- $Revision: 1.1 $
//-- $Name:  $
//
//----------------------------------------------------------------

#include "devicewise/modbus/modbus.h"

extern void *g_modbus_logger;

// this function is called whenever the deviceWISE Workbench is told to 
// "validate" the device.
// the function should do whatever is required in order to determine that the device is configured correctly 
// and that it actually exists on the IP and Port specified in the device configuration.
int modbus_device_validate(DW_DEVICE *dev, int deep) {
	if(deep) {
		MODBUS_DEVICE *md;
		char *value;
		int ret;

		if( (md=ilsMalloc(sizeof(MODBUS_DEVICE)))==NULL ) {
			return ERR_MALLOC;
		}
		ilsMemset(md,0,sizeof(MODBUS_DEVICE));

		if ((ret = device_get_prop(dev,"address", &value))!=0 ) {
			lwarn(g_modbus_logger,"Missing required property [address].");
			ilsFree(md);
			return ERR_DEV_PROP_NOTFOUND;
		} else {
			strncpy(md->addr, value, MODBUS_STR_LEN);
			ilsFree(value);
		}

		if ((ret = device_get_prop(dev,"port",&value))!=0 ) {
			strncat(md->addr,":502",MODBUS_STR_LEN-strlen(md->addr));
		} else {
			strncat(md->addr,":",MODBUS_STR_LEN-strlen(md->addr));
			strncat(md->addr,value,MODBUS_STR_LEN-strlen(md->addr));
			ilsFree(value);
		}

		if( (ret=socket_create(&md->socket))!=0 ) {
			lwarn(g_modbus_logger,format("socket_create(): %d",ret));
			ilsFree(md);
			return ret;
		} else {
			ldebug2(g_modbus_logger,"socket_create(): OK");
		}

		if( (ret=socket_connect(md->socket,md->addr))!=0 ) {
			lwarn(g_modbus_logger,format("socket_connect(): %d (%d)",ret, socket_error(md->socket)));
			socket_delete(md->socket);
			ilsFree(md);
			return ret;
		} else {
			ldebug2(g_modbus_logger,"socket_connect(): OK");
		}

		socket_close(md->socket);
		socket_delete(md->socket);
		ilsFree(md);
		return 0;
	} else {
		return 0;
	}
}

// this function is called when a request is made to "start" the device.  
// the call to "start" may be controlled explicitly via the Workbench or
// during deviceWISE startup.
int modbus_device_start(DW_DEVICE *dev) {
	DW_VARIABLE_INFO *vinfo;
	MODBUS_DEVICE *md;
	char *value;
	int ret;
	unsigned int build_number;

	if( (md=ilsMalloc(sizeof(MODBUS_DEVICE)))==NULL ) {
		return ERR_MALLOC;
	}
	ilsMemset(md,0,sizeof(MODBUS_DEVICE));

	dev->custom	= md;

	if ((ret = device_get_prop(dev,"address", &value))!=0 ) {
		lwarn(g_modbus_logger,"Missing required property [address].");
		ilsFree(md);
		device_set_status(dev,ERR_DEV_PROP_NOTFOUND,0);
		return ERR_DEV_PROP_NOTFOUND;
	} else {
		strncpy(md->addr, value, MODBUS_STR_LEN);
		ilsFree(value);
	}

	if ((ret = device_get_prop(dev,"port",&value))!=0 ) {
		strncat(md->addr,":502",MODBUS_STR_LEN-strlen(md->addr));
	} else {
		strncat(md->addr,":",MODBUS_STR_LEN-strlen(md->addr));
		strncat(md->addr,value,MODBUS_STR_LEN-strlen(md->addr));
		ilsFree(value);
	}

	if( (ret=socket_create(&md->socket))!=0 ) {
		lwarn(g_modbus_logger,format("socket_create(): %d",ret));
		modbus_device_stop(dev);
		device_set_status(dev,ret,0);
		return ret;
	} else {
		ldebug2(g_modbus_logger,"socket_create(): OK");
	}

	if( (ret=socket_connect(md->socket,md->addr))!=0 ) {
		lwarn(g_modbus_logger,format("socket_connect(): %d (%d)",ret, socket_error(md->socket)));
		modbus_device_stop(dev);
		device_set_status(dev,ret,0);
		return ret;
	} else {
		ldebug2(g_modbus_logger,"socket_connect(): OK");
	}

	if ((ret = device_get_prop(dev,"slave_address", &value))!=0 ) {
		md->slave_address = 0;
	} else {
		int value_int=atoi(value);
		ilsFree(value);
		if(value_int < 0 || value_int > 247) {
			lwarn(g_modbus_logger,"Slave address not in range [0->247].");
			ilsFree(md);
			device_set_status(dev,ERR_DEV_PROP_INVALID,0);
			return ERR_DEV_PROP_INVALID;
		} else {
			md->slave_address = value_int;
		}
	}

	if ((ret = device_get_prop(dev,"timeout",&value))!=0 ) {
		md->timeout = 7500;
	} else {
		md->timeout = atoi(value);
		ilsFree(value);
	}

	ldebug2(g_modbus_logger,"Connection Parameters");
	ldebug2(g_modbus_logger,format("  Address: [%s]", md->addr));
	ldebug2(g_modbus_logger,format("  Slave Address: [%d]",md->slave_address));
	ldebug2(g_modbus_logger,format("  Timeout: [%d]", md->timeout));

	build_number=system_get_build_number();

	if(device_get_prop(dev,"coils_count",&value)==0 ) {
		if(atoi(value)>0) {
			DEVICE_ADD_VINFO(g_modbus_logger,dev,vinfo,"Coils",DW_BOOL,DW_READABLE|DW_WRITABLE);
			if(ret==0) {
				//vinfo->xstart=0;
				vinfo->xdim=atoi(value);
			} else {
				ilsFree(value);
				modbus_device_stop(dev);
				device_set_status(dev,ERR_DEV_PROP_INVALID,0);
				return ret;
			}
		}
		ilsFree(value);
	}

	if(device_get_prop(dev,"discrete_count",&value)==0 ) {
		if(atoi(value)>0) {
			DEVICE_ADD_VINFO(g_modbus_logger,dev,vinfo,"Discrete Inputs",DW_BOOL,DW_READABLE);
			if(ret==0) {
				vinfo->xdim=atoi(value);
				if( build_number>=0x02030000 ) {
					if(vinfo->xdim>9999) {
						vinfo->xstart=100000;
					} else {
						vinfo->xstart=10000;
					}
				}
			} else {
				ilsFree(value);
				modbus_device_stop(dev);
				device_set_status(dev,ERR_DEV_PROP_INVALID,ret);
				return ret;
			}
		}
		ilsFree(value);
	}

	if(device_get_prop(dev,"input_count",&value)==0 ) {
		if(atoi(value)>0) {
			DEVICE_ADD_VINFO(g_modbus_logger,dev,vinfo,"Input Registers",DW_INT2,DW_READABLE);
			if(ret==0) {
				vinfo->casts=DW_INT2_MASK|DW_INT4_MASK|DW_UINT2_MASK|DW_UINT4_MASK|DW_FLOAT4_MASK;
				vinfo->xdim=atoi(value);
				if( build_number>=0x02030000 ) {
					if(vinfo->xdim>9999) {
						vinfo->xstart=300000;
					} else {
						vinfo->xstart=30000;
					}
				}
			} else {
				modbus_device_stop(dev);
				ilsFree(value);
				device_set_status(dev,ERR_DEV_PROP_INVALID,0);
				return ret;
			}
		}
		ilsFree(value);
	}

	if(device_get_prop(dev,"holding_count",&value)==0 ) {
		if(atoi(value)>0) {
			DEVICE_ADD_VINFO(g_modbus_logger,dev,vinfo,"Holding Registers",DW_INT2,DW_READABLE|DW_WRITABLE);
			if(ret==0) {
				vinfo->casts=DW_INT2_MASK|DW_INT4_MASK|DW_UINT2_MASK|DW_UINT4_MASK|DW_FLOAT4_MASK;
				vinfo->xdim=atoi(value);
				if( build_number>=0x02030000 ) {
					if(vinfo->xdim>9999) {
						vinfo->xstart=400000;
					} else {
						vinfo->xstart=40000;
					}
				}
			} else {
				modbus_device_stop(dev);
				ilsFree(value);
				device_set_status(dev,ERR_DEV_PROP_INVALID,0);
				return ret;
			}
		}
		ilsFree(value);
	}

	return 0;
}

// this function is called when a request is made to "stop" the device.  
// the call to "stop" may be controlled explicitly via the Workbench or
// during deviceWISE shutdown.
int modbus_device_stop(DW_DEVICE *dev) {
	MODBUS_DEVICE *md = (MODBUS_DEVICE *) dev->custom;

	if(md->socket!=NULL) {
		socket_close(md->socket);
		socket_delete(md->socket);
	}

	ilsFree(md);
	return 0;
}
