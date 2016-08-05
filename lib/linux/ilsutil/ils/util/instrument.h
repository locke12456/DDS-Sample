//----------------------------------------------------------------
//
//-- Filename: ils/util/instrument.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_INSTRUMENT_H_
#define ILS_UTIL_INSTRUMENT_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*instrument_header_callback)(JSON *json);
typedef void (*instrument_callback)(const void *item, JSON *json);

UTIL_EXPORT int instrument_global_disable();
UTIL_EXPORT int instrument_global_is_disabled();

UTIL_EXPORT int instrument_create(void **handle, const char *name, instrument_header_callback list_header_func, instrument_callback list_func, instrument_callback detail_func);
UTIL_EXPORT int instrument_delete(void *handle);

UTIL_EXPORT int instrument_add(void *handle, void *item);
UTIL_EXPORT int instrument_remove(void *handle, void *item);

UTIL_EXPORT int instrument_count(void *handle);
UTIL_EXPORT int instrument_list(void *handle, JSON **json);
UTIL_EXPORT int instrument_detail(void *handle, long long hash, JSON **json);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_INSTRUMENT_H_*/
