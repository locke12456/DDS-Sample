//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/prop.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_PROP_H_
#define ILS_UTIL_PROP_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*prop_fefunc)(const char *key, const char *value, void *custom);

UTIL_EXPORT int prop_open(void **handle, const char *filename);
UTIL_EXPORT int prop_append(void *handle, const char *filename);
UTIL_EXPORT int prop_write(void *handle, const char *filename);
UTIL_EXPORT int prop_close(void *handle);
UTIL_EXPORT int prop_count(void *handle);

UTIL_EXPORT int prop_foreach(void *handle, prop_fefunc func, void *custom);

UTIL_EXPORT const char *prop_get(void *handle, const char *key, const char *default_value);
UTIL_EXPORT int         prop_set(void *handle, const char *key, const char *value);
UTIL_EXPORT int         prop_del(void *handle, const char *key);

UTIL_EXPORT void *prop_instrument_handle();

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_PROP_H_*/
