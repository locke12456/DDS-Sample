//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/internal/btree.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_INTERNAL_BTREE_H_
#define ILS_INTERNAL_BTREE_H_

#include "ils/util/errors.h"
#include "ils/internal/config.h"
#include "ils/internal/platform.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*btree_free)(void *);
typedef long long (*btree_hash)(const void *);

UTIL_EXPORT int btree_create_ex(void **handle, btree_hash hash_func, btree_free free_func, int options);
UTIL_EXPORT int btree_create(void **handle, btree_hash hash_func, btree_free free_func);

#ifdef __cplusplus
}
#endif

#endif /*ILS_INTERNAL_BTREE_H_*/
