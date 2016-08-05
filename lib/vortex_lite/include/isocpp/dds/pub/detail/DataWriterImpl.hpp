#ifndef OMG_DDS_PUB_DATA_WRITER_IMPL_HPP_
#define OMG_DDS_PUB_DATA_WRITER_IMPL_HPP_

/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Corp.
 * Copyright 2010, Real-Time Innovations, Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */




/***************************************************************************
 *
 * dds/pub/DataWriter<> WRAPPER implementation.
 * Declaration can be found in dds/pub/DataWriter.hpp
 *
 ***************************************************************************/

#include <dds/topic/Topic.hpp>
#include <dds/pub/PublisherListener.hpp>
#include <dds/domain/DomainParticipantListener.hpp>
#include <org/opensplice/core/ListenerDispatcher.hpp>

namespace dds
{
namespace pub
{

template <typename T, template <typename Q> class DELEGATE>
DataWriter<T, DELEGATE>::DataWriter(
    const dds::pub::Publisher& pub,
    const dds::topic::Topic<T>& topic) :
        dds::core::Reference< DELEGATE<T> >(
            new DELEGATE<T>(pub, topic, pub.default_datawriter_qos(), NULL, dds::core::status::StatusMask::none()))
{
    this->delegate()->init(this->impl_);
}

template <typename T, template <typename Q> class DELEGATE>
DataWriter<T, DELEGATE>::DataWriter(const dds::pub::Publisher& pub,
     const ::dds::topic::Topic<T>& topic,
     const dds::pub::qos::DataWriterQos& qos,
     dds::pub::DataWriterListener<T>* listener,
     const dds::core::status::StatusMask& mask) :
         dds::core::Reference< DELEGATE<T> >(
            new DELEGATE<T>(pub, topic, qos, listener, mask))
{
    this->delegate()->init(this->impl_);
}

template <typename T, template <typename Q> class DELEGATE>
DataWriter<T, DELEGATE>::~DataWriter()
{
}

template <typename T, template <typename Q> class DELEGATE>
void
DataWriter<T, DELEGATE>::write(const T& sample)
{
    this->delegate()->write(sample);
}

template <typename T, template <typename Q> class DELEGATE>
void
DataWriter<T, DELEGATE>::write(const T& sample, const dds::core::Time& timestamp)
{
    this->delegate()->write(sample, timestamp);
}

template <typename T, template <typename Q> class DELEGATE>
void
DataWriter<T, DELEGATE>::write(const T& sample, const ::dds::core::InstanceHandle& instance)
{
    this->delegate()->write(sample, instance);
}

template <typename T, template <typename Q> class DELEGATE>
void
DataWriter<T, DELEGATE>::write(const T& sample,
        const ::dds::core::InstanceHandle& instance,
        const dds::core::Time& timestamp)
{
    this->delegate()->write(sample, instance, timestamp);
}

template <typename T, template <typename Q> class DELEGATE>
void
DataWriter<T, DELEGATE>::write(const dds::topic::TopicInstance<T>& i)
{
    this->delegate()->write(i);
}

template <typename T, template <typename Q> class DELEGATE>
void
DataWriter<T, DELEGATE>::write(const dds::topic::TopicInstance<T>& i,
        const dds::core::Time& timestamp)
{
    this->delegate()->write(i, timestamp);
}

template <typename T, template <typename Q> class DELEGATE>
template <typename FWIterator>
void
DataWriter<T, DELEGATE>::write(const FWIterator& begin, const FWIterator& end)
{
    FWIterator b = begin;
    while(b != end)
    {
        this->delegate()->write(*b);
        ++b;
    }
}

template <typename T, template <typename Q> class DELEGATE>
template <typename FWIterator>
void
DataWriter<T, DELEGATE>::write(const FWIterator& begin, const FWIterator& end,
        const dds::core::Time& timestamp)
{
    FWIterator b = begin;
    while(b != end)
    {
        this->delegate()->write(*b, timestamp);
        ++b;
    }
}

template <typename T, template <typename Q> class DELEGATE>
template <typename SamplesFWIterator, typename HandlesFWIterator>
void
DataWriter<T, DELEGATE>::write(const SamplesFWIterator& data_begin,
        const SamplesFWIterator& data_end,
        const HandlesFWIterator& handle_begin,
        const HandlesFWIterator& handle_end)
{
    SamplesFWIterator data = data_begin;
    HandlesFWIterator handle = handle_begin;

    while(data != data_end && handle != handle_end)
    {
        this->delegate()->write(*data, *handle);
        ++data;
        ++handle;
    }
}

template <typename T, template <typename Q> class DELEGATE>
template <typename SamplesFWIterator, typename HandlesFWIterator>
void
DataWriter<T, DELEGATE>::write(const SamplesFWIterator& data_begin,
        const SamplesFWIterator& data_end,
        const HandlesFWIterator& handle_begin,
        const HandlesFWIterator& handle_end,
        const dds::core::Time& timestamp)
{
    SamplesFWIterator data = data_begin;
    HandlesFWIterator handle = handle_begin;

    while(data != data_end && handle != handle_end)
    {
        this->delegate()->write(*data, *handle, timestamp);
        ++data;
        ++handle;
    }
}

template <typename T, template <typename Q> class DELEGATE>
DataWriter<T, DELEGATE>&
DataWriter<T, DELEGATE>::operator <<(const ::dds::pub::qos::DataWriterQos& qos)
{
    this->delegate()->qos(qos);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
DataWriter<T, DELEGATE>&
DataWriter<T, DELEGATE>::operator << (const T& data)
{
    this->write(data);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
DataWriter<T, DELEGATE>&
DataWriter<T, DELEGATE>::operator << (const std::pair<T, dds::core::Time>& data)
{
    this->write(data.first, data.second);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
DataWriter<T, DELEGATE>&
DataWriter<T, DELEGATE>::operator << (const std::pair<T, ::dds::core::InstanceHandle>& data)
{
    this->write(data.first, data.second);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
DataWriter<T, DELEGATE>&
DataWriter<T, DELEGATE>::operator <<(DataWriter & (*manipulator)(DataWriter&))
{
    return manipulator(*this);
}

template <typename T, template <typename Q> class DELEGATE>
const dds::core::InstanceHandle
DataWriter<T, DELEGATE>::register_instance(const T& key)
{
    /* Invalid time will be used as current time. */
    return this->delegate()->register_instance(key, dds::core::Time::invalid());
}

template <typename T, template <typename Q> class DELEGATE>
const dds::core::InstanceHandle
DataWriter<T, DELEGATE>::register_instance(const T& key,
        const dds::core::Time& timestamp)
{
    return this->delegate()->register_instance(key, timestamp);
}

template <typename T, template <typename Q> class DELEGATE>
DataWriter<T, DELEGATE>&
DataWriter<T, DELEGATE>::unregister_instance(const ::dds::core::InstanceHandle& i)
{
    /* Invalid time will be used as current time. */
    this->delegate()->unregister_instance(i, dds::core::Time::invalid());
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
DataWriter<T, DELEGATE>&
DataWriter<T, DELEGATE>::unregister_instance(const ::dds::core::InstanceHandle& i,
        const dds::core::Time& timestamp)
{
    this->delegate()->unregister_instance(i, timestamp);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
DataWriter<T, DELEGATE>&
DataWriter<T, DELEGATE>::unregister_instance(const T& key)
{
    /* Invalid time will be used as current time. */
    this->delegate()->unregister_instance(key, dds::core::Time::invalid());
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
DataWriter<T, DELEGATE>&
DataWriter<T, DELEGATE>::unregister_instance(const T& key,
        const dds::core::Time& timestamp)
{
    this->delegate()->unregister_instance(key, timestamp);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
DataWriter<T, DELEGATE>&
DataWriter<T, DELEGATE>::dispose_instance(const ::dds::core::InstanceHandle& i)
{
    /* Invalid time will be used as current time. */
    this->delegate()->dispose_instance(i, dds::core::Time::invalid());
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
DataWriter<T, DELEGATE>&
DataWriter<T, DELEGATE>::dispose_instance(const ::dds::core::InstanceHandle& i,
        const dds::core::Time& timestamp)
{
    this->delegate()->dispose_instance(i, timestamp);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
DataWriter<T, DELEGATE>&
DataWriter<T, DELEGATE>::dispose_instance(const T& key)
{
    /* Invalid time will be used as current time. */
    this->delegate()->dispose_instance(key, dds::core::Time::invalid());
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
DataWriter<T, DELEGATE>&
DataWriter<T, DELEGATE>::dispose_instance(const T& key,
        const dds::core::Time& timestamp)
{
    this->delegate()->dispose_instance(key, timestamp);
    return *this;
}

template <typename T, template <typename Q> class DELEGATE>
dds::topic::TopicInstance<T>&
DataWriter<T, DELEGATE>::key_value(dds::topic::TopicInstance<T>& i,
        const ::dds::core::InstanceHandle& h)
{
    return this->delegate()->key_value(i, h);
}

template <typename T, template <typename Q> class DELEGATE>
T&
DataWriter<T, DELEGATE>::key_value(T& sample, const ::dds::core::InstanceHandle& h)
{
    return this->delegate()->key_value(sample, h);
}

template <typename T, template <typename Q> class DELEGATE>
dds::core::InstanceHandle
DataWriter<T, DELEGATE>::lookup_instance(const T& key)
{
    return this->delegate()->lookup_instance(key);
}

template <typename T, template <typename Q> class DELEGATE>
const dds::topic::Topic<T>&
DataWriter<T, DELEGATE>::topic() const
{
    return this->delegate()->topic();
}

template <typename T, template <typename Q> class DELEGATE>
void
DataWriter<T, DELEGATE>::listener(DataWriterListener<T>* listener,
    const ::dds::core::status::StatusMask& mask)
{
    this->delegate()->listener(listener, mask);
}

template <typename T, template <typename Q> class DELEGATE>
DataWriterListener<T>*
DataWriter<T, DELEGATE>::listener() const
{
    return this->delegate()->listener();
}

}
}




/***************************************************************************
 *
 * dds/pub/detail/DataWriter<> DELEGATE implementation.
 * Declaration can be found in dds/pub/detail/DataWriter.hpp
 *
 * Implementation and declaration have been separated because some circular
 * dependencies, like with DataWriterListener and AnyDataWriter.
 *
 ***************************************************************************/

#include <dds/pub/AnyDataWriter.hpp>
#include <dds/pub/DataWriterListener.hpp>
#include <org/opensplice/pub/AnyDataWriterDelegate.hpp>

template <typename T>
dds::pub::detail::DataWriter<T>::DataWriter(
    const dds::pub::Publisher& pub,
    const ::dds::topic::Topic<T>& topic,
    const dds::pub::qos::DataWriterQos& qos,
    dds::pub::DataWriterListener<T>* listener,
    const dds::core::status::StatusMask& mask)
    : ::org::opensplice::pub::AnyDataWriterDelegate(qos, topic), pub_(pub), topic_(topic)
{
    if (dds::topic::is_topic_type<T>::value == 0) {
        ISOCPP_THROW_EXCEPTION(ISOCPP_PRECONDITION_NOT_MET_ERROR, "DataWriter cannot be created, topic information not found");
    }

    org::opensplice::pub::qos::DataWriterQosDelegate dwQos = qos.delegate();

    // get and validate the kernel qos
    dwQos.check();
    dds_qos_t *uQos = dwQos.u_qos();

    dds_entity_t uPublisher = (dds_entity_t)pub.delegate()->get_user_handle();
    dds_entity_t uTopic = (dds_entity_t)topic.delegate()->get_user_handle();
    //@todo dds_writer_listener_t *uListener = (dds_writer_listener_t)listener.delegate()->get_user_handle();

    std::string name = topic.name() + "_datawriter";

    dds_entity_t uWriter;

    int result = dds_writer_create (uPublisher, &uWriter, uTopic, uQos, NULL);
    dds_free(uQos);
    if (result) {
        ISOCPP_THROW_EXCEPTION(ISOCPP_ERROR, "Failed to create DataWriter");
    } else {
        topic_.delegate()->incrNrDependents();
    }

    this->setCopyIn(org::opensplice::topic::TopicTraits<T>::getCopyIn());
    this->setCopyOut(org::opensplice::topic::TopicTraits<T>::getCopyOut());

    this->userHandle = uWriter;
    this->listener(listener, mask);

    this->set_c_entity() ;
}

template <typename T>
dds::pub::detail::DataWriter<T>::~DataWriter()
{
    if (!this->closed) {
        try {
            this->close();
        } catch (...) {
            /* Empty: the exception throw should have already traced an error. */
        }
    }
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::init(ObjectDelegate::weak_ref_type weak_ref)
{
    /* Set weak_ref before passing ourselves to other isocpp objects. */
    this->set_weak_ref(weak_ref);
    /* Register writer at publisher. */
    this->pub_.delegate()->add_datawriter(*this);

    /* Enable when needed. */
    if (this->pub_.delegate()->is_auto_enable()) {
        this->enable();
    }
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::write(const T& sample)
{
    this->check();
    AnyDataWriterDelegate::write((dds_entity_t)this->userHandle,
                                  &sample,
                                  dds::core::InstanceHandle(dds::core::null),
                                  dds::core::Time::invalid());
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::write(const T& sample, const dds::core::Time& timestamp)
{
    this->check();
    AnyDataWriterDelegate::write((dds_entity_t)this->userHandle,
                                  &sample,
                                  dds::core::InstanceHandle(dds::core::null),
                                  timestamp);
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::write(const T& sample, const ::dds::core::InstanceHandle& instance)
{
    this->check();
    AnyDataWriterDelegate::write((dds_entity_t)this->userHandle,
                                  &sample,
                                  instance,
                                  dds::core::Time::invalid());
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::write(const T& sample,
           const ::dds::core::InstanceHandle& instance,
           const dds::core::Time& timestamp)
{
    this->check();
    AnyDataWriterDelegate::write((dds_entity_t)this->userHandle,
                                  &sample,
                                  instance,
                                  timestamp);
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::write(const dds::topic::TopicInstance<T>& i)
{
    this->check();
    AnyDataWriterDelegate::write((dds_entity_t)this->userHandle,
                                  &i.sample(),
                                  i.handle(),
                                  dds::core::Time::invalid());
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::write(const dds::topic::TopicInstance<T>& i,
           const dds::core::Time& timestamp)
{
    this->check();
    AnyDataWriterDelegate::write((dds_entity_t)this->userHandle,
                                  &i.sample(),
                                  i.handle(),
                                  timestamp);
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::writedispose(const T& sample)
{
    this->check();
    AnyDataWriterDelegate::writedispose(
                                  (dds_entity_t)this->userHandle,
                                  &sample,
                                  dds::core::InstanceHandle(dds::core::null),
                                  dds::core::Time::invalid());
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::writedispose(const T& sample, const dds::core::Time& timestamp)
{
    this->check();
    AnyDataWriterDelegate::writedispose(
                                  (dds_entity_t)this->userHandle,
                                  &sample,
                                  dds::core::InstanceHandle(dds::core::null),
                                  timestamp);
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::writedispose(const T& sample, const ::dds::core::InstanceHandle& instance)
{
    this->check();
    AnyDataWriterDelegate::writedispose(
                                  (dds_entity_t)this->userHandle,
                                  &sample,
                                  instance,
                                  dds::core::Time::invalid());
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::writedispose(
           const T& sample,
           const ::dds::core::InstanceHandle& instance,
           const dds::core::Time& timestamp)
{
    this->check();
    AnyDataWriterDelegate::writedispose(
                                  (dds_entity_t)this->userHandle,
                                  &sample,
                                  instance,
                                  timestamp);
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::writedispose(const dds::topic::TopicInstance<T>& i)
{
    this->check();
    AnyDataWriterDelegate::writedispose(
                                  (dds_entity_t)this->userHandle,
                                  &i.sample(),
                                  i.handle(),
                                  dds::core::Time::invalid());
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::writedispose(
           const dds::topic::TopicInstance<T>& i,
           const dds::core::Time& timestamp)
{
    this->check();
    AnyDataWriterDelegate::writedispose(
                                  (dds_entity_t)this->userHandle,
                                  &i.sample(),
                                  i.handle(),
                                  timestamp);
}

template <typename T>
template <typename FWIterator>
void
dds::pub::detail::DataWriter<T>::writedispose(const FWIterator& begin, const FWIterator& end)
{
    FWIterator b = begin;
    while(b != end)
    {
        this->writedispose(*b);
        ++b;
    }
}

template <typename T>
template <typename FWIterator>
void
dds::pub::detail::DataWriter<T>::writedispose(const FWIterator& begin, const FWIterator& end,
        const dds::core::Time& timestamp)
{
    FWIterator b = begin;
    while(b != end)
    {
        this->writedispose(*b, timestamp);
        ++b;
    }
}

template <typename T>
template <typename SamplesFWIterator, typename HandlesFWIterator>
void
dds::pub::detail::DataWriter<T>::writedispose(
        const SamplesFWIterator& data_begin,
        const SamplesFWIterator& data_end,
        const HandlesFWIterator& handle_begin,
        const HandlesFWIterator& handle_end)
{
    SamplesFWIterator data = data_begin;
    HandlesFWIterator handle = handle_begin;

    while(data != data_end && handle != handle_end)
    {
        this->writedispose(*data, *handle);
        ++data;
        ++handle;
    }
}

template <typename T>
template <typename SamplesFWIterator, typename HandlesFWIterator>
void
dds::pub::detail::DataWriter<T>::writedispose(
        const SamplesFWIterator& data_begin,
        const SamplesFWIterator& data_end,
        const HandlesFWIterator& handle_begin,
        const HandlesFWIterator& handle_end,
        const dds::core::Time& timestamp)
{
    SamplesFWIterator data = data_begin;
    HandlesFWIterator handle = handle_begin;

    while(data != data_end && handle != handle_end)
    {
        this->writedispose(*data, *handle, timestamp);
        ++data;
        ++handle;
    }
}

template <typename T>
const ::dds::core::InstanceHandle
dds::pub::detail::DataWriter<T>::register_instance(const T& key,
                                                   const dds::core::Time& timestamp)
{
    this->check();
    dds::core::InstanceHandle handle(AnyDataWriterDelegate::register_instance((dds_entity_t)this->userHandle, &key, timestamp));
    return handle;
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::unregister_instance(const ::dds::core::InstanceHandle& handle,
                                                     const dds::core::Time& timestamp)
{
    this->check();
    AnyDataWriterDelegate::unregister_instance((dds_entity_t)this->userHandle, handle, timestamp);
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::unregister_instance(const T& sample,
                                                     const dds::core::Time& timestamp)
{
    this->check();
    AnyDataWriterDelegate::unregister_instance((dds_entity_t)this->userHandle, &sample, timestamp);
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::dispose_instance(const ::dds::core::InstanceHandle& handle,
                                                  const dds::core::Time& timestamp)
{
    this->check();
    AnyDataWriterDelegate::dispose_instance((dds_entity_t)this->userHandle, handle, timestamp);
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::dispose_instance(const T& sample,
                                                  const dds::core::Time& timestamp)
{
    this->check();
    AnyDataWriterDelegate::dispose_instance((dds_entity_t)this->userHandle, &sample, timestamp);
}


template <typename T>
dds::topic::TopicInstance<T>&
dds::pub::detail::DataWriter<T>::key_value(dds::topic::TopicInstance<T>& i,
                                           const ::dds::core::InstanceHandle& h)
{
    this->check();

    T sample;
    AnyDataWriterDelegate::get_key_value((dds_entity_t)this->userHandle, &sample, h);
    i.handle(h);
    i.sample(sample);

    return i;
}

template <typename T>
T&
dds::pub::detail::DataWriter<T>::key_value(T& sample, const ::dds::core::InstanceHandle& h)
{
    this->check();

    AnyDataWriterDelegate::get_key_value((dds_entity_t)this->userHandle, &sample, h);

    return sample;
}

template <typename T>
dds::core::InstanceHandle
dds::pub::detail::DataWriter<T>::lookup_instance(const T& key)
{
    this->check();

    dds::core::InstanceHandle handle(AnyDataWriterDelegate::lookup_instance((dds_entity_t)this->userHandle, &key));

    return handle;
}

template <typename T>
const dds::topic::Topic<T>&
dds::pub::detail::DataWriter<T>::topic() const
{
    return this->topic_;
}

template <typename T>
const dds::pub::Publisher&
dds::pub::detail::DataWriter<T>::publisher() const
{
    return this->pub_;
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::listener(DataWriterListener<T>* listener,
                                   const ::dds::core::status::StatusMask& mask)
{
   uint32_t merged_mask = 0 ;
   if( listener != NULL )
   {
      this->listener_mask = mask ;
   }
   else
   {
      this->listener_mask = dds::core::status::StatusMask::none() ;
   }
   merged_mask = this->listener_mask.to_ulong() |
                 this->publisher().delegate()->get_merged_mask() ;

   memset( &(this->listener_callback_pointers),
           0,
           sizeof(dds_writerlistener_t) ) ; 

    if( merged_mask &
        dds::core::status::StatusMask::offered_deadline_missed().to_ulong() )
    {
       listener_callback_pointers.on_offered_deadline_missed =
          callback_on_offered_deadline_missed ;
    }
    if( merged_mask &
        dds::core::status::StatusMask::offered_incompatible_qos().to_ulong() )
    {
       listener_callback_pointers.on_offered_incompatible_qos =
          callback_on_offered_incompatible_qos ;
    }
    if( merged_mask &
        dds::core::status::StatusMask::liveliness_lost().to_ulong() )
    {
       listener_callback_pointers.on_liveliness_lost =
          callback_on_liveliness_lost ;
    }
    if( merged_mask &
        dds::core::status::StatusMask::publication_matched().to_ulong() )
    {
       listener_callback_pointers.on_publication_matched =
          callback_on_publication_matched ;
    }

    // dds_listener_set( reinterpret_cast<dds_entity_t>(this->userHandle),
    //           reinterpret_cast<dds_listener_t>(&listener_callback_pointers) ) ;
    this->listener_set( listener, mask, &listener_callback_pointers ) ;
}

template <typename T>
dds::pub::DataWriterListener<T>*
dds::pub::detail::DataWriter<T>::listener() const
{
    return reinterpret_cast<dds::pub::DataWriterListener<T>*>(this->listener_get());
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::close()
{
    org::opensplice::core::ScopedObjectLock scopedLock(*this);

    this->listener(NULL, dds::core::status::StatusMask::none());

    topic_.delegate()->decrNrDependents();

    this->pub_.delegate()->remove_datawriter(*this);

    org::opensplice::pub::AnyDataWriterDelegate::close();

    scopedLock.unlock();
}

template <typename T>
dds::pub::DataWriter<T, dds::pub::detail::DataWriter>
dds::pub::detail::DataWriter<T>::wrapper()
{
    typename DataWriter::ref_type ref =
            OSPL_CXX11_STD_MODULE::dynamic_pointer_cast<DataWriter<T> >(this->get_strong_ref());
    dds::pub::DataWriter<T, dds::pub::detail::DataWriter> writer(ref);

    return writer;
}

template <typename T>
void
dds::pub::detail::DataWriter<T>::listener_notify(
        ObjectDelegate::ref_type source,
        uint32_t                 triggerMask,
        void                    *eventData,
        void                    *l)
{
#if 0
    /* The EntityDelegate takes care of the thread safety and always
     * provides a listener and source. */
    dds::pub::DataWriterListener<T>* listener =
            reinterpret_cast<dds::pub::DataWriterListener<T>*>(l);
    assert(listener);

    /* Get DataWriter wrapper from given source EntityDelegate. */
    typename DataWriter::ref_type ref =
            OSPL_CXX11_STD_MODULE::dynamic_pointer_cast<DataWriter<T> >(source);
    dds::pub::DataWriter<T, dds::pub::detail::DataWriter> writer(ref->wrapper());


    if (triggerMask & V_EVENT_LIVELINESS_LOST) {
        dds::core::status::LivelinessLostStatus status;
        status.delegate().v_status(v_writerStatus(eventData)->livelinessLost);
        listener->on_liveliness_lost(writer, status);
    }

    if (triggerMask & V_EVENT_OFFERED_DEADLINE_MISSED) {
        dds::core::status::OfferedDeadlineMissedStatus status;
        status.delegate().v_status(v_writerStatus(eventData)->deadlineMissed);
        listener->on_offered_deadline_missed(writer, status);
    }

    if (triggerMask & V_EVENT_OFFERED_INCOMPATIBLE_QOS) {
        dds::core::status::OfferedIncompatibleQosStatus status;
        status.delegate().v_status(v_writerStatus(eventData)->incompatibleQos);
        listener->on_offered_incompatible_qos(writer, status);
    }

    if (triggerMask & V_EVENT_PUBLICATION_MATCHED) {
        dds::core::status::PublicationMatchedStatus status;
        status.delegate().v_status(v_writerStatus(eventData)->publicationMatch);
        listener->on_publication_matched(writer, status);
    }
#endif
}

template <typename T>
void dds::pub::detail::DataWriter<T>::on_offered_deadline_missed(
             org::opensplice::core::OfferedDeadlineMissedStatusDelegate &sd )
{
   dds::core::status::OfferedDeadlineMissedStatus s ;
   s.delegate() = sd ;

   dds::pub::DataWriter<T, dds::pub::detail::DataWriter> dw = wrapper() ;

   dds::pub::DataWriterListener<T> *l =
      reinterpret_cast<dds::pub::DataWriterListener<T> *>(this->listener_get());
   if( (l != NULL) &&
       (this->get_listener_mask().to_ulong() &
        dds::core::status::StatusMask::offered_deadline_missed().to_ulong()) )
   {
      l->on_offered_deadline_missed( dw, s ) ;
   }
   else if( (this->publisher().delegate()->listener() != NULL ) &&
            ( this->publisher().delegate()->get_listener_mask().to_ulong() &
              dds::core::status::StatusMask::offered_deadline_missed().
                                                                  to_ulong()) )
   {
      dds::pub::AnyDataWriter adw = dw ;
      this->publisher().delegate()->listener()->
                                       on_offered_deadline_missed( adw, s ) ;
   }
   else
   {
      dds::domain::DomainParticipant dp =
         this->publisher().delegate()->participant() ;
      if( (dp.delegate()->listener() != NULL) &&
          (dp.delegate()->get_listener_mask().to_ulong() &
               dds::core::status::StatusMask::offered_deadline_missed().
                                                                  to_ulong()) )
      {
         dds::pub::AnyDataWriter adw = dw ;
         dp.delegate()->listener()->on_offered_deadline_missed( adw, s ) ;
      }
   }
}

template <typename T>
void dds::pub::detail::DataWriter<T>::on_offered_incompatible_qos(
             org::opensplice::core::OfferedIncompatibleQosStatusDelegate &sd )
{
   dds::core::status::OfferedIncompatibleQosStatus s ;
   s.delegate() = sd ;

   dds::pub::DataWriter<T, dds::pub::detail::DataWriter> dw = wrapper() ;

   dds::pub::DataWriterListener<T> *l =
      reinterpret_cast<dds::pub::DataWriterListener<T> *>(this->listener_get());
   if( (l != NULL) &&
       (this->get_listener_mask().to_ulong() &
        dds::core::status::StatusMask::offered_incompatible_qos().to_ulong()) )
   {
      l->on_offered_incompatible_qos( dw, s ) ;
   }
   else if( (this->publisher().delegate()->listener() != NULL ) &&
            ( this->publisher().delegate()->get_listener_mask().to_ulong() &
              dds::core::status::StatusMask::offered_incompatible_qos().
                                                                  to_ulong()) )
   {
      dds::pub::AnyDataWriter adw = dw ;
      this->publisher().delegate()->listener()->
                                       on_offered_incompatible_qos( adw, s ) ;
   }
   else
   {
      dds::domain::DomainParticipant dp =
         this->publisher().delegate()->participant() ;
      if( (dp.delegate()->listener() != NULL) &&
          (dp.delegate()->get_listener_mask().to_ulong() &
               dds::core::status::StatusMask::offered_incompatible_qos().
                                                                  to_ulong()) )
      {
         dds::pub::AnyDataWriter adw = dw ;
         dp.delegate()->listener()->on_offered_incompatible_qos( adw, s ) ;
      }
   }
}

template <typename T>
void dds::pub::detail::DataWriter<T>::on_liveliness_lost(
             org::opensplice::core::LivelinessLostStatusDelegate &sd )
{
   dds::core::status::LivelinessLostStatus s ;
   s.delegate() = sd ;

   dds::pub::DataWriter<T, dds::pub::detail::DataWriter> dw = wrapper() ;

   dds::pub::DataWriterListener<T> *l =
      reinterpret_cast<dds::pub::DataWriterListener<T> *>(this->listener_get());
   if( (l != NULL) &&
       (this->get_listener_mask().to_ulong() &
        dds::core::status::StatusMask::liveliness_lost().to_ulong()) )
   {
      l->on_liveliness_lost( dw, s ) ;
   }
   else if( (this->publisher().delegate()->listener() != NULL ) &&
            ( this->publisher().delegate()->get_listener_mask().to_ulong() &
              dds::core::status::StatusMask::liveliness_lost().to_ulong()) )
   {
      dds::pub::AnyDataWriter adw = dw ;
      this->publisher().delegate()->listener()->
                                       on_liveliness_lost( adw, s ) ;
   }
   else
   {
      dds::domain::DomainParticipant dp =
         this->publisher().delegate()->participant() ;
      if( (dp.delegate()->listener() != NULL) &&
          (dp.delegate()->get_listener_mask().to_ulong() &
               dds::core::status::StatusMask::liveliness_lost().to_ulong()) )
      {
         dds::pub::AnyDataWriter adw = dw ;
         dp.delegate()->listener()->on_liveliness_lost( adw, s ) ;
      }
   }
}

template <typename T>
void dds::pub::detail::DataWriter<T>::on_publication_matched(
             org::opensplice::core::PublicationMatchedStatusDelegate &sd )
{
   dds::core::status::PublicationMatchedStatus s ;
   s.delegate() = sd ;

   dds::pub::DataWriter<T, dds::pub::detail::DataWriter> dw = wrapper() ;

   dds::pub::DataWriterListener<T> *l =
      reinterpret_cast<dds::pub::DataWriterListener<T> *>(this->listener_get());
   if( (l != NULL) &&
       (this->get_listener_mask().to_ulong() &
        dds::core::status::StatusMask::publication_matched().to_ulong()) )
   {
      l->on_publication_matched( dw, s ) ;
   }
   else if( (this->publisher().delegate()->listener() != NULL ) &&
            ( this->publisher().delegate()->get_listener_mask().to_ulong() &
              dds::core::status::StatusMask::publication_matched().to_ulong()) )
   {
      dds::pub::AnyDataWriter adw = dw ;
      this->publisher().delegate()->listener()->
                                            on_publication_matched( adw, s ) ;
   }
   else
   {
      dds::domain::DomainParticipant dp =
         this->publisher().delegate()->participant() ;
      if( (dp.delegate()->listener() != NULL) &&
          (dp.delegate()->get_listener_mask().to_ulong() &
              dds::core::status::StatusMask::publication_matched().to_ulong()) )
      {
         dds::pub::AnyDataWriter adw = dw ;
         dp.delegate()->listener()->on_publication_matched( adw, s ) ;
      }
   }
}

#endif /* OMG_DDS_PUB_DATA_WRITER_IMPL_HPP_ */
