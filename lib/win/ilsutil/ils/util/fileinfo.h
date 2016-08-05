//----------------------------------------------------------------
//
//-- Filename: ils/util/fileinfo.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_FILEINFO_H_
#define ILS_UTIL_FILEINFO_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int fileinfo_create(void **handle, const char *name);
UTIL_EXPORT int fileinfo_delete(void *handle);

UTIL_EXPORT long long fileinfo_size(void *handle);
UTIL_EXPORT unsigned int fileinfo_created_time(void *handle);
UTIL_EXPORT unsigned int fileinfo_modified_time(void *handle);
UTIL_EXPORT unsigned int fileinfo_accessed_time(void *handle);

UTIL_EXPORT int fileinfo_isfile(void *handle);
UTIL_EXPORT int fileinfo_isdirectory(void *handle);

UTIL_EXPORT const char *fileinfo_created_time_str(void *handle);
UTIL_EXPORT const char *fileinfo_modified_time_str(void *handle);
UTIL_EXPORT const char *fileinfo_accessed_time_str(void *handle);
UTIL_EXPORT const char *fileinfo_type_str(void *handle);

UTIL_EXPORT int fileinfo_query( void *handle, const char *name );

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_FILEINFO_H_*/
