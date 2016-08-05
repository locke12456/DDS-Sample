//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/constants.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_CONSTANTS_H_
#define DW_DATA_CONSTANTS_H_

#define DW_VARIABLE_NAME_LEN 				128  ///< Maximum length of a deviceWISE variable name
#define DW_STRUCTURE_NAME_LEN 				128  ///< Maximum length of a deviceWISE structure name
#define DW_COMMAND_NAME_LEN 				128
#define DW_DEVICE_NAME_LEN 					128  ///< Maximum length of a deviceWISE device name
#define DW_DRIVER_NAME_LEN 					128  ///< Maximum length of a deviceWISE driver name
#define DW_DEVICE_ATTRIB_LEN				64
#define DW_DRIVER_CURRENT_VERSION 			1
#define DW_VARIABLE_MAX_DEVICES_PER_READ	32
#define DW_DEVICE_ERROR_HISTORY				10
#define DW_DEVICE_TYPE_TYPE_LEN				64
#define DW_DEVICE_WORK_QUEUE_DEFAULT_SIZE	256
#define DW_DEVICE_WORK_QUEUE_DEFAULT_DWELL	100

#define DW_INT1			1     ///< Code for a deviceWISE 1 byte signed integer data type 
#define DW_INT2			2     ///< Code for a deviceWISE 2 byte signed integer data type 
#define DW_INT4			3     ///< Code for a deviceWISE 4 byte signed integer data type 
#define DW_INT8			4     ///< Code for a deviceWISE 8 byte signed integer data type 
#define DW_UINT1		5     ///< Code for a deviceWISE 1 byte unsigned integer data type
#define DW_UINT2		6     ///< Code for a deviceWISE 2 byte unsigned integer data type 
#define DW_UINT4		7     ///< Code for a deviceWISE 4 byte unsigned integer data type 
#define DW_UINT8		8     ///< Code for a deviceWISE 8 byte unsigned integer data type 
#define DW_FLOAT4		9     ///< Code for a deviceWISE 4 byte floating point data type 
#define DW_FLOAT8		10    ///< Code for a deviceWISE 8 byte floating point data type 
#define DW_BOOL			11    ///< Code for a deviceWISE boolean data type 
#define DW_STRING		16    ///< Code for a deviceWISE string data type 
#define DW_TIMESTAMP	17    ///< Code for a deviceWISE timestamp data type 
#define DW_STRUCT		18    ///< Code for a deviceWISE structure data type 
#define DW_BINARY		19    ///< Code for a deviceWISE binary data type --future use
#define DW_NUMBER		253    ///< Code for a deviceWISE numeric data type --future use
#define DW_UNKNOWN		254    ///< Code for an unknown deviceWISE data type --future use
#define DW_ANY			255    ///< Code for a deviceWISE data type to be determined 

#define DW_INT1_MASK		(0x01<<DW_INT1)  ///< Used with DW_VARIABLE_INFO casts to allow mapping the variable as a 1 byte signed integer data type 
#define DW_INT2_MASK		(0x01<<DW_INT2)  ///< Used with DW_VARIABLE_INFO casts to allow mapping the variable as a 2 byte signed integer data type 
#define DW_INT4_MASK		(0x01<<DW_INT4)  ///< Used with DW_VARIABLE_INFO casts to allow mapping the variable as a 4 byte signed integer data type 
#define DW_INT8_MASK		(0x01<<DW_INT8)  ///< Used with DW_VARIABLE_INFO casts to allow mapping the variable as a 8 byte signed integer data type 
#define DW_UINT1_MASK		(0x01<<DW_UINT1)  ///< Used with DW_VARIABLE_INFO casts to allow mapping the variable as a 1 byte unsigned integer data type 
#define DW_UINT2_MASK		(0x01<<DW_UINT2)  ///< Used with DW_VARIABLE_INFO casts to allow mapping the variable as a 2 byte unsigned integer data type 
#define DW_UINT4_MASK		(0x01<<DW_UINT4)  ///< Used with DW_VARIABLE_INFO casts to allow mapping the variable as a 4 byte unsigned integer data type 
#define DW_UINT8_MASK		(0x01<<DW_UINT8)  ///< Used with DW_VARIABLE_INFO casts to allow mapping the variable as a 8 byte unsigned integer data type 
#define DW_FLOAT4_MASK		(0x01<<DW_FLOAT4)  ///< Used with DW_VARIABLE_INFO casts to allow mapping the variable as a 4 byte Floating Point data type 
#define DW_FLOAT8_MASK		(0x01<<DW_FLOAT8)  ///< Used with DW_VARIABLE_INFO casts to allow mapping the variable as a 8 byte Floating Point data type 
#define DW_BOOL_MASK		(0x01<<DW_BOOL)  ///< Used with DW_VARIABLE_INFO casts to allow mapping the variable as a boolean data type 
#define DW_STRING_MASK		(0x01<<DW_STRING)  ///< Used with DW_VARIABLE_INFO casts to allow mapping the variable as a string data type 
#define DW_TIMESTAMP_MASK	(0x01<<DW_TIMESTAMP)  ///< Used with DW_VARIABLE_INFO casts to allow mapping the variable as a timestamp data type 
#define DW_BINARY_MASK		(0x01<<DW_BINARY)  ///< Used with DW_VARIABLE_INFO casts to allow mapping the variable as a binary data type 

