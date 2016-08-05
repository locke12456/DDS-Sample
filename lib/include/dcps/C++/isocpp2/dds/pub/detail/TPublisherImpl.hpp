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
#ifndef OSPL_DDS_PUB_TPUBLISHER_IMPL_HPP_
#define OSPL_DDS_PUB_TPUBLISHER_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/pub/TPublisher.hpp>
#include <org/opensplice/core/ReportUtils.hpp>

// Implementation

namespace dds
{
namespace pub
{

template <typename DELEGATE>
TPublisher<DELEGATE>::TPublisher(const dds::domain::DomainParticipant& dp)
    :   ::dds::core::Reference<DELEGATE>(new DELEGATE(dp,
                                                      dp.default_publisher_qos(),
                                                      NULL,
                                                      dds::core::status::StatusMask::none()))
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->init(this->impl_);
}

template <typename DELEGATE>
TPublisher<DELEGATE>::TPublisher(const dds::domain::DomainParticipant& dp,
                                 const dds::pub::qos::PublisherQos& qos,
                                 dds::pub::PublisherListener* listener,
                                 const dds::core::status::StatusMask& mask)
    :   ::dds::core::Reference<DELEGATE>(new DELEGATE(dp, qos, listener, mask))
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->init(this->impl_);
}

template <typename DELEGATE>
TPublisher<DELEGATE>::~TPublisher() { }

template <typename DELEGATE>
const dds::pub::qos::PublisherQos& TPublisher<DELEGATE>::qos() const
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->qos();
}

template <typename DELEGATE>
void TPublisher<DELEGATE>::qos(const dds::pub::qos::PublisherQos& pqos)
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->qos(pqos);
}

template <typename DELEGATE>
TPublisher<DELEGATE>& TPublisher<DELEGATE>::operator <<(const dds::pub::qos::PublisherQos& qos)
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->qos(qos);
    return *this;
}

template <typename DELEGATE>
TPublisher<DELEGATE>& TPublisher<DELEGATE>::operator >> (dds::pub::qos::PublisherQos& qos)
{
    ISOCPP_REPORT_STACK_BEGIN();
    qos = this->qos();
    return *this;
}

template <typename DELEGATE>
TPublisher<DELEGATE>& TPublisher<DELEGATE>::default_datawriter_qos(const dds::pub::qos::DataWriterQos& dwqos)
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->default_datawriter_qos(dwqos);
    return *this;
}

template <typename DELEGATE>
dds::pub::qos::DataWriterQos TPublisher<DELEGATE>::default_datawriter_qos() const
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->default_datawriter_qos();
}

template <typename DELEGATE>
void TPublisher<DELEGATE>::listener(Listener* plistener, const dds::core::status::StatusMask& event_mask)
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->listener(plistener, event_mask);
}

template <typename DELEGATE>
typename TPublisher<DELEGATE>::Listener* TPublisher<DELEGATE>::listener() const
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->listener();
}

template <typename DELEGATE>
void TPublisher<DELEGATE>::wait_for_acknowledgments(const dds::core::Duration& timeout)
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->wait_for_acknowledgments(timeout);
}

template <typename DELEGATE>
const dds::domain::DomainParticipant& TPublisher<DELEGATE>::participant() const
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->participant();
}

}
}

// End of implementation

#endif /* OSPL_DDS_PUB_TPUBLISHER_IMPL_HPP_ */
