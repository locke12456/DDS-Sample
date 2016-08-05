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
#include "os_if.h"

#ifdef OS_STREAMS_API
#undef OS_STREAMS_API
#endif

#if defined(OSPL_BUILD_STREAMSCCPP) || defined(OSPL_BUILD_STREAMSSACPP)
#define OS_STREAMS_API OS_API_EXPORT
#else
#define OS_STREAMS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */
