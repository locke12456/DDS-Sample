//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/winsvc.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_WINSVC_H_
#define ILS_UTIL_WINSVC_H_

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)

#define WINSVC_SETUP_DISPATCHER(svc_name,func_name) SERVICE_TABLE_ENTRY dispatch_table[] = { { TEXT(svc_name), (LPSERVICE_MAIN_FUNCTION)func_name},{ NULL, NULL } };

UTIL_EXPORT int winsvc_start(const char *svc_name);
UTIL_EXPORT int winsvc_stop(const char *svc_name);
UTIL_EXPORT int winsvc_install(const char *svc_name, const char *display_name, const char *desc, const char *dependencies);
UTIL_EXPORT int winsvc_remove(const char *svc_name);

typedef void (*winsvc_stop_callback)(void);

UTIL_EXPORT int winsvc_status_init(const char *svc_name, winsvc_stop_callback stop_callback);
UTIL_EXPORT int winsvc_status_report(unsigned long current_state, unsigned long exit_code, unsigned long wait_hint);

#endif

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_WINSVC_H_*/
