//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/indirect.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_INDIRECT_H_
#define ILS_UTIL_INDIRECT_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*indirect_free_func)(void *);

UTIL_EXPORT void indirect_init(int page_size,int page_max);
UTIL_EXPORT void indirect_status();

UTIL_EXPORT int indirect_new(void *ptr, indirect_free_func free_func);
UTIL_EXPORT void indirect_free(int id);
UTIL_EXPORT void *indirect_get(int id);
UTIL_EXPORT void indirect_unget(int id);
UTIL_EXPORT int indirect_exists(int id);
UTIL_EXPORT int indirect_count(int id);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_INDIRECT_H_*/
