//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/persistence.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_PERSISTENCE_H_
#define DW_CORE_PERSISTENCE_H_

#ifdef __cplusplus
extern "C" {
#endif

DWCORE_EXPORT int persistence_get(const char *group, const char *key, char **value);
DWCORE_EXPORT int persistence_del(const char *group, const char *key);
DWCORE_EXPORT int persistence_set(const char *group, const char *key, const char *value);

DWCORE_EXPORT int persistence_get_binary(const char *group, const char *key, char **value, int *len);
DWCORE_EXPORT int persistence_set_binary(const char *group, const char *key, const char *value, int len);

DWCORE_EXPORT int persistence_list_groups(char ***groups);
DWCORE_EXPORT int persistence_list_keys(const char *group, char ***keys);
DWCORE_EXPORT void persistence_list_free(char **lst);

DWCORE_EXPORT int persistence_import_group(const char *group, char *xml);
DWCORE_EXPORT int persistence_export_group(const char *group, char **xml);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_PERSISTENCE_H_*/
