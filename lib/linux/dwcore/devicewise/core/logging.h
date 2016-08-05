//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/logging.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_LOGGING_H_
#define DW_CORE_LOGGING_H_

#ifdef __cplusplus
extern "C" {
#endif

#define LOG_FATAL	1
#define LOG_ERROR	2
#define LOG_WARN	3
#define LOG_INFO	4

#define LOG_CHAN_MSG			1
#define LOG_CLEAR_EXCEPTION		2
#define LOG_CLEAR_AUDIT			3

DWCORE_EXPORT int logging_exception(int level, const char *component, int msgid, const char* arg1, const char* arg2, const char* arg3, const char* arg4, const char* arg5);
DWCORE_EXPORT int logging_audit(const char *component, void *secctx, int op, int msgid, const char* arg1, const char* arg2, const char* arg3, const char* arg4, const char* arg5);
DWCORE_EXPORT int logging_system(int level, const char *component, int msgid, const char* arg1, const char* arg2, const char* arg3, const char* arg4, const char* arg5);

DWCORE_EXPORT int logging_custom_register(int nls_type, const char *name);
DWCORE_EXPORT int logging_custom(int nls_type, int level, const char *component, int msgid, const char* arg1, const char* arg2, const char* arg3, const char* arg4, const char* arg5);
DWCORE_EXPORT const char *logging_custom_name(int nls_type);
typedef void (*logging_list_fefunc)(int nls_type, const char *name,void *args);
DWCORE_EXPORT int logging_custom_list(logging_list_fefunc callback, void *custom);

DWCORE_EXPORT int logging_query_count(const char *xml, int *count);
DWCORE_EXPORT int logging_query(const char *xml, char ***result, int *count);
DWCORE_EXPORT void logging_result_free(char **result, int count);

DWCORE_EXPORT int logging_dump(const char *xml, const char *sqlite_select, const char *filename);
DWCORE_EXPORT int logging_export_get(char **xml);
DWCORE_EXPORT int logging_export_persist(const char *xml);

DWCORE_EXPORT void *logging_get_database_handle();
DWCORE_EXPORT int logging_is_full();

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_LOGGING_H_*/
