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
#ifndef U_BUILTIN_H
#define U_BUILTIN_H

#include "vortex_os.h"
#include "c_typebase.h"
#include "v_kernel.h"
#include "u_types.h"
#include "u_writer.h"

#if defined (__cplusplus)
extern "C" {
#endif

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

/** \brief Create writer for builtin topic specified by v_infoId
 *
 * \param publisher  Publisher object created by service to act as factory
 *                   for creating builtin topic writers.
 * \param infoId     Identifier for builtin topic.
 * \return           Writer object on successful operation or NULL on error.
 */
OS_API u_writer
u_builtinWriterNew(
    const u_publisher publisher,
    v_infoId infoId);

/**
 * \brief Write fake heartbeat using the builtin heartbeat writer.
 *
 * \param _this      Builtin writer to use for writing the fake heartbeat.
 * \param systemId   System identifier of node to impersonate.
 * \param state      State flags to write new heartbeat with.
 * \return u_result  U_RESULT_* constant.
 */
OS_API u_result
u_builtinWriteFakeHeartbeat(
    u_writer _this,
    c_ulong systemId,
    v_state state);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif /* U_BUILTIN_H */
