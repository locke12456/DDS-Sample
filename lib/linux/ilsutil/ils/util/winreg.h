//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/winreg.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_WINREG_H_
#define ILS_UTIL_WINREG_H_

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)

UTIL_EXPORT int winreg_get_value( const char *path, const char *key, char **value, long *rc);
UTIL_EXPORT int winreg_set_value( const char *path, const char *key, char *value, long *rc);
UTIL_EXPORT int winreg_get_value2( const char *path, const char *key, char *value, int len, long *rc);
UTIL_EXPORT int winreg_list_values(const char *path, void *ptree );

#endif

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_WINREG_H_*/
