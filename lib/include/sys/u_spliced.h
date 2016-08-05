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
#ifndef U_SPLICED_H
#define U_SPLICED_H

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

#define u_spliced(sd) ((u_spliced)(sd))

OS_API u_result
u_splicedNew(
    u_spliced *spliced,
    const os_char *uri);

OS_API u_result
u_splicedGarbageCollector(
    const u_spliced spliced);

OS_API u_result
u_splicedKernelManager(
    const u_spliced spliced);

OS_API u_result
u_splicedBuiltinResendManager(
    const u_spliced spliced);

OS_API u_result
u_splicedBuiltinCAndMCommandDispatcher(
   const u_spliced spliced);

OS_API u_result
u_splicedCAndMCommandDispatcherQuit(
   const u_spliced spliced);

OS_API u_result
u_splicedPrepareTermination(
   const u_spliced spliced);

OS_API v_leaseManager
u_splicedGetHeartbeatManager(
    u_spliced spliced,
    c_bool create);

OS_API u_result
u_splicedStartHeartbeat(
    const u_spliced spliced,
    u_time period,
    u_time renewal);

OS_API u_result
u_splicedStopHeartbeat(
   const u_spliced spliced);

OS_API void
u_splicedSetInProcess(
    c_bool flag);

OS_API u_bool
u_splicedInProcess(void);

OS_API u_result
u_splicedCleanupProcessInfo(
    const u_spliced spliced,
    os_procId procId);

/**
 * \brief Setup the durability client within spliced.
 *
 * This method will setup the durability client feature within spliced.
 *
 * Communication channel:
 * partitionRequest     - The partition to send requests in.
 * partitionDataGlobal  - The partition to expect 'global' data.
 * partitionDataPrivate - The partition to expect 'private' data.
 */
OS_API u_result
u_splicedDurabilityClientSetup(
    u_spliced spliced,
    const char* partitionRequest,
    const char* partitionDataGlobal,
    const char* partitionDataPrivate);

/**
 * \brief Durability client main thread loop.
 */
OS_API void*
u_splicedDurabilityClientMain(
    void *spliced);

/**
 * \brief Terminate request for the durability client main thread loop.
 *
 * It is possible that the thread still runs when this function returns.
 * The only guarantee is that the thread will terminate as quickly as
 * possible.
 */
OS_API u_result
u_splicedDurabilityClientTerminate(
    u_spliced spliced);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif /* U_SPLICED_H */
