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
#ifndef V_NETWORKING_H
#define V_NETWORKING_H

#include "kernelModuleI.h"
#include "v_participantQos.h"

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

/**
 * \brief The <code>v_networking</code> cast method.
 *
 * This method casts an object to a <code>v_networking</code> object.
 * Before the cast is performed, if compiled with the NDEBUG flag not set,
 * the type of the object is checked to be <code>v_networking</code> or
 * one of its subclasses.
 */
#define v_networking(o) (C_CAST(o,v_networking))

OS_API v_networking
v_networkingNew(
    v_kernel kernel,
    const c_char *name,
    const c_char *extStateName,
    v_serviceType serviceType,
    v_participantQos qos,
    c_bool enable);

OS_API void
v_networkingFree(
    v_networking nw);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
