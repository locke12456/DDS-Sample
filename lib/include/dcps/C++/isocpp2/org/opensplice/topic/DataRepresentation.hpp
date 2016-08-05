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
#ifndef ORG_OPENSPLICE_TOPIC_DATA_REPRESENTATION_HPP
#define ORG_OPENSPLICE_TOPIC_DATA_REPRESENTATION_HPP

namespace org { namespace opensplice { namespace topic {

typedef int16_t DataRepresentationId_t;

const DataRepresentationId_t XCDR_REPRESENTATION  = 0;
const DataRepresentationId_t XML_REPRESENTATION   = 0x001;
const DataRepresentationId_t OSPL_REPRESENTATION  = 0x400;
const DataRepresentationId_t GPB_REPRESENTATION   = 0x401;
const DataRepresentationId_t INVALID_REPRESENTATION = 0x7FFF;

}}}

#endif /* ORG_OPENSPLICE_TOPIC_DATA_REPRESENTATION_HPP */
