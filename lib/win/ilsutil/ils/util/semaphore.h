//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/semaphore.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_SEMAPHORE_H_
#define ILS_UTIL_SEMAPHORE_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int semaphore_create(void **handle);
UTIL_EXPORT int semaphore_create_ex(void **handle, int initial_value);
UTIL_EXPORT int semaphore_delete(void *handle);
UTIL_EXPORT int semaphore_wait(void *handle);
UTIL_EXPORT int semaphore_timedwait(void *handle, int ms);
UTIL_EXPORT int semaphore_signal(void *handle);
UTIL_EXPORT int semaphore_error(void *handle);
UTIL_EXPORT int semaphore_count(void *handle);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_SEMAPHORE_H_*/
