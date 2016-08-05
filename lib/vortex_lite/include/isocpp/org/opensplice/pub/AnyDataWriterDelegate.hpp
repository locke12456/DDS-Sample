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


/**
 * @file
 */

#ifndef LITE_PUB_ANYDATAWRITERDELEGATE_HPP_
#define LITE_PUB_ANYDATAWRITERDELEGATE_HPP_

#include <dds/core/types.hpp>
#include <dds/core/Time.hpp>
#include <dds/core/InstanceHandle.hpp>
#include <dds/core/status/Status.hpp>
#include <dds/pub/qos/DataWriterQos.hpp>
#include <org/opensplice/topic/TopicTraits.hpp>
#include <org/opensplice/core/EntityDelegate.hpp>
#include <dds/topic/TopicDescription.hpp>
#include <dds/topic/BuiltinTopic.hpp>


namespace dds { namespace pub {
template <typename DELEGATE>
class TAnyDataWriter;
} }


namespace org
{
namespace opensplice
{
namespace pub
{

class OMG_DDS_API AnyDataWriterDelegate : public org::opensplice::core::EntityDelegate
{
public:
    typedef ::dds::core::smart_ptr_traits< AnyDataWriterDelegate >::ref_type ref_type;
    typedef ::dds::core::smart_ptr_traits< AnyDataWriterDelegate >::weak_ref_type weak_ref_type;

    virtual ~AnyDataWriterDelegate();

    void close();

public:
    /* DDS API mirror. */
    dds::pub::qos::DataWriterQos qos() const;
    void qos(const dds::pub::qos::DataWriterQos& qos);

    /* Let DataWriter<T> implement the publisher handling to circumvent circular dependencies. */
    virtual const dds::pub::TPublisher<org::opensplice::pub::PublisherDelegate>& publisher() const = 0;

    const dds::topic::TopicDescription& topic_description() const;

    void wait_for_acknowledgments(const dds::core::Duration& timeout);

    const ::dds::core::status::LivelinessLostStatus liveliness_lost_status();

    const ::dds::core::status::OfferedDeadlineMissedStatus offered_deadline_missed_status();

    const ::dds::core::status::OfferedIncompatibleQosStatus offered_incompatible_qos_status();

    const ::dds::core::status::PublicationMatchedStatus publication_matched_status();

    ::dds::core::InstanceHandleSeq
    matched_subscriptions();

    template <typename FwdIterator>
    uint32_t
    matched_subscriptions(FwdIterator begin, uint32_t max_size)
    {
        ::dds::core::InstanceHandleSeq handleSeq = matched_subscriptions();
        uint32_t size = (handleSeq.size() < max_size ? handleSeq.size() : max_size);
        for (uint32_t i = 0; i < size; i++, begin++) {
            *begin = handleSeq[i];
        }
        return size;
    }

    const dds::topic::SubscriptionBuiltinTopicData
    matched_subscription_data(const ::dds::core::InstanceHandle& h);

    void assert_liveliness();

public:
    dds::pub::TAnyDataWriter<AnyDataWriterDelegate> wrapper_to_any();
    void write_flush();
    void set_batch(bool);

protected:
    AnyDataWriterDelegate(const dds::pub::qos::DataWriterQos& qos,
                          const dds::topic::TopicDescription& td);


    inline void setCopyIn(org::opensplice::topic::copyInFunction copyIn)
    {
        this->copyIn = copyIn;
    }

    inline org::opensplice::topic::copyInFunction getCopyIn()
    {
        return this->copyIn;
    }

    inline void setCopyOut(org::opensplice::topic::copyOutFunction copyOut)
    {
        this->copyOut = copyOut;
    }

    inline org::opensplice::topic::copyOutFunction getCopyOut()
    {
        return this->copyOut;
    }

    void
    write(dds_entity_t writer,
          const void *data,
          const dds::core::InstanceHandle& handle,
          const dds::core::Time& timestamp);

    void
    writedispose(dds_entity_t writer,
                 const void *data,
                 const dds::core::InstanceHandle& handle,
                 const dds::core::Time& timestamp);

    dds_instance_handle_t
    register_instance(dds_entity_t writer,
                      const void *data,
                      const dds::core::Time& timestamp);

    void
    unregister_instance(dds_entity_t writer,
                        const dds::core::InstanceHandle& handle,
                        const dds::core::Time& timestamp);

    void
    unregister_instance(dds_entity_t writer,
                        const void *data,
                        const dds::core::Time& timestamp);

    void
    dispose_instance(dds_entity_t writer,
                     const dds::core::InstanceHandle& handle,
                     const dds::core::Time& timestamp);

    void
    dispose_instance(dds_entity_t writer,
                     const void *data,
                     const dds::core::Time& timestamp);

    void
    get_key_value(dds_entity_t writer,
                  void *data,
                  const dds::core::InstanceHandle& handle);

    dds_instance_handle_t
    lookup_instance(dds_entity_t writer,
                    const void *data);

private:
    org::opensplice::topic::copyInFunction  copyIn;
    org::opensplice::topic::copyOutFunction copyOut;
    dds::pub::qos::DataWriterQos qos_;
    dds::topic::TopicDescription td_;

    //@todo static bool copy_data(c_type t, void *data, void *to);
};

}
}
}

#endif /* LITE_PUB_ANYDATAWRITERDELEGATE_HPP_ */
