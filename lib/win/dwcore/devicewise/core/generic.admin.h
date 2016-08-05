//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/generic.admin.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_GENERIC_ADMIN_H_
#define DW_CORE_GENERIC_ADMIN_H_

#ifdef __cplusplus
extern "C" {
#endif

#define GENERICADMIN_OPT_CLOSE_ON_SUCCESS		0x01
#define GENERICADMIN_OPT_PROPERTIES_IN			0x02
#define GENERICADMIN_OPT_PROPERTIES_OUT			0x04
#define GENERICADMIN_OPT_DATA_LOSS				0x08
#define GENERICADMIN_OPT_TABLE_SINGLE			0x10
#define GENERICADMIN_OPT_TABLE_MULTI			0x20

typedef int (*generic_admin_callback)(void *session, void *in_props, void *out_props);

DWCORE_EXPORT int generic_admin_tab_create(void **tab, const char *name, int name_nls, const char *save_security_rule, generic_admin_callback get_callback, generic_admin_callback set_callback);
DWCORE_EXPORT int generic_admin_tab_delete(void *tab);

DWCORE_EXPORT int generic_admin_set_group(void *tab, const char *group);
DWCORE_EXPORT int generic_admin_set_default_buttons(void *tab, int show_buttons);
DWCORE_EXPORT int generic_admin_set_advanced(void *tab, int is_advanced);
DWCORE_EXPORT int generic_admin_set_readonly_condition(void *tab, const char *key, const char *value);
DWCORE_EXPORT int generic_admin_set_index(void *tab, int index);

DWCORE_EXPORT int generic_admin_add_button           (void *tab, const char *key, const char *name, int name_nls, const char *security_rule, generic_admin_callback callback);
DWCORE_EXPORT int generic_admin_add_subpanel_button	 (void *tab, const char *key, const char *name, int name_nls, const char *security_rule, const char *subpanel);
DWCORE_EXPORT int generic_admin_add_button_options   (void *tab, const char *key, int options);
DWCORE_EXPORT int generic_admin_add_button_warning_nls(void *tab, const char *key, int warning_nls);
DWCORE_EXPORT int generic_admin_add_button_condition (void *tab, const char *key, const char *value, int condition);

DWCORE_EXPORT int generic_admin_add_property_string  (void *tab, const char *key, const char *name, int name_id, int desc_id, int opts, const char *def);
DWCORE_EXPORT int generic_admin_add_property_other   (void *tab, const char *key, const char *name, int name_id, int desc_id, int opts, const char *type, const char *def);
DWCORE_EXPORT int generic_admin_add_property_option  (void *tab, const char *key, const char *name, int name_id, int desc_id, int opts, const char *options, int def);
DWCORE_EXPORT int generic_admin_add_property_integer (void *tab, const char *key, const char *name, int name_id, int desc_id, int opts, int defval, int minval, int maxval);
DWCORE_EXPORT int generic_admin_add_property_check   (void *tab, const char *key, const char *name, int name_id, int desc_id, int opts, int defval);
DWCORE_EXPORT int generic_admin_add_condition        (void *tab, const char *key, const char *value, int condition);

DWCORE_EXPORT int generic_admin_add_properties_file(void *tab, void **handle, const char *filename);
DWCORE_EXPORT int generic_admin_properties_set(void *handle, void *in_props);
DWCORE_EXPORT int generic_admin_properties_get(void *handle, void *out_props);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_GENERIC_ADMIN_H_*/
