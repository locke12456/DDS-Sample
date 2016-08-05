//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/directory.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_DIRECTORY_H_
#define ILS_UTIL_DIRECTORY_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*directory_fefunc)(const char *name, void *fileinfo_entry, void *custom);

UTIL_EXPORT int directory_create(const char *name);
UTIL_EXPORT int directory_create_recursive(const char *name);
UTIL_EXPORT int directory_query(const char *name, const char *pattern, char *entries[], int count);
UTIL_EXPORT int directory_query2(const char *name, const char *pattern, char ***entries);

UTIL_EXPORT char *directory_cwd_get(char *buffer, int len);
UTIL_EXPORT int   directory_cwd_set(const char *buffer);

UTIL_EXPORT int directory_delete(const char *name);
UTIL_EXPORT int directory_delete_recursive(const char *name);
UTIL_EXPORT int directory_foreach(const char *name, int recursive, directory_fefunc func, void *custom);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_DIRECTORY_H_*/
