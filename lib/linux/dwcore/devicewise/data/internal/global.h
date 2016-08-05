//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Global Driver
//
//-- Filename: devicewise/data/internal/GLOBAL.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_INTERNAL_GLOBAL_H_
#define DW_DATA_INTERNAL_GLOBAL_H_

#define GLOBAL_TYPE_DEVICE	9

#include <devicewise/core/core.h>
#include <devicewise/data/smart.h>

typedef struct {
	int default_value;
	int persist_values;
	int sort_vars;
	void *var_btree;
	void *persistence_database;
} GLOBAL_DEVICE;

typedef struct {
	char device[DW_DEVICE_NAME_LEN+4];
	char name[DW_VARIABLE_NAME_LEN+4];
	int type;
	int length;
	int index_as_hex;
	int xdim;
	int ydim;
	int zdim;
} GLOBAL_VARIABLE;

int global_device_validate(DW_DEVICE *dev, int deep);
int global_device_start(DW_DEVICE *dev);
int global_device_stop(DW_DEVICE *dev);
int global_refresh_model(DW_DEVICE *dev);

int global_variable_read(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count);
int global_variable_write(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count);
int global_command_execute(DW_DEVICE *dev, const char *name);

#endif /*DW_DATA_INTERNAL_GLOBAL_H_*/
