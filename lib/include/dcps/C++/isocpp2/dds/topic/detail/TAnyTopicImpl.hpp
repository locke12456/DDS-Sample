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
#ifndef OSPL_DDS_TOPIC_TANYTOPIC_IMPL_HPP_
#define OSPL_DDS_TOPIC_TANYTOPIC_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/topic/TAnyTopic.hpp>

// Implementation
namespace dds
{
namespace topic
{


template <typename DELEGATE>
TAnyTopic<DELEGATE>::~TAnyTopic()
{
}

template <typename DELEGATE>
dds::topic::qos::TopicQos
TAnyTopic<DELEGATE>::qos() const
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->qos();
}

template <typename DELEGATE>
void
TAnyTopic<DELEGATE>::qos(const dds::topic::qos::TopicQos& qos)
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->qos(qos);
}

template <typename DELEGATE>
TAnyTopic<DELEGATE>&
TAnyTopic<DELEGATE>::operator << (const dds::topic::qos::TopicQos& qos)
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->qos(qos);
    return *this;
}

template <typename DELEGATE>
const TAnyTopic<DELEGATE>&
TAnyTopic<DELEGATE>::operator >> (dds::topic::qos::TopicQos& qos) const
{
    ISOCPP_REPORT_STACK_BEGIN();
    qos = this->delegate()->qos();
    return *this;
}

template <typename DELEGATE>
dds::core::status::InconsistentTopicStatus
TAnyTopic<DELEGATE>::inconsistent_topic_status() const
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->inconsistent_topic_status();
}


}
}

// End of implementation

#endif /* OSPL_DDS_TOPIC_TANYTOPIC_IMPL_HPP_ */
