/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2015 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE 
 *
 *   for full copyright notice and license terms. 
 *
 */
#include "os_abstract.h"

#ifdef PA_LITTLE_ENDIAN
#  define htole16(x) (x)
#  define le32toh(x) (x)
#else
#  define htole16(x) ((u16)( (((x) & 0xff) << 8) | (((x) >> 8) & 0xff) ))
#  define le32toh(x) ( (((x) & 0xff000000) >> 24) | (((x) & 0xff0000) >>  8) | (((x) & 0xff00) <<  8) | (((x) & 0xff) << 24) )

#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef unsigned long long u64;

#define BUG_ON(x) assert(!(x))

#define get_unaligned(x) (*(x))
#define get_unaligned_le32(x) (le32toh(*(u32 *)(x)))
#define put_unaligned(v,x) (*(x) = (v))
#define put_unaligned_le16(v,x) (*(u16 *)(x) = htole16(v))

#define vmalloc(x) malloc(x)
#define vfree(x) free(x)

#define EXPORT_SYMBOL(x)

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

#ifdef __GNU__
#define likely(x) __builtin_expect((x), 1)
#define unlikely(x) __builtin_expect((x), 0)
#else
#define likely(x) (x)
#define unlikely(x) (x)
#endif

#define min_t(t,x,y) ((x) < (y) ? (x) : (y))
#define max_t(t,x,y) ((x) > (y) ? (x) : (y))

#define BITS_PER_LONG (__SIZEOF_LONG__ * 8)
