//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/stcp.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_STCP_H_
#define ILS_UTIL_STCP_H_

#ifdef __cplusplus
extern "C" {
#endif

//general SSL functions
UTIL_EXPORT void stcp_init();

UTIL_EXPORT int stcp_morph(void *handle, const unsigned char *key, const unsigned char *iv, int bits);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_STCP_H_*/
