/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2011 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE 
 *
 *   for full copyright notice and license terms. 
 *
 */
#ifndef V_LISTENER_H
#define V_LISTENER_H

#if defined (__cplusplus)
extern "C" {
#endif

/**
 * \class v_listener
 *
 * The listener extends the <code>v_observer</code> class and can be used to wait
 * on events. While waiting for events, every event is administrated
 */

/**
 * \brief The <code>v_listener</code> cast method.
 *
 * This method casts a kernel object to a <code>v_listener</code> object.
 * Before the cast is performed, the type of the object is checked to
 * be <code>v_listener</code> or one of its subclasses.
 */
#define v_listener(o)   (C_CAST(o,v_listener))

#include "v_participant.h"
#include "v_event.h"
#include "os_if.h"

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

/**
 * The definition of the action callback method, which is called when
 * one or more events are received.
 *
 * \param e   a received event.
 * \param arg a pointer to user data needed to perform the action.
 */
typedef void (*v_listenerAction)(v_listenerEvent e, c_voidp arg);

/**
 * Creates a new listener.
 *
 * \param kernel a reference to the kernel
 * \return       the reference to the newly created listener.
 */
OS_API v_listener
v_listenerNew(
    v_participant p);

/**
 * Destroys the referenced listener.
 *
 * \param _this a reference to the listener object.
 */
OS_API void
v_listenerFree(
    v_listener _this);

/**
 * Wait until at least one event is received or the specified timeout has
 * elapsed.
 * The caller is blocked until at least one event is received or the specified
 * timeout ('time') parameter has elapsed. At receiving event(s) the given
 * action routine is called for each received event. The given 'arg' parameter
 * is passed-through as-is. On timeout the action routine is not called.
 *
 * \param _this  a reference to the listener object.
 * \param action reference to the action callback method.
 * \param arg    reference to data passed on to the action method.
 * \param time   the maximum time to wait until an event is received.
 */
OS_API v_result
v_listenerWait(
    v_listener _this,
    v_listenerAction action,
    c_voidp arg,
    const c_time time);

/**
 * Wake-up the thread(s) waiting on the listener.
 * The event returned to the waiting thread is V_EVENT_TRIGGER.
 *
 * \param _this    a reference to the listener object.
 */
OS_API void
v_listenerTrigger(
    v_listener _this);

/**
 * Notifies the listener on a state change of one of the conditions.
 * Every event the listener receives is stored in a list. The events
 * are grouped on the origin of the event.
 *
 * \param _this    a reference to the listener object.
 * \param e        a reference to the event describing the reason of the
 *                 notification.
 * \param userData data that has to be forwarded with the given event.
 */
OS_API void
v_listenerNotify(
    v_listener _this,
    v_event e,
    c_voidp userData);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
