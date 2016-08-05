//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/internal/rwlock.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_INTERNAL_RWLOCK_H_
#define ILS_INTERNAL_RWLOCK_H_

#include "ils/util/errors.h"
#include "ils/internal/config.h"
#include "ils/internal/platform.h"

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int rwlock_writelock(void *handle);
UTIL_EXPORT int rwlock_readlock(void *handle);

#ifdef __cplusplus
}
#endif

#endif /*ILS_INTERNAL_RWLOCK_H_*/
