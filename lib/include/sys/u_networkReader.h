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
#ifndef U_NETWORKREADER_H
#define U_NETWORKREADER_H

#include "u_types.h"
#include "u_reader.h"

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

#if defined (__cplusplus)
extern "C" {
#endif

#define u_networkReader(o) \
        ((u_networkReader)u_objectCheckType(u_object(o), U_NETWORKREADER))

OS_API u_networkReader
u_networkReaderNew(
    const u_subscriber s,
    const os_char *name,
    const u_readerQos qos,
    u_bool ignoreReliabilityQoS);
    
OS_API u_result        
u_networkReaderCreateQueue(
    const u_networkReader _this,
    os_uint32 queueSize,
    os_uint32 priority,
    u_bool reliable,
    u_bool P2P,
    u_time resolution,
    u_bool useAsDefault,
    os_uint32 *queueId, /* out */
    const os_char *name);
    
OS_API u_result        
u_networkReaderTrigger(
    const u_networkReader _this,
    os_uint32 queueId);
    
OS_API u_result        
u_networkReaderRemoteActivityDetected(
    const u_networkReader _this);
    
OS_API u_result        
u_networkReaderRemoteActivityLost(
    const u_networkReader _this);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
