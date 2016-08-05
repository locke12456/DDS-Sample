//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/base64.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_BASE64_H_
#define ILS_UTIL_BASE64_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT void base64_set_pad( char c );
UTIL_EXPORT int base64_sizeof( int asciiSize );
UTIL_EXPORT int base64_encode( const unsigned char *in, int inlen, char **out );
UTIL_EXPORT int base64_decode( const char *in, unsigned char **out, int *outlen );

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_BASE64_H_*/
