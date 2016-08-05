//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/internal/memory.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_INTERNAL_MEMORY_H_
#define ILS_INTERNAL_MEMORY_H_

#include "ils/util/errors.h"
#include "ils/internal/config.h"
#include "ils/internal/platform.h"
#include "ils/internal/log.h"

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT void  ilsFree(void *ptr);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_MEMORY_H_*/
