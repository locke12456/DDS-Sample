//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/strings.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_STRINGS_H_
#define ILS_UTIL_STRINGS_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT char *clone_string(const char *str, int len);
UTIL_EXPORT char *trim_string(const char *str);
UTIL_EXPORT void trim_string2(char *str);
UTIL_EXPORT void trim_string3(char *str, char find);
UTIL_EXPORT char *replace_string(char *str, char find, char replace);

UTIL_EXPORT char **clone_argv(const char **argv, int argc);
UTIL_EXPORT void free_argv(char **argv, int argc);

UTIL_EXPORT int str2num(const char *value);
UTIL_EXPORT char *str2upper(char *str);
UTIL_EXPORT char *str2lower(char *str);

UTIL_EXPORT int str_safelen(const char *str, int max_len);
UTIL_EXPORT int str_starts_with(const char *haystack, const char *needle);
UTIL_EXPORT int str_ends_with(const char *haystack, const char *needle);
UTIL_EXPORT char *str_strip(char *str, char find);

UTIL_EXPORT const char *format( const char *msg, ...);
UTIL_EXPORT const char *format_r( char *buffer, int len, const char *msg, ...);

typedef void (*stringsorter_fefunc)(const char *str, void *ptr, void *custom);

UTIL_EXPORT int  stringsorter_create(		void **sorter);
UTIL_EXPORT void stringsorter_delete(		void *sorter);
UTIL_EXPORT int  stringsorter_add(			void *sorter, const char *str, void *ptr);
UTIL_EXPORT int  stringsorter_add_btree(	void *sorter, void *btree);
UTIL_EXPORT void stringsorter_foreach(		void *sorter, stringsorter_fefunc func, void *custom);

#if defined(_WIN32)  || defined(_VXWORKS)
UTIL_EXPORT char *strptime(const char *buf, const char *fmt, struct tm *tm);
#endif

#if defined(_VXWORKS)
UTIL_EXPORT int strcasecmp(const char *s1, const char *s2);
UTIL_EXPORT int strncasecmp(const char *s1, const char *s2, size_t len);
UTIL_EXPORT long long strtoll(const char *s, char **e, int b);
#endif

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_STRINGS_H_*/
