//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/data.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_DATA_H_
#define DW_DATA_DATA_H_

#include <devicewise/data/constants.h>
#include <devicewise/data/commands.h>
#include <devicewise/data/errors.h>
#include <devicewise/data/messages.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*custom_free)(void *);

typedef void DW_DRIVER;

///
/// A structure that holds the definition of a deviceWISE device. A DW_DEVICE object is created by the device_create() function
///
typedef struct {
	char name[DW_DEVICE_NAME_LEN+4]; ///< Name given to the device 
	int type;   ///< Integer value that identifies the type of device 
	void *custom;   ///< Pointer to hold a user defined structure that will be unique to each device  
} DW_DEVICE;

///
/// A structure to hold the definition of a deviceWISE structure definition
/// The DW_STRUCTURE_INFO is a container that will hold DW_VARIABLE_INFO items and other DW_STRUCTURE_INFO items. The DW_STRUCTURE_INFO is created by the sinfo_create() function and the DEVICE_ADD_SINFO macro
/// 
typedef struct {
	char *name;    ///< Name given to the DW_STRUCTURE_INFO item 
	int struct_id; ///< Numeric value that identifies a structure within the DW_DEVICE it has been added 
	int length;
	int options;  ///< Numeric codes that define the read (DW_READABLE) and write (DW_WRITEABLE) properties of the structure as well as its displayable (DW_SORTABLE) properties 
	void *custom; ///< A pointer to assign data that is unique to the structure 
	custom_free custom_free_func; ///< A function to be called to release the memory used by the data in the custom variable 
} DW_STRUCTURE_INFO;

/// 
/// A structure to hold the definition of a deviceWISE variable definition
/// The DW_VARIABLE_INFO represents tag variables, local and static trigger variables and global variable items. The DW_VARIABLE_INFO is created by the vinfo_create() function, the DEVICE_ADD_VINFO macro, and the SINFO_ADD_MEMBER macro
/// 
typedef struct {
	char *name; ///< Name given to the DW_VARIABLE_INFO item
	int name_nls;
	int type;  ///< The deviceWISE data type of the variable
	int struct_id; ///< The variables that are structures, the structural id value of the structure the variable represents 
	int xdim; ///< The size of the array for one dimensional arrays or the size of the first dimension for two or three dimensional array variables 
	int ydim; ///< The size of the second dimension for two or three dimensional array variables 
	int zdim;  ///< The size of the third dimension for three dimensional array variables 
	int length; ///< The size of the variable or an element within an array of variables 
	int count;  ///< Total number of elements within the variable if the variable is an array
	int offset; ///< Element offset within an array of items 
	int bitno;  ///< Bit offset within an integer variable
	int xstart; ///< The x dimension offset of the item within a two or three dimension array 
	int ystart; ///< The y dimension offset of the item within a two or three dimension array 
	int zstart; ///< The z dimension offset of the item within a two or three dimension array 
	int casts;  ///< Additional data type masks (ie. DW_INT4_MASK) that can be applied to the variable when reading its data \sa constants.h
	int options; ///< Numeric codes that define the read (DW_READABLE) and write (DW_WRITEABLE) properties of the variable \sa constants.h
	char *desc; ///< The description of the variable
	void *custom; ///< A pointer to assign data that is unique to the DW_VARIABLE_INFO 
	custom_free custom_free_func; ///< A pointer to assign data that is unique to the structure 
} DW_VARIABLE_INFO;

typedef struct {
	char name[DW_COMMAND_NAME_LEN+4];
	int name_nls;
	int desc_nls;
	int options;
} DW_COMMAND_INFO;

/// 
/// A structure used to request the read or write of a device variable
/// The DW_VARIABLE_DATA is passed to the device driver functions that read or write data. The DW_VARIABLE_DATA object is created by the variable_create() function and the variable_create_from_vinfo() function
/// 
typedef struct {
	char name[DW_VARIABLE_NAME_LEN+4];  ///< Name of the DW_VARIABLE_DATA item
	int type;  ///< The deviceWISE data type of the variable
	int count;  ///< The number of data items associated with this variable 
	int length; ///< The length of one data item in this variable 
	int bitno;  ///< The bit of interest within an integer variable 
	int offset; ///< The offset within an array for this variable 

	int status; ///< Status code associated with the read or write process for the variable, 0 value indicates success 
	int has_been_handled;  ///< Integer indicating if the read or write process has been performed for the variable 
	int max_age;
	DW_VARIABLE_INFO *vinfo;  ///< The DW_VARIABLE_INFO instance for this variable 
	unsigned char *data;  ///< The variable's data region that will hold either the value to be written or will hold the value read. It is the developers responsibility to allocate memory in the data variable. The variable_alloc_data() function can be used to allocate this memory 
	int data_len;  ///< the size, in number of bytes, of the data variable 
} DW_VARIABLE_DATA;

// WARNING: Modifying members of this structure at runtime
// can cause asynchronous reads and writes to fail!
typedef struct {
	DW_DEVICE *dev;
	DW_VARIABLE_DATA **vars;
	int var_count;
} DW_DRIVER_RW_METADATA;

// Subscription callback
typedef void DW_SUBSCRIPTION;
typedef void (*_driver_publish)(DW_SUBSCRIPTION *sub, DW_DEVICE *dev, DW_VARIABLE_DATA *var,void *custom);

//typedef void DW_VARIABLE_BLOCK;

DWDATA_EXPORT const char *data_build_version();

#ifdef __cplusplus
}
#endif

#include <devicewise/data/support.h>

#include <devicewise/data/variable.h>
#include <devicewise/data/structure.h>
#include <devicewise/data/command.h>
#include <devicewise/data/device.h>
#include <devicewise/data/driver.h>
#include <devicewise/data/publisher.h>
#include <devicewise/data/mapper.h>
#include <devicewise/data/binary.encoding.h>

#include <devicewise/data/macros.h>

#endif /*DW_DATA_H_*/
