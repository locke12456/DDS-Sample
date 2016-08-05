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
#ifndef U_PARTITION_H
#define U_PARTITION_H

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

#define u_partition(o) \
        ((u_partition)u_objectCheckType(u_object(o), U_PARTITION))

/* A u_partition object is a user proxy to the kernel partition object.
 * The constructor will lookup or else create a kernel partition object and
 * create a u_partition object as user proxy.
 */
OS_API u_partition
u_partitionNew (
    u_participant p,
    const os_char *name,
    u_partitionQos qos);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
