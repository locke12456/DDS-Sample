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
#ifndef LITE_DDS_SUB_TDATAREADER_IMPL_HPP_
#define LITE_DDS_SUB_TDATAREADER_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/sub/detail/DataReader.hpp>
#include <dds/sub/Query.hpp>
#include <dds/sub/detail/SamplesHolder.hpp>
#include <dds/domain/DomainParticipantListener.hpp>




/***************************************************************************
 *
 * dds/sub/DataReader<> WRAPPER implementation.
 * Declaration can be found in dds/sub/TDataReader.hpp
 *
 ***************************************************************************/

// Implementation

namespace dds
{
namespace sub
{

//--------------------------------------------------------------------------------
//  DATAREADER
//--------------------------------------------------------------------------------

template <typename T, template <typename Q> class DELEGATE>
DataReader<T, DELEGATE>::Selector::Selector(DataReader& dr) : impl_(dr.delegate())
{
}

template <typename T, template <typename Q> class DELEGATE>
typename DataReader<T, DELEGATE>::Selector&
DataReader<T, DELEGATE>::Selector::instance(const dds::core::InstanceHandle& h)
{
    impl_.instance(h);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
typename DataReader<T, DELEGATE>::Selector&
DataReader<T, DELEGATE>::Selector::state(const dds::sub::status::DataState& s)
{
    impl_.filter_state(s);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
typename DataReader<T, DELEGATE>::Selector&
DataReader<T, DELEGATE>::Selector::content(const dds::sub::Query& query)
{
    impl_.filter_content(query);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
typename DataReader<T, DELEGATE>::Selector&
DataReader<T, DELEGATE>::Selector::max_samples(uint32_t n)
{
    impl_.max_samples(n);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
dds::sub::LoanedSamples<T>
DataReader<T, DELEGATE>::Selector::read()
{
    return impl_.read();
}

template <typename T, template <typename Q> class DELEGATE>
dds::sub::LoanedSamples<T>
DataReader<T, DELEGATE>::Selector::take()
{
    return impl_.take();
}

template <typename T, template <typename Q> class DELEGATE>
template <typename SamplesFWIterator>
uint32_t
DataReader<T, DELEGATE>::Selector::read(SamplesFWIterator sfit, uint32_t max_samples)
{
    return impl_.read(sfit, max_samples);
}

template <typename T, template <typename Q> class DELEGATE>
template <typename SamplesFWIterator>
uint32_t
DataReader<T, DELEGATE>::Selector::take(SamplesFWIterator sfit,    uint32_t max_samples)
{
    return impl_.take(sfit, max_samples);
}

template <typename T, template <typename Q> class DELEGATE>
template <typename SamplesBIIterator>
uint32_t
DataReader<T, DELEGATE>::Selector::read(SamplesBIIterator sbit)
{
    return impl_.read(sbit);
}

template <typename T, template <typename Q> class DELEGATE>
template <typename SamplesBIIterator>
uint32_t
DataReader<T, DELEGATE>::Selector::take(SamplesBIIterator sbit)
{
    return impl_.take(sbit);
}

//--------------------------------------------------------------------------------
//  DATAREADER::MANIPULATORSELECTOR
//--------------------------------------------------------------------------------
template <typename T, template <typename Q> class DELEGATE>
DataReader<T, DELEGATE>::ManipulatorSelector::
ManipulatorSelector(DataReader& dr) : impl_(dr.delegate()) {}

template <typename T, template <typename Q> class DELEGATE>
bool
DataReader<T, DELEGATE>::ManipulatorSelector::read_mode()
{
    return impl_.read_mode();
}

template <typename T, template <typename Q> class DELEGATE>
void
DataReader<T, DELEGATE>::ManipulatorSelector::read_mode(bool b)
{
    impl_.read_mode(b);
}

template <typename T, template <typename Q> class DELEGATE>
typename DataReader<T, DELEGATE>::ManipulatorSelector&
DataReader<T, DELEGATE>::ManipulatorSelector::instance(const dds::core::InstanceHandle& h)
{
    impl_.instance(h);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
typename DataReader<T, DELEGATE>::ManipulatorSelector&
DataReader<T, DELEGATE>::ManipulatorSelector::next_instance(const dds::core::InstanceHandle& h)
{
    impl_.next_instance(h);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
typename DataReader<T, DELEGATE>::ManipulatorSelector&
DataReader<T, DELEGATE>::ManipulatorSelector::operator >>(dds::sub::LoanedSamples<T>& samples)
{
    impl_ >> samples;
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
typename DataReader<T, DELEGATE>::ManipulatorSelector&
DataReader<T, DELEGATE>::ManipulatorSelector::operator >> (ManipulatorSelector & (manipulator)(ManipulatorSelector&))
{
    manipulator(*this);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
template <typename Functor>
typename DataReader<T, DELEGATE>::ManipulatorSelector
DataReader<T, DELEGATE>::ManipulatorSelector::operator >> (Functor f)
{
    f(*this);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
typename DataReader<T, DELEGATE>::ManipulatorSelector&
DataReader<T, DELEGATE>::ManipulatorSelector::state(const dds::sub::status::DataState& s)
{
    impl_.filter_state(s);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
typename DataReader<T, DELEGATE>::ManipulatorSelector&
DataReader<T, DELEGATE>::ManipulatorSelector::content(const dds::sub::Query& query)
{
    impl_.filter_content(query);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
typename DataReader<T, DELEGATE>::ManipulatorSelector&
DataReader<T, DELEGATE>::ManipulatorSelector::max_samples(uint32_t n)
{
    impl_.max_samples(n);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
DataReader<T, DELEGATE>::DataReader(
    const dds::sub::Subscriber& sub,
    const dds::topic::Topic<T>& topic):
        ::dds::core::Reference< DELEGATE<T> >(new DELEGATE<T>(sub, topic, sub->default_datareader_qos()))
{
    this->delegate()->init(this->impl_);
}

template <typename T, template <typename Q> class DELEGATE>
DataReader<T, DELEGATE>::DataReader(
    const dds::sub::Subscriber& sub,
    const ::dds::topic::Topic<T>& topic,
    const dds::sub::qos::DataReaderQos& qos,
    dds::sub::DataReaderListener<T>* listener,
    const dds::core::status::StatusMask& mask) :
        ::dds::core::Reference< DELEGATE<T> >(new DELEGATE<T>(sub, topic, qos, listener, mask))
{
    this->delegate()->init(this->impl_);
}

#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT
template <typename T, template <typename Q> class DELEGATE>
DataReader<T, DELEGATE>::DataReader(
    const dds::sub::Subscriber& sub,
    const dds::topic::ContentFilteredTopic<T>& topic) :
        ::dds::core::Reference< DELEGATE<T> >(new DELEGATE<T>(sub, topic, sub.default_datareader_qos()))
{
    this->delegate()->init(this->impl_);
}

template <typename T, template <typename Q> class DELEGATE>
DataReader<T, DELEGATE>::DataReader(
    const dds::sub::Subscriber& sub,
    const ::dds::topic::ContentFilteredTopic<T>& topic,
    const dds::sub::qos::DataReaderQos& qos,
    dds::sub::DataReaderListener<T>* listener,
    const dds::core::status::StatusMask& mask) :
    ::dds::core::Reference< DELEGATE<T> >(new DELEGATE<T>(sub, topic, qos, listener, mask))
{
    this->delegate()->init(this->impl_);
}
#endif /* OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT */

#ifdef OMG_DDS_MULTI_TOPIC_SUPPORT
template <typename T, template <typename Q> class DELEGATE>
DataReader<T, DELEGATE>::DataReader(
    const dds::sub::Subscriber& sub,
    const dds::topic::MultiTopic<T>& topic) :
        ::dds::core::Reference< DELEGATE<T> >(new DELEGATE<T>(sub, topic))
{
    this->delegate()->init(this->impl_);
}

template <typename T, template <typename Q> class DELEGATE>
DataReader<T, DELEGATE>::DataReader(
    const dds::sub::Subscriber& sub,
    const ::dds::topic::MultiTopic<T>& topic,
    const dds::sub::qos::DataReaderQos& qos,
    dds::sub::DataReaderListener<T>* listener,
    const dds::core::status::StatusMask& mask) :
       ::dds::core::Reference< DELEGATE<T> >(new DELEGATE<T>(sub, topic, qos, listener, mask))
{
    this->delegate()->init(this->impl_);
}
#endif /* OMG_DDS_MULTI_TOPIC_SUPPORT */

template <typename T, template <typename Q> class DELEGATE>
DataReader<T, DELEGATE>::~DataReader() { }

template <typename T, template <typename Q> class DELEGATE>
dds::sub::status::DataState
DataReader<T, DELEGATE>::default_filter_state()
{
    return this->delegate()->default_filter_state();
}

template <typename T, template <typename Q> class DELEGATE>
DataReader<T, DELEGATE>& DataReader<T, DELEGATE>::default_filter_state(const dds::sub::status::DataState& status)
{
    this->delegate()->default_filter_state(status);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
DataReader<T, DELEGATE>& DataReader<T, DELEGATE>::operator >>(dds::sub::LoanedSamples<T>& ls)
{
    ls = this->read();
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
typename DataReader<T, DELEGATE>::ManipulatorSelector
DataReader<T, DELEGATE>::operator >> (ManipulatorSelector& (manipulator)(ManipulatorSelector&))
{
    ManipulatorSelector selector(*this);
    manipulator(selector);
    return selector;
}

template <typename T, template <typename Q> class DELEGATE>
template <typename Functor>
typename DataReader<T, DELEGATE>::ManipulatorSelector
DataReader<T, DELEGATE>::operator >> (Functor f)
{
    ManipulatorSelector selector(*this);
    f(selector);
    return selector;
}

template <typename T, template <typename Q> class DELEGATE>
LoanedSamples<T>
DataReader<T, DELEGATE>::read()
{
    return this->delegate()->read();
}

template <typename T, template <typename Q> class DELEGATE>
LoanedSamples<T>
DataReader<T, DELEGATE>::take()
{
    return this->delegate()->take();
}


template <typename T, template <typename Q> class DELEGATE>
template <typename SamplesFWIterator>
uint32_t
DataReader<T, DELEGATE>::read(SamplesFWIterator sfit, uint32_t max_samples)
{
    return this->delegate()->read(sfit, max_samples);
}

template <typename T, template <typename Q> class DELEGATE>
template <typename SamplesFWIterator>
uint32_t
DataReader<T, DELEGATE>::take(SamplesFWIterator sfit, uint32_t max_samples)
{
    return this->delegate()->take(sfit, max_samples);
}

template <typename T, template <typename Q> class DELEGATE>
template <typename SamplesBIIterator>
uint32_t
DataReader<T, DELEGATE>::read(SamplesBIIterator sbit)
{
    return this->delegate()->read(sbit);
}

template <typename T, template <typename Q> class DELEGATE>
template <typename SamplesBIIterator>
uint32_t
DataReader<T, DELEGATE>::take(SamplesBIIterator sbit)
{
    return this->delegate()->take(sbit);
}

template <typename T, template <typename Q> class DELEGATE>
typename DataReader<T, DELEGATE>::Selector
DataReader<T, DELEGATE>::select()
{
    Selector selector(*this);
    return selector;
}

template <typename T, template <typename Q> class DELEGATE>
dds::topic::TopicInstance<T>
DataReader<T, DELEGATE>::key_value(const dds::core::InstanceHandle& h)
{
    return this->delegate()->key_value(h);
}

template <typename T, template <typename Q> class DELEGATE>
T&
DataReader<T, DELEGATE>::key_value(T& sample, const dds::core::InstanceHandle& h)
{
    return this->delegate()->key_value(sample, h);
}

template <typename T, template <typename Q> class DELEGATE>
const dds::core::InstanceHandle
DataReader<T, DELEGATE>::lookup_instance(const T& key) const
{
    return this->delegate()->lookup_instance(key);
}

template <typename T, template <typename Q> class DELEGATE>
void
DataReader<T, DELEGATE>::listener(
    Listener* listener,
    const dds::core::status::StatusMask& event_mask)
{
    this->delegate()->listener(listener, event_mask);
}

template <typename T, template <typename Q> class DELEGATE>
typename DataReader<T, DELEGATE>::Listener*
DataReader<T, DELEGATE>::listener() const
{
    return this->delegate()->listener();
}

}
}




/***************************************************************************
 *
 * dds/sub/detail/DataReader<> DELEGATE implementation.
 * Declaration can be found in dds/sub/detail/DataReader.hpp
 *
 * Implementation and declaration have been separated because some circular
 * dependencies, like with DataReaderListener and AnyDataReader.
 *
 ***************************************************************************/

#include <dds/sub/AnyDataReader.hpp>
#include <dds/sub/DataReaderListener.hpp>
#include <dds/topic/Topic.hpp>
#include <dds/topic/ContentFilteredTopic.hpp>
#include <org/opensplice/sub/AnyDataReaderDelegate.hpp>
#include <org/opensplice/core/ListenerDispatcher.hpp>


template <typename T>
dds::sub::detail::DataReader<T>::DataReader(const dds::sub::Subscriber& sub,
           const dds::topic::Topic<T>& topic,
           const dds::sub::qos::DataReaderQos& qos,
           dds::sub::DataReaderListener<T>* listener,
           const dds::core::status::StatusMask& mask)
    : ::org::opensplice::sub::AnyDataReaderDelegate(qos, topic), sub_(sub),
      typed_sample_()
{
    common_constructor(listener, mask);
}

template <typename T>
dds::sub::detail::DataReader<T>::DataReader(const dds::sub::Subscriber& sub,
           const dds::topic::ContentFilteredTopic<T, dds::topic::detail::ContentFilteredTopic>& topic,
           const dds::sub::qos::DataReaderQos& qos,
           dds::sub::DataReaderListener<T>* listener,
           const dds::core::status::StatusMask& mask)
  : ::org::opensplice::sub::AnyDataReaderDelegate(qos, topic), sub_(sub),
    typed_sample_()

{
    common_constructor(listener, mask);
}

template <typename T>
void
dds::sub::detail::DataReader<T>::common_constructor(
            dds::sub::DataReaderListener<T>* listener,
            const dds::core::status::StatusMask& mask)
{
    if (dds::topic::is_topic_type<T>::value == 0) {
        ISOCPP_THROW_EXCEPTION(ISOCPP_PRECONDITION_NOT_MET_ERROR, "DataReader cannot be created, topic information not found");
    }

    org::opensplice::sub::qos::DataReaderQosDelegate drQos = qos_.delegate();

    // get and validate the kernel qos
    drQos.check();
    dds_qos_t* uQos = drQos.u_qos();

    dds_entity_t uSubscriber = (dds_entity_t)(sub_.delegate()->get_user_handle());
    dds_entity_t uTopic = (dds_entity_t)((dds::topic::Topic<T>)this->AnyDataReaderDelegate::td_).delegate()->get_user_handle();

#if 0
    std::string expression = this->AnyDataReaderDelegate::td_.delegate()->reader_expression();
    c_value *params = this->AnyDataReaderDelegate::td_.delegate()->reader_parameters();
#endif

    dds_entity_t uReader;
    int result = dds_reader_create(uSubscriber, &uReader, uTopic, uQos, NULL);
    dds_free(uQos);

    if (result) {
        ISOCPP_THROW_EXCEPTION(ISOCPP_ERROR, "Failed to create DataReader");
    } else {
        this->AnyDataReaderDelegate::td_.delegate()->incrNrDependents();
    }

    this->AnyDataReaderDelegate::setCopyOut(org::opensplice::topic::TopicTraits<T>::getCopyOut());
    this->AnyDataReaderDelegate::setCopyIn(org::opensplice::topic::TopicTraits<T>::getCopyIn());
    this->AnyDataReaderDelegate::setSample(&this->typed_sample_);
    this->userHandle = (void*)uReader;
    this->set_c_entity() ;
    this->listener(listener, mask);
}

template <typename T>
dds::sub::detail::DataReader<T>::~DataReader()
{
    if (!this->closed) {
        try {
            close();
        } catch (...) {

        }
    }
}

template <typename T>
void
dds::sub::detail::DataReader<T>::init(ObjectDelegate::weak_ref_type weak_ref)
{
    /* Set weak_ref before passing ourselves to other isocpp objects. */
    this->set_weak_ref(weak_ref);
    /* Register writer at publisher. */
    this->sub_.delegate()->add_datareader(*this);
    this->enable() ;
}

template <typename T>
dds::sub::status::DataState
dds::sub::detail::DataReader<T>::default_filter_state()
{
    org::opensplice::core::ScopedObjectLock scopedLock(*this);

    dds::sub::status::DataState state = this->status_filter_;

    scopedLock.unlock();

    return state;
}

template <typename T>
void
dds::sub::detail::DataReader<T>::default_filter_state(const dds::sub::status::DataState& state)
{
    org::opensplice::core::ScopedObjectLock scopedLock(*this);

    this->status_filter_ = state;

    scopedLock.unlock();
}


template <typename T>
dds::sub::LoanedSamples<T>
dds::sub::detail::DataReader<T>::read()
{
    dds::sub::LoanedSamples<T> samples;
    dds::sub::detail::LoanedSamplesHolder<T> holder(samples);

    this->AnyDataReaderDelegate::read((dds_entity_t)(this->userHandle), this->status_filter_, holder, -1);

    return samples;
}

template <typename T>
dds::sub::LoanedSamples<T>
dds::sub::detail::DataReader<T>::take()
{
    dds::sub::LoanedSamples<T> samples;
    dds::sub::detail::LoanedSamplesHolder<T> holder(samples);

    this->AnyDataReaderDelegate::take((dds_entity_t)(this->userHandle), this->status_filter_, holder, -1);

    return samples;
}

template <typename T>
template<typename SamplesFWIterator>
uint32_t
dds::sub::detail::DataReader<T>::read(SamplesFWIterator samples, uint32_t max_samples)
{
    dds::sub::detail::SamplesFWInteratorHolder<T, SamplesFWIterator> holder(samples);

    this->AnyDataReaderDelegate::read((dds_entity_t)(this->userHandle), this->status_filter_, holder, max_samples);

    return holder.get_length();
}

template <typename T>
template<typename SamplesFWIterator>
uint32_t
dds::sub::detail::DataReader<T>::take(SamplesFWIterator samples, uint32_t max_samples)
{
    dds::sub::detail::SamplesFWInteratorHolder<T, SamplesFWIterator> holder(samples);

    this->AnyDataReaderDelegate::take((dds_entity_t)(this->userHandle), this->status_filter_, holder, max_samples);

    return holder.get_length();
}

template <typename T>
template<typename SamplesBIIterator>
uint32_t
dds::sub::detail::DataReader<T>::read(SamplesBIIterator samples)
{
    dds::sub::detail::SamplesBIIteratorHolder<T, SamplesBIIterator> holder(samples);

    this->AnyDataReaderDelegate::read((dds_entity_t)(this->userHandle), this->status_filter_, holder, -1);

    return holder.get_length();
}

template <typename T>
template<typename SamplesBIIterator>
uint32_t
dds::sub::detail::DataReader<T>::take(SamplesBIIterator samples)
{
    dds::sub::detail::SamplesBIIteratorHolder<T, SamplesBIIterator> holder(samples);

    this->AnyDataReaderDelegate::take((dds_entity_t)(this->userHandle), this->status_filter_, holder, -1);

    return holder.get_length();
}

template <typename T>
dds::topic::TopicInstance<T>
dds::sub::detail::DataReader<T>::key_value(const dds::core::InstanceHandle& h)
{
    T key_holder;

    this->AnyDataReaderDelegate::get_key_value((dds_entity_t)(this->userHandle), h, &key_holder);

    return dds::topic::TopicInstance<T>(h, key_holder);
}

template <typename T>
T&
dds::sub::detail::DataReader<T>::key_value(T& key, const dds::core::InstanceHandle& h)
{
    this->AnyDataReaderDelegate::get_key_value((dds_entity_t)(this->userHandle), h, &key);

    return key;
}

template <typename T>
const dds::core::InstanceHandle
dds::sub::detail::DataReader<T>::lookup_instance(const T& key) const
{
    dds::core::InstanceHandle handle(this->AnyDataReaderDelegate::lookup_instance((dds_entity_t)(this->userHandle), &key));

    return handle;
}

template <typename T>
const dds::sub::Subscriber&
dds::sub::detail::DataReader<T>::subscriber() const
{
    this->check();

    return sub_;
}

template <typename T>
void
dds::sub::detail::DataReader<T>::close()
{
    this->prevent_callbacks();
    org::opensplice::core::ScopedObjectLock scopedLock(*this);

    this->listener(NULL, dds::core::status::StatusMask::none());

    this->sub_.delegate()->remove_datareader(*this);

    // Remove our dependency on the topicdescription, and drop our reference to it,
    // so that it can become garbage collected.
    // It is important that we also drop our reference to the topicdescription, since
    // subsequent dependencies between for example ContentFilteredTopic to Topic can
    // only be dropped by the destructor of the ContentFilteredTopic.
    this->AnyDataReaderDelegate::td_.delegate()->decrNrDependents();
    this->AnyDataReaderDelegate::td_ = dds::topic::TopicDescription(dds::core::null);

    org::opensplice::sub::AnyDataReaderDelegate::close();

    scopedLock.unlock();
}


template <typename T>
dds::sub::DataReaderListener<T>*
dds::sub::detail::DataReader<T>::listener()
{
    return reinterpret_cast<dds::sub::DataReaderListener<T>*>(this->listener_get());
}

template <typename T>
void
dds::sub::detail::DataReader<T>::listener(
        dds::sub::DataReaderListener<T>* l,
        const dds::core::status::StatusMask& event_mask)
{
    /* AnyDataReaderDelegate takes care of thread safety. */

   this->listener_set( l, event_mask ) ;
}

template <typename T>
dds::sub::DataReader<T, dds::sub::detail::DataReader>
dds::sub::detail::DataReader<T>::wrapper()
{
    typename DataReader::ref_type ref =
            OSPL_CXX11_STD_MODULE::dynamic_pointer_cast<DataReader<T> >(this->get_strong_ref());
    dds::sub::DataReader<T, dds::sub::detail::DataReader> reader(ref);

    return reader;
}

template <typename T>
void
dds::sub::detail::DataReader<T>::listener_notify(
        ObjectDelegate::ref_type source,
        uint32_t                 triggerMask,
        void                    *eventData,
        void                    *l)
{
#if 0
    /* The EntityDelegate takes care of the thread safety and always
     * provides a listener and source. */
    dds::sub::DataReaderListener<T>* listener =
            reinterpret_cast<dds::sub::DataReaderListener<T>*>(l);
    assert(listener);

    /* Get DataWriter wrapper from given source EntityDelegate. */
    typename DataReader::ref_type ref =
            OSPL_CXX11_STD_MODULE::dynamic_pointer_cast<DataReader<T> >(source);
    dds::sub::DataReader<T, dds::sub::detail::DataReader> reader(ref->wrapper());


    if (triggerMask & V_EVENT_DATA_AVAILABLE) {
        ref->reset_data_available();
        listener->on_data_available(reader);
    }

    if (triggerMask & V_EVENT_SAMPLE_REJECTED) {
        dds::core::status::SampleRejectedStatus status;
        status.delegate().v_status(v_readerStatus(eventData)->sampleRejected);
        listener->on_sample_rejected(reader, status);
    }

    if (triggerMask & V_EVENT_LIVELINESS_CHANGED) {
        dds::core::status::LivelinessChangedStatus status;
        status.delegate().v_status(v_readerStatus(eventData)->livelinessChanged);
        listener->on_liveliness_changed(reader, status);
    }

    if (triggerMask & V_EVENT_REQUESTED_DEADLINE_MISSED) {
        dds::core::status::RequestedDeadlineMissedStatus status;
        status.delegate().v_status(v_readerStatus(eventData)->deadlineMissed);
        listener->on_requested_deadline_missed(reader, status);
    }

    if (triggerMask & V_EVENT_REQUESTED_INCOMPATIBLE_QOS) {
        dds::core::status::RequestedIncompatibleQosStatus status;
        status.delegate().v_status(v_readerStatus(eventData)->incompatibleQos);
        listener->on_requested_incompatible_qos(reader, status);
    }

    if (triggerMask & V_EVENT_SAMPLE_LOST) {
        dds::core::status::SampleLostStatus status;
        status.delegate().v_status(v_readerStatus(eventData)->sampleLost);
        listener->on_sample_lost(reader, status);
    }

    if (triggerMask & V_EVENT_SUBSCRIPTION_MATCHED) {
        dds::core::status::SubscriptionMatchedStatus status;
        status.delegate().v_status(v_readerStatus(eventData)->subscriptionMatch);
        listener->on_subscription_matched(reader, status);
    }
#endif
}

template <typename T>
dds::sub::detail::DataReader<T>::Selector::Selector(typename DataReader<T>::ref_type dr)
    : mode(SELECT_MODE_READ), reader(dr), state_filter_is_set_(false),
      max_samples_((uint32_t)-1), query_(dds::core::null)
{
}

template <typename T>
typename dds::sub::detail::DataReader<T>::Selector&
dds::sub::detail::DataReader<T>::Selector::instance(const dds::core::InstanceHandle& h)
{
    this->handle = h;
    switch (this->mode) {
    case SELECT_MODE_READ:
    case SELECT_MODE_READ_INSTANCE:
    case SELECT_MODE_READ_NEXT_INSTANCE:
        this->mode = SELECT_MODE_READ_INSTANCE;
        break;
    case SELECT_MODE_READ_WITH_CONDITION:
    case SELECT_MODE_READ_INSTANCE_WITH_CONDITION:
    case SELECT_MODE_READ_NEXT_INSTANCE_WITH_CONDITION:
        this->mode = SELECT_MODE_READ_INSTANCE_WITH_CONDITION;
        break;
    }

    return *this;
}

template <typename T>
typename dds::sub::detail::DataReader<T>::Selector&
dds::sub::detail::DataReader<T>::Selector::next_instance(const dds::core::InstanceHandle& h)
{
    ISOCPP_THROW_EXCEPTION(ISOCPP_UNSUPPORTED_ERROR, "Function not currently supported");

    this->handle = h;
    switch (this->mode) {
    case SELECT_MODE_READ:
    case SELECT_MODE_READ_INSTANCE:
    case SELECT_MODE_READ_NEXT_INSTANCE:
        this->mode = SELECT_MODE_READ_NEXT_INSTANCE;
        break;
    case SELECT_MODE_READ_WITH_CONDITION:
    case SELECT_MODE_READ_INSTANCE_WITH_CONDITION:
    case SELECT_MODE_READ_NEXT_INSTANCE_WITH_CONDITION:
        this->mode = SELECT_MODE_READ_NEXT_INSTANCE_WITH_CONDITION;
        break;
    }

    return *this;
}

template <typename T>
typename dds::sub::detail::DataReader<T>::Selector&
dds::sub::detail::DataReader<T>::Selector::filter_state(const dds::sub::status::DataState& s)
{
    this->state_filter_ = s;
    this->state_filter_is_set_ = true;
#if 0
    if ((this->mode == SELECT_MODE_READ_WITH_CONDITION) ||
        (this->mode == SELECT_MODE_READ_INSTANCE_WITH_CONDITION) ||
        (this->mode == SELECT_MODE_READ_NEXT_INSTANCE_WITH_CONDITION)) {
        if (!this->query_.delegate()->modify_state_filter(this->state_filter_)) {
            dds::sub::Query q(this->query_.data_reader(), this->query_.expression(), this->query_.delegate()->parameters());
            q.delegate()->state_filter(this->state_filter_);
            this->query_ = q;
        }
    }
#endif
    return *this;
}

template <typename T>
typename dds::sub::detail::DataReader<T>::Selector&
dds::sub::detail::DataReader<T>::Selector::max_samples(uint32_t n)
{
    this->max_samples_ = n;
    return *this;
}

template <typename T>
typename dds::sub::detail::DataReader<T>::Selector&
dds::sub::detail::DataReader<T>::Selector::filter_content(
    const dds::sub::Query& query)
{
    this->query_ = query;
    switch (this->mode) {
    case SELECT_MODE_READ:
    case SELECT_MODE_READ_INSTANCE:
    case SELECT_MODE_READ_NEXT_INSTANCE:
        this->mode = SELECT_MODE_READ_WITH_CONDITION;
        break;
    default:
        break;
    }
    return *this;
}

template <typename T>
dds::sub::LoanedSamples<T>
dds::sub::detail::DataReader<T>::Selector::read()
{
    return this->reader->read(*this);
}

template <typename T>
dds::sub::LoanedSamples<T>
dds::sub::detail::DataReader<T>::Selector::take()
{
    return this->reader->take(*this);
}

// --- Forward Iterators: --- //

template <typename T>
template<typename SamplesFWIterator>
uint32_t
dds::sub::detail::DataReader<T>::Selector::read(SamplesFWIterator sfit, uint32_t max_samples)
{
    return this->reader->read(sfit, max_samples, *this);
}

template <typename T>
template<typename SamplesFWIterator>
uint32_t
dds::sub::detail::DataReader<T>::Selector::take(SamplesFWIterator sfit, uint32_t max_samples)
{
    return this->reader->take(sfit, max_samples, *this);
}

// --- Back-Inserting Iterators: --- //

template <typename T>
template<typename SamplesBIIterator>
uint32_t
dds::sub::detail::DataReader<T>::Selector::read(SamplesBIIterator sbit)
{
    return this->reader->read(sbit, *this);
}

template <typename T>
template<typename SamplesBIIterator>
uint32_t
dds::sub::detail::DataReader<T>::Selector::take(SamplesBIIterator sbit)
{
    return this->reader->take(sbit, *this);
}

template <typename T>
typename dds::sub::detail::DataReader<T>::SelectMode
dds::sub::detail::DataReader<T>::Selector::get_mode() const
{
    return this->mode;
}

template <typename T>
dds::sub::detail::DataReader<T>::ManipulatorSelector::ManipulatorSelector(typename DataReader<T>::ref_type dr) :
      Selector(dr), read_mode_(true)
{
}

template <typename T>
bool
dds::sub::detail::DataReader<T>::ManipulatorSelector::read_mode()
{
    return read_mode_;
}

template <typename T>
void
dds::sub::detail::DataReader<T>::ManipulatorSelector::read_mode(bool b)
{
    read_mode_ = b;
}

template <typename T>
typename dds::sub::detail::DataReader<T>::ManipulatorSelector&
dds::sub::detail::DataReader<T>::ManipulatorSelector::operator >>(dds::sub::LoanedSamples<T>& samples)
{
    if(read_mode_)
    {
        samples = this->Selector::read();
    }
    else
    {
        samples = this->Selector::take();
    }
    return *this;
}


template <typename T>
dds::sub::LoanedSamples<T>
dds::sub::detail::DataReader<T>::read(const Selector& selector)
{
    //@todo u_query uQuery;

    dds::sub::LoanedSamples<T> samples;
    dds::sub::detail::LoanedSamplesHolder<T> holder(samples);

    switch(selector.mode) {
    case SELECT_MODE_READ:
        this->AnyDataReaderDelegate::read((dds_entity_t)userHandle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_INSTANCE:
        this->AnyDataReaderDelegate::read_instance((dds_entity_t)userHandle, selector.handle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_NEXT_INSTANCE:
        //@todo this->AnyDataReaderDelegate::read_next_instance((dds_entity_t)userHandle, selector.handle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_WITH_CONDITION:
        //@todo uQuery = selector.query_.delegate()->get_user_query();
        //@todo /*FIXME */this->AnyDataReaderDelegate::read_w_condition(selector.query, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_INSTANCE_WITH_CONDITION:
        //@todo uQuery = selector.query_.delegate()->get_user_query();
        //@todo this->AnyDataReaderDelegate::read_instance_w_condition(uQuery, selector.handle, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_NEXT_INSTANCE_WITH_CONDITION:
        //@todo uQuery = selector.query_.delegate()->get_user_query();
        //@todo this->AnyDataReaderDelegate::read_next_instance_w_condition(uQuery, selector.handle, holder, selector.max_samples_);
        break;
    }

    return samples;
}

template <typename T>
dds::sub::LoanedSamples<T>
dds::sub::detail::DataReader<T>::take(const Selector& selector)
{
    //@todo u_query uQuery;

    dds::sub::LoanedSamples<T> samples;
    dds::sub::detail::LoanedSamplesHolder<T> holder(samples);

    switch(selector.mode) {
    case SELECT_MODE_READ:
        this->AnyDataReaderDelegate::take((dds_entity_t)userHandle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_INSTANCE:
        this->AnyDataReaderDelegate::take_instance((dds_entity_t)userHandle, selector.handle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_NEXT_INSTANCE:
        //@todo this->AnyDataReaderDelegate::take_next_instance((dds_entity_t)userHandle, selector.handle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_WITH_CONDITION:
        this->AnyDataReaderDelegate::take((dds_entity_t)userHandle,
                                          selector.state_filter_,
                                          holder,
                                          selector.max_samples_,
                                          selector.query_.delegate()->get_user_condition());
        break;
    case SELECT_MODE_READ_INSTANCE_WITH_CONDITION:
        //@todo uQuery = selector.query_.delegate()->get_user_query();
        //@todo this->AnyDataReaderDelegate::take_instance_w_condition(selector.query, selector.handle, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_NEXT_INSTANCE_WITH_CONDITION:
        //@todo uQuery = selector.query_.delegate()->get_user_query();
        //@todo this->AnyDataReaderDelegate::take_next_instance_w_condition(uQuery, selector.handle, holder, selector.max_samples_);
        break;
    }

    return samples;
}

// --- Forward Iterators: --- //

template <typename T>
template<typename SamplesFWIterator>
uint32_t
dds::sub::detail::DataReader<T>::read(SamplesFWIterator samples,
              uint32_t max_samples, const Selector& selector)
{
    //@todo u_query uQuery;

    dds::sub::detail::SamplesFWInteratorHolder<T, SamplesFWIterator> holder(samples);

    switch(selector.mode) {
    case SELECT_MODE_READ:
        this->AnyDataReaderDelegate::read((dds_entity_t)userHandle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_INSTANCE:
        this->AnyDataReaderDelegate::read_instance((dds_entity_t)userHandle, selector.handle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_NEXT_INSTANCE:
        //@todo this->AnyDataReaderDelegate::read_next_instance((dds_entity_t)userHandle, selector.handle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_WITH_CONDITION:
        this->AnyDataReaderDelegate::read((dds_entity_t)userHandle,
                                          selector.state_filter_,
                                          holder,
                                          selector.max_samples_,
                                          selector.query_.delegate()->get_user_condition());
        break;
    case SELECT_MODE_READ_INSTANCE_WITH_CONDITION:
        //@todo uQuery = selector.query_.delegate()->get_user_query();
        //@todo this->AnyDataReaderDelegate::read_instance_w_condition(uQuery, selector.handle, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_NEXT_INSTANCE_WITH_CONDITION:
        //@todo uQuery = selector.query_.delegate()->get_user_query();
        //@todo this->AnyDataReaderDelegate::read_next_instance_w_condition(uQuery, selector.handle, holder, selector.max_samples_);
        break;
    }

    return holder.get_length();
}

template <typename T>
template<typename SamplesFWIterator>
uint32_t
dds::sub::detail::DataReader<T>::take(SamplesFWIterator samples,
              uint32_t max_samples, const Selector& selector)
{
    //@todo u_query uQuery;

    dds::sub::detail::SamplesFWInteratorHolder<T, SamplesFWIterator> holder(samples);

    switch(selector.mode) {
    case SELECT_MODE_READ:
        this->AnyDataReaderDelegate::take((dds_entity_t)userHandle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_INSTANCE:
        this->AnyDataReaderDelegate::take_instance((dds_entity_t)userHandle, selector.handle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_NEXT_INSTANCE:
        //@todo this->AnyDataReaderDelegate::take_next_instance((dds_entity_t)userHandle, selector.handle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_WITH_CONDITION:
        //@todo uQuery = selector.query_.delegate()->get_user_query();
        //@todo this->AnyDataReaderDelegate::take_w_condition(uQuery, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_INSTANCE_WITH_CONDITION:
        //@todo uQuery = selector.query_.delegate()->get_user_query();
        //@todo this->AnyDataReaderDelegate::take_instance_w_condition(uQuery, selector.handle, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_NEXT_INSTANCE_WITH_CONDITION:
        //@todo uQuery = selector.query_.delegate()->get_user_query();
        //@todo this->AnyDataReaderDelegate::take_next_instance_w_condition(uQuery, selector.handle, holder, selector.max_samples_);
        break;
    }

    return holder.get_length();
}

// --- Back-Inserting Iterators: --- //

template <typename T>
template<typename SamplesBIIterator>
uint32_t
dds::sub::detail::DataReader<T>::read(SamplesBIIterator samples, const Selector& selector)
{
    //@todo u_query uQuery;

    dds::sub::detail::SamplesBIIteratorHolder<T, SamplesBIIterator> holder(samples);

    switch(selector.mode) {
    case SELECT_MODE_READ:
        this->AnyDataReaderDelegate::read((dds_entity_t)userHandle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_INSTANCE:
        this->AnyDataReaderDelegate::read_instance((dds_entity_t)userHandle, selector.handle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_NEXT_INSTANCE:
        //@todo this->AnyDataReaderDelegate::read_next_instance((dds_entity_t)userHandle, selector.handle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_WITH_CONDITION:
        //@todo uQuery = selector.query_.delegate()->get_user_query();
        //@todo this->AnyDataReaderDelegate::read_w_condition(uQuery, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_INSTANCE_WITH_CONDITION:
        //@todo uQuery = selector.query_.delegate()->get_user_query();
        //@todo this->AnyDataReaderDelegate::read_instance_w_condition(uQuery, selector.handle, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_NEXT_INSTANCE_WITH_CONDITION:
        //@todo uQuery = selector.query_.delegate()->get_user_query();
        //@todo this->AnyDataReaderDelegate::read_next_instance_w_condition(uQuery, selector.handle, holder, selector.max_samples_);
        break;
    }

    return holder.get_length();
}

template <typename T>
template<typename SamplesBIIterator>
uint32_t
dds::sub::detail::DataReader<T>::take(SamplesBIIterator samples, const Selector& selector)
{
    //@todo u_query uQuery;

    dds::sub::detail::SamplesBIIteratorHolder<T, SamplesBIIterator> holder(samples);

    switch(selector.mode) {
    case SELECT_MODE_READ:
        this->AnyDataReaderDelegate::take((dds_entity_t)userHandle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_INSTANCE:
        this->AnyDataReaderDelegate::take_instance((dds_entity_t)userHandle, selector.handle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_NEXT_INSTANCE:
        //@todo this->AnyDataReaderDelegate::take_next_instance((dds_entity_t)userHandle, selector.handle, selector.state_filter_, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_WITH_CONDITION:
        //@todo uQuery = selector.query_.delegate()->get_user_query();
        //@todo this->AnyDataReaderDelegate::take_w_condition(uQuery, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_INSTANCE_WITH_CONDITION:
        //@todo uQuery = selector.query_.delegate()->get_user_query();
        //@todo this->AnyDataReaderDelegate::take_instance_w_condition(uQuery, selector.handle, holder, selector.max_samples_);
        break;
    case SELECT_MODE_READ_NEXT_INSTANCE_WITH_CONDITION:
        //@todo uQuery = selector.query_.delegate()->get_user_query();
        //@todo this->AnyDataReaderDelegate::take_next_instance_w_condition(uQuery, selector.handle, holder, selector.max_samples_);
        break;
    }

    return holder.get_length();
}


namespace dds
{
namespace sub
{

template <typename SELECTOR>
SELECTOR& read(SELECTOR& selector)
{
    selector.read_mode(true);
    return selector;
}

template <typename SELECTOR>
SELECTOR& take(SELECTOR& selector)
{
    selector.read_mode(false);
    return selector;
}

inline dds::sub::functors::ContentFilterManipulatorFunctor
content(const dds::sub::Query& query)
{
    return dds::sub::functors::ContentFilterManipulatorFunctor(query);
}


inline dds::sub::functors::StateFilterManipulatorFunctor
state(const dds::sub::status::DataState& s)
{
    return dds::sub::functors::StateFilterManipulatorFunctor(s);
}

inline dds::sub::functors::InstanceManipulatorFunctor
instance(const dds::core::InstanceHandle& h)
{
    return dds::sub::functors::InstanceManipulatorFunctor(h);
}

inline dds::sub::functors::NextInstanceManipulatorFunctor
next_instance(const dds::core::InstanceHandle& h)
{
    return dds::sub::functors::NextInstanceManipulatorFunctor(h);
}

}
}



template <typename T>
void dds::sub::detail::DataReader<T>::on_requested_deadline_missed(
             org::opensplice::core::RequestedDeadlineMissedStatusDelegate &sd )
{
   dds::core::status::RequestedDeadlineMissedStatus s ;
   s.delegate() = sd ;

   dds::sub::DataReader<T, dds::sub::detail::DataReader> dr = wrapper() ;

   dds::sub::DataReaderListener<T> *l =
      reinterpret_cast<dds::sub::DataReaderListener<T> *>(this->listener_get());
   if( (l != NULL) &&
       (this->get_listener_mask().to_ulong() &
        dds::core::status::StatusMask::requested_deadline_missed().to_ulong()) )
   {
      l->on_requested_deadline_missed( dr, s ) ;
   }
   else if( (this->subscriber().delegate()->listener() != NULL ) &&
            ( this->subscriber().delegate()->get_listener_mask().to_ulong() &
              dds::core::status::StatusMask::requested_deadline_missed().
                                                                  to_ulong()) )
   {
      dds::sub::AnyDataReader adr = dr ;
      this->subscriber().delegate()->listener()->
                                       on_requested_deadline_missed( adr, s ) ;
   }
   else
   {
      dds::domain::DomainParticipant dp =
         this->subscriber().delegate()->participant() ;
      if( (dp.delegate()->listener() != NULL) &&
          (dp.delegate()->get_listener_mask().to_ulong() &
               dds::core::status::StatusMask::requested_deadline_missed().
                                                                  to_ulong()) )
      {
         dds::sub::AnyDataReader adr = dr ;
         dp.delegate()->listener()->on_requested_deadline_missed( adr, s ) ;
      }
   }
}

template <typename T>
void dds::sub::detail::DataReader<T>::on_requested_incompatible_qos(
             org::opensplice::core::RequestedIncompatibleQosStatusDelegate &sd )
{
   dds::core::status::RequestedIncompatibleQosStatus s ;
   s.delegate() = sd ;

   dds::sub::DataReader<T, dds::sub::detail::DataReader> dr = wrapper() ;

   dds::sub::DataReaderListener<T> *l =
      reinterpret_cast<dds::sub::DataReaderListener<T> *>(this->listener_get());
   if( (l != NULL) &&
       (this->get_listener_mask().to_ulong() &
               dds::core::status::StatusMask::requested_incompatible_qos().
                                                                  to_ulong()) )
   {
      l->on_requested_incompatible_qos( dr, s ) ;
   }
   else if( (this->subscriber().delegate()->listener() != NULL ) &&
            ( this->subscriber().delegate()->get_listener_mask().to_ulong() &
              dds::core::status::StatusMask::requested_incompatible_qos().
                                                                  to_ulong()) )
   {
      dds::sub::AnyDataReader adr = dr ;
      this->subscriber().delegate()->listener()->
                                       on_requested_incompatible_qos( adr, s ) ;
   }
   else
   {
      dds::domain::DomainParticipant dp =
         this->subscriber().delegate()->participant() ;
      if( (dp.delegate()->listener() != NULL) &&
          (dp.delegate()->get_listener_mask().to_ulong() &
               dds::core::status::StatusMask::requested_incompatible_qos().
                                                                  to_ulong()) )
      {
         dds::sub::AnyDataReader adr = dr ;
         dp.delegate()->listener()->on_requested_incompatible_qos( adr, s ) ;
      }
   }
}


template <typename T>
void dds::sub::detail::DataReader<T>::on_sample_rejected(
             org::opensplice::core::SampleRejectedStatusDelegate &sd )
{
   dds::core::status::SampleRejectedStatus s ;
   s.delegate() = sd ;

   dds::sub::DataReader<T, dds::sub::detail::DataReader> dr = wrapper() ;

   dds::sub::DataReaderListener<T> *l =
      reinterpret_cast<dds::sub::DataReaderListener<T> *>(this->listener_get());
   if( (l != NULL) &&
       (this->get_listener_mask().to_ulong() &
               dds::core::status::StatusMask::sample_rejected().to_ulong()) )
   {
      l->on_sample_rejected( dr, s ) ;
   }
   else if( (this->subscriber().delegate()->listener() != NULL ) &&
            ( this->subscriber().delegate()->get_listener_mask().to_ulong() &
              dds::core::status::StatusMask::sample_rejected().to_ulong()) )
   {
      dds::sub::AnyDataReader adr = dr ;
      this->subscriber().delegate()->listener()->on_sample_rejected( adr, s ) ;
   }
   else
   {
      dds::domain::DomainParticipant dp =
         this->subscriber().delegate()->participant() ;
      if( (dp.delegate()->listener() != NULL) &&
          (dp.delegate()->get_listener_mask().to_ulong() &
               dds::core::status::StatusMask::sample_rejected().to_ulong()) )
      {
         dds::sub::AnyDataReader adr = dr ;
         dp.delegate()->listener()->on_sample_rejected( adr, s ) ;
      }
   }
}


template <typename T>
void dds::sub::detail::DataReader<T>::on_liveliness_changed(
             org::opensplice::core::LivelinessChangedStatusDelegate &sd )
{
   dds::core::status::LivelinessChangedStatus s ;
   s.delegate() = sd ;

   dds::sub::DataReader<T, dds::sub::detail::DataReader> dr = wrapper() ;

   dds::sub::DataReaderListener<T> *l =
      reinterpret_cast<dds::sub::DataReaderListener<T> *>(this->listener_get());
   if( (l != NULL) &&
       (this->get_listener_mask().to_ulong() &
               dds::core::status::StatusMask::liveliness_changed().to_ulong()) )
   {
      l->on_liveliness_changed( dr, s ) ;
   }
   else if( (this->subscriber().delegate()->listener() != NULL ) &&
            ( this->subscriber().delegate()->get_listener_mask().to_ulong() &
              dds::core::status::StatusMask::liveliness_changed().to_ulong()) )
   {
      dds::sub::AnyDataReader adr = dr ;
      this->subscriber().delegate()->listener()->
                                              on_liveliness_changed( adr, s ) ;
   }
   else
   {
      dds::domain::DomainParticipant dp =
         this->subscriber().delegate()->participant() ;
      if( (dp.delegate()->listener() != NULL) &&
          (dp.delegate()->get_listener_mask().to_ulong() &
               dds::core::status::StatusMask::liveliness_changed().to_ulong()) )
      {
         dds::sub::AnyDataReader adr = dr ;
         dp.delegate()->listener()->on_liveliness_changed( adr, s ) ;
      }
   }
}


template <typename T>
void dds::sub::detail::DataReader<T>::on_data_available()
{
   dds::sub::DataReader<T, dds::sub::detail::DataReader> dr = wrapper() ;

   dds::sub::DataReaderListener<T> *l =
      reinterpret_cast<dds::sub::DataReaderListener<T> *>(this->listener_get());
   if( (l != NULL) &&
       (this->get_listener_mask().to_ulong() &
               dds::core::status::StatusMask::data_available().to_ulong()) )
   {
      l->on_data_available( dr ) ;
   }
   else if( (this->subscriber().delegate()->listener() != NULL ) &&
            ( this->subscriber().delegate()->get_listener_mask().to_ulong() &
              dds::core::status::StatusMask::data_available().to_ulong()) )
   {
      dds::sub::AnyDataReader adr = dr ;
      this->subscriber().delegate()->listener()->
                                              on_data_available( adr ) ;
   }
   else
   {
      dds::domain::DomainParticipant dp =
         this->subscriber().delegate()->participant() ;
      if( (dp.delegate()->listener() != NULL) &&
          (dp.delegate()->get_listener_mask().to_ulong() &
               dds::core::status::StatusMask::data_available().to_ulong()) )
      {
         dds::sub::AnyDataReader adr = dr ;
         dp.delegate()->listener()->on_data_available( adr ) ;
      }
   }
}


template <typename T>
void dds::sub::detail::DataReader<T>::on_subscription_matched(
             org::opensplice::core::SubscriptionMatchedStatusDelegate &sd )
{
   dds::core::status::SubscriptionMatchedStatus s ;
   s.delegate() = sd ;

   dds::sub::DataReader<T, dds::sub::detail::DataReader> dr = wrapper() ;

   dds::sub::DataReaderListener<T> *l =
      reinterpret_cast<dds::sub::DataReaderListener<T> *>(this->listener_get());
   if( (l != NULL) &&
       (this->get_listener_mask().to_ulong() &
             dds::core::status::StatusMask::subscription_matched().to_ulong()) )
   {
      l->on_subscription_matched( dr, s ) ;
   }
   else if( (this->subscriber().delegate()->listener() != NULL ) &&
            ( this->subscriber().delegate()->get_listener_mask().to_ulong() &
              dds::core::status::StatusMask::subscription_matched().
                                                                   to_ulong()) )
   {
      dds::sub::AnyDataReader adr = dr ;
      this->subscriber().delegate()->listener()->
                                            on_subscription_matched( adr, s ) ;
   }
   else
   {
      dds::domain::DomainParticipant dp =
         this->subscriber().delegate()->participant() ;
      if( (dp.delegate()->listener() != NULL) &&
          (dp.delegate()->get_listener_mask().to_ulong() &
             dds::core::status::StatusMask::subscription_matched().to_ulong()) )
      {
         dds::sub::AnyDataReader adr = dr ;
         dp.delegate()->listener()->on_subscription_matched( adr, s ) ;
      }
   }
}


template <typename T>
void dds::sub::detail::DataReader<T>::on_sample_lost(
             org::opensplice::core::SampleLostStatusDelegate &sd )
{
   dds::core::status::SampleLostStatus s ;
   s.delegate() = sd ;

   dds::sub::DataReader<T, dds::sub::detail::DataReader> dr = wrapper() ;

   dds::sub::DataReaderListener<T> *l =
      reinterpret_cast<dds::sub::DataReaderListener<T> *>(this->listener_get());
   if( (l != NULL) &&
       (this->get_listener_mask().to_ulong() &
             dds::core::status::StatusMask::sample_lost().to_ulong()) )
   {
      l->on_sample_lost( dr, s ) ;
   }
   else if( (this->subscriber().delegate()->listener() != NULL ) &&
            ( this->subscriber().delegate()->get_listener_mask().to_ulong() &
              dds::core::status::StatusMask::sample_lost().to_ulong()) )
   {
      dds::sub::AnyDataReader adr = dr ;
      this->subscriber().delegate()->listener()->on_sample_lost( adr, s ) ;
   }
   else
   {
      dds::domain::DomainParticipant dp =
         this->subscriber().delegate()->participant() ;
      if( (dp.delegate()->listener() != NULL) &&
          (dp.delegate()->get_listener_mask().to_ulong() &
             dds::core::status::StatusMask::sample_lost().to_ulong()) )
      {
         dds::sub::AnyDataReader adr = dr ;
         dp.delegate()->listener()->on_sample_lost( adr, s ) ;
      }
   }
}

// End of implementation

#endif /* LITE_DDS_SUB_TDATAREADER_IMPL_HPP_ */
