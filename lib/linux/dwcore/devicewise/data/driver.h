//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/driver.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_DRIVER_H_
#define DW_DATA_DRIVER_H_

#include <devicewise/data/variable.h>
#include <devicewise/data/device.h>
///
/// \file /devicewise/data/driver.h
/// \brief This header file contains the structures and function declarations needed to create a deviceWISE compatible device driver. 
/// A device driver is integrated with deviceWISE by registering a DW_DRIVER_REG structure with the deviceWISE DeviceManager component.
/// The DW_DRIVER_REG structure contains the program entry points that the deviceWISE DeviceManager will call for the device driver.
/// The program entry points must implement the function declarations defined within this header file.
///
#ifdef __cplusplus
extern "C" {
#endif

///
/// \typedef *_driver_device_validate
/// \brief declaration for the device driver validate function. The implementation of this function is required of all deviceWISE device drivers.
/// The validate function executes the steps necessary to see if the input parameters allow a connection to a physical device
/// \param dev is a pointer to a DW_DEVICE structure. This structure contains the input parameters that define the connection to the physical device
/// \param deep an integer value that determines if the level of validation. A value of 0 indicates a high level check of the validity of the parameters. A value of 1 indicates a low level, device connect validation, should be perfomed. 
/// return 0 if the device validation was successful. Return one of the deviceWISE error codes if the validation failed.
/// \sa errors.h. device.h
///
typedef int (*_driver_device_validate)(DW_DEVICE *dev, int deep);

///
/// \typedef *_driver_device_start
/// \brief declaration for the device driver start function. The implementation of this function is required of all deviceWISE device drivers.
/// The start function executes the steps necessary to connect to a physical device and enumerate the tags or register items defined on the devie.
/// \param dev is a pointer to a DW_DEVICE structure. This structure contains the input parameters that define the connection to the physical device.
/// return 0 if the device start was successful. Return one of the deviceWISE error codes if the start failed.
/// \sa errors.h. device.h
///
typedef int (*_driver_device_start)(DW_DEVICE *dev);

///
/// \typedef *_driver_device_stop
/// brief declaration for the device driver stop function. The implementation of this function is required of all deviceWISE device drivers.
/// The stop function executes the steps necessary to disconnect from a physical device. This function must release any memory allocated for the storage of device configuration data.
/// \param dev is a pointer to a DW_DEVICE structure. 
/// return 0 if the device stop was successful. Return one of the deviceWISE error codes if the stop failed.
/// \sa errors.h. device.h
///
typedef int (*_driver_device_stop)(DW_DEVICE *dev);

///
/// \typedef _driver_device_time_get
/// \brief declaration for the device driver function to read the time on the device.  The implementation of this function is optional.
/// The time get function executes the steps necessary to read the time from a physical device. The device must be in a started state to execute this function.
/// \param dev is a pointer to a DW_DEVICE structure. 
/// \param device_time is a pointer to a long long. The millisecond time representation from the device will be held in this variable.
/// return 0 if the device time was successfully read. Return one of the deviceWISE error codes if the get time request failed.
/// \sa errors.h. device.h
///
typedef int (*_driver_device_time_get)(DW_DEVICE *dev, long long *device_time);

///
/// \typedef _driver_device_time_set
/// \brief declaration for the device driver function to set the time on the device.  The implementation of this function is optional.
/// The time set function executes the steps necessary to set the time on a physical device. The device must be in a started state to execute this function.
/// \param dev is a pointer to a DW_DEVICE structure. 
/// \param device_time is a pointer to a long long. The millisecond time representation that will be set on the device will be held in this variable.
/// return 0 if the device time was successfully set. Return one of the deviceWISE error codes if the set time request failed.
/// \sa errors.h. device.h
///
typedef int (*_driver_device_time_set)(DW_DEVICE *dev, long long device_time);

///
/// \typedef _driver_device_refresh
/// \brief declaration for the device driver refresh function.  The implementation of this function is optional.
/// The refresh function re-enumerates the list tags or registers on a physical device. The device must be in a started state to execute this function.
/// \param dev is a pointer to a DW_DEVICE structure. 
/// return 0 if the re-enumeration of the device tags or registers was successful. Return one of the deviceWISE error codes if the refresh request failed.
/// \sa errors.h. device.h
///
typedef int (*_driver_device_refresh)(DW_DEVICE *dev);

// Runtime Variable Commands

///
/// \typedef _driver_variable_read
/// \brief declaration for function to read the value from a tag or register on a physical device. The implementation of this function is required if the driver has implemented the code to synchronously read data from a device.
/// The variable read function reads the data from a tag or a group of tags on a physical device. The device must be in a started state to execute this function.
/// \param dev is a pointer to a DW_DEVICE structure. 
/// \param vars is a pointer to an array of DW_VARIABLE_DATA structure. Each DW_VARIABLE_DATA structure contains the information about the tag or register to be read. The structure also contains a field where the data that is read will be stored.
/// \param var_count is an integer that contains the number of DW_VARIABLE_DATA structures in the vars parameter.
/// return 0 if the variables on the device were read. Return one of the deviceWISE error codes if the variable read request failed. Each DW_VARIABLE_DATA structure has a status and extended status field to record the results of each read request.
/// \sa errors.h. device.h variable.h
///
typedef int (*_driver_variable_read)(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count);

///
/// \typedef _driver_variable_write
/// \brief declaration for function to write a value to a tag or register on a physical device. The implementation of this function is required if the driver has implemented the code to synchronously write data to a device.
/// The variable write function writes data to a tag or a group of tags on a physical device. The device must be in a started state to execute this function.
/// \param dev is a pointer to a DW_DEVICE structure. 
/// \param vars is a pointer to an array of DW_VARIABLE_DATA structure. Each DW_VARIABLE_DATA structure contains the information about the tag or register to be written to. The structure also contains the data that will be written.
/// \param var_count is an integer that contains the number of DW_VARIABLE_DATA structures in the vars parameter.
/// return 0 if the variables on the device were successfully written to. Return one of the deviceWISE error codes if the variable write request failed. Each DW_VARIABLE_DATA structure has a status and extended status field to record the results of each write request.
/// \sa errors.h. device.h variable.h
///
typedef int (*_driver_variable_write)(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count);

///
/// \typedef _driver_variable_read_async
/// \brief declaration for function to read the value from a tag or register on a physical device. The implementation of this function is required if the driver has implemented the code to asynchronously read data from a device.
/// The variable read async function issues a read request to the physical device for data from a tag or a group of tags on a physical device. The receipt of the reply message from the device and the processing of the read data is handeled in a separate device driver thread. The device must be in a started state to execute this function.
/// \param dev is a pointer to a DW_DEVICE structure. 
/// \param vars is a pointer to an array of DW_VARIABLE_DATA structure. Each DW_VARIABLE_DATA structure contains the information about the tag or register to be read. The structure also contains a field where the data that is read will be stored.
/// \param var_count is an integer that contains the number of DW_VARIABLE_DATA structures in the vars parameter.
/// \param metadata is an internal deviceWISE structure that must be made available in the thread that issue the read request and the thread that processes the reply. The metadata must be returned to the deviceWISE driver manager's callback routine when the read process has completed.
/// return 0 if the read request for the variables was successfully sent to the device. Return one of the deviceWISE error codes if the read request failed. Each DW_VARIABLE_DATA structure has a status and extended status field to record the results of each read request. These values must be set in the thread that processes the responses from the physical device.
/// \sa errors.h. device.h variable.h
///
typedef int (*_driver_variable_read_async)(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count, void *metadata);

///
/// \typedef _driver_variable_write_async
/// \brief declaration for function to write data to a tag or register on a physical device. The implementation of this function is required if the driver has implemented the code to asynchronously write data to a device.
/// The variable write async function issues a write request to the physical device to a tag or a group of tags on a physical device. The receipt of the reply message from the device indicating the success or failure of the write request is handeled in a separate device driver thread. The device must be in a started state to execute this function.
/// \param dev is a pointer to a DW_DEVICE structure. 
/// \param vars is a pointer to an array of DW_VARIABLE_DATA structure. Each DW_VARIABLE_DATA structure contains the information about the tag or register to be written to. The structure also contains the data that will be written to the tags.
/// \param var_count is an integer that contains the number of DW_VARIABLE_DATA structures in the vars parameter.
/// \param metadata is an internal deviceWISE structure that must be made available in the thread that issues the write request and the thread that processes the reply. The metadata must be returned to the deviceWISE driver manager's callback routine when the write process has completed.
/// return 0 if the write request for the variables was successfully sent to the device. Return one of the deviceWISE error codes if the write request failed. Each DW_VARIABLE_DATA structure has a status and extended status field to record the results of each write request. These values must be set in the thread that processes the responses from the physical device.
/// \sa errors.h. device.h variable.h
///
typedef int (*_driver_variable_write_async)(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count, void *metadata);

typedef int (*_driver_variable_subscribe)(DW_DEVICE *dev, DW_SUBSCRIPTION **sub, DW_VARIABLE_DATA *vars,_driver_publish publish, void *custom,int qos, void *userctx);
typedef int (*_driver_variable_unsubscribe)(DW_DEVICE *dev, DW_SUBSCRIPTION *sub);
typedef int (*_driver_command_execute)(DW_DEVICE *dev, const char *name);

///
/// A structure that holds the information for a device driver that is registering with deviceWISE. The DW_DRIVER_REG object contains the device drivers function entry points.
///
typedef struct _DW_DRIVER_REG {
	_driver_device_validate			_device_validate;  ///< The name of the device drivers validate function: REQUIRED
	_driver_device_start			_device_start;     ///< The name of the device drivers start function: REQUIRED
	_driver_device_stop				_device_stop;      ///< The name of the device drivers stop function: REQUIRED
	_driver_device_time_get			_device_time_get;  ///< The name of the device drivers time get function: OPTIONAL
	_driver_device_time_set			_device_time_set;  ///< The name of the device drivers time set function: OPTIONAL
	_driver_device_refresh			_device_refresh;   ///< The name of the device drivers refresh function: OPTIONAL
	_driver_variable_read			_variable_read;    ///< The name of the device drivers read function: REQUIRED if processing read requests from the device synchronously
	_driver_variable_write			_variable_write;   ///< The name of the device drivers write function: REQUIRED if processing write requests to the device synchronously
	_driver_variable_read_async		_variable_read_async;   ///< The name of the device drivers read function: REQUIRED if processing read requests from the device asynchronously
	_driver_variable_write_async	_variable_write_async;  ///< The name of the device drivers write function: REQUIRED if processing write requests to the device asynchronously
	_driver_variable_subscribe		_variable_subscribe;    ///< The name of the device drivers variable subscribe function: FUTURE USE
	_driver_variable_unsubscribe	_variable_unsubscribe;  ///< The name of the device drivers variable unsubscribe function: FUTURE USE
	_driver_command_execute			_command_execute;       ///< The name of the device drivers command execute function: FUTURE USE
	processor_function				_processor_function;    ///< The name of the device drivers processor function: FUTURE USE
} DW_DRIVER_REG;

///
/// Function to register a device driver with deviceWISE.
/// \param name a character pointer that contains a name that will be associated with the device driver. 
/// \param reg a pointer to a DW_DRIVER_REG structure. 
/// \param reg_size of the memory region taken by the reg parameter, sizeof(DW_DRIVER_REG).
/// \param driver a pointer to a pointer to a DW_DRIVER structure. This variable will be NULL upon entry of the function. It will contain a handle to DW_DRIVER object that is created and maintained by the deviceWISE DeviceHandler component. This handle will be needed in device_type_register() function calls.
/// \return 0 if successful. Returns an error if a DW_DRIVER_REG of this name already exists (ERR_DRVR_ALREADYEXISTS). Will also return an error if it could not register the driver.
/// \sa errors.h
///
DWDATA_EXPORT int driver_register(const char *name, DW_DRIVER_REG *reg, int reg_size, DW_DRIVER **driver);

///
/// Function to retrieve a DW_DRIVER handle for a device driver that was previously registered with deviceWISE.
/// \param name a character pointer that contains a name of a device driver registered with deviceWISE 
/// \param driver a pointer to a pointer to a DW_DRIVER structure. This variable will be NULL upon entry of the function. It will contain a handle to DW_DRIVER object that is created and maintained by the deviceWISE DeviceHandler component. This handle will be needed in device_type_register() function calls.
/// \return 0 if successful. Will return an error if the device driver does not exist.
/// \sa errors.h
///
DWDATA_EXPORT int driver_find(const char *name, DW_DRIVER **driver);

DWDATA_EXPORT int driver_debug_check(DW_DEVICE *dev, void *socket);

///
/// This function is called by the device driver when it is done servicing an asynchronous read or write request. 
/// This is the deviceWISE driver manager's that must be called to complete the asynchronous read or write process.
/// \param metadata is a void pointer that is passed into the device drivers asynchronous read or write request. It must be returned back to the driver manager when the physical device response read or write request is processed.
/// \param call_here an integer value, either 0 (FALSE) or 1(TRUE) that indicates if the asynchronous read or write request has fully completed, ie. request was sent and a response was processed.
/// return 0 if successful.
/// \sa errors.h
///
DWDATA_EXPORT int driver_variable_async_callback(void *metadata, int call_here);

#ifdef __cplusplus
}
#endif

#endif /*DW_DATA_DRIVER_H_*/
