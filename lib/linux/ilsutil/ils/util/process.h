//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/process.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_PROCESS_H_
#define ILS_UTIL_PROCESS_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int process_create(char **argv);

UTIL_EXPORT int process_is_running(const char *process_name);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_PROCESS_H_*/

