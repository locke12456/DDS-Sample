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
#ifndef U_GROUPQUEUE_H
#define U_GROUPQUEUE_H

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

#define u_groupQueue(o) \
        ((u_groupQueue)u_objectCheckType(u_object(o), U_GROUPQUEUE))

OS_API u_groupQueue
u_groupQueueNew (
    const u_subscriber s,
    const c_char *name,
    c_ulong queueSize,
    const u_readerQos qos,
    c_iter expr);
                                             
#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif /*U_GROUPQUEUE_H*/
