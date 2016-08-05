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
#ifndef V_TIME_H
#define V_TIME_H

#include "v_kernel.h"

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

#define V_TIME_MAX_NANOSECONDS (1000000000)

#define v_timeIsZero(t) (c_timeCompare((t),C_TIME_ZERO) == C_EQ)
#define v_timeIsInfinite(t) (c_timeCompare((t),C_TIME_INFINITE) == C_EQ)

/** Get the current time.
 *
 *  @see os_timeGet()
 */
OS_API c_time
v_timeGet(
    void);

/** Get the current (monotonic) time.
 *
 *  @see os_timeGetMonotonic()
 */
OS_API c_time
v_timeGetMonotonic(
    void);

/** Get the current (elapsed) time.
 *
 *  @see os_timeGetElapsed()
 */
OS_API c_time
v_timeGetElapsed(
    void);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
