//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/log.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_LOG_H_
#define ILS_UTIL_LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*ils_log_err_func)(const char *format, ...);
UTIL_EXPORT int ilsLogInit(const char *filename,ils_log_err_func func);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_LOG_H_*/
