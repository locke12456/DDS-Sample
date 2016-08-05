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
#ifndef OMG_DDS_PUB_DETAIL_TANYDATAWRITER_HPP_
#define OMG_DDS_PUB_DETAIL_TANYDATAWRITER_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/pub/TAnyDataWriter.hpp>

// Implementation

namespace dds
{
namespace pub
{

template <typename DELEGATE>
TAnyDataWriter<DELEGATE>::~TAnyDataWriter()
{
}

template <typename DELEGATE>
const dds::pub::Publisher&
TAnyDataWriter<DELEGATE>::publisher() const
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->publisher();
}

template <typename DELEGATE>
const dds::topic::TopicDescription&
TAnyDataWriter<DELEGATE>::topic_description() const
{
    ISOCPP_REPORT_STACK_BEGIN();

    return this->delegate()->topic_description();
}

template <typename DELEGATE>
dds::pub::qos::DataWriterQos
TAnyDataWriter<DELEGATE>::qos() const
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->qos();
}

template <typename DELEGATE>
void
TAnyDataWriter<DELEGATE>::qos(const dds::pub::qos::DataWriterQos& qos)
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->qos(qos);
}

template <typename DELEGATE>
TAnyDataWriter<DELEGATE>&
TAnyDataWriter<DELEGATE>::operator << (const dds::pub::qos::DataWriterQos& qos)
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->qos(qos);
    return *this;
}

template <typename DELEGATE>
const TAnyDataWriter<DELEGATE>&
TAnyDataWriter<DELEGATE>::operator >> (dds::pub::qos::DataWriterQos& qos) const
{
    ISOCPP_REPORT_STACK_BEGIN();
    qos = this->delegate()->qos();
    return *this;
}

template <typename DELEGATE>
void
TAnyDataWriter<DELEGATE>::wait_for_acknowledgments(const dds::core::Duration& timeout)
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->wait_for_acknowledgments(timeout);
}

template <typename DELEGATE>
const dds::core::status::LivelinessLostStatus
TAnyDataWriter<DELEGATE>::liveliness_lost_status()
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->liveliness_lost_status();
}

template <typename DELEGATE>
const dds::core::status::OfferedDeadlineMissedStatus
TAnyDataWriter<DELEGATE>::offered_deadline_missed_status()
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->offered_deadline_missed_status();
}

template <typename DELEGATE>
const dds::core::status::OfferedIncompatibleQosStatus
TAnyDataWriter<DELEGATE>::offered_incompatible_qos_status()
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->offered_incompatible_qos_status();
}

template <typename DELEGATE>
const dds::core::status::PublicationMatchedStatus
TAnyDataWriter<DELEGATE>::publication_matched_status()
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->publication_matched_status();
}

template <typename DELEGATE>
void
TAnyDataWriter<DELEGATE>::assert_liveliness()
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->assert_liveliness();
}

}
}
// End of implementation

#endif /* OMG_DDS_PUB_DETAIL_TANYDATAWRITER_HPP_ */
