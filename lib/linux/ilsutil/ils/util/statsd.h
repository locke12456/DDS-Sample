//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/statsd.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_STATSD_H_
#define ILS_UTIL_STATSD_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int statsd_create(void **handle, const char *address);
UTIL_EXPORT int statsd_delete(void *handle);

UTIL_EXPORT int statsd_publish_timing( void *handle, const char *bucket, int value);
UTIL_EXPORT int statsd_publish_counter(void *handle, const char *bucket, int value, float sampling);
UTIL_EXPORT int statsd_publish_gauge(  void *handle, const char *bucket, int value);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_STATSD_H_*/
