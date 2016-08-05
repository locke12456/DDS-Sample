//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/time.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_TIME_H_
#define ILS_UTIL_TIME_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT long long time_now();
UTIL_EXPORT int time_now_in_sec();
UTIL_EXPORT void time_diff(char *buffer, int len, long long d1, long long d2);
UTIL_EXPORT void time_sprintf(char *buffer, const char *time_format, long long mstime);
UTIL_EXPORT void time_sprintf2(char *buffer, const char *time_format, long long mstime, int use_gmt);

UTIL_EXPORT int time_detailed(long long *current_time, long long *offset_from_gmt, int *in_dst, const char **timezone);
UTIL_EXPORT int time_set(long long msec);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_TIME_H_*/
