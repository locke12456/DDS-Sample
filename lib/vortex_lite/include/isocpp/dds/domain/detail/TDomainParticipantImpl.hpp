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
#ifndef LITE_DDS_DOMAIN_TDOMAINPARTICIPANT_IMPL_HPP_
#define LITE_DDS_DOMAIN_TDOMAINPARTICIPANT_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/domain/TDomainParticipant.hpp>
#include <org/opensplice/domain/DomainParticipantDelegate.hpp>
#include <org/opensplice/domain/DomainParticipantRegistry.hpp>
#include <org/opensplice/core/ReportUtils.hpp>


// Implementation

namespace dds
{
namespace domain
{

template <typename DELEGATE>
TDomainParticipant<DELEGATE>::TDomainParticipant(uint32_t did):
    ::dds::core::Reference<DELEGATE>(
            new DELEGATE(did,
                         org::opensplice::domain::DomainParticipantDelegate::default_participant_qos(),
                         NULL,
                         dds::core::status::StatusMask::none()))
{
    this->delegate()->init(this->impl_);
    org::opensplice::domain::DomainParticipantRegistry::insert(*this);
}

template <typename DELEGATE>
TDomainParticipant<DELEGATE>::TDomainParticipant(uint32_t id,
        const dds::domain::qos::DomainParticipantQos& qos,
        dds::domain::DomainParticipantListener* listener,
        const dds::core::status::StatusMask& mask) :
    ::dds::core::Reference<DELEGATE>(new DELEGATE(id, qos, listener, mask))
{
    this->delegate()->init(this->impl_);
    org::opensplice::domain::DomainParticipantRegistry::insert(*this);
}

template <typename DELEGATE>
TDomainParticipant<DELEGATE>::~TDomainParticipant() { }

template <typename DELEGATE>
void TDomainParticipant<DELEGATE>::listener(Listener* listener,
        const ::dds::core::status::StatusMask& event_mask)
{
    this->delegate()->listener(listener, event_mask);
}

template <typename DELEGATE>
typename TDomainParticipant<DELEGATE>::Listener*  TDomainParticipant<DELEGATE>::listener() const
{
    return this->delegate()->listener();
}

template <typename DELEGATE>
const dds::domain::qos::DomainParticipantQos&
TDomainParticipant<DELEGATE>::qos() const
{
    return this->delegate()->qos();
}

template <typename DELEGATE>
void TDomainParticipant<DELEGATE>::qos(const dds::domain::qos::DomainParticipantQos& qos)
{
    this->delegate()->qos(qos);
}

template <typename DELEGATE>
uint32_t TDomainParticipant<DELEGATE>::domain_id() const
{
    return this->delegate()->domain_id();
}

template <typename DELEGATE>
void TDomainParticipant<DELEGATE>::assert_liveliness()
{
    this->delegate()->assert_liveliness();
}

template <typename DELEGATE>
bool TDomainParticipant<DELEGATE>::contains_entity(const ::dds::core::InstanceHandle& handle)
{
    return this->delegate()->contains_entity(handle);
}

template <typename DELEGATE>
dds::core::Time TDomainParticipant<DELEGATE>::current_time() const
{
    return this->delegate()->current_time();
}

template <typename DELEGATE>
dds::domain::qos::DomainParticipantQos TDomainParticipant<DELEGATE>::default_participant_qos()
{
    return DELEGATE::default_participant_qos();
}

template <typename DELEGATE>
void TDomainParticipant<DELEGATE>::default_participant_qos(const ::dds::domain::qos::DomainParticipantQos& qos)
{
    DELEGATE::default_participant_qos(qos);
}

template <typename DELEGATE>
dds::pub::qos::PublisherQos  TDomainParticipant<DELEGATE>::default_publisher_qos() const
{
    return this->delegate()->default_publisher_qos();
}

template <typename DELEGATE>
TDomainParticipant<DELEGATE>& TDomainParticipant<DELEGATE>::default_publisher_qos(
    const ::dds::pub::qos::PublisherQos& qos)
{
    this->delegate()->default_publisher_qos(qos);
    return *this;
}

template <typename DELEGATE>
dds::sub::qos::SubscriberQos  TDomainParticipant<DELEGATE>::default_subscriber_qos() const
{
    return this->delegate()->default_subscriber_qos();
}

template <typename DELEGATE>
TDomainParticipant<DELEGATE>& TDomainParticipant<DELEGATE>::default_subscriber_qos(
    const ::dds::sub::qos::SubscriberQos& qos)
{
    this->delegate()->default_subscriber_qos(qos);
    return *this;
}

template <typename DELEGATE>
dds::topic::qos::TopicQos  TDomainParticipant<DELEGATE>::default_topic_qos() const
{
    return this->delegate()->default_topic_qos();
}

template <typename DELEGATE>
TDomainParticipant<DELEGATE>&  TDomainParticipant<DELEGATE>::default_topic_qos(const dds::topic::qos::TopicQos& qos)
{
    this->delegate()->default_topic_qos(qos);
    return *this;
}

template <typename DELEGATE>
TDomainParticipant<DELEGATE>& TDomainParticipant<DELEGATE>::operator << (const dds::domain::qos::DomainParticipantQos& qos)
{
    this->qos(qos);
    return *this;
}

template <typename DELEGATE>
const TDomainParticipant<DELEGATE>& TDomainParticipant<DELEGATE>::operator >> (dds::domain::qos::DomainParticipantQos& qos) const
{
    qos = this->qos();
    return *this;
}

}
}
// End of implementation

#endif /* LITE_DDS_DOMAIN_TDOMAINPARTICIPANT_IMPL_HPP_ */
