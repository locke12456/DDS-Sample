//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/updatable.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_UPDATABLE_H_
#define ILS_UTIL_UPDATABLE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*updatable_callback)(void);

UTIL_EXPORT void updatable_start_thread();
UTIL_EXPORT void updatable_run_here();

UTIL_EXPORT int updatable_put_work(updatable_callback cb, long interval);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_UPDATABLE_H_*/
