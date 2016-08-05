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

#ifndef LITE_SUB_ANY_DATA_READER_DELEGATE_HPP_
#define LITE_SUB_ANY_DATA_READER_DELEGATE_HPP_

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

#include <dds/core/types.hpp>
#include <dds/core/Time.hpp>
#include <dds/core/InstanceHandle.hpp>
#include <dds/core/status/Status.hpp>
#include <dds/sub/status/detail/DataStateImpl.hpp>
#include <dds/sub/qos/DataReaderQos.hpp>
#include <dds/sub/Sample.hpp>
#include <org/opensplice/core/EntityDelegate.hpp>
#include <org/opensplice/topic/TopicTraits.hpp>
#include <org/opensplice/core/ObjectSet.hpp>
#include <org/opensplice/ForwardDeclarations.hpp>
#include <dds/topic/TopicDescription.hpp>

#include <dds/topic/BuiltinTopic.hpp>


namespace dds { namespace sub {
template <typename DELEGATE>
class TAnyDataReader;
} }

namespace org { namespace opensplice { namespace sub {
class QueryContainer;
} } }

namespace dds
{
namespace sub
{
namespace detail
{

class SamplesHolder
{
public:
    SamplesHolder() {}
    virtual ~SamplesHolder() {}

    virtual void set_length(uint32_t len) = 0;
    virtual uint32_t get_length() const = 0;
    virtual SamplesHolder& operator++(int) = 0;
    virtual void *data() = 0;
    virtual detail::SampleInfo* info() = 0;
};

}
}
}



namespace org
{
namespace opensplice
{
namespace sub
{

class QueryDelegate;


class OMG_DDS_API AnyDataReaderDelegate : public org::opensplice::core::EntityDelegate
{
public:
    typedef ::dds::core::smart_ptr_traits< AnyDataReaderDelegate >::ref_type ref_type;
    typedef ::dds::core::smart_ptr_traits< AnyDataReaderDelegate >::weak_ref_type weak_ref_type;

    AnyDataReaderDelegate(const dds::sub::qos::DataReaderQos& qos,
                          const dds::topic::TopicDescription& td);
    virtual ~AnyDataReaderDelegate();

public:
    /* DDS API mirror. */
    dds::sub::qos::DataReaderQos qos() const;
    void qos(const dds::sub::qos::DataReaderQos& qos);

    /* Let DataReader<T> implement the subscriber handling to circumvent circular dependencies. */
    virtual const dds::sub::TSubscriber<org::opensplice::sub::SubscriberDelegate>& subscriber() const = 0;
    const dds::topic::TopicDescription& topic_description() const;

    void wait_for_historical_data(const dds::core::Duration& timeout);

    dds::core::status::LivelinessChangedStatus
    liveliness_changed_status();
    dds::core::status::SampleRejectedStatus
    sample_rejected_status();
    dds::core::status::SampleLostStatus
    sample_lost_status();
    dds::core::status::RequestedDeadlineMissedStatus
    requested_deadline_missed_status();
    dds::core::status::RequestedIncompatibleQosStatus
    requested_incompatible_qos_status();
    dds::core::status::SubscriptionMatchedStatus
    subscription_matched_status();

    ::dds::core::InstanceHandleSeq
     matched_publications();

    template <typename FwdIterator>
    uint32_t
    matched_publications(FwdIterator begin, uint32_t max_size)
    {
        ::dds::core::InstanceHandleSeq handleSeq = matched_publications();
        uint32_t size = (handleSeq.size() < max_size ? handleSeq.size() : max_size);
        for (uint32_t i = 0; i < size; i++, begin++) {
            *begin = handleSeq[i];
        }
        return size;
    }

    const dds::topic::PublicationBuiltinTopicData
    matched_publication_data(const ::dds::core::InstanceHandle& h);

public:
    /* Internal API. */
    dds::sub::TAnyDataReader<AnyDataReaderDelegate> wrapper_to_any();

    static uint32_t getUserMask(const dds::sub::status::DataState& state);

    void reset_data_available();

    void add_query(org::opensplice::sub::QueryDelegate& query);
    void remove_query(org::opensplice::sub::QueryDelegate& query);

    inline void setCopyIn(org::opensplice::topic::copyInFunction copyIn)
    {
        this->copyIn = copyIn;
    }

