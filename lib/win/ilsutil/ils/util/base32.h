//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/base32.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_BASE32_H_
#define ILS_UTIL_BASE32_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT void base32_set_pad( char c );
UTIL_EXPORT int base32_encode( const unsigned char *in, int inlen, char **out );
UTIL_EXPORT int base32_decode( const char *in, unsigned char **out, int *outlen );

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_BASE32_H_*/
