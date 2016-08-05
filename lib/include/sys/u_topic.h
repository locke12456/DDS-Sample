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
#ifndef U_TOPIC_H
#define U_TOPIC_H

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

#define u_topic(o) \
        ((u_topic)u_objectCheckType(u_object(o), U_TOPIC))

OS_API u_topic
u_topicNew (
    const u_participant p,
    const os_char *name,
    const os_char *typeName,
    const os_char *keyList,
    u_topicQos qos);

OS_API u_result
u_topicGetQos (
    const u_topic _this,
    u_topicQos *qos);

OS_API u_topic
u_topicNewFromTopicInfo(
    u_participant p,
    const struct v_topicInfo *info,
    c_bool announce);

OS_API u_result
u_topicSetQos (
    const u_topic _this,
    const u_topicQos qos);

OS_API os_char *
u_topicName (
    const u_topic _this);

OS_API os_char *
u_topicTypeName (
    const u_topic _this);

OS_API os_char *
u_topicKeyExpr(
    const u_topic _this);

OS_API os_char *
u_topicMetaDescriptor (
    const u_topic _this);

OS_API u_result
u_topicGetInconsistentTopicStatus (
    const u_topic _this,
    u_bool reset,
    u_statusAction action,
    void *arg);

OS_API u_result
u_topicGetAllDataDisposedStatus (
    const u_topic _this,
    u_bool reset,
    u_statusAction action,
    void *arg);

OS_API u_result
u_topicDisposeAllData (
    const u_topic _this);

OS_API u_bool
u_topicContentFilterValidate (
    const u_topic _this,
    const q_expr expr,
    const c_value params[]);

OS_API u_bool
u_topicContentFilterValidate2 (
    const u_topic _this,
    const q_expr expr,
    const c_value params[]);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
