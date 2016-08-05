//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/rlimits.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_RLIMIT_H_
#define ILS_UTIL_RLIMIT_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int rlimit_enable_core_files();
UTIL_EXPORT int rlimit_get_core_file_limits(int *soft_limit, int *hard_limit);
UTIL_EXPORT int rlimit_get_max_open_files(int *soft_limit, int *hard_limit);
UTIL_EXPORT int rlimit_get_max_threads(int *soft_limit, int *hard_limit);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_RLIMIT_H_*/
