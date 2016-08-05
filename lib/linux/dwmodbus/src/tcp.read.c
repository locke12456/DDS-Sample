//----------------------------------------------------------------
//
//-- Filename: tcp.read.c
//
//-- $Date: 2011/08/30 15:22:34 $
//-- $Revision: 1.1 $
//-- $Name:  $
//
//----------------------------------------------------------------

#include "devicewise/modbus/modbus.h"
#include "devicewise/modbus/tcp.h"

extern void *g_modbus_logger;

// local function prototypes
int _modbus_read_words(DW_DEVICE *dev, DW_VARIABLE_DATA *var, unsigned char func);
int _modbus_read_bits(DW_DEVICE *dev, DW_VARIABLE_DATA *var, unsigned char func);

// function called when requested to "read" a variable
int modbus_variable_read(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count) {
	int v;

        // loop for each variable requested to read
	for(v=0;v<var_count; ++v) {
		if(!vars[v]->has_been_handled) {
			 if( str_starts_with(vars[v]->name,"Coils") ) {
				vars[v]->status=_modbus_read_bits(dev,vars[v],0x01);
				vars[v]->has_been_handled=1;	
			} else if( str_starts_with(vars[v]->name,"Discrete") ) {
				vars[v]->status=_modbus_read_bits(dev,vars[v],0x02);
				vars[v]->has_been_handled=1;
			} else if( str_starts_with(vars[v]->name,"Holding") ) {
				vars[v]->status=_modbus_read_words(dev,vars[v],0x03);
				vars[v]->has_been_handled=1;
			} else if( str_starts_with(vars[v]->name,"Input") ) {
				vars[v]->status=_modbus_read_words(dev,vars[v],0x04);
				vars[v]->has_been_handled=1;
			}
		}	
	}
	return 0;
}

int _modbus_read_words(DW_DEVICE *dev, DW_VARIABLE_DATA *var, unsigned char func) {
	MODBUS_DEVICE *md=dev->custom;
	MODBUS_TCP_PACKET  pkt;
	MODBUS_READ_REQ   *req;
	MODBUS_READ_RSP   *rsp;
	int total_size=0, current_size=0, chunk_size=0, idx;
	int packet_len, ret;
	int retries = 0;

	switch(var->type) {
		case DW_INT2:
		case DW_UINT2:
			total_size=var->count;
			break;
		case DW_INT4:
		case DW_UINT4:
		case DW_FLOAT4:
			total_size=var->count*2;
			break;
	}

	req=(MODBUS_READ_REQ *)pkt.data;
	rsp=(MODBUS_READ_RSP *)pkt.data;

	while(current_size<total_size) {
		idx=0;

		if(total_size-current_size>MODBUS_MAX_WORDS_PER_REQUEST) {
			chunk_size = MODBUS_MAX_WORDS_PER_REQUEST;
		} else {
			chunk_size = total_size-current_size;
		}

		ilsMemset(&pkt,0,sizeof(MODBUS_DEVICE));
		packet_len=MODBUS_TCP_HEADER_LEN;

		pkt.txn_id=swap16((md->seqid++));
		pkt.length=swap16(6);
		pkt.unit_id=md->slave_address;
		pkt.func=func;

		req->start_address=swap16(var->offset+current_size);
		req->count=swap16(chunk_size);
		packet_len+=5;

recv_words_retry:
		if( (ret=socket_send(md->socket,(char *)&pkt,packet_len))!=0 ) {
			if(ret<0) {
				if(retries==1) {
					device_set_status(dev,ERR_DEV_COMM,0);
					device_disable(dev);
					return ret;
				}
				if( (ret=socket_connect(md->socket,md->addr))!=0 ) {
					lwarn(g_modbus_logger,format("socket_connect(): %d (%d)",ret, socket_error(md->socket)));
					device_set_status(dev,ERR_DEV_COMM,0);
					device_disable(dev);
					return ret;
				} else {
					ldebug2(g_modbus_logger,"socket_connect(): OK");
					++retries;
					goto recv_words_retry;
				}
			} else {
				lwarn(g_modbus_logger,format("socket_send(): %d",ret));
				device_set_status(dev,ERR_DEV_COMM,0);
				device_disable(dev);
				return ret;
			}
		} else {
			ldebug3(g_modbus_logger,"socket_send(): OK");
		}

		if( (ret=socket_recv(md->socket,(char *)&pkt,MODBUS_TCP_HEADER_LEN-1,md->timeout))!=0 ) {
			if(ret<0) {
				if(retries==1) {
					device_set_status(dev,ERR_DEV_COMM,0);
					device_disable(dev);
					return ret;
				}
				if( (ret=socket_connect(md->socket,md->addr))!=0 ) {
					lwarn(g_modbus_logger,format("socket_connect(): %d (%d)",ret, socket_error(md->socket)));
					device_set_status(dev,ERR_DEV_COMM,0);
					device_disable(dev);
					return ret;
				} else {
					ldebug2(g_modbus_logger,"socket_connect(): OK");
					++retries;
					goto recv_words_retry;
				}
			} else {
				lwarn(g_modbus_logger,format("socket_recv(): %d",ret));
				device_set_status(dev,ERR_DEV_COMM,0);
				device_disable(dev);
				return ret;
			}
		} else {
			ldebug3(g_modbus_logger,"socket_recv(): OK");
		}

		packet_len=swap16(pkt.length);
		if(packet_len>0) {
			if( (ret=socket_recv(md->socket,((char *)&pkt)+MODBUS_TCP_HEADER_LEN-1,packet_len,md->timeout))!=0 ) {
				lwarn(g_modbus_logger,format("socket_recv(): %d",ret));
				device_set_status(dev,ERR_DEV_COMM,0);
				device_disable(dev);
				return ret;
			} else {
				ldebug3(g_modbus_logger,"socket_recv(): OK");
			}
		}

		if(pkt.func&0x80) {
			MODBUS_ERROR_RSP *err=(MODBUS_ERROR_RSP *)pkt.data;
			lwarn(g_modbus_logger,format("Data Error: %d",err->exception_code));
			ret=ERR_DEV_PROTO;
			device_error(dev,var->name,ERR_DEV_PROTO,err->exception_code);
			break;
		} else {
			//ok
			ilsMemcpy(((char *)var->data)+current_size*2,rsp->data,rsp->bytes);
			switch(var->type) {
				case DW_INT2:
				case DW_UINT2:
					variable_data_swap(((char *)var->data)+current_size*2,DW_INT2,chunk_size);
					break;
				case DW_INT4:
				case DW_UINT4:
				case DW_FLOAT4:
					variable_data_swap(((char *)var->data)+current_size*2,DW_INT4,chunk_size/2);
					break;
			}
			ret=0;
		}
		current_size+=chunk_size;
	}

	return ret;
}

