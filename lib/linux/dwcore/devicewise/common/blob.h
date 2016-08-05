//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/common/blob.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_COMMON_BLOB_H_
#define DW_COMMON_BLOB_H_

#ifdef __cplusplus
extern "C" {
#endif

DWCOMMON_EXPORT int dwblob_append(void *handle, const void *data, int len);
DWCOMMON_EXPORT int dwblob_append_arr(void *handle, const void *data[], int len[], int count);
DWCOMMON_EXPORT int dwblob_append_int4(void *handle, int value);
DWCOMMON_EXPORT int dwblob_append_int8(void *handle, long long value);
DWCOMMON_EXPORT void dwblob_tokenize(const char *data, int data_len, char **argv, int *arglen, int *argc);
DWCOMMON_EXPORT void dwblob_tokenize_and_alloc(const char *data, int data_len, char ***argv, int **arglen, int *argc);
DWCOMMON_EXPORT int dwblob_get_max_token(const char *data, int data_len);
DWCOMMON_EXPORT int dwblob_get_count_tokens(const char *data, int data_len);

#ifdef __cplusplus
}
#endif

#endif /*DW_COMMON_BLOB_H_*/
