//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/reference.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_REFERENCE_H_
#define DW_CORE_REFERENCE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define REFERENCE_DELIMITER		"\v"

typedef int (*reference_check_callback)(const char *item);

DWCORE_EXPORT int reference_register_check(const char *key_type, reference_check_callback callback);
DWCORE_EXPORT int reference_set(const char *key_type, const char *key, const char *resource_type, const char *resource);
DWCORE_EXPORT int reference_set_list(const char *key_type, const char *key, void *resource_list);
DWCORE_EXPORT int reference_del(const char *key_type, const char *key);
DWCORE_EXPORT int reference_del2(const char *key_type, const char *key, const char *resource_type, const char *resource);

DWCORE_EXPORT int reference_list(const char *combo_key, char ***out_argv, int *out_argc);
DWCORE_EXPORT int reference_list_children(const char *type, const char *key, char ***out_argv, int *out_argc);
DWCORE_EXPORT int reference_list_parents(const char *type, const char *key, char ***out_argv, int *out_argc);

DWCORE_EXPORT int resource_list_create(void **resource_list);
DWCORE_EXPORT void resource_list_delete(void *resource_list);
DWCORE_EXPORT int resource_list_add(void *resource_list, const char *type, const char *resource);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_REFERENCE_H_*/
