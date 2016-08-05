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
#ifndef U_RNR_H
#define U_RNR_H

#include "u_types.h"
#include "u_cfElement.h"
#include "cf_node.h"

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
 * \brief The <code>u_rnr</code> cast method.
 *
 * This method casts an object to a <code>u_rnr</code> object.
 * Since objects of the user layer are allocated on heap, no type checking
 * is performed.
 */
#define u_durability(o) ((u_durability)(o))

OS_API u_service
u_rnrNew (
    const os_char *uri,
    const u_domainId_t id,
    const os_int32 timeout, /* in seconds */
    const os_char *name,
    const u_participantQos qos,
    c_bool enable);

/* Note: This function is part of a temporary workaround used by R&R.
 * The function copies heap-configuration (cf_node from parser) to shm-configuration (v_cfNode).
 * This is needed so R&R can use a single operation to process configuration nodes, either from the config file (URI)
 * or a string (R&R config command).
 * Ideally in the future this will be replaced by memory-agnostic XML processing so that it doesn't make a difference
 * if the configuration is on heap or in shared memory.
 */
OS_API u_result
u_domainCopyConfiguration(
    cf_node cfgNode,
    u_participant participant,
    u_cfElement *element);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
