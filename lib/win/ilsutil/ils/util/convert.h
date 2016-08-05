//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/convert.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_CONVERT_H_
#define ILS_UTIL_CONVERT_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int convert_to_c(char *value, const char *str, char **endptr, int base);
UTIL_EXPORT int convert_to_uc(unsigned char *value, const char *str, char **endptr, int base);

UTIL_EXPORT int convert_to_s(short *value, const char *str, char **endptr, int base);
UTIL_EXPORT int convert_to_us(unsigned short *value, const char *str, char **endptr, int base);

UTIL_EXPORT int convert_to_i(int *value, const char *str, char **endptr, int base);
UTIL_EXPORT int convert_to_ui(unsigned int *value, const char *str, char **endptr, int base);

UTIL_EXPORT int convert_to_ll(long long *value, const char *str, char **endptr, int base);
UTIL_EXPORT int convert_to_ull(unsigned long long *value, const char *str, char **endptr, int base);

UTIL_EXPORT int convert_to_f(float *value, const char *str, char **endptr);

UTIL_EXPORT int convert_to_d(double *value, const char *str, char **endptr);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_CONVERT_H_*/
