/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2014 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */

#ifndef OS_COMMON_SIGNALHANDLERCALLBACK_H
#define OS_COMMON_SIGNALHANDLERCALLBACK_H

#include "os_mutex.h"

#if defined (__cplusplus)
extern "C" {
#endif

typedef struct os_signalHandlerExitRequestCallbackInfo_s os_signalHandlerExitRequestCallbackInfo;
struct os_signalHandlerExitRequestCallbackInfo_s {
    os_signalHandlerExitRequestCallbackInfo *next;
    os_signalHandlerExitRequestCallback callback;
    void * arg;
};

typedef struct os_signalHandlerExceptionCallbackInfo_s os_signalHandlerExceptionCallbackInfo;
struct os_signalHandlerExceptionCallbackInfo_s {
    os_signalHandlerExceptionCallbackInfo *next;
    os_signalHandlerExceptionCallback callback;
    void * arg;
};

typedef struct os_signalHandlerCallbackInfo_s os_signalHandlerCallbackInfo;
struct os_signalHandlerCallbackInfo_s {
    os_mutex exitRequestMtx;
    os_signalHandlerExitRequestCallbackInfo *exitRequestCallbackInfo;
    os_mutex exceptionMtx;
    os_signalHandlerExceptionCallbackInfo *exceptionCallbackInfo;
};

static os_result    os__signalHandlerCallbackInit(os_signalHandlerCallbackInfo *_this);
static void         os__signalHandlerCallbackDeinit(os_signalHandlerCallbackInfo *_this);

static unsigned int os__signalHandlerExitRequestCallbackInvoke(os_signalHandlerCallbackInfo *_this, os_callbackArg arg);
static void         os__signalHandlerExceptionCallbackInvoke(os_signalHandlerCallbackInfo *_this, os_callbackArg arg);

/* The implementation of the below static call must be provided by the platform-
 * specific implementation of the signalhandler. */
static os_signalHandlerCallbackInfo* os__signalHandlerGetCallbackInfo(void);

#if defined (__cplusplus)
}
#endif

#endif /* OS_COMMON_SIGNALHANDLERCALLBACK_H */