#define DW_DEVICE_STARTED	1  ///< Device is in the Started state
#define DW_DEVICE_STOPPED	2 ///< Device is in the Stopped state
#define DW_DEVICE_DISABLED	3 ///< Device is in the Disableed state
#define DW_DEVICE_STARTING	4 ///< Device is in the process of Starting
#define DW_DEVICE_STOPPING	5 ///< Device is in the process of Stopping
#define DW_DEVICE_UNKNOWN	6 ///< Device is in an unknown state
//used by the DEVICE channel
#define DW_DEVICE_CHANGED	7
#define DW_DEVICE_CREATED	8
#define DW_DEVICE_DELETED	9
#define DW_DEVICE_EDITED	10

#define DW_DEVICE_STARTED_MASK		(0x01<<DW_DEVICE_STARTED)
#define DW_DEVICE_STOPPED_MASK		(0x01<<DW_DEVICE_STOPPED)
#define DW_DEVICE_DISABLED_MASK		(0x01<<DW_DEVICE_DISABLED)
#define DW_DW_DEVICE_STARTING_MASK	(0x01<<DW_DEVICE_STARTING)
#define DW_DEVICE_STOPPING_MASK		(0x01<<DW_DEVICE_STOPPING)
#define DW_DEVICE_UNKNOWN_MASK		(0x01<<DW_DEVICE_UNKNOWN)

//used by the VARGROUP channel
#define DW_VARGROUP_CHL_ADDED			1
#define DW_VARGROUP_CHL_EDITED			2
#define DW_VARGROUP_CHL_DELETED			3
#define DW_VARGROUP_CHL_STARTED			4
#define DW_VARGROUP_CHL_STOPPED			5
#define DW_VARGROUP_CHL_ITEM_UPDATED	6

#define DW_READABLE			1   ///< The deviceWISE item can be read from
#define DW_WRITABLE			2   ///< The deviceWISE item can be written to
#define DW_SUBSCRIBABLE		4   ///< The deviceWISE item can be subscribed to
#define DW_DELETABLE		8   ///< The deviceWISE item can be deleted
#define DW_EDITABLE			16   ///< The deviceWISE item can be edited to
#define DW_CONTROLLABLE		32
#define DW_HOTEDITS			64
#define DW_NOFREE			128
#define DW_VALUE_AS_HEX		256   ///< Display the value of the deviceWISE item in hexadecimal format
#define DW_INDEX_AS_HEX		512   ///< The array offsets for the deviceWISE item is in hexadecimal format
#define DW_REFRESHABLE		1024
#define DW_CREATEABLE		2048
#define DW_ALLOW_COUNT		4096
#define DW_SORTVARS			8192  ///<The deviceWISE items are to be sorted
#define DW_EXSTATUS_AS_HEX	16384 ///< Display the extended status code for he deviceWISE item in hexadecimal format
#define DW_STR_LEN_EVEN		32768 ///< Accept input of Strings with an even number of characters
#define DW_LOCAL			65536
#define DW_MISSING			131072
#define DW_VALUE_AS_CHAR	262144
#define DW_INDEX_AS_OCTAL	524288   ///< The array offsets for the deviceWISE item is in octal format

#define DW_DEV_LIST_PROPS		1
#define DW_DEV_LIST_VARS		2
#define DW_DEV_LIST_STRUCTS		4
#define DW_DEV_LIST_RTSTATUS	8
#define DW_DEV_LIST_ERRORS		16
#define DW_DEV_LIST_ATTRIBS		32
#define DW_DEV_LIST_MAPDESCS	64
#define DW_DEV_LIST_COMMANDS	128

#define DW_INT1_MAX			(char)0x7F    ///< The maximum value for a 1 byte signed integer
#define DW_INT1_MIN			(char)0x80    ///< The minimum value for a 1 byte signed integer
#define DW_INT2_MAX			(short)0x7FFF    ///< The maximum value for a 2 byte signed integer
#define DW_INT2_MIN			(short)0x8000    ///< The minimum value for a 2 byte signed integer
#define DW_INT4_MAX			(int)0x7FFFFFFF    ///< The maximum value for a 4 byte signed integer
#define DW_INT4_MIN			(int)0x80000000    ///< The minimum value for a 4 byte signed integer
#define DW_INT8_MAX			(long long)0x7FFFFFFFFFFFFFFFLL    ///< The maximum value for an 8 byte signed integer
#define DW_INT8_MIN			(long long)0x8000000000000000LL    ///< The minimum value for an 8 byte signed integer

#define DW_UINT1_MAX		(unsigned char)0xFF   ///< The maximum value for a 1 byte unsigned integer
#define DW_UINT1_MIN		(unsigned char)0x00   ///< The minimum value for a 1 byte unsigned integer
#define DW_UINT2_MAX		(unsigned short)0xFFFF   ///< The maximum value for a 2 byte unsigned integer
#define DW_UINT2_MIN		(unsigned short)0x0000   ///< The minimum value for a 2 byte unsigned integer
#define DW_UINT4_MAX		(unsigned int)0xFFFFFFFF   ///< The maximum value for a 4 byte unsigned integer
#define DW_UINT4_MIN		(unsigned int)0x00000000   ///< The minimum value for a 4 byte unsigned integer
#define DW_UINT8_MAX		(unsigned long long)0xFFFFFFFFFFFFFFFFLL    ///< The maximum value for an 8 byte unsigned integer
#define DW_UINT8_MIN		(unsigned long long)0x0000000000000000LL    ///< The minimum value for an 8 byte unsigned integer

#define DW_FLOAT4_MAX		3.4E38      ///< The maximum value for a 4 byte Floating Point
#define DW_FLOAT4_MIN		-3.4E38     ///< The minimum value for a 4 byte Floating Point
#define DW_FLOAT8_MAX		1.7E308     ///< The maximum value for a 8 byte Floating Point
#define DW_FLOAT8_MIN		-1.7E308    ///< The minimum value for a 8 byte Floating Point

#endif /*DW_DATA_CONSTANTS_H_*/
