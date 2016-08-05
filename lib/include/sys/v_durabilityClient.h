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

#ifndef V_DURABILITY_CLIENT_H
#define V_DURABILITY_CLIENT_H

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

#define v_durabilityClient(o) (C_CAST(o, v_durabilityClient))

#if 0
#define V_DC_TRACE  printf("V_DC<%d> : ", os_procIdSelf()); printf
#else
#define V_DC_TRACE(...)
#endif


/**
 * \brief Load the durability client types.
 *
 * The types are loaded separately from the client creation.
 * This is done because it isn't sure that the client will be created
 * at all. That depends on configuration. The types, however, have to
 * be loaded anyway because it is possible that the durability service
 * needs them.
 */
OS_API void
v_durabilityClientLoadTypes(
    v_spliced spliced);

/**
 * \brief Create a new durability client as part of spliced.
 *
 * Communication channel:
 * partitionRequest     - The partition to send requests in.
 * partitionDataGlobal  - The partition to expect 'global' data.
 * partitionDataPrivate - The partition to expect 'private' data.
 */
OS_API v_durabilityClient
v_durabilityClientNew(
    v_spliced spliced,
    const char* partitionRequest,
    const char* partitionDataGlobal,
    const char* partitionDataPrivate);

/**
 * \brief Durability client main thread loop.
 */
OS_API void
v_durabilityClientMain(
    v_durabilityClient _this);

/**
 * \brief Terminate request for the durability client main thread loop.
 *
 * It is possible that the thread still runs when this function returns.
 * The only guarantee is that the thread will terminate as quickly as
 * possible.
 */
OS_API void
v_durabilityClientTerminate(
    v_durabilityClient _this);

/* TODO: Change function name and add comment header. */
OS_API c_bool
v_dcSendMsgDataRequest(
    v_durabilityClient _this,
    v_handle rhandle,
    c_iter partitions,
    c_char *topic,
    c_char *filter,
    c_iter params,
    c_time minSourceTime,
    c_time maxSourceTime,
    c_long max_samples,
    c_long max_instances,
    c_long max_samples_per_instance,
    c_iter alignmentPartition,
    c_time timeout);

OS_API c_bool
v_durabilityClientIsResponsibleForAlignment(
    v_durabilityClient _this);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
