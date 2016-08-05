//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/blob.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_BLOB_H_
#define ILS_UTIL_BLOB_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int blob_create(void **handle, int initial_length);
UTIL_EXPORT void blob_delete(void *handle);
UTIL_EXPORT void blob_delete_object(void *handle);
UTIL_EXPORT int blob_clear(void *handle);
UTIL_EXPORT int blob_clone(void *handle, void **new_blob);

UTIL_EXPORT int blob_file2blob(void *blob,const char *filename);

UTIL_EXPORT void *blob_get_buffer(void *handle);
UTIL_EXPORT int blob_get_length(void *handle);

UTIL_EXPORT int blob_truncate(void *handle, int length);

UTIL_EXPORT int blob_append(void *handle, const void *data, int data_len);
UTIL_EXPORT int blob_append_string(void *handle, const char *str);
UTIL_EXPORT int blob_format_append(void *handle, const char *msg, ...);

UTIL_EXPORT int blob_array_init(void *handle, int record_size);
UTIL_EXPORT int blob_array_push(void *handle, void *data);
UTIL_EXPORT int blob_array_get(void *handle, int index, void *buffer);
UTIL_EXPORT int blob_array_get_buffer(void *handle, int index, void **ptr);
UTIL_EXPORT int blob_array_set(void *handle, int index, void *buffer);
UTIL_EXPORT int blob_array_count(void *handle);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_BLOB_H_*/
