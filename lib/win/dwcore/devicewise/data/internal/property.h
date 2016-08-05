//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Global Driver
//
//-- Filename: devicewise/data/internal/property.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_INTERNAL_PROPERTY_H_
#define DW_DATA_INTERNAL_PROPERTY_H_

#define PROPERTY_TYPE_DEVICE	10

#include <devicewise/core/core.h>
#include <devicewise/data/smart.h>

int property_device_validate(DW_DEVICE *dev, int deep);
int property_device_start(DW_DEVICE *dev);
int property_device_stop(DW_DEVICE *dev);
int property_refresh_model(DW_DEVICE *dev);
int property_refresh_model_cmd(DW_DEVICE *dev, const char *name);

int property_variable_read(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count);
int property_variable_write(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count);

#endif /*DW_DATA_INTERNAL_PROPERTY_H_*/
