//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/event.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_EVENT_H_
#define ILS_UTIL_EVENT_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int event_create(void **handle);
UTIL_EXPORT int event_create_ex(void **handle, const char *name, int options);
UTIL_EXPORT int event_delete(void *handle);
UTIL_EXPORT int _event_wait(void *handle, int timeout, const char *file, int line);
#define event_wait(handle,timeout) _event_wait((handle),(timeout),__FILE__,__LINE__)
UTIL_EXPORT int event_lock(void *handle);
UTIL_EXPORT int event_unlock(void *handle);
UTIL_EXPORT int event_unlock1(void *handle);
UTIL_EXPORT int event_error(void *handle);
UTIL_EXPORT void *event_instrument_handle();

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_EVENT_H_*/
