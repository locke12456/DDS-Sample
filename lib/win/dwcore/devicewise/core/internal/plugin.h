//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/internal/plugin.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_INTERNAL_PLUGIN_H_
#define DW_CORE_INTERNAL_PLUGIN_H_

#ifdef __cplusplus
extern "C" {
#endif

DWCORE_EXPORT void plugin_load_all(void *props_file);
DWCORE_EXPORT int plugin_list(void *packet);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_INTERNAL_PLUGIN_H_*/
