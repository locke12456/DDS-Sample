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

#ifndef ILS_INTERNAL_EVENT_H_
#define ILS_INTERNAL_EVENT_H_

#include "ils/util/errors.h"
#include "ils/internal/config.h"
#include "ils/internal/platform.h"

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int event_wait(void *handle, int timeout);

#ifdef __cplusplus
}
#endif

#endif /*ILS_INTERNAL_EVENT_H_*/
