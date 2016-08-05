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
#ifndef CPP_DDS_OPENSPLICE_DATAREADER_H
#define CPP_DDS_OPENSPLICE_DATAREADER_H

#include "Entity.h"
#include "EntityContainer.h"
#include "Topic.h"
#include "TopicDescription.h"
#include "Subscriber.h"
#include "TypeSupportMetaHolder.h"
#include "cpp_dcps_if.h"

namespace DDS {
    namespace OpenSplice {

        class Subscriber;
        class ReadCondition;
        class QueryCondition;

        class OS_API DataReader :
            public virtual DDS::DataReader,
            public ::DDS::OpenSplice::EntityContainer,
            public ::DDS::OpenSplice::Entity
        {
            friend class ::DDS::OpenSplice::Subscriber;
            friend class ::DDS::OpenSplice::ReadCondition;
            friend class ::DDS::OpenSplice::QueryCondition;

        protected:
            DataReader ();
            virtual ~DataReader ();

            virtual DDS::ReturnCode_t
            init (
                DDS::OpenSplice::Subscriber *subscriber,
                const DDS::DataReaderQos &qos,
                DDS::OpenSplice::TopicDescription *a_topic,
                const char *name,
                DDS::OpenSplice::cxxCopyIn copyIn,
                DDS::OpenSplice::cxxCopyOut copyOut,
                DDS::OpenSplice::cxxCopyOutSeq copyOutSeq) = 0;

            DDS::ReturnCode_t
            nlReq_init (
                DDS::OpenSplice::Subscriber *subscriber,
                const DDS::DataReaderQos &qos,
                DDS::OpenSplice::TopicDescription *a_topic,
                const char *name);

            virtual DDS::ReturnCode_t
            wlReq_deinit ();

            DDS::Long historydepth ;

        public:
            DDS::ReadCondition_ptr
            create_readcondition (
                SampleStateMask sample_states,
                ViewStateMask view_states,
                InstanceStateMask instance_states
            ) THROW_ORB_EXCEPTIONS;

            DDS::QueryCondition_ptr
            create_querycondition (
                SampleStateMask sample_states,
                ViewStateMask view_states,
                InstanceStateMask instance_states,
                const char* query_expression,
                const StringSeq& query_parameters
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            delete_readcondition (
                ReadCondition_ptr a_condition);

            DDS::ReturnCode_t
            delete_contained_entities (
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            set_qos (
                const DataReaderQos& qos
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_qos (
                DataReaderQos& qos
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            set_listener (
                DataReaderListener_ptr a_listener,
                StatusMask mask
            ) THROW_ORB_EXCEPTIONS;

            DDS::DataReaderListener_ptr
            get_listener (
            ) THROW_ORB_EXCEPTIONS;

            DDS::TopicDescription_ptr
            get_topicdescription (
            ) THROW_ORB_EXCEPTIONS;

            DDS::Subscriber_ptr
            get_subscriber (
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_sample_rejected_status (
                SampleRejectedStatus& status
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_liveliness_changed_status (
                LivelinessChangedStatus& status
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_requested_deadline_missed_status (
                RequestedDeadlineMissedStatus& status
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_requested_incompatible_qos_status (
                RequestedIncompatibleQosStatus& status
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_subscription_matched_status (
                SubscriptionMatchedStatus& status
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_sample_lost_status (
                SampleLostStatus& status
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            wait_for_historical_data (
                const Duration_t& max_wait
            ) THROW_ORB_EXCEPTIONS;

            virtual DDS::ReturnCode_t
            wait_for_historical_data_w_condition (
                const char *,
                const DDS::StringSeq &,
                const DDS::Time_t &,
                const DDS::Time_t &,
                const DDS::ResourceLimitsQosPolicy &,
                const DDS::Duration_t &
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_matched_publications (
                InstanceHandleSeq &publication_handles
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_matched_publication_data (
                PublicationBuiltinTopicData &publication_data,
                InstanceHandle_t publication_handle
            ) THROW_ORB_EXCEPTIONS;

        private:
            DDS::OpenSplice::TopicDescription *
            get_topic ();

            static DDS::ReturnCode_t
            deinit_condition (
                DDS::OpenSplice::ReadCondition * view);

            struct Implementation;
            Implementation *pimpl;
        }; /* class DataReader */
    }; /* namespace OpenSplice */
}; /* namespace DDS */

#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_DATAREADER_H */
