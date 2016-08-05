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
#ifndef V_TOPIC_IMPL_H
#define V_TOPIC_IMPL_H

#include "v_topic.h"
#include "v_topicAdapter.h"

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

/**
 * \brief The <code>v_topicImpl</code> cast methods.
 *
 * This method casts an object to a <code>v_topic</code> object.
 * Before the cast is performed, if the NDEBUG flag is not set,
 * the type of the object is checked to be <code>v_topicImpl</code> or
 * one of its subclasses.
 */

#define v_topicImpl(o) (C_CAST(o,v_topicImpl))

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif
