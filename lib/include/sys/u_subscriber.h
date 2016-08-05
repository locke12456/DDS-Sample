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
#ifndef U_SUBSCRIBER_H
#define U_SUBSCRIBER_H

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

#define u_subscriber(o) \
        ((u_subscriber)u_objectCheckType(u_object(o),U_SUBSCRIBER))

typedef c_bool (*u_subscriberAction)(u_dataReader reader, void *arg);

OS_API u_subscriber
u_subscriberNew (
    const u_participant _scope,
    const os_char *name,
    const u_subscriberQos qos,
    u_bool enable);

OS_API u_result
u_subscriberGetQos (
    const u_subscriber _this,
    u_subscriberQos *qos);

OS_API u_result
u_subscriberSetQos (
    const u_subscriber _this,
    const u_subscriberQos qos);

OS_API u_result
u_subscriberBeginAccess(
    const u_subscriber _this);

OS_API u_result
u_subscriberEndAccess(
    const u_subscriber _this);

OS_API u_dataReader
u_subscriberCreateDataReader (
    const u_subscriber _this,
    const os_char *name,
    const os_char *expression,
    const c_value params[],
    const u_readerQos qos,
    u_bool enable);

OS_API u_result
u_subscriberGetDataReaders (
    const u_subscriber _this,
    u_sampleMask mask,
    c_iter *readers);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
