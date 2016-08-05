//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/usage.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_USAGE_H_
#define DW_CORE_USAGE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef double(*usage_component_query)();
DWCORE_EXPORT int usage_total_register(const char *group_name, const char *name_for_remaining, int nls, usage_component_query callback);
DWCORE_EXPORT int usage_others_register(const char *group_name, const char *name_for_others, int nls, usage_component_query callback);
DWCORE_EXPORT int usage_component_register(const char *group_name, const char *name_for_compoenent, int nls, usage_component_query callback);

typedef void(*usage_foreach_func)(const char *name, int nls, double value, double percentage, void *custom);
DWCORE_EXPORT int usage_foreach(const char *group_name, usage_foreach_func foreach_callback, void *custom);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_USAGE_H_*/
