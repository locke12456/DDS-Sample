//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/mstimer.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_MSTIMER_H_
#define ILS_UTIL_MSTIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int mstimer_create(void **handle);
UTIL_EXPORT int mstimer_delete(void *handle);
UTIL_EXPORT int mstimer_start(void *handle);
UTIL_EXPORT int mstimer_stop(void *handle);
UTIL_EXPORT int mstimer_total(void *handle);
UTIL_EXPORT int mstimer_last(void *handle);
UTIL_EXPORT int mstimer_avg(void *handle);
UTIL_EXPORT int mstimer_clear(void *handle);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_MSTIMER_H_*/
