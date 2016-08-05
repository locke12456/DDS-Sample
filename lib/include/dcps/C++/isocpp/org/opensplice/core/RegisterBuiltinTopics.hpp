
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


/**
 * @file
 */

#ifndef ORG_OPENSPLICE_CORE_REGISTER_BUILTIN_TOPICS_HPP_
#define ORG_OPENSPLICE_CORE_REGISTER_BUILTIN_TOPICS_HPP_

#include <dds/dds.hpp>
#include <org/opensplice/topic/TopicTraits.hpp>

REGISTER_TOPIC_TRAITS(::DDS::ParticipantBuiltinTopicData)

REGISTER_TOPIC_TRAITS(::DDS::TopicBuiltinTopicData)

REGISTER_TOPIC_TRAITS(::DDS::PublicationBuiltinTopicData)

REGISTER_TOPIC_TRAITS(::DDS::SubscriptionBuiltinTopicData)

REGISTER_TOPIC_TRAITS(::DDS::CMParticipantBuiltinTopicData)

REGISTER_TOPIC_TRAITS(::DDS::CMPublisherBuiltinTopicData)

REGISTER_TOPIC_TRAITS(::DDS::CMSubscriberBuiltinTopicData)

REGISTER_TOPIC_TRAITS(::DDS::CMDataWriterBuiltinTopicData)

REGISTER_TOPIC_TRAITS(::DDS::CMDataReaderBuiltinTopicData)

#endif /* ORG_OPENSPLICE_CORE_REGISTER_BUILTIN_TOPICS_HPP_ */

