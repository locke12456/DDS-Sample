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
#ifndef V_TYPEREPRESENTATION_H_
#define V_TYPEREPRESENTATION_H_

#include "kernelModule.h"

/**
 * \brief The <code>v_typeRepresentation</code> cast method.
 *
 * This method casts an object to a <code>v_typeRepresentation</code> object.
 * Before the cast is performed, if compiled with the NDEBUG flag not set,
 * the type of the object is checked to be <code>v_typeRepresentation</code> or
 * one of its subclasses.
 */
#define v_typeRepresentation(o) (C_CAST(o,v_typeRepresentation))

v_typeRepresentation
v_typeRepresentationNew(
    v_participant participant,
    const os_char *typeName,
    v_dataRepresentationId_t dataRepresentationId,
    const v_typeHash typeHash,
    const os_uchar *metaData,
    os_uint32 metaDataLength,
    const os_uchar *extentions,
    os_uint32 extentionsLength);

#endif /* V_TYPEREPRESENTATION_H_ */
