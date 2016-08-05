/*
*                         Vortex Lite
*
*   This software and documentation are Copyright 2006 to 2014 PrismTech
*   Limited and its licensees. All rights reserved. See file:
*
*                     $LITE_HOME/LICENSE
*
*   for full copyright notice and license terms.
*
*/


/**
 * @file
 */

#ifndef LITE_CORE_ENTITY_DELEGATE_HPP_
#define LITE_CORE_ENTITY_DELEGATE_HPP_

#include <dds/core/status/State.hpp>
#include <dds/core/InstanceHandle.hpp>
#include <dds/core/policy/CorePolicy.hpp>
#include <org/opensplice/core/UserObjectDelegate.hpp>
#include <org/opensplice/ForwardDeclarations.hpp>
#include <org/opensplice/core/status/StatusDelegate.hpp>

namespace org
{
namespace opensplice
{
namespace core
{

class OMG_DDS_API EntityDelegate :
    public virtual ::org::opensplice::core::UserObjectDelegate
{
public:
    typedef ::dds::core::smart_ptr_traits< EntityDelegate >::ref_type ref_type;
    typedef ::dds::core::smart_ptr_traits< EntityDelegate >::weak_ref_type weak_ref_type;

    EntityDelegate();
    virtual ~EntityDelegate();

    /**
     *  @internal Enables this entity.
     */
    void enable();

    ::dds::core::status::StatusMask status_changes() const;

    ::dds::core::InstanceHandle instance_handle() const;

    bool contains_entity(const ::dds::core::InstanceHandle& handle);

    ObjectDelegate::ref_type get_statusCondition();

    virtual void close();

    virtual void retain();

    /*
     * Listener related functionality.
     */
    void *listener_get() const;

protected:
    /* This will be used to store the listener and listener mask. */
    void
    listener_set(void *listener,
                 const dds::core::status::StatusMask& mask,
                 dds_listener_t callback_pointers);



    void add_c_entity_ref() ;
    void set_c_entity() ;

public:


    const dds::core::status::StatusMask get_listener_mask() const ;

    bool obtain_callback_lock() ;
    void release_callback_lock() ;

    // Topic callback

    virtual void on_inconsistent_topic(
          org::opensplice::core::InconsistentTopicStatusDelegate &) ;


    // Writer callbacks

    virtual void on_offered_deadline_missed(
          org::opensplice::core::OfferedDeadlineMissedStatusDelegate &) ;

    virtual void on_offered_incompatible_qos(
          org::opensplice::core::OfferedIncompatibleQosStatusDelegate &) ;

    virtual void on_liveliness_lost(
          org::opensplice::core::LivelinessLostStatusDelegate &) ;

    virtual void on_publication_matched(
          org::opensplice::core::PublicationMatchedStatusDelegate &) ;


    // Reader callbacks

    virtual void on_requested_deadline_missed(
          org::opensplice::core::RequestedDeadlineMissedStatusDelegate &) ;

    virtual void on_requested_incompatible_qos(
          org::opensplice::core::RequestedIncompatibleQosStatusDelegate &) ;

    virtual void on_sample_rejected(
          org::opensplice::core::SampleRejectedStatusDelegate &) ;

    virtual void on_liveliness_changed(
          org::opensplice::core::LivelinessChangedStatusDelegate &) ;

    virtual void on_data_available() ;

    virtual void on_subscription_matched(
          org::opensplice::core::SubscriptionMatchedStatusDelegate &) ;

    virtual void on_sample_lost(
          org::opensplice::core::SampleLostStatusDelegate &) ;


    // Subscriber callback

    virtual void on_data_readers() ;

public:
    static ObjectDelegate::ref_type extract_strong_ref(dds_entity_t e);

protected:
    static volatile unsigned int entityID_;
    bool enabled_;
    dds::core::status::StatusMask listener_mask;
    void prevent_callbacks() ;
    long callback_count ;

private:
    void *listener;
    ObjectDelegate::weak_ref_type myStatusCondition;
    void *callback_mutex;
    void *callback_cond ;
//    long callback_count ;
    void *listener_callbacks;
};

}
}
}

#endif /* LITE_CORE_ENTITY_DELEGATE_HPP_ */
