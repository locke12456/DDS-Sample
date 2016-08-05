//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/internal/module.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_INTERNAL_MODULE_H_
#define DW_CORE_INTERNAL_MODULE_H_

#include "devicewise/core/globals.h"

#ifdef __cplusplus
extern "C" {
#endif

DWCORE_EXPORT void module_set_properties_file(void *prop_file);
DWCORE_EXPORT void module_load_all(DW_GLOBALS *globals);
DWCORE_EXPORT void module_unload_all(DW_GLOBALS *globals);
DWCORE_EXPORT int module_list(void *packet);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_INTERNAL_MODULE_H_*/
