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
#ifndef U_GROUP_H
#define U_GROUP_H

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

#define u_group(o) \
        ((u_group)u_objectCheckType(u_object(o), U_GROUP))

OS_API u_group
u_groupNew(
    const u_participant participant,
    const os_char *partitionName,
    const os_char *topicName,
    u_time timeout);

OS_API u_result
u_groupSetRoutingEnabled(
    u_group group,
    c_bool routingEnabled,
    c_bool *oldRoutingEnabled);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif /* U_GROUP_H */
