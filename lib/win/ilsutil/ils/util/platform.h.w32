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

#undef ILS_BIG_ENDIAN
#define ILS_LITTLE_ENDIAN 1
#undef CROSS_ENDIAN_DOUBLES

#define OS_PATH_SEPERATOR '\\'

#if defined(_WIN32)
#  if defined (_MSC_VER) && (_MSC_VER >= 1020)
#    define strcasecmp(one,two) _strcmpi(one,two)
#  else
#    define strcasecmp(one,two) strcmpi(one,two)
#  endif
#  define strncasecmp(one,two,len) _strnicmp(one,two,len)
#  define strtoll(one,two,three) _strtoi64(one,two,three)
#  define strtoull(one,two,three) _strtoui64(one,two,three)
#  define strtok_r(one,two,three) strtok(one,two)
#  define localtime_r(one,two) localtime(one)
#  define snprintf _snprintf
#  define atoll _atoi64
#  if defined(EXPORT_UTIL_SYMS)
#    define UTIL_EXPORT __declspec(dllexport)
#  else
#    define UTIL_EXPORT __declspec(dllimport)
#  endif
#endif

#undef HAS_STRTOK_R

#endif /*ILS_UTIL_PLATFORM_H_*/
