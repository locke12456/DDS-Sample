//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/schevent.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_SCHEVENT_H_
#define ILT_UTIL_SCHEVENT_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int schevent_create(void **handle);
UTIL_EXPORT int schevent_delete(void *handle);

UTIL_EXPORT int schevent_wait(void *handle);
UTIL_EXPORT int schevent_waitfor(void *handle, int timeout);
UTIL_EXPORT int schevent_waituntil(void *handle, long long ms);

UTIL_EXPORT int schevent_interrupt(void *handle);

UTIL_EXPORT int schevent_error(void *handle);

#ifdef __cplusplus
}
#endif

#endif /*SCHEVENT_H_*/
