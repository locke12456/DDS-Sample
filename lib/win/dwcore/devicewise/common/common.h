//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/common/common.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_COMMON_COMMON_H_
#define DW_COMMON_COMMON_H_

#if !defined(TRUE)
#  define TRUE 1
#endif
#if !defined(FALSE)
#  define FALSE 0
#endif

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include <devicewise/common/config.h>
#include <devicewise/common/platform.h>
#include <devicewise/common/version.h>

#include <ils/util/everything.h>
#include <ils/logging/log.h>

// The unused options are reserved for individual
// components that need their own masks just for that
// specific feature.
#define DW_OPT_UNUSED1			1
#define DW_OPT_UNUSED2			2
#define DW_OPT_UNUSED3			4
#define DW_OPT_UNUSED4			8
#define DW_OPT_NO_ASYNC			16
#define DW_OPT_NO_AUDIT			32
#define DW_OPT_SEC_SESS			64
#define DW_OPT_INTERNAL			128
/// \brief DW_OPT_REQUIRED - User input is required for this variable
#define DW_OPT_REQUIRED			256
#define DW_OPT_IGNORE_STATE		512
/// \brief DW_OPT_READ_ONLY - The variable is Read only
#define DW_OPT_READ_ONLY		1024
/// \brief DW_OPT_SHOW_AS_HEX - The variable is to be represented in a Hexadecimal (0-F) format
#define DW_OPT_SHOW_AS_HEX		2048
#define DW_OPT_SORT				4096
/// \brief DW_OPT_SHOW_AS_OCTAL - The variable is to be represented in an Octal (0-7) format
#define DW_OPT_SHOW_AS_OCTAL	8192
#define DW_OPT_READ_ONLY_SAVE	16384
#define DW_OPT_LINK_IN_OUT		32768

#define MSG_MISSING				-1
#define MSG_LOGTHIS				100

#ifdef __cplusplus
extern "C" {
#endif

DWCOMMON_EXPORT const char *common_build_version();

#ifdef __cplusplus
}
#endif

#endif /*DW_COMMON_COMMON_H_*/