int _modbus_read_bits(DW_DEVICE *dev, DW_VARIABLE_DATA *var, unsigned char func) {
	MODBUS_DEVICE *md=dev->custom;
	MODBUS_TCP_PACKET  pkt;
	MODBUS_READ_REQ   *req;
	MODBUS_READ_RSP   *rsp;
	int total_size=0, current_size=0, chunk_size=0, idx;
	int packet_len, ret;
	int retries=0;

	//total_size=var->count/8+(((var->count%8)>0)?1:0);
	total_size=var->count;

	req=(MODBUS_READ_REQ *)pkt.data;
	rsp=(MODBUS_READ_RSP *)pkt.data;

	while(current_size<total_size) {
		idx=0;

		if(total_size-current_size>MODBUS_MAX_BITS_PER_REQUEST) {
			chunk_size = MODBUS_MAX_BITS_PER_REQUEST;
		} else {
			chunk_size = total_size-current_size;
		}

		ilsMemset(&pkt,0,sizeof(MODBUS_DEVICE));
		packet_len=MODBUS_TCP_HEADER_LEN;

		pkt.txn_id=swap16((md->seqid++));
		pkt.length=swap16(6);
		pkt.unit_id=md->slave_address;
		pkt.func=func;

		req->start_address=swap16(var->offset+current_size);
		req->count=swap16(chunk_size);
		packet_len+=5;

recv_bits_retry:
		if( (ret=socket_send(md->socket,(char *)&pkt,packet_len))!=0 ) {
			if(ret<0) {
				if(retries==1) {
					device_set_status(dev,ERR_DEV_COMM,0);
					device_disable(dev);
					return ret;
				}
				if( (ret=socket_connect(md->socket,md->addr))!=0 ) {
					lwarn(g_modbus_logger,format("socket_connect(): %d (%d)",ret, socket_error(md->socket)));
					device_set_status(dev,ERR_DEV_COMM,0);
					device_disable(dev);
					return ret;
				} else {
					ldebug2(g_modbus_logger,"socket_connect(): OK");
					++retries;
					goto recv_bits_retry;
				}
			} else {
				lwarn(g_modbus_logger,format("socket_send(): %d",ret));
				device_set_status(dev,ERR_DEV_COMM,0);
				device_disable(dev);
				return ret;
			}
		} else {
			ldebug3(g_modbus_logger,"socket_send(): OK");
		}

		if( (ret=socket_recv(md->socket,(char *)&pkt,MODBUS_TCP_HEADER_LEN-1,md->timeout))!=0 ) {
			if(ret<0) {
				if(retries==1) {
					device_set_status(dev,ERR_DEV_COMM,0);
					device_disable(dev);
					return ret;
				}
				if( (ret=socket_connect(md->socket,md->addr))!=0 ) {
					lwarn(g_modbus_logger,format("socket_connect(): %d (%d)",ret, socket_error(md->socket)));
					device_set_status(dev,ERR_DEV_COMM,0);
					device_disable(dev);
					return ret;
				} else {
					ldebug2(g_modbus_logger,"socket_connect(): OK");
					++retries;
					goto recv_bits_retry;
				}
			} else {
				lwarn(g_modbus_logger,format("socket_recv(): %d",ret));
				device_set_status(dev,ERR_DEV_COMM,0);
				device_disable(dev);
				return ret;
			}
		} else {
			ldebug3(g_modbus_logger,"socket_recv(): OK");
		}

		packet_len=swap16(pkt.length);
		if(packet_len>0) {
			if( (ret=socket_recv(md->socket,((char *)&pkt)+MODBUS_TCP_HEADER_LEN-1,packet_len,md->timeout))!=0 ) {
				lwarn(g_modbus_logger,format("socket_recv(): %d",ret));
				device_set_status(dev,ERR_DEV_COMM,0);
				device_disable(dev);
				return ret;
			} else {
				ldebug3(g_modbus_logger,"socket_recv(): OK");
			}
		}

		if(pkt.func&0x80) {
			MODBUS_ERROR_RSP *err=(MODBUS_ERROR_RSP *)pkt.data;
			lwarn(g_modbus_logger,format("Data Error: %d",err->exception_code));
			ret=ERR_DEV_PROTO;
			device_error(dev,var->name,ERR_DEV_PROTO,err->exception_code);
			break;
		} else {
			int i;
			//ok
			for(i=0;i<chunk_size;++i) {
				((char *)var->data)[current_size+i]=bool_getbit(&(rsp->data[i/8]),i%8);
			}
			ret=0;
		}
		current_size+=chunk_size;
	}

	return ret;
}
