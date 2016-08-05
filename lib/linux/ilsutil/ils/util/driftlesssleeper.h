//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/driftlesssleeper.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_DRIFTLESSSLEEPER_H_
#define ILS_UTIL_DRIFTLESSSLEEPER_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int driftlesssleeper_create(void **handle, int ms);
UTIL_EXPORT int driftlesssleeper_create_ex(void **handle, int ms, int *total_iter_ptr, int *miss_iter_ptr);
UTIL_EXPORT int driftlesssleeper_set_overflow_protection(void *handle, int enabled);
UTIL_EXPORT int driftlesssleeper_sleep(void *handle);
UTIL_EXPORT int driftlesssleeper_delete(void *handle);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_DIFTLESSSLEEPER_H_*/
