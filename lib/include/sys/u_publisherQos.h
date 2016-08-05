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
#ifndef U_PUBLISHERQOS_H
#define U_PUBLISHERQOS_H

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

/** \brief This operation creates a Qos object.
 *
 * The Qos policy values are copied from the given template, if no template
 * is provided (i.e. NULL is passed as agrument) a Qos object with the default
 * values is created.
 * The Qos object including any containing referenced policy objects are allocated
 * on heap, it is the respocibility of the user to free any containing referenced
 * policy objects when overriding them by assignment of new policy objects.
 * The whole Qos object is freed by the following Free operation.
 */
OS_API u_publisherQos u_publisherQosNew (const u_publisherQos _template);

/** \brief This operation frees the emory resources claimed by the Qos object.
 *
 * The Qos policy resources including all contained referenced policy objects
 * are freed. Be aware that for this reason all contained policy objects MUST
 * be allocated on heap!
 */
OS_API void u_publisherQosFree (u_publisherQos _this);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
