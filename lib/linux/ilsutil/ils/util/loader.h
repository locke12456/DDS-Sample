//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/loader.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_LOADER_H_
#define ILS_UTIL_LOADER_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int loader_load(void **handle, const char *path);
UTIL_EXPORT int loader_unload(void *handle);
UTIL_EXPORT const char *loader_error(void *handle);
UTIL_EXPORT void *loader_get_symbol(void *handle, const char *symbol);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_LOADER_H_*/
