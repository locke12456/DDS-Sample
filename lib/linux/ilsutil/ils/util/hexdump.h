//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/hexdump.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_HEXDUMP_H_
#define ILS_UTIL_HEXDUMP_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT char *hexdump( const void *data, int len );

UTIL_EXPORT void hexdump_console( const void *data, int len );

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_HEXDUMP_H_*/
