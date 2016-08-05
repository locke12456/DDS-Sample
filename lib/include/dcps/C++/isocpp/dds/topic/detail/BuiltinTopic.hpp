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
#ifndef OSPL_DDS_TOPIC_DETAIL_BUILTINTOPIC_HPP_
#define OSPL_DDS_TOPIC_DETAIL_BUILTINTOPIC_HPP_

/**
 * @file
 */

// Implementation

#include <org/opensplice/topic/BuiltinTopicImpl.hpp>
#include <dds/topic/TBuiltinTopic.hpp>

namespace dds
{
namespace topic
{
namespace detail
{

typedef dds::topic::TParticipantBuiltinTopicData<org::opensplice::topic::ParticipantBuiltinTopicDataImpl>
ParticipantBuiltinTopicData;

typedef dds::topic::TTopicBuiltinTopicData<org::opensplice::topic::TopicBuiltinTopicDataImpl>
TopicBuiltinTopicData;

typedef dds::topic::TPublicationBuiltinTopicData<org::opensplice::topic::PublicationBuiltinTopicDataImpl>
PublicationBuiltinTopicData;

typedef dds::topic::TSubscriptionBuiltinTopicData<org::opensplice::topic::SubscriptionBuiltinTopicDataImpl>
SubscriptionBuiltinTopicData;

typedef dds::topic::TCMParticipantBuiltinTopicData<org::opensplice::topic::CMParticipantBuiltinTopicDataImpl>
CMParticipantBuiltinTopicData;

typedef dds::topic::TCMPublisherBuiltinTopicData<org::opensplice::topic::CMPublisherBuiltinTopicDataImpl>
CMPublisherBuiltinTopicData;

typedef dds::topic::TCMSubscriberBuiltinTopicData<org::opensplice::topic::CMSubscriberBuiltinTopicDataImpl>
CMSubscriberBuiltinTopicData;

typedef dds::topic::TCMDataWriterBuiltinTopicData<org::opensplice::topic::CMDataWriterBuiltinTopicDataImpl>
CMDataWriterBuiltinTopicData;

typedef dds::topic::TCMDataReaderBuiltinTopicData<org::opensplice::topic::CMDataReaderBuiltinTopicDataImpl>
CMDataReaderBuiltinTopicData;

}
}
}


// End of implementation

#endif /* OSPL_DDS_TOPIC_DETAIL_BUILTINTOPIC_HPP_ */
