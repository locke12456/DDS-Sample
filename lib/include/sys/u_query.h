/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2015 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */
#ifndef U_QUERY_H
#define U_QUERY_H

#include "u_types.h"
#include "u_reader.h"

#if defined (__cplusplus)
extern "C" {
#endif

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

#define u_query(o) ((u_query)(o))

typedef u_bool (u_queryAction)(c_object o, void *arg);

OS_API u_query
u_queryNew(
    const u_reader reader,
    const os_char *name,
    const os_char *predicate,
    const os_char *params[],
    const os_uint32 nrOfParams,
    const u_sampleMask sampleMask);

OS_API u_result
u_queryRead(
    const u_query _this,
    u_readerAction action,
    void *actionArg);

OS_API u_result
u_queryTake(
    const u_query _this,
    u_readerAction action,
    void *actionArg);

OS_API u_result
u_queryReadInstance(
    const u_query _this,
    u_instanceHandle h,
    u_readerAction action,
    void *actionArg);

OS_API u_result
u_queryTakeInstance(
    const u_query _this,
    u_instanceHandle h,
    u_readerAction action,
    void *actionArg);

OS_API u_result
u_queryReadNextInstance(
    const u_query _this,
    u_instanceHandle h,
    u_readerAction action,
    void *actionArg);

OS_API u_result
u_queryTakeNextInstance(
    const u_query _this,
    u_instanceHandle h,
    u_readerAction action,
    void *actionArg);

OS_API u_bool
u_queryTest(
    const u_query _this,
    u_queryAction action,
    void *args);

OS_API u_result
u_querySet(
    const u_query _this,
    const os_char *params[],
    const os_uint32 nrOfParams);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif

