//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/mutex.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_MUTEX_H_
#define ILS_UTIL_MUTEX_H_

#ifdef __cplusplus
extern "C" {
#endif

#define MUTEX_OPT_DEBUG		2
#define MUTEX_OPT_NOINSTRUMENT 4

UTIL_EXPORT int _mutex_create_ex(void **handle, const char *name, int options, const char *file, int line);
UTIL_EXPORT int _mutex_lock(void *handle, const char *file, int line);
UTIL_EXPORT int _mutex_trylock(void *handle,const char *file, int line);
UTIL_EXPORT int _mutex_unlock(void *handle, const char *file, int line);

#define mutex_create(handle) _mutex_create_ex((handle), NULL, 0, __FILE__, __LINE__)
#define mutex_create_ex(handle,name,options) _mutex_create_ex((handle), (name), (options),  __FILE__, __LINE__)
#define mutex_lock(handle) _mutex_lock((handle), __FILE__, __LINE__)
#define mutex_trylock(handle) _mutex_trylock((handle), __FILE__, __LINE__)
#define mutex_unlock(handle) _mutex_unlock((handle), __FILE__, __LINE__)

UTIL_EXPORT int mutex_delete(void *handle);
UTIL_EXPORT int mutex_error(void *handle);
UTIL_EXPORT void *mutex_instrument_handle();

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_MUTEX_H_*/
