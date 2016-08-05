//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/internal/driver.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_INTERNAL_DRIVER_H_
#define DW_DATA_INTERNAL_DRIVER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define META_OP_READ_ASYNC	1
#define META_OP_READ_SYNC	2
#define META_OP_WRITE_ASYNC	3
#define META_OP_WRITE_SYNC	4

typedef struct {
	char name[DW_DRIVER_NAME_LEN+4];
	_driver_device_validate			_device_validate;
	_driver_device_start			_device_start;
	_driver_device_stop				_device_stop;
	_driver_device_time_get			_device_time_get;
	_driver_device_time_set			_device_time_set;
	_driver_device_refresh			_device_refresh;
	_driver_variable_read			_variable_read;
	_driver_variable_write			_variable_write;
	_driver_variable_read_async		_variable_read_async;
	_driver_variable_write_async	_variable_write_async;
	_driver_variable_subscribe		_variable_subscribe;
	_driver_variable_unsubscribe	_variable_unsubscribe;
	_driver_command_execute			_command_execute;
	processor_function				_processor_function;
} _DW_DRIVER;

typedef struct {
	DW_DEVICE *dev;
	DW_VARIABLE_DATA **vars;
	int var_count;

	variable_async_callback user_callback;
	void *user_custom;
	long long start_time;
	int op;	
} _DW_DRIVER_RW_METADATA;

void driver_foreach(btree_fefunc func, void *custom);

const char *driver_get_name(const DW_DRIVER *driver);

// These functions are called by the device manager to invoke commands within a driver

int driver_device_validate(DW_DEVICE *dev, int deep);
int driver_device_start(DW_DEVICE *dev);
int driver_device_stop(DW_DEVICE *dev);

int driver_device_refresh(DW_DEVICE *dev);

int driver_device_time_get(DW_DEVICE *dev, long long *device_time);
int driver_device_time_set(DW_DEVICE *dev, long long device_time);

int driver_variable_read(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count);
int driver_variable_write(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count);
int driver_variable_read_async(_DW_DRIVER_RW_METADATA *metadata);
int driver_variable_write_async(_DW_DRIVER_RW_METADATA *metadata);
int driver_variable_subscribe(DW_DEVICE *dev, DW_SUBSCRIPTION **sub, DW_VARIABLE_DATA *var,_driver_publish publish,void *custom,int qos, void *userctx);
int driver_variable_unsubscribe(DW_DEVICE *dev, DW_SUBSCRIPTION *sub);
int driver_command_execute(DW_DEVICE *dev, const char *name);

int driver_device_ready_to_stop(DW_DEVICE *dev);

#ifdef __cplusplus
}
#endif

#endif /*DW_DATA_INTERNAL_DRIVER_H_*/
