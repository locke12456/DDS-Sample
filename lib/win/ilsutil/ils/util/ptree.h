//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/ptree.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_PTREE_H_
#define ILS_UTIL_PTREE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*ptree_fefunc)(const char *key, const char *value, void *args);

UTIL_EXPORT int ptree_create(void **handle);
UTIL_EXPORT void ptree_delete(void *handle);
UTIL_EXPORT void ptree_clear(void *handle);
UTIL_EXPORT int ptree_count(void *handle);

UTIL_EXPORT int ptree_append(void *handle, void *other_ptree);

UTIL_EXPORT void ptree_foreach(void *handle, ptree_fefunc func, void *args);
UTIL_EXPORT int ptree_insert(void *handle, const char *key, const char *value);
UTIL_EXPORT int ptree_insert_int4(void *handle, const char *key, int value);
UTIL_EXPORT int ptree_insert_int8(void *handle, const char *key, long long value);
UTIL_EXPORT int ptree_update(void *handle, const char *key, const char *value);
UTIL_EXPORT int ptree_update_int4(void *handle, const char *key, int value);
UTIL_EXPORT int ptree_update_int8(void *handle, const char *key, long long value);
UTIL_EXPORT const char *ptree_find_by_key(void *handle, const char *key);
UTIL_EXPORT const char *ptree_find_by_key2(void *handle, const char *key, const char *def);
UTIL_EXPORT char *ptree_find_by_key_and_delete(void *handle, const char *key);
UTIL_EXPORT int ptree_delete_by_key(void *handle, const char *key);

UTIL_EXPORT int ptree_find_string(void *handle, const char *key, char **val);
UTIL_EXPORT int ptree_find_int4(void *handle, const char *key, int *val);
UTIL_EXPORT int ptree_find_int8(void *handle, const char *key, long long *val);

UTIL_EXPORT int ptree_to_json(void *handle, char **json_str);
UTIL_EXPORT int ptree_from_json(void *handle, const char *json_str);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_PTREE_H_*/
