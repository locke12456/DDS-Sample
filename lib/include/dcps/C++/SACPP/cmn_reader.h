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
#ifndef CMN_READER_H
#define CMN_READER_H

#include "v_readerSample.h"
#include "c_base.h"

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

OS_API v_actionResult cmn_reader_action(
    c_object o,
    void *arg);

OS_API v_actionResult cmn_reader_nextInstanceAction(
    c_object o,
    void *arg);

/*
 * TODO: when OSPL-3588 is finished, remove this function and replace
 * the calls with cmn_reader_nextInstanceAction.
 */
OS_API v_actionResult cmn_reader_nextInstanceAction_OSPL3588(
    c_object o,
    void *arg);

#undef OS_API
#if defined (__cplusplus)
}
#endif

#endif /* CMN_READER_H */
