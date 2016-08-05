//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/rwlock.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_RWLOCK_H_
#define ILS_UTIL_RWLOCK_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int rwlock_create(void **handle);
UTIL_EXPORT int rwlock_create_ex(void **handle, int opt, const char *name);
UTIL_EXPORT int rwlock_delete(void *handle);
UTIL_EXPORT int _rwlock_writelock(void *handle, const char *file, int line);
#define rwlock_writelock(handle) _rwlock_writelock((handle),__FILE__,__LINE__)
UTIL_EXPORT int _rwlock_readlock(void *handle, const char *file, int line);
#define rwlock_readlock(handle) _rwlock_readlock((handle),__FILE__,__LINE__)
UTIL_EXPORT int rwlock_unlock(void *handle);
UTIL_EXPORT void *rwlock_instrument_handle();

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_RWLOCK_H_*/
