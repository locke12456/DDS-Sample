//----------------------------------------------------------------
//
//-- Filename: src/dwmodbus.c
//
//-- $Date: 2011/09/01 22:01:53 $
//-- $Revision: 1.2 $
//-- $Name:  $
//
//----------------------------------------------------------------

#include "devicewise/modbus/modbus.h"

#if defined(_WIN32)
#  if defined(EXPORT_DWMODBUS_SYMS)
#    define MODBUS_EXPORT __declspec(dllexport)
#  else
#    define MODBUS_EXPORT __declspec(dllimport)
#  endif
#else
#  define MODBUS_EXPORT
#endif

void *g_modbus_logger=NULL;
void *g_modbus_driver=NULL;

#define PLUGIN_NAME				"deviceWISE Modbus Driver"
#define PLUGIN_AUTHOR			"ILS Technology"
#define PLUGIN_MAJOR_VERSION	2
#define PLUGIN_MINOR_VERSION	1

void _modbus_module_init(DW_GLOBALS *globals);
void _modbus_set_device_type_info(int type);

MODBUS_EXPORT int devicewise_interface_function() {
	return DEVICEWISE_INTERFACE_VERSION;
}

// This function is called by the deviceWISE Core when this library is loaded.  The
// only work that should be done in this function is to register the plugin and the
// modules.
MODBUS_EXPORT void devicewise_registration_function(DW_PLUGIN_REGISTRATION *reg) {

	if(reg!=NULL) {
		strncpy(reg->name,PLUGIN_NAME,DW_PLUGIN_NAME_LEN);
		strncpy(reg->author,PLUGIN_AUTHOR,DW_PLUGIN_NAME_LEN);
		strncpy(reg->build,modbus_build_version(),DW_PLUGIN_NAME_LEN);
		reg->version_major=PLUGIN_MAJOR_VERSION;
		reg->version_minor=PLUGIN_MINOR_VERSION;
	}

	// module_register() registers a deviceWISE Module to the system.  A plugin can have multiple
	// modules that load at different times during the initialization process.
	module_register("Driver:Modbus",_modbus_module_init,NULL,"DriverSubsystem","DeviceLoader");
}

// _modbus_module_init() registers the driver functions for a specific device type.
void _modbus_module_init(DW_GLOBALS *globals) {
	int ret;
	DW_DRIVER_REG drvr;

	log_create(&g_modbus_logger,"dw.modbus.driver");
	ilsMemset(&drvr,0,sizeof(DW_DRIVER_REG));

	drvr._device_validate=modbus_device_validate;
	drvr._device_start=modbus_device_start;
	drvr._device_stop=modbus_device_stop;

	drvr._variable_read=modbus_variable_read;
	drvr._variable_write=modbus_variable_write;

	if( (ret=driver_register("Modbus Driver",&drvr,sizeof(DW_DRIVER_REG),&g_modbus_driver))!=0 ) {
		lwarn(g_modbus_logger,format("driver_register(): %d.",ret));
	} else {
		ldebug2(g_modbus_logger,"driver_register(): OK.");
	}

	linfo(g_modbus_logger, "Registering Device Types...");
	if( (ret=device_type_register(MODBUS_TYPE_GENERIC, "TCP Device", MSG_MISSING,DW_CREATEABLE|DW_EDITABLE|DW_DELETABLE|DW_CONTROLLABLE,g_modbus_driver))!=0 ) {
		lwarn(g_modbus_logger, format("device_type_register(): %d.",ret));
	} else {
		ldebug2(g_modbus_logger, "device_type_register(): OK.");
		_modbus_set_device_type_info(MODBUS_TYPE_GENERIC);
	}

	return;
}

// set the device type - this provides properties that will show up on the deviceWISE Workbench
// when adding and/or editing this device.
void _modbus_set_device_type_info(int type) {
	device_type_set_listing_info(type,"Modbus",MSG_MISSING,NULL,MSG_MISSING);
	device_type_add_property_string(type,"address","IP Address",MSG_DATA_IPADDY_N,MSG_DATA_IPADDY_D,DW_OPT_REQUIRED,NULL);
	device_type_add_property_integer(type,"port","Port",MSG_DATA_PORT_N,MSG_DATA_PORT_D,DW_OPT_REQUIRED,502,1,65535);

	device_type_add_property_integer(type,"slave_address","Slave Address",MSG_MISSING,MSG_MISSING,DW_OPT_ADVANCED,0,0,247);

	device_type_add_property_integer(type,"timeout","Timeout",MSG_MISSING,MSG_MISSING,0,5000,5000,60000);

	if(type==MODBUS_TYPE_GENERIC) {
		device_type_add_property_integer(type,"coils_count","Coils",MSG_MISSING,MSG_MISSING,0,0,0,65536);
		device_type_add_property_integer(type,"discrete_count","Discrete Inputs",MSG_MISSING,MSG_MISSING,0,0,0,65536);
		device_type_add_property_integer(type,"input_count","Input Registers",MSG_MISSING,MSG_MISSING,0,0,0,65536);
		device_type_add_property_integer(type,"holding_count","Holding Registers",MSG_MISSING,MSG_MISSING,0,0,0,65536);
	}
}
