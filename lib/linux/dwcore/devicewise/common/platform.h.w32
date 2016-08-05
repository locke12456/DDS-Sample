//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/common/platform.h.w32
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_COMMON_PLATFORM_H_
#define DW_COMMON_PLATFORM_H_

#if !defined(_WIN32)
#  if defined(_VX_CPU)
#    define _VXWORKS 1
#  endif
#  define _UNIX 1
#endif

#if defined(_WIN32)
#  if defined(EXPORT_DWCOMMON_SYMS)
#    define DWCOMMON_EXPORT __declspec(dllexport)
#  else
#    define DWCOMMON_EXPORT __declspec(dllimport)
#  endif
#else
#  define DWCOMMON_EXPORT
#endif

#if defined(_WIN32)
#  if defined(EXPORT_DWCORE_SYMS)
#    define DWCORE_EXPORT __declspec(dllexport)
#  else
#    define DWCORE_EXPORT __declspec(dllimport)
#  endif
#else
#  define DWCORE_EXPORT
#endif

#if defined(_WIN32)
#  if defined(EXPORT_DWDATA_SYMS)
#    define DWDATA_EXPORT __declspec(dllexport)
#  else
#    define DWDATA_EXPORT __declspec(dllimport)
#  endif
#else
#  define DWDATA_EXPORT
#endif

#if defined(_WIN32)
#  if defined(EXPORT_DWLOGIC_SYMS)
#    define DWLOGIC_EXPORT __declspec(dllexport)
#  else
#    define DWLOGIC_EXPORT __declspec(dllimport)
#  endif
#else
#  define DWLOGIC_EXPORT
#endif

#define HAVE_DATA_MAPPER 1
#define HAVE_CORE_NOTIFICATIONS 1

#endif /*DW_COMMON_PLATFORM_H_*/
