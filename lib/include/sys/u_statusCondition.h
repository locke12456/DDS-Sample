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
#ifndef U_STATUSCONDITION_H
#define U_STATUSCONDITION_H

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

#define u_statusCondition(o) \
        ((u_statusCondition)u_objectCheckType(u_object(o), U_STATUSCONDITION))

OS_API u_statusCondition
u_statusConditionNew(
    const u_entity entity);

OS_API u_result
u_statusCondition_set_mask(
    const u_statusCondition _this,
    u_eventMask eventMask);

OS_API u_result
u_statusCondition_get_triggerValue (
    const u_statusCondition _this,
    u_eventMask *triggerValue);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
