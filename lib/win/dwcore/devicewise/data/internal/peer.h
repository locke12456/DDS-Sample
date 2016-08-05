//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE PeerLINK Driver
//
//-- Filename: devicewise/data/internal/peer.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_INTERNAL_PEER_H_
#define DW_DATA_INTERNAL_PEER_H_

#define PEER_TYPE_DEVICE	5
#define PEER_TYPE_NODE		6
#define PEER_TYPE_ENDPOINT	7

#include <devicewise/core/core.h>
#include <devicewise/data/smart.h>

typedef struct {
	int sid;
	void *brdgconn;
	char *url;
	char *user;
	char *pass;
	char *type;
	char *device;
	void *struct_lookup;
	void *struct_lookup_pd;
	void *subscriptions;
	void *brdgstatus;
	void *channel;
	int timeout;
} PEER_DEVICE;

int peer_device_validate(DW_DEVICE *dev, int deep);
int peer_device_start(DW_DEVICE *dev);
int peer_device_stop(DW_DEVICE *dev);

int peer_variable_read(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count, void *metadata);
int peer_variable_write(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count, void *metadata);
int peer_command_execute(DW_DEVICE *dev, const char *name);

int node_device_validate(DW_DEVICE *dev, int deep);
int node_device_start(DW_DEVICE *dev);
int node_device_stop(DW_DEVICE *dev);
int node_refresh_model(DW_DEVICE *dev);

int node_variable_read(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count, void *metadata);
int node_variable_write(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count, void *metadata);
int node_command_execute(DW_DEVICE *dev, const char *name);

int peer_variable_subscribe(DW_DEVICE *dev, DW_SUBSCRIPTION **sub, DW_VARIABLE_DATA *var,_driver_publish publish,void *custom, int qos, void *userctx);
int peer_variable_unsubscribe(DW_DEVICE *dev, DW_SUBSCRIPTION *sub);
void peer_publisher_fail_now(DW_DEVICE *dev, DW_SUBSCRIPTION *sub);

#endif /*DW_DATA_INTERNAL_PEER_H_*/
