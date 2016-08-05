//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/internal/mutex.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_INTERNAL_MUTEX_H_
#define ILS_INTERNAL_MUTEX_H_

#include "ils/util/errors.h"
#include "ils/internal/config.h"
#include "ils/internal/platform.h"
#include "ils/internal/log.h"

#ifdef __cplusplus
extern "C" {
#endif

	
UTIL_EXPORT int mutex_create(void **handle);
UTIL_EXPORT int mutex_create_ex(void **handle, const char *name, int options);
UTIL_EXPORT int mutex_lock(void *handle);
UTIL_EXPORT int mutex_trylock(void *handle);
UTIL_EXPORT int mutex_unlock(void *handle);

#ifdef __cplusplus
}
#endif

#endif /*ILS_INTERNAL_MUTEX_H_*/
