/*
*                         Vortex Lite
*
*   This software and documentation are Copyright 2006 to 2015 PrismTech
*   Limited and its licensees. All rights reserved. See file:
*
*                     $LITE_HOME/LICENSE
*
*   for full copyright notice and license terms.
*
*/


#ifndef LITE_TOPIC_BUILTIN_TOPIC_COPY_HPP_
#define LITE_TOPIC_BUILTIN_TOPIC_COPY_HPP_

namespace org
{
namespace opensplice
{
namespace topic
{
#if 0
u_bool
__ParticipantBuiltinTopicData__copyIn(
    c_base base,
    const dds::topic::ParticipantBuiltinTopicData *from,
    struct v_participantInfo *to);

u_bool
__TopicBuiltinTopicData__copyIn(
    c_base base,
    const dds::topic::TopicBuiltinTopicData *from,
    struct v_topicInfo *to);

u_bool
__PublicationBuiltinTopicData__copyIn(
    c_base base,
    const dds::topic::PublicationBuiltinTopicData *from,
    v_publicationInfo *to);

u_bool
__SubscriptionBuiltinTopicData__copyIn(
    c_base base,
    const dds::topic::SubscriptionBuiltinTopicData *from,
    struct v_subscriptionInfo *to);

u_bool
__CMParticipantBuiltinTopicData__copyIn(
    c_base base,
    const org::opensplice::topic::CMParticipantBuiltinTopicData *from,
    struct v_participantCMInfo *to);

u_bool
__CMPublisherBuiltinTopicData__copyIn(
    c_base base,
    const  org::opensplice::topic::CMPublisherBuiltinTopicData *from,
    struct v_publisherCMInfo  *to);

u_bool
__CMSubscriberBuiltinTopicData__copyIn(
    c_base base,
    const org::opensplice::topic::CMSubscriberBuiltinTopicData *from,
    struct v_subscriberCMInfo *to);

u_bool
__CMDataWriterBuiltinTopicData__copyIn(
    c_base base,
    const org::opensplice::topic::CMDataWriterBuiltinTopicData *from,
    struct v_dataWriterCMInfo *to);

u_bool
__CMDataReaderBuiltinTopicData__copyIn(
    c_base base,
    const org::opensplice::topic::CMDataReaderBuiltinTopicData *from,
    struct v_dataReaderCMInfo *to);

void
__ParticipantBuiltinTopicData__copyOut(
    const void *_from,
    void *_to);

void
__TopicBuiltinTopicData__copyOut(
    const void *_from,
    void *_to);

void
__PublicationBuiltinTopicData__copyOut(
    const void *_from,
    void *_to);

void
__SubscriptionBuiltinTopicData__copyOut(
    const void *_from,
    void *_to);

void
__CMParticipantBuiltinTopicData__copyOut(
    const void *_from,
    void *_to);

void
__CMPublisherBuiltinTopicData__copyOut(
    const void *_from,
    void *_to);

void
__CMSubscriberBuiltinTopicData__copyOut(
    const void *_from,
    void *_to);

void
__CMDataWriterBuiltinTopicData__copyOut(
    const void *_from,
    void *_to);

void
__CMDataReaderBuiltinTopicData__copyOut(
    const void *_from,
    void *_to);
#endif
}
}
}


#endif /* LITE_TOPIC_BUILTIN_TOPIC_COPY_HPP_ */
