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
#ifndef U_DURABILITY_H
#define U_DURABILITY_H

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

/**
 * \brief The <code>u_durability</code> cast method.
 *
 * This method casts an object to a <code>u_durability</code> object.
 * Since objects of the user layer are allocated on heap, no type checking
 * is performed.
 */
#define u_durability(o) ((u_durability)(o))

OS_API u_service
u_durabilityNew (
    const os_char *uri,
    const u_domainId_t id,
    const os_int32 timeout, /* in seconds */
    const os_char *name,
    const u_participantQos qos,
    c_bool enable);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
