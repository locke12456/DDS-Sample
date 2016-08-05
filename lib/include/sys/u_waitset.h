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
#ifndef U_WAITSET_H
#define U_WAITSET_H

#include "u_types.h"

#if defined (__cplusplus)
extern "C" {
#endif

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

#define u_waitset(o) \
        ((u_waitset)u_objectCheckType(u_object(o), U_WAITSET))

typedef void (*u_waitsetAction)(u_waitsetEvent e, void *arg);
typedef os_boolean (*u_waitsetAction2)(void *context, void *arg);

OS_API u_waitset
u_waitsetNew(void);

OS_API u_waitset
u_waitsetNew2(void);

OS_API void
u_waitsetAnnounceDestruction(
    const u_waitset _this);

OS_API u_result
u_waitsetWaitAction(
    const u_waitset _this,
    u_waitsetAction action,
    void *arg,
    const u_time timeout);

OS_API u_result
u_waitsetWaitAction2(
    const u_waitset _this,
    u_waitsetAction2 action,
    void *arg,
    const u_time timeout);

OS_API u_result
u_waitsetNotify(
    const u_waitset _this,
    void *eventArg);

OS_API u_result
u_waitsetTrigger(
    const u_waitset _this);

OS_API u_result
u_waitsetAttach(
    const u_waitset _this,
    const u_observable observable,
    void *context);

OS_API void
u_waitsetDetach(
    const u_waitset _this,
    const u_observable observable);

OS_API u_result
u_waitsetDetach_s(
    const u_waitset _this,
    const u_observable observable);

OS_API u_result
u_waitsetGetEventMask(
    const u_waitset _this,
    u_eventMask *eventMask);

OS_API u_result
u_waitsetSetEventMask(
    const u_waitset _this,
    u_eventMask eventMask);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
