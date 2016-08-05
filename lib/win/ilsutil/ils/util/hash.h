//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/hash.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_HASH_H_
#define ILS_UTIL_HASH_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT unsigned short hash_crc16_ccitt(const void * addr, unsigned short len, unsigned short seed);

UTIL_EXPORT unsigned int hash_crc32( const char *data, unsigned int datalen );
UTIL_EXPORT int hash_file_crc32( const char *filename, unsigned int *crc32 );

UTIL_EXPORT void hash_crc32_init( unsigned int *crc );
UTIL_EXPORT void hash_crc32_calc( unsigned int *crc, const char *data, unsigned int datalen );
UTIL_EXPORT void hash_crc32_end( unsigned int *crc );
#ifdef __cplusplus
}
#endif

#endif /*HASH_H_*/
