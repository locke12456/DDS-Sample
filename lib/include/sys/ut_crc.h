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
#ifndef UT_CRC_H
#define UT_CRC_H

#include "os_defs.h"
#include "os_classbase.h"


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

OS_API os_uint32 ut_crcCalculate (const void *buf, os_size_t length) __nonnull_all__
                                                                     __attribute_pure__;

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif /* UT_CRC_H */
