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
#ifndef U_DISPATCHER_H
#define U_DISPATCHER_H

#include "u_types.h"

#if defined (__cplusplus)
extern "C" {
#endif
#include "os_if.h"

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

/* Returns mask of events that have been handled by the listener. */
typedef u_eventMask (*u_dispatcherListener)(u_dispatcher o, u_eventMask event, void *usrData);
typedef void (*u_dispatcherThreadAction)(u_dispatcher o, void *usrData);

#define  u_dispatcher(o) ((u_dispatcher)(o))

OS_API u_result
u_dispatcherInsertListener(
    const u_dispatcher o,
    const u_observableListener l,
    void *userData);

OS_API u_result
u_dispatcherAppendListener(
    const u_dispatcher o,
    const u_observableListener l,
    void *userData);

OS_API u_result
u_dispatcherRemoveListener(
     const u_dispatcher o,
     const u_observableListener l);

OS_API u_result
u_dispatcherNotify(
    const u_dispatcher o);

OS_API u_result
u_dispatcherSetEventMask(
    const u_dispatcher o,
    u_eventMask eventMask);

OS_API u_result
u_dispatcherGetEventMask(
    const u_dispatcher o,
    u_eventMask *eventMask);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif

