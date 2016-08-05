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
#ifndef LITE_DDS_TOPIC_TTOPIC_HPP_
#define LITE_DDS_TOPIC_TTOPIC_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/topic/TTopic.hpp>
#include "org/opensplice/topic/TopicTraits.hpp"
#include "org/opensplice/topic/TopicListener.hpp"

// Implementation

namespace dds
{
namespace topic
{


/***************************************************************************
 *
 * dds/topic/Topic<> WRAPPER implementation.
 * Declaration can be found in dds/topic/TTopic.hpp
 *
 ***************************************************************************/


template <typename T, template <typename Q> class DELEGATE>
Topic<T, DELEGATE>::Topic(const dds::domain::DomainParticipant& dp,
                          const std::string& topic_name) :
      ::dds::core::Reference< DELEGATE<T> >(new DELEGATE<T>(
              dp,
              topic_name,
              "",
              dp.default_topic_qos(),
              NULL,
              dds::core::status::StatusMask::none()))
{
    this->delegate()->init(this->impl_);
}

template <typename T, template <typename Q> class DELEGATE>
Topic<T, DELEGATE>::Topic(const dds::domain::DomainParticipant& dp,
                          const std::string& topic_name,
                          const std::string& type_name) :
      ::dds::core::Reference< DELEGATE<T> >(new DELEGATE<T>(
              dp,
              topic_name,
              type_name,
              dp.default_topic_qos(),
              NULL,
              dds::core::status::StatusMask::none())),
      ::dds::topic::TAnyTopic< DELEGATE<T> >(::dds::core::Reference< DELEGATE<T>  >::delegate())
{
    this->delegate()->init(this->impl_);
}

template <typename T, template <typename Q> class DELEGATE>
Topic<T, DELEGATE>::Topic(const dds::domain::DomainParticipant& dp,
                          const std::string& topic_name,
                          const dds::topic::qos::TopicQos& qos,
                          dds::topic::TopicListener<T>* listener,
                          const dds::core::status::StatusMask& mask) :
      ::dds::core::Reference< DELEGATE<T> >(new DELEGATE<T>(
              dp,
              topic_name,
              "",
              qos,
              listener,
              mask)),
      ::dds::topic::TAnyTopic< DELEGATE<T> >(::dds::core::Reference< DELEGATE<T>  >::delegate())
{
    this->delegate()->init(this->impl_);
}

template <typename T, template <typename Q> class DELEGATE>
Topic<T, DELEGATE>::Topic(const dds::domain::DomainParticipant& dp,
                          const std::string& topic_name,
                          const std::string& type_name,
                          const dds::topic::qos::TopicQos& qos,
                          dds::topic::TopicListener<T>* listener,
                          const dds::core::status::StatusMask& mask) :
      ::dds::core::Reference< DELEGATE<T> >(new DELEGATE<T>(
              dp,
              topic_name,
              type_name,
              qos,
              listener,
              mask)),
      ::dds::topic::TAnyTopic< DELEGATE<T> >(::dds::core::Reference< DELEGATE<T>  >::delegate())
{
    this->delegate()->init(this->impl_);
}

template <typename T, template <typename Q> class DELEGATE>
Topic<T, DELEGATE>::~Topic() { }

/** @internal  @todo Relates to OMG_DDS_X_TYPE_DYNAMIC_TYPE_SUPPORT OSPL-1736 no implementation */
template <typename T, template <typename Q> class DELEGATE>
void Topic<T, DELEGATE>::listener(Listener* listener,
                                  const ::dds::core::status::StatusMask& event_mask)
{
    this->delegate()->listener(listener, event_mask);
}

/** @internal @todo Relates to OMG_DDS_X_TYPE_DYNAMIC_TYPE_SUPPORT OSPL-1736 no implementation */
template <typename T, template <typename Q> class DELEGATE>
typename Topic<T, DELEGATE>::Listener* Topic<T, DELEGATE>::listener() const
{
    return this->delegate()->listener();
}


}
}




