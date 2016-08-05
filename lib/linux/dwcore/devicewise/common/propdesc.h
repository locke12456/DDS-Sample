//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/common/propdesc.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_COMMON_PROPDESC_H_
#define DW_COMMON_PROPDESC_H_

#ifdef __cplusplus
extern "C" {
#endif

#define DW_OPT_ADVANCED		1
#define DW_OPT_REVALIDATE	2

#define PROP_COND_EQUAL			1
#define PROP_COND_NOT_EQUAL		2
#define PROP_COND_RELATION_OR	1
#define PROP_COND_RELATION_AND	2

DWCOMMON_EXPORT int propdesc_create(void **phandle);
DWCOMMON_EXPORT void propdesc_delete(void *phandle);
//DWCOMMON_EXPORT void propdesc_to_xml(void *phandle, const char **xml);
DWCOMMON_EXPORT void propdesc_to_xmlwriter(void *phandle, void *writer);
DWCOMMON_EXPORT void propdesc_to_xmlwriter2(void *phandle, void *writer);

DWCOMMON_EXPORT int propdesc_add_property_string(void *phandle, const char *key, const char *name, int name_id, int desc_id, int opts, const char *def);
DWCOMMON_EXPORT int propdesc_add_property_option(void *phandle, const char *key, const char *name, int name_id, int desc_id, int opts, const char *options, int defopt);
DWCOMMON_EXPORT int propdesc_add_property_integer(void *phandle, const char *key, const char *name, int name_id, int desc_id, int opts, int defval, int minval, int maxval);
DWCOMMON_EXPORT int propdesc_add_property_check(void *phandle, const char *key, const char *name, int name_id, int desc_id, int opts, int defval);
DWCOMMON_EXPORT int propdesc_add_property_other(void *phandle, const char *key, const char *name, int name_id, int desc_id, int opts, const char *type, const char *def);

DWCOMMON_EXPORT int propdesc_add_condition(void *phandle, int condition, const char *key, const char *value);

#ifdef __cplusplus
}
#endif

#endif /*DW_COMMON_PROPDESC_H_*/
