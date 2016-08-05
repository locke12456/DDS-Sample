//----------------------------------------------------------------
//
//-- Filename: ils/logging/internal.h
//-- INTERNAL USE ONLY
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_LOGGING_INTERNAL_H_
#define ILS_LOGGING_INTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(_WIN32)
#  if defined(_VX_CPU)
#    define _VXWORKS 1
#  endif
#  define _UNIX 1
#endif

#include <ils/internal/config.h>
#include "ils/logging/errors.h"

#if defined(HAVE_SYS_TIME_H)
#  include <sys/time.h>
#endif

#if defined(HAVE_TIME_H)
#  include <time.h>
#endif

#if defined(HAVE_ERRNO_H)
#  include <errno.h>
#endif

#if defined(HAVE_STDARG_H)
#  include <stdarg.h>
#endif

#if defined(_WIN32)
#  include <windows.h>
#  if defined(_MSC_VER) && (_MSC_VER >= 1020)
#    define strcasecmp(one,two) _strcmpi(one,two)
#  else
#    define strcasecmp(one,two) strcmpi(one,two)
#  endif
#  if defined(EXPORT_LOG_SYMS)
#    define LOG_EXPORT __declspec(dllexport)
#  else
#    define LOG_EXPORT __declspec(dllimport)
#  endif
#  undef ERROR
#  undef TRACE
#  undef DEBUG
#else
#  define LOG_EXPORT
#endif

#define TRUE 1
#define FALSE 0

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Logging Constants
#define MAX_APPENDERS_PER_LOGGER 32
#define MAX_PATH_DEPTH 8
#define MAX_APPENDER_NAME 63
#define MAX_PART_NAME 31
#define MAX_PATH_NAME 63

#ifdef __cplusplus
}
#endif

#endif /*INTERNAL_H_*/