/***************************************************************************
 *
 * dds/topic/detail/Topic<> DELEGATE implementation.
 * Declaration can be found in dds/topic/detail/Topic.hpp
 *
 * Implementation and declaration have been separated because some circular
 * dependencies, like with TopicListener and AnyTopic.
 *
 ***************************************************************************/

#include <dds/topic/detail/Topic.hpp>
#include <dds/topic/AnyTopic.hpp>
#include <dds/topic/TopicListener.hpp>
//#include <dds/domain/DomainParticipantListener.hpp>
#include <org/opensplice/core/ScopedLock.hpp>
#include <org/opensplice/core/ListenerDispatcher.hpp>

template <typename T>
dds::topic::detail::Topic<T>::Topic(const dds::domain::DomainParticipant& dp,
      const std::string& name,
      const std::string& type_name,
      const dds::topic::qos::TopicQos& qos,
      dds::topic::TopicListener<T>* listener,
      const dds::core::status::StatusMask& mask)
    : org::opensplice::topic::TopicDescriptionDelegate(dp, name, type_name),
      org::opensplice::topic::AnyTopicDelegate(qos, dp, name, type_name)
{
    // Set the correct (IDL) type_name in the TopicDescription.
    org::opensplice::topic::TopicDescriptionDelegate::myTypeName = org::opensplice::topic::TopicTraits<T>::getTypeName();

    // get and validate the kernel qos
    org::opensplice::topic::qos::TopicQosDelegate tQos = qos.delegate();
    tQos.check();
    dds_qos_t* uTopicQos = tQos.u_qos();
    dds_entity_t uParticipant = (dds_entity_t)dp.delegate()->get_user_handle();

    dds_entity_t uTopic;
    int result = dds_topic_create(
            uParticipant,
            &uTopic,
            org::opensplice::topic::TopicTraits<T>::getDescriptor(),
            name.c_str(),
            uTopicQos,
            NULL);

    dds_qos_delete(uTopicQos);

    if (result) {
        ISOCPP_THROW_EXCEPTION(ISOCPP_ERROR, "Failed to create Topic");
    }

    this->userHandle = (void*)uTopic;
    this->listener(listener, mask);

    this->set_c_entity();

    this->AnyTopicDelegate::set_copy_out(org::opensplice::topic::TopicTraits<T>::getCopyOut());
    this->AnyTopicDelegate::set_sample(&this->sample_);
}

template <typename T>
dds::topic::detail::Topic<T>::Topic(const dds::domain::DomainParticipant& dp,
      const std::string& name,
      const std::string& type_name,
      const dds::topic::qos::TopicQos& qos,
      dds_entity_t uTopic)
    : org::opensplice::topic::TopicDescriptionDelegate(dp, name, type_name),
      org::opensplice::topic::AnyTopicDelegate(qos, dp, name, type_name)
{
    this->userHandle = (void*)uTopic;
    this->listener(NULL, dds::core::status::StatusMask::none());

    this->add_c_entity_ref();
    this->set_c_entity() ;

    this->AnyTopicDelegate::set_copy_out(org::opensplice::topic::TopicTraits<T>::getCopyOut());
    this->AnyTopicDelegate::set_sample(&this->sample_);
}


template <typename T>
dds::topic::detail::Topic<T>::~Topic()
{
    if (!closed) {
        try {
            close();
        } catch (...) {

        }
    }
}

template <typename T>
void
dds::topic::detail::Topic<T>::close()
{
    org::opensplice::core::ScopedObjectLock scopedLock(*this);

    if (this->hasDependents()) {
        ISOCPP_THROW_EXCEPTION(ISOCPP_PRECONDITION_NOT_MET_ERROR, "Topic still has unclosed dependencies (e.g. Readers/Writers/ContentFilteredTopics)");
    }

    this->listener(NULL, dds::core::status::StatusMask::none());

    this->myParticipant.delegate()->remove_topic(*this);

    org::opensplice::core::EntityDelegate::close();
}

