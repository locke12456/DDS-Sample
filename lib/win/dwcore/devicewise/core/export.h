//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/export.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_EXPORT_H_
#define DW_CORE_EXPORT_H_

#ifdef __cplusplus
extern "C" {
#endif

#define EXPORT_PUT_RETURN	0

#define DW_EXPORT_OPT_START		1

typedef int (*import_callback)(const char *item, const char *xml, void *secctx, int opt);
typedef int (*export_callback)(const char *item, char **xml, void *secctx, int opt);
typedef int (*verify_callback)(const char *item, void *secctx, int opt);

typedef int (*import_callback_ex)(const char *item, const char *xml, void *properties, int export_opt, void *secctx, int opt);
typedef int (*export_callback_ex)(const char *item, char **xml, void *properties, int export_opt, void *secctx, int opt);

DWCORE_EXPORT int export_register(const char* type, int nls_name, import_callback import, export_callback exprt, verify_callback verify);
DWCORE_EXPORT int export_register_ex(const char* type, int nls_name, import_callback_ex import, export_callback_ex exprt, verify_callback verify);
DWCORE_EXPORT int export_deregister(const char *type);

typedef void (*import_status_callback)(char *name, char *type, int status, void *custom); 
DWCORE_EXPORT int export_put(const char *xml, void *secctx, int opt, int verify, int import_state, import_status_callback callback, void *custom);

DWCORE_EXPORT int export_add_unexportable_item(const char *name, const char *type);
DWCORE_EXPORT int export_del_unexportable_item(const char *name, const char *type);

DWCORE_EXPORT int export_blob_build(char **result, const char **argv, int *arglen, int argc);
DWCORE_EXPORT int export_blob_extract(const char *xml, char **buffer, char **argv, int *arglen, int *argc);

#ifdef __cplusplus
}
#endif

#endif /*EXPORT_H_*/
