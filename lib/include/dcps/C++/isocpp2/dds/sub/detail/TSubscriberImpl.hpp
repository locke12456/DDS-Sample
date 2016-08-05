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
#ifndef OSPL_DDS_SUB_TSUBSCRIBER_IMPL_HPP_
#define OSPL_DDS_SUB_TSUBSCRIBER_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/sub/TSubscriber.hpp>

// Implementation

namespace dds
{
namespace sub
{

template <typename DELEGATE>
TSubscriber<DELEGATE>::TSubscriber(const ::dds::domain::DomainParticipant& dp)
    : ::dds::core::Reference<DELEGATE>(new DELEGATE(dp,
                                                    dp.default_subscriber_qos(),
                                                    NULL,
                                                    dds::core::status::StatusMask::none()))
{
    ISOCPP_REPORT_STACK_BEGIN();

    this->delegate()->init(this->impl_);
}

template <typename DELEGATE>
TSubscriber<DELEGATE>::TSubscriber(const ::dds::domain::DomainParticipant& dp,
                                   const dds::sub::qos::SubscriberQos& qos,
                                   dds::sub::SubscriberListener* listener,
                                   const dds::core::status::StatusMask& mask)
    : ::dds::core::Reference<DELEGATE>(new DELEGATE(dp, qos, listener, mask))
{
    ISOCPP_REPORT_STACK_BEGIN();

    this->delegate()->init(this->impl_);
}

template <typename DELEGATE>
TSubscriber<DELEGATE>::~TSubscriber() {}

template <typename DELEGATE>
void TSubscriber<DELEGATE>::notify_datareaders()
{
    ISOCPP_REPORT_STACK_BEGIN();

    this->delegate()->notify_datareaders();
}

template <typename DELEGATE>
void TSubscriber<DELEGATE>::listener(Listener* listener,
                                     const dds::core::status::StatusMask& event_mask)
{
    ISOCPP_REPORT_STACK_BEGIN();

    return this->delegate()->listener(listener, event_mask);
}

template <typename DELEGATE>
typename TSubscriber<DELEGATE>::Listener* TSubscriber<DELEGATE>::listener() const
{
    ISOCPP_REPORT_STACK_BEGIN();

    return this->delegate()->listener();
}


template <typename DELEGATE>
const dds::sub::qos::SubscriberQos& TSubscriber<DELEGATE>::qos() const
{
    ISOCPP_REPORT_STACK_BEGIN();

    return this->delegate()->qos();
}

template <typename DELEGATE>
void TSubscriber<DELEGATE>::qos(const dds::sub::qos::SubscriberQos& sqos)
{
    ISOCPP_REPORT_STACK_BEGIN();

    this->delegate()->qos(sqos);
}

template <typename DELEGATE>
dds::sub::qos::DataReaderQos TSubscriber<DELEGATE>::default_datareader_qos() const
{
    ISOCPP_REPORT_STACK_BEGIN();

    return this->delegate()->default_datareader_qos();
}

template <typename DELEGATE>
TSubscriber<DELEGATE>& TSubscriber<DELEGATE>::default_datareader_qos(
    const dds::sub::qos::DataReaderQos& qos)
{
    ISOCPP_REPORT_STACK_BEGIN();

    this->delegate()->default_datareader_qos(qos);
    return *this;
}

template <typename DELEGATE>
const dds::domain::DomainParticipant& TSubscriber<DELEGATE>::participant() const
{
    ISOCPP_REPORT_STACK_BEGIN();

    return this->delegate()->participant();
}

template <typename DELEGATE>
TSubscriber<DELEGATE>& TSubscriber<DELEGATE>::operator << (const dds::sub::qos::SubscriberQos& qos)
{
    ISOCPP_REPORT_STACK_BEGIN();

    this->qos(qos);
    return *this;
}

template <typename DELEGATE>
const TSubscriber<DELEGATE>& TSubscriber<DELEGATE>::operator >> (dds::sub::qos::SubscriberQos& qos) const
{
    ISOCPP_REPORT_STACK_BEGIN();

    qos = this->qos();
    return *this;
}

}
}
// End of implementation

#endif /* OSPL_DDS_SUB_TSUBSCRIBER_IMPL_HPP_ */