template <typename T>
void
dds::topic::detail::Topic<T>::init(ObjectDelegate::weak_ref_type weak_ref)
{
    /* Set weak_ref before passing ourselves to other isocpp objects. */
    this->set_weak_ref(weak_ref);
    /* Register topic at participant. */
    this->myParticipant.delegate()->add_topic(*this);

    /* Enable when needed. */
    if (this->myParticipant.delegate()->is_auto_enable()) {
        this->enable();
    }
}

template <typename T>
void
dds::topic::detail::Topic<T>::listener(TopicListener<T>* listener,
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
   merged_mask =
         this->listener_mask.to_ulong() |
         this->myParticipant.delegate()->get_listener_mask().to_ulong() ;
   
   memset( &(this->listener_callback_pointers),
           0,
           sizeof(dds_topiclistener_t) ) ; 

    if( merged_mask &
        dds::core::status::StatusMask::inconsistent_topic().to_ulong() )
    {
       listener_callback_pointers.on_inconsistent_topic =
          callback_on_inconsistent_topic ;
    }

    this->listener_set( listener, mask, &listener_callback_pointers ) ;
}

template <typename T>
dds::topic::TopicListener<T>*
dds::topic::detail::Topic<T>::listener()
{
    return reinterpret_cast<dds::topic::TopicListener<T>*>(this->listener_get());
}

template <typename T>
dds::topic::Topic<T, dds::topic::detail::Topic>
dds::topic::detail::Topic<T>::wrapper()
{

    typename Topic::ref_type ref =
            OSPL_CXX11_STD_MODULE::dynamic_pointer_cast<Topic<T> >(this->get_strong_ref());
    dds::topic::Topic<T, dds::topic::detail::Topic> topic(ref);

    return topic;
}

template <typename T>
void
dds::topic::detail::Topic<T>::listener_notify(
        ObjectDelegate::ref_type source,
        uint32_t                 triggerMask,
        void                    *eventData,
        void                    *l)
{
#if 0
    /* The EntityDelegate takes care of the thread safety and always
     * provides a listener and source. */
    dds::topic::TopicListener<T>* listener =
            reinterpret_cast<dds::topic::TopicListener<T>*>(l);
    assert(listener);

    /* Get Topic wrapper from given source EntityDelegate. */
    typename Topic::ref_type ref =
            OSPL_CXX11_STD_MODULE::dynamic_pointer_cast<Topic<T> >(source);
    dds::topic::Topic<T, dds::topic::detail::Topic> topic(ref->wrapper());

    if (triggerMask & V_EVENT_INCONSISTENT_TOPIC) {
        dds::core::status::InconsistentTopicStatus status;
        status.delegate().v_status(v_topicStatus(eventData)->inconsistentTopic);
        listener->on_inconsistent_topic(topic, status);
    }

    if (triggerMask & V_EVENT_ALL_DATA_DISPOSED ) {
        org::opensplice::topic::TopicListener<T>* extListener =
                  dynamic_cast<org::opensplice::topic::TopicListener<T>*>(listener);
        if (extListener) {
            org::opensplice::core::status::AllDataDisposedTopicStatus status;
            status.delegate().v_status(v_topicStatus(eventData)->allDataDisposed);
            extListener->on_all_data_disposed(topic, status);
        }
    }
#endif
}

template <typename T>
dds::topic::Topic<T, dds::topic::detail::Topic>
dds::topic::detail::Topic<T>::discover_topic(
        const dds::domain::DomainParticipant& dp,
        const std::string& name,
        const dds::core::Duration& timeout)
{
    dds_entity_t uTopic = dp.delegate()->lookup_topic(name, timeout);

    if (uTopic == NULL) {
        return dds::core::null;
    }

    char *uTypename = dds_topic_get_type_name(uTopic);
    std::string type_name = uTypename;
    dds_free(uTypename);

    dds_qos_t* uQos = dds_qos_create();
    dds_qos_get(uTopic, uQos);

    dds::topic::qos::TopicQos qos;
    qos.delegate().u_qos(uQos);
    dds_free(uQos);

    typename dds::topic::Topic<T, dds::topic::detail::Topic>::DELEGATE_REF_T ref(new Topic<T>(dp, name, type_name, qos, uTopic));
    ref->init(ref);

    return dds::topic::Topic<T>(ref);
}

