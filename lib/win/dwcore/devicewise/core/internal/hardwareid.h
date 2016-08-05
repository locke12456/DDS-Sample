//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/internal/hardwareid.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_INTERNAL_HARDWAREID_H_
#define DW_CORE_INTERNAL_HARDWAREID_H_

#include "devicewise/core/globals.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*hardwareid_list_callback)(HWID_ENTRY *hwids, int *count);
typedef int (*hardwareid_count_callback)();

DWCORE_EXPORT int global_hi_function_register(const char *type, int type_nls, hardwareid_count_callback count_callback,hardwareid_list_callback list_callback);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_INTERNAL_HARDWAREID_H_*/
