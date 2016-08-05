//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/strings.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_VERSION_H_
#define ILS_UTIL_VERSION_H_

#ifdef __cplusplus
extern "C" {
#endif

#define ILSUTIL_INTERFACE_VERSION	1

UTIL_EXPORT const char *ilsutil_build_version();
UTIL_EXPORT int ilsutil_interface_version();

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_VERSION_H_*/