template <typename T>
void
dds::topic::detail::Topic<T>::discover_topics(
        const dds::domain::DomainParticipant& dp,
        std::vector<dds::topic::Topic<T, dds::topic::detail::Topic> >& topics,
        uint32_t max_size)
{
#if 0
    std::vector<u_topic> uTopics;

    dp.delegate()->lookup_topics(topic_type_name<T>::value(), uTopics, max_size);

    topics.clear();
    topics.reserve(uTopics.size());

    for (std::vector<u_topic>::const_iterator it = uTopics.begin(); it != uTopics.end(); ++it) {
        u_topic uTopic = *it;
        os_char *topic_name = u_topicName(uTopic);
        os_char *type_name = u_topicTypeName(uTopic);

        u_topicQos uQos;
        u_result uResult = u_topicGetQos(uTopic, &uQos);
        ISOCPP_U_RESULT_CHECK_AND_THROW(uResult, "Failed to get user layer topic qos");

        dds::topic::qos::TopicQos qos;
        qos.delegate().u_qos(uQos);
        u_topicQosFree(uQos);

        typename dds::topic::Topic<T, dds::topic::detail::Topic>::DELEGATE_REF_T ref(new Topic<T>(dp, topic_name, type_name, qos, uTopic));
        ref->init(ref);

        os_free(topic_name);
        os_free(type_name);

        topics.push_back(dds::topic::Topic<T>(ref));
    }
#endif
}



#if 0
template <typename T>
dds::topic::TTopicDescription<org::opensplice::topic::TopicDescriptionDelegate>
dds::topic::detail::Topic<T>::clone()
{
    org::opensplice::core::ScopedObjectLock scopedLock(*this);

    typename dds::topic::Topic<T, Topic>::DELEGATE_REF_T ref(
            new Topic<T>(this->myParticipant, this->myTopicName,
                         this->myTypeName, this->qos_, NULL, dds::core::status::StatusMask::none()));
    ref->init(ref);

    return dds::topic::Topic<T, Topic>(ref);
}
#endif



OMG_DDS_API void avoid_include_errors( dds::domain::DomainParticipant &dp,
                           dds::topic::AnyTopic &at,
                           dds::core::status::InconsistentTopicStatus &s ) ;

template <typename T>
void dds::topic::detail::Topic<T>::on_inconsistent_topic(
           org::opensplice::core::InconsistentTopicStatusDelegate &sd )
{
   dds::core::status::InconsistentTopicStatus s ;
   s.delegate() = sd ;

   dds::topic::Topic<T, dds::topic::detail::Topic> t = wrapper() ;

   dds::topic::TopicListener<T> *l =
      reinterpret_cast<dds::topic::TopicListener<T> *>(this->listener_get());
   if( (l != NULL) &&
       (this->get_listener_mask().to_ulong() &
             dds::core::status::StatusMask::inconsistent_topic().to_ulong()) )
   {
      l->on_inconsistent_topic( t, s ) ;
   }
   else
   {
      dds::domain::DomainParticipant dp = this->myParticipant ;
      if( (dp.delegate()->listener() != NULL) &&
          (dp.delegate()->get_listener_mask().to_ulong() &
             dds::core::status::StatusMask::inconsistent_topic().to_ulong()) )
      {
         dds::topic::AnyTopic at = t ;

         // If you do this:
         //    dp.delegate()->listener()->on_inconsistent_topic( at, s );
         // you have to do this:
         //     #include <dds/domain/DomainParticipantListener.hpp>
         // which produces intractable compile errors, possibly to do with
         // circular inclusion. So do this instead:
         avoid_include_errors( dp, at, s ) ;
      }
   }
}

// End of implementation

#endif /* LITE_DDS_TOPIC_TTOPIC_HPP_ */
