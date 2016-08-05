//----------------------------------------------------------------
//
//-- Filename: ils/logging/log.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_LOGGING_LOG_H_
#define ILS_LOGGING_LOG_H_

#if defined(_WIN32)
#  if defined(EXPORT_LOG_SYMS)
#    define LOG_EXPORT __declspec(dllexport)
#  else
#    define LOG_EXPORT __declspec(dllimport)
#  endif
#else
#  define LOG_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define LOG_FATAL	1
#define LOG_ERROR	2
#define LOG_WARN	3
#define LOG_INFO	4
#define LOG_TRACE	5
#define LOG_DEBUG	6
#define LOG_DEBUG1	7
#define LOG_DEBUG2	8
#define LOG_DEBUG3	9
#define LOG_DEBUG4	10

LOG_EXPORT void log_create(void **handle, const char *name);
LOG_EXPORT void log_delete(void *handle);
LOG_EXPORT void log_recheck(void *handle);
LOG_EXPORT void log_this(void *handle, int level, const char *msg, const char *file, int line);
LOG_EXPORT int  log_is_fatal_enabled(void *handle);
LOG_EXPORT int  log_is_error_enabled(void *handle);
LOG_EXPORT int  log_is_warn_enabled(void *handle);
LOG_EXPORT int  log_is_info_enabled(void *handle);
LOG_EXPORT int  log_is_trace_enabled(void *handle);
LOG_EXPORT int  log_is_debug_enabled(void *handle);
LOG_EXPORT int  log_is_debug1_enabled(void *handle);
LOG_EXPORT int  log_is_debug2_enabled(void *handle);
LOG_EXPORT int  log_is_debug3_enabled(void *handle);
LOG_EXPORT int  log_is_debug4_enabled(void *handle);

LOG_EXPORT const char *ilslog_build_version();

LOG_EXPORT int log_tolevel(const char *lvl);
LOG_EXPORT void log_reload_loggers();

LOG_EXPORT void log_load_properties(const char *prop_file, int default_level);
LOG_EXPORT void log_reload_properties(const char *prop_file);

#ifndef MAX_LOG_LEVEL
#  define MAX_LOG_LEVEL 10
#endif

#if MAX_LOG_LEVEL >= 1
#  define lfatal(logger,msg) if( log_is_fatal_enabled(logger) ) log_this(logger,LOG_FATAL,msg,__FILE__,__LINE__);
#else
#  define lfatal(logger,msg)
#endif
#if MAX_LOG_LEVEL >= 2
#  define lerror(logger,msg) if( log_is_error_enabled(logger) ) log_this(logger,LOG_ERROR,msg,__FILE__,__LINE__);
#else
#  define lerror(logger,msg)
#endif
#if MAX_LOG_LEVEL >= 3
#  define lwarn(logger,msg)  if( log_is_warn_enabled(logger) ) log_this(logger,LOG_WARN,msg,__FILE__,__LINE__);
#else
#  define lwarn(logger,msg)
#endif
#if MAX_LOG_LEVEL >= 4
#  define linfo(logger,msg)  if( log_is_info_enabled(logger) ) log_this(logger,LOG_INFO,msg,__FILE__,__LINE__);
#else
#  define linfo(logger,msg)
#endif
#if MAX_LOG_LEVEL >= 5
#  define ltrace(logger,msg) if( log_is_trace_enabled(logger) ) log_this(logger,LOG_TRACE,msg,__FILE__,__LINE__);
#else
#  define ltrace(logger,msg)
#endif
#if MAX_LOG_LEVEL >= 6
#  define ldebug(logger,msg) if( log_is_debug_enabled(logger) ) log_this(logger,LOG_DEBUG,msg,__FILE__,__LINE__);
#else
#  define ldebug(logger,msg)
#endif
#if MAX_LOG_LEVEL >= 7
#  define ldebug1(logger,msg) if( log_is_debug1_enabled(logger) ) log_this(logger,LOG_DEBUG1,msg,__FILE__,__LINE__);
#else
#  define ldebug1(logger,msg)
#endif
#if MAX_LOG_LEVEL >= 8
#  define ldebug2(logger,msg) if( log_is_debug2_enabled(logger) ) log_this(logger,LOG_DEBUG2,msg,__FILE__,__LINE__);
#else
#  define ldebug2(logger,msg)
#endif
#if MAX_LOG_LEVEL >= 9
#  define ldebug3(logger,msg) if( log_is_debug3_enabled(logger) ) log_this(logger,LOG_DEBUG3,msg,__FILE__,__LINE__);
#else
#  define ldebug3(logger,msg)
#endif
#if MAX_LOG_LEVEL >= 10
#  define ldebug4(logger,msg) if( log_is_debug4_enabled(logger) ) log_this(logger,LOG_DEBUG4,msg,__FILE__,__LINE__);
#else
#  define ldebug4(logger,msg)
#endif

#ifdef __cplusplus
}
#endif

#endif
