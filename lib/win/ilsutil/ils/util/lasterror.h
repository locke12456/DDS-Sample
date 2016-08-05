//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/lasterror.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_LASTERROR_H_
#define ILS_UTIL_LASTERROR_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int get_last_platform_error();
UTIL_EXPORT const char *get_last_platform_error_str();

UTIL_EXPORT int get_last_platform_net_error();

UTIL_EXPORT const char *get_platform_error_str(int err);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_LASTERROR_H_*/
