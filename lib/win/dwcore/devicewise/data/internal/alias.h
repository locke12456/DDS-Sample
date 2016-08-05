//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Alias Driver
//
//-- Filename: devicewise/data/internal/alias.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_INTERNAL_ALIAS_H_
#define DW_DATA_INTERNAL_ALIAS_H_

#define ALIAS_TYPE_DEVICE	8

#include <devicewise/core/core.h>
#include <devicewise/data/smart.h>

#define ALIAS_MODE_VARIABLE		1
#define ALIAS_MODE_DEVICE		2

typedef struct {
	int x;
	int  mode;
	char *dev_name;
	DW_DEVICE *adev;
	void *var_btree;
} ALIAS_DEVICE;

typedef struct {
	char device[DW_DEVICE_NAME_LEN+4];
	char name[DW_VARIABLE_NAME_LEN+4];
	int type;
	int length;
	int bitno;
	int index_format;
	int xdim;
	int ydim;
	int zdim;
} ALIAS_VARIABLE;

int alias_device_validate(DW_DEVICE *dev, int deep);
int alias_device_start(DW_DEVICE *dev);
int alias_device_stop(DW_DEVICE *dev);
int alias_refresh_model(DW_DEVICE *dev);

int alias_variable_read(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count, void *metadata);
int alias_variable_write(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count, void *metadata);
int alias_command_execute(DW_DEVICE *dev, const char *name);

//int alias_variable_subscribe(DW_DEVICE *dev, DW_SUBSCRIPTION **sub, DW_VARIABLE_DATA *var,_driver_publish publish,void *custom, int qos, void *userctx);
//int alias_variable_unsubscribe(DW_DEVICE *dev, DW_SUBSCRIPTION *sub);
//void alias_publisher_fail_now(DW_DEVICE *dev, DW_SUBSCRIPTION *sub);

#endif /*DW_DATA_INTERNAL_ALIAS_H_*/
