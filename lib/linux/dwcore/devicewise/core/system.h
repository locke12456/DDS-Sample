//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/system.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_SYSTEM_H_
#define DW_CORE_SYSTEM_H_

#define SYSTEM_VAR_INTEGER	1
#define SYSTEM_VAR_STRING	2
#define SYSTEM_VAR_LONGLONG	3

#ifdef __cplusplus
extern "C" {
#endif

#define SYSTEM_CHNL_NAME_CHANGED		1
#define SYSTEM_CHNL_DESC_CHANGED		2
#define SYSTEM_CHNL_ATTN_SET			3
#define SYSTEM_CHNL_ATTN_CLEAR			4
#define SYSTEM_CHNL_SAFEMODE_EXIT		5
#define SYSTEM_CHNL_SUSPEND_CHANGED		6
#define SYSTEM_CHNL_LOCATION_CHANGED	7
#define SYSTEM_CHNL_DEPOYMENT_MODE_CHANGED	8
#define SYSTEM_CHNL_CMD_EXIT			9
#define SYSTEM_CHNL_VERSION_CHANGED		10

DWCORE_EXPORT const char *system_get_uptime_string();
DWCORE_EXPORT long long system_get_uptime_ms();

DWCORE_EXPORT int system_set_name(const char *name,void *secctx, int opt);
DWCORE_EXPORT const char *system_get_name();

DWCORE_EXPORT int system_set_version(const char *ver,void *secctx, int opt);
DWCORE_EXPORT const char *system_get_version();

DWCORE_EXPORT int system_set_desc(const char *desc,void *secctx, int opt);
DWCORE_EXPORT const char *system_get_desc();

DWCORE_EXPORT const char *system_get_product_name();
DWCORE_EXPORT const char *system_get_product_version();
DWCORE_EXPORT const char *system_get_product_platform();
DWCORE_EXPORT const char *system_get_product_type();
DWCORE_EXPORT const char *system_get_product_icon();

DWCORE_EXPORT int         system_database_is_deployment_mode_enabled();
DWCORE_EXPORT int         system_database_set_deployment_mode(int enabled, void *userctx);
DWCORE_EXPORT const char *system_database_get_version();

typedef void (*system_database_on_export_func)(void *deployment_db);
DWCORE_EXPORT void system_database_register_on_export_callback(system_database_on_export_func func);

DWCORE_EXPORT const char *system_get_build_string();
DWCORE_EXPORT unsigned int system_get_build_number();

DWCORE_EXPORT int system_is_authorized();
DWCORE_EXPORT int system_get_vendor_id();

DWCORE_EXPORT int  system_location_get(double *latitude, double *longitude);
DWCORE_EXPORT void system_location_set(double latitude, double longitude);

typedef int (*system_suspend_func)(void *secctx, int op);
DWCORE_EXPORT int system_suspend_register(system_suspend_func suspend, system_suspend_func resume);
DWCORE_EXPORT int system_suspend(void *secctx, int op);
DWCORE_EXPORT int system_resume(void *secctx, int op);
DWCORE_EXPORT int syetem_is_suspended();

typedef void (*sysvar_fefunc)(const char *name, const char *value, void *custom);

DWCORE_EXPORT int system_variable_register(const char *name, int type, void *value, int length, int opts);
DWCORE_EXPORT int system_variable_deregister(const char *name);
DWCORE_EXPORT int system_variable_set_value(const char *name, const char *value);
DWCORE_EXPORT int system_variable_get_value(const char *name, int *type, int *length, void *value);
DWCORE_EXPORT int system_variable_foreach(sysvar_fefunc func, void *custom);
DWCORE_EXPORT int system_variable_filedump(const char *filename);
DWCORE_EXPORT void system_variable_logdump();
typedef void(*system_variable_refresh_func)();
DWCORE_EXPORT void system_variable_refresh_register(system_variable_refresh_func callback);

DWCORE_EXPORT int system_version_to_int(const char *version);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_SYSTEM_H_*/
