//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/bool.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_BOOL_H_
#define ILS_UTIL_BOOL_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int bool_getbit(const void *data,unsigned int bit);
UTIL_EXPORT int bool_getbit_from_char(const unsigned char *data,unsigned int bit);
UTIL_EXPORT int bool_getbit_from_short(const unsigned short *data,unsigned int bit);
UTIL_EXPORT int bool_getbit_from_int(const unsigned int *data,unsigned int bit);
UTIL_EXPORT int bool_getbit_from_longlong(const unsigned long long *data,unsigned int bit);
UTIL_EXPORT void bool_setbit(void *data,unsigned int bit, int value);
UTIL_EXPORT void bool_setbit_from_char(unsigned char *source, unsigned int bit, int value);
UTIL_EXPORT void bool_setbit_from_short(unsigned short *source, unsigned int bit, int value);
UTIL_EXPORT void bool_setbit_from_int(unsigned int *source, unsigned int bit, int value);
UTIL_EXPORT void bool_setbit_from_longlong(unsigned long long *source, unsigned int bit, int value);
UTIL_EXPORT int bool_get(const char *str);
UTIL_EXPORT int bool_getbits(const void *source, unsigned int bit, int length);
UTIL_EXPORT int bool_setbits(void *source, unsigned int bit, int length, int value);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_BOOL_H_*/
