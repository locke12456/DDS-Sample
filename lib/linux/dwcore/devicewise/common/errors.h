//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/common/errors.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_COMMON_ERRORS_H_
#define DW_COMMON_ERRORS_H_

//General Errors
// -1000 - -1099 Generic Error Codes
#define ERR_INTERFACE_VERSION_MISMATCH	-1000

#define ERR_UNKNOWN					-1001
#define ERR_BADXML					-1002
#define ERR_GENERIC					-1003

#define ERR_GEN_NOTFOUND			-1011
#define ERR_GEN_EXISTS				-1012
#define ERR_GEN_STARTED				-1013
#define ERR_GEN_STOPPED				-1014
#define ERR_GEN_KEY_EXISTS			-1015
#define ERR_GEN_KEY_NOTFOUND		-1016

#define ERR_VALIDATE_TOOLONG		-1021
#define ERR_VALIDATE_BADCHARS		-1022

#define ERR_PKT_BADCRC				-1051 // Header Checksum Incorrect.
#define ERR_PKT_BADPAYLOAD			-1052 // Payload is invalid.

#endif /*DW_COMMON_ERRORS_H_*/
