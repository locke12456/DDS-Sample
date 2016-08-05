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


#ifndef ORG_OPENSPLICE_TOPIC_BUILTIN_TOPIC_HPP_
#define ORG_OPENSPLICE_TOPIC_BUILTIN_TOPIC_HPP_


#include <org/opensplice/topic/TBuiltinTopic.hpp>


namespace org
{
namespace opensplice
{
namespace topic
{

typedef TCMParticipantBuiltinTopicData<CMParticipantBuiltinTopicDataDelegate>
CMParticipantBuiltinTopicData;

typedef TCMPublisherBuiltinTopicData<CMPublisherBuiltinTopicDataDelegate>
CMPublisherBuiltinTopicData;

typedef TCMSubscriberBuiltinTopicData<CMSubscriberBuiltinTopicDataDelegate>
CMSubscriberBuiltinTopicData;

typedef TCMDataWriterBuiltinTopicData<CMDataWriterBuiltinTopicDataDelegate>
CMDataWriterBuiltinTopicData;

typedef TCMDataReaderBuiltinTopicData<CMDataReaderBuiltinTopicDataDelegate>
CMDataReaderBuiltinTopicData;

typedef TTypeBuiltinTopicData<TypeBuiltinTopicDataDelegate>
TypeBuiltinTopicData;

}
}
}


#endif /* ORG_OPENSPLICE_TOPIC_BUILTIN_TOPIC_HPP_ */
