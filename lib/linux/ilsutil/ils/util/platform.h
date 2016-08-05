//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/platform.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_PLATFORM_H_
#define ILS_UTIL_PLATFORM_H_

#ifdef _VX_CPU
#  ifdef _WRS_KERNEL
#    define _VXWORKS_KNL 1
#  else
#    define _VXWORKS_RTP 1
#  endif
#  define _VXWORKS 1
#endif
#define _UNIX 1
#define _LINUX 1
#define _REENTRANT 1

#if defined(_LINUX) || defined(_VXWORKS)
#  define _GNU_SOURCE 1
#endif

#if defined(_VXWORKS)
#  define atoll(x) strtoll(x,NULL,0)
#endif

#undef ILS_BIG_ENDIAN
#define ILS_LITTLE_ENDIAN 1

#undef CROSS_ENDIAN_DOUBLES

#define ILS_SIZEOF_VOIDP 4

#define OS_PATH_SEPERATOR '/'

#define UTIL_EXPORT

#define HAS_STRTOK_R 1

#endif /*ILS_UTIL_PLATFORM_H_*/
