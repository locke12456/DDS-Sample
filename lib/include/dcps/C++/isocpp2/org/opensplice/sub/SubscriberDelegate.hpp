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


/**
 * @file
 */

#ifndef ORG_OPENSPLICE_SUB_SUBSCRIBER_DELEGATE_HPP_
#define ORG_OPENSPLICE_SUB_SUBSCRIBER_DELEGATE_HPP_

#include <dds/core/types.hpp>
#include <dds/core/status/State.hpp>
#include <dds/sub/qos/SubscriberQos.hpp>
#include <dds/sub/qos/DataReaderQos.hpp>
#include <dds/domain/DomainParticipant.hpp>

#include <org/opensplice/ForwardDeclarations.hpp>
#include <org/opensplice/core/EntityDelegate.hpp>
#include <org/opensplice/core/EntitySet.hpp>
#include <org/opensplice/sub/AnyDataReaderDelegate.hpp>

#include <vector>

namespace org
{
namespace opensplice
{
namespace sub
{

class OMG_DDS_API SubscriberDelegate : public org::opensplice::core::EntityDelegate
{
public:
    typedef ::dds::core::smart_ptr_traits< SubscriberDelegate >::ref_type ref_type;
    typedef ::dds::core::smart_ptr_traits< SubscriberDelegate >::weak_ref_type weak_ref_type;

    SubscriberDelegate(const dds::domain::DomainParticipant& dp,
                       const dds::sub::qos::SubscriberQos& qos,
                       dds::sub::SubscriberListener* listener,
                       const dds::core::status::StatusMask& event_mask);

    virtual ~SubscriberDelegate();

    void init(ObjectDelegate::weak_ref_type weak_ref);

    void close();

    const dds::sub::qos::SubscriberQos& qos() const;
    void qos(const dds::sub::qos::SubscriberQos& sqos);

    void default_datareader_qos(const dds::sub::qos::DataReaderQos& qos);
    dds::sub::qos::DataReaderQos default_datareader_qos() const;

    void begin_coherent_access();
    void end_coherent_access();

    /**
     *  @internal This function initialises the delegate as the built in subscriber
     */
    //void init_builtin(DDS::Subscriber_ptr sub);

    void listener(dds::sub::SubscriberListener* listener,
                  const ::dds::core::status::StatusMask& mask);
    dds::sub::SubscriberListener* listener() const;

    const dds::domain::DomainParticipant& participant() const;

    /** @internal @todo OSPL-1944 Subscriber Listener should return list of affected DataReaders (on_data_on_readers) **/
    //dds::sub::AnyDataReader get_datareaders(); /* TODO: OSPL-1944? */

    bool contains_entity(const ::dds::core::InstanceHandle& handle);

    void add_datareader(org::opensplice::core::EntityDelegate& datareader);
    void remove_datareader(org::opensplice::core::EntityDelegate& datareader);

    virtual std::vector<org::opensplice::sub::AnyDataReaderDelegate::ref_type>
    find_datareaders(const std::string& topic_name);

    std::vector<org::opensplice::sub::AnyDataReaderDelegate::ref_type>
    get_datareaders(const dds::sub::status::DataState& mask);

    void notify_datareaders();

    dds::sub::TSubscriber<SubscriberDelegate>
    wrapper();

    bool is_auto_enable() const;

    virtual void
    listener_notify(ObjectDelegate::ref_type source,
                    uint32_t       triggerMask,
                    void           *eventData,
                    void           *listener);

    void reset_data_on_readers();

private:
    static void
    reset_data_on_readers_callback(v_public p, c_voidp arg);

private:
    dds::domain::DomainParticipant dp_;
    dds::sub::qos::SubscriberQos qos_;
    dds::sub::qos::DataReaderQos default_dr_qos_;

    org::opensplice::core::EntitySet readers;
};

}
}
}

#endif /* ORG_OPENSPLICE_SUB_SUBSCRIBER_DELEGATE_HPP_ */
