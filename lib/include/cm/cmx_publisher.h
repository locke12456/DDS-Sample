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
/**@file api/cm/xml/include/cmx_publisher.h
 *
 * Represents a publisher in Splice in XML format.
 */
#ifndef CMX_PUBLISHER_H
#define CMX_PUBLISHER_H

#include "c_typebase.h"

#if defined (__cplusplus)
extern "C" {
#endif
#include "os_if.h"

#ifdef OSPL_BUILD_CMXML
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

/**
 * Creates a new publisher. It is creates by creating its user layer
 * counterpart and serializing it into XML format.
 *
 * An XML publisher looks like:
   @verbatim
   <entity>
       <pointer>...</pointer>
       <handle_index>...</handle_index>
       <handle_serial>..</handle_serial>
       <name>...</name>
       <kind>PUBLISHER</kind>
       <enabled>...</enabled>
   </entity>
   @endverbatim
 * @param participant The XML representation of the participant to attach the
 *                    publisher to.
 * @param name The name for the publisher.
 * @param qos The qos for the publisher. If NULL is supplied, the default is
 *            taken.
 * @return The XML representation of the created publisher or NULL if it could
 *         not be created.
 */
OS_API c_char*     cmx_publisherNew        (const c_char* participant,
                                            const c_char* name,
                                            const c_char* qos);


OS_API const c_char* cmx_publisherCoherentBegin (const c_char* publisher);

OS_API const c_char* cmx_publisherCoherentEnd   (const c_char* publisher);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif /* CMX_PUBLISHER*/
