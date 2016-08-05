//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/module.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_MODULE_H_
#define DW_CORE_MODULE_H_

#include "devicewise/core/globals.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*module_func)(DW_GLOBALS *globals);
//typedef void (*module_func)(GLOBAL_CONTEXT *ctx);
typedef void (*module_all_started_func)(void);

DWCORE_EXPORT void module_register(const char *name, module_func install_func, module_func uninstall_func, const char *start_after,const char *start_before);
DWCORE_EXPORT void module_call_when_all_loaded(module_all_started_func func);

DWCORE_EXPORT int module_get_version(const char *name);
DWCORE_EXPORT int module_set_version(const char *name, int version);
DWCORE_EXPORT int module_check_all_loaded();

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_MODULE_H_*/
