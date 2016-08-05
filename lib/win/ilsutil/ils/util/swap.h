//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/swap.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_SWAP_H_
#define ILS_UTIL_SWAP_H_

#if defined(ILS_LITTLE_ENDIAN)
#  define swap16(n) (((((unsigned short)(n) & 0xFF)) << 8) | (((unsigned short)(n) & 0xFF00) >> 8))
#  define swap32(n) (((((unsigned long)(n) & 0xFF)) << 24) | \
                    ((((unsigned long)(n) & 0xFF00)) << 8) | \
                    ((((unsigned long)(n) & 0xFF0000)) >> 8) | \
                    ((((unsigned long)(n) & 0xFF000000)) >> 24))
#  if defined(WIN32)
#    define swap64(x) (((_int64)(swap32((int)((x << 32) >> 32))) << 32) | (unsigned int)swap32(((int)(x >> 32))))
#    define swapdbl(x) (((_int64)(swap32((int)((x << 32) >> 32))) << 32) | (unsigned int)swap32(((int)(x >> 32))))
#  elif defined(CROSS_ENDIAN_DOUBLES)
#    define swap64(x) (((long long)(swap32((int)((x << 32) >> 32))) << 32) | (unsigned int)swap32(((int)(x >> 32))))
#    define swapdbl(x) (((long long)(swap32(((int)(x >> 32)))) << 32) | (unsigned int)swap32((int)((x << 32) >> 32)))
#  else
#    define swap64(x) (((long long)(swap32((int)((x << 32) >> 32))) << 32) | (unsigned int)swap32(((int)(x >> 32))))
#    define swapdbl(x) (((long long)(swap32((int)((x << 32) >> 32))) << 32) | (unsigned int)swap32(((int)(x >> 32))))
#  endif
#  define bswap16(n) n
#  define bswap32(n) n
#  define bswap64(n) n
#  define bswapdbl(n) n
#else
#  define swap16(n) n
#  define swap32(n) n
#  define swap64(n) n
#  define swapdbl(n) n
#  define bswap16(n) (((((unsigned short)(n) & 0xFF)) << 8) | (((unsigned short)(n) & 0xFF00) >> 8))
#  define bswap32(n) (((((unsigned long)(n) & 0xFF)) << 24) | \
                     ((((unsigned long)(n) & 0xFF00)) << 8) | \
                     ((((unsigned long)(n) & 0xFF0000)) >> 8) | \
                     ((((unsigned long)(n) & 0xFF000000)) >> 24))
#  define bswap64(n) (((long long)(bswap32((int)((n << 32) >> 32))) << 32) | (unsigned int)bswap32(((int)(n >> 32))))
#  define bswapdbl(n) (((long long)(bswap32((int)((n << 32) >> 32))) << 32) | (unsigned int)bswap32(((int)(n >> 32))))

#endif

#endif /*ILS_UTIL_SWAP_H_*/
