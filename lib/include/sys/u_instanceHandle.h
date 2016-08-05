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
#ifndef U_INSTANCEHANDLE_H
#define U_INSTANCEHANDLE_H


#if defined (__cplusplus)
extern "C" {
#endif

#include "v_public.h"

typedef c_longlong u_instanceHandle;

#define U_INSTANCEHANDLE_NIL (0)

#include "u_user.h"

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

OS_API u_bool
u_instanceHandleIsNil (
    u_instanceHandle _this);

OS_API u_bool
u_instanceHandleIsEqual (
    u_instanceHandle h1,
    u_instanceHandle h2);

/**
 * Following methods should preferably be made private.
 * For now they should only be used in action routines that operate in kernel context.
 */
OS_API u_instanceHandle
u_instanceHandleFromGID (
    v_gid gid);

OS_API u_instanceHandle
u_instanceHandleNew(
    v_public object);


#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