    inline org::opensplice::topic::copyInFunction getCopyIn() const
    {
        return this->copyIn;
    }

    void setCopyOut(org::opensplice::topic::copyOutFunction copyOut)
    {
        this->copyOut = copyOut;
    }

    inline org::opensplice::topic::copyOutFunction getCopyOut() const
    {
        return this->copyOut;
    }

    void setSample(void* sample);
    void* getSample() const;


    void read(
            const dds_entity_t reader, const dds::sub::status::DataState& mask,
            dds::sub::detail::SamplesHolder& samples, uint32_t max_samples, const dds_condition_t cond=0 );

    void take(
            const dds_entity_t reader, const dds::sub::status::DataState& mask,
            dds::sub::detail::SamplesHolder& samples, uint32_t max_samples, const dds_condition_t cond=0);

    void read_instance(
            const dds_entity_t reader, const dds::core::InstanceHandle& handle,
            const dds::sub::status::DataState& mask, dds::sub::detail::SamplesHolder& samples, uint32_t max_samples);

    void take_instance(
            const dds_entity_t reader, const dds::core::InstanceHandle& handle,
            const dds::sub::status::DataState& mask, dds::sub::detail::SamplesHolder& samples, uint32_t max_samples);

#if 0
    void read_next_instance(
            const dds_entity_t reader, const dds::core::InstanceHandle& handle,
            const dds::sub::status::DataState& mask, dds::sub::detail::SamplesHolder& samples, uint32_t max_samples);

    void take_next_instance(
            const dds_entity_t reader, const dds::core::InstanceHandle& handle,
            const dds::sub::status::DataState& mask, dds::sub::detail::SamplesHolder& samples, uint32_t max_samples);

    void read_instance_w_condition(
             const u_query query, const dds::core::InstanceHandle& handle,
             dds::sub::detail::SamplesHolder& samples, uint32_t max_samples);

    void take_instance_w_condition(
             const u_query query, const dds::core::InstanceHandle& handle,
             dds::sub::detail::SamplesHolder& samples, uint32_t max_samples);

    void read_next_instance_w_condition(
            const u_query query, const dds::core::InstanceHandle& handle,
            dds::sub::detail::SamplesHolder& samples, uint32_t max_samples);

    void take_next_instance_w_condition(
            const u_query query, const dds::core::InstanceHandle& handle,
            dds::sub::detail::SamplesHolder& samples, uint32_t max_samples);
#endif

    void get_key_value(
            const dds_entity_t reader,
            const dds::core::InstanceHandle& handle, void *key);

    dds_instance_handle_t lookup_instance(
            const dds_entity_t reader, const void *key) const;

    void close();

    void listener_set(void *listener,
                      const dds::core::status::StatusMask& mask) ;
    void merge_from_sub() ;

private:
#if 0
    static void
    reset_data_available_callback(v_public p, c_voidp arg);
#endif

private:
    uint32_t init_samples(uint32_t requested_max_samples,
                          void**& c_sample_pointers, dds_sample_info_t*& c_sample_infos);
    void copy_samples(dds::sub::detail::SamplesHolder& samples,
                      void**& c_sample_pointers, dds_sample_info_t*& c_sample_infos,
                      dds_entity_t uReader, int num_read, uint32_t max_samples);
    static void copy_sample_info(dds_sample_info_t &from, dds::sub::SampleInfo *to);
#if 0
    typedef struct FlushActionArguments {
        AnyDataReaderDelegate& reader;
        dds::sub::detail::SamplesHolder& samples;
    } FlushActionArguments;
    static void flush_action(void *sample, cmn_sampleInfo sampleInfo, void *args);
    static void copy_key(c_type t, const void *data, void *to);
#endif

    dds_readerlistener_t listener_callback_pointers ;

protected:
    org::opensplice::topic::copyInFunction  copyIn;
    org::opensplice::topic::copyOutFunction copyOut;
    org::opensplice::core::ObjectSet queries;
    dds::sub::qos::DataReaderQos qos_;
    int32_t historyDepth_;
    dds::topic::TopicDescription td_;

    void *sample_;

};


}
}
}

#endif /* LITE_SUB_ANY_DATA_READER_DELEGATE_HPP_ */
