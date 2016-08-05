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
#ifndef V_OBJECTLOAN_H
#define V_OBJECTLOAN_H

#include "v_kernel.h"

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

#define v_objectLoan(o) (C_CAST((o),v_objectLoan))

OS_API c_object
v_objectLoanInsert(
    v_objectLoan loan,
    c_object object);

OS_API void
v_objectLoanRelease(
    v_objectLoan loan);

#undef OS_API

#endif /* V_OBJECTLOAN_H */

