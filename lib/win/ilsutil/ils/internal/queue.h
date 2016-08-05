//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/internal/queue.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_INTERNAL_QUEUE_H_
#define ILS_INTERNAL_QUEUE_H_

#include "ils/util/errors.h"
#include "ils/internal/config.h"
#include "ils/internal/platform.h"

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int queue_create(void **handle);
UTIL_EXPORT int queue_create_ex(void **handle, int max_size, int options);

#ifdef __cplusplus
}
#endif

#endif /*ILS_INTERNAL_QUEUE_H_*/
