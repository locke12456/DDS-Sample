//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/debug.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_DEBUG_H_
#define ILS_UTIL_DEBUG_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT void *debug_malloc(int i, const char *s,const char *file, int line);
UTIL_EXPORT void  debug_free(void *a, const char *s,const char *file, int line);

UTIL_EXPORT int debug_get_core_file_limits(char **msg);
UTIL_EXPORT int debug_enable_core_files();

UTIL_EXPORT int debug_get_max_open_files(char **msg);
UTIL_EXPORT int debug_get_max_threads(char **msg);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_DEBUG_H_*/
