//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/guid.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_GUID_H_
#define ILS_UTIL_GUID_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT void guid_init();

UTIL_EXPORT char *guid_create();

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_GUID_H_*/
