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
#ifndef V_COPYIN_H
#define V_COPYIN_H

#include "c_typebase.h"

#if defined (__cplusplus)
extern "C" {
#endif

typedef os_uchar v_copyin_result;

#define V_COPYIN_RESULT_INVALID              0
#define V_COPYIN_RESULT_OK                   1
#define V_COPYIN_RESULT_OUT_OF_MEMORY        2

#define V_COPYIN_RESULT_IS_OK(x)             ((x) == V_COPYIN_RESULT_OK)
#define V_COPYIN_RESULT_IS_INVALID(x)        ((x) == V_COPYIN_RESULT_INVALID)
#define V_COPYIN_RESULT_IS_OUT_OF_MEMORY(x)  ((x) == V_COPYIN_RESULT_OUT_OF_MEMORY)

#define V_COPYIN_RESULT_TO_RESULT(r) \
    (V_COPYIN_RESULT_IS_OK(r) ? V_RESULT_OK : V_COPYIN_RESULT_IS_INVALID(r) ? V_RESULT_ILL_PARAM : V_RESULT_OUT_OF_MEMORY)


#if defined (__cplusplus)
}
#endif

#endif /* V_COPYIN_H */
