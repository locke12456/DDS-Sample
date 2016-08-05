//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/random.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_RANDOM_H_
#define ILS_UTIL_RANDOM_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT void random_init();

UTIL_EXPORT void *randomize(void *buffer, unsigned int length);

UTIL_EXPORT int random_int();
UTIL_EXPORT long long random_int64();
UTIL_EXPORT char *random_string(char *buffer, unsigned int size);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_RANDOMIZE_H_*/
