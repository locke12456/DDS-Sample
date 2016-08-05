//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Modbus Driver Driver
//
//-- Filename: devicewise/modbus/modbus.h
//
//-- $Date: 2011/09/01 22:01:31 $
//-- $Revision: 1.2 $
//-- $Name:  $
//
//----------------------------------------------------------------

#ifndef DW_DEVICEWISE_MODBUS_MODBUS_H_
#define DW_DEVICEWISE_MODBUS_MODBUS_H_

#include <devicewise/core/core.h>
#include <devicewise/data/smart.h>
#include <devicewise/logic/logic.h>

#define MODBUS_TYPE_GENERIC			200

#define MODBUS_STR_LEN	64

typedef struct {
	char  addr[MODBUS_STR_LEN+4];
	int   options;
	int   timeout;
	unsigned short seqid;
	unsigned char slave_address;
	void *socket;
} MODBUS_DEVICE;

int modbus_device_validate(DW_DEVICE *dev, int deep);
int modbus_device_start(DW_DEVICE *dev);
int modbus_device_stop(DW_DEVICE *dev);

int modbus_variable_read(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count);
int modbus_variable_write(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count);

const char *modbus_build_version();

#endif /*DW_DEVICEWISE_MODBUS_MODBUS_H_*/
