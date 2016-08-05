//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/config.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_CONFIG_H_
#define DW_CORE_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif

DWCORE_EXPORT int config_load(const char *file, const char *fullpath);
DWCORE_EXPORT int config_set(const char *file, const char *key, const char *value);
DWCORE_EXPORT int config_del(const char *file, const char *key);
DWCORE_EXPORT const char *config_get(const char *file, const char *key, const char *default_value);

typedef void (*config_callback)(const char *key, const char *value, void *custom);
DWCORE_EXPORT int config_foreach(const char *file, config_callback func, void *custom);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_CONFIG_H_*/
