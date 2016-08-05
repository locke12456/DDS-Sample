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
#ifndef V_HISTORICALDATAREQUEST_H
#define V_HISTORICALDATAREQUEST_H

/** \file kernel/include/v_historicalDataRequest.h
 *  \brief This file defines the interface
 *
 */

#include "v_kernel.h"

#if defined (__cplusplus)
extern "C" {
#endif

#define v_historicalDataRequest(o) (C_CAST(o,v_historicalDataRequest));

#include "os_if.h"

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif

OS_API v_historicalDataRequest
v_historicalDataRequestNew(
    v_kernel kernel,
    const c_char* filter,
    const c_char* params[],
    c_ulong nofParams,
    c_time minSourceTime,
    c_time maxSourceTime,
    v_resourcePolicyI *resourceLimits,
    c_time timeout);

OS_API c_bool
v_historicalDataRequestEquals(
    v_historicalDataRequest req1,
    v_historicalDataRequest req2);

OS_API c_bool
v_historicalDataRequestIsValid(
    v_historicalDataRequest request,
    v_reader reader);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
