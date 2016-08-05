//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/cmdline.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_CMDLINE_H_
#define ILS_UTIL_CMDLINE_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int  cmdline_init(void **handle, int argc, const char *argv[]);
UTIL_EXPORT void cmdline_free(void *handle);
UTIL_EXPORT int  cmdline_get_option(void *handle, const char *opt, char *value, int value_len);
UTIL_EXPORT int cmdline_get_option2(void *handle, const char *opt, char **value);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_CMDLINE_H_*/
