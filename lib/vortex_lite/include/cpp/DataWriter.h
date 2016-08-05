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
#ifndef CPP_DDS_OPENSPLICE_DATAWRITER_H
#define CPP_DDS_OPENSPLICE_DATAWRITER_H

#include "Entity.h"
#include "Publisher.h"
#include "TypeSupportMetaHolder.h"
#include "cpp_dcps_if.h"

namespace DDS {
    namespace OpenSplice {

        class Publisher;

        class OS_API DataWriter
            : public virtual DDS::DataWriter,
              public DDS::OpenSplice::Entity
        {
            friend class ::DDS::OpenSplice::Publisher;

        private:
            DDS::OpenSplice::Publisher *publisher;
            DDS::OpenSplice::Topic *topic;


        protected:
            DataWriter ();

            virtual ~DataWriter ();

            virtual DDS::ReturnCode_t
            init(
                DDS::OpenSplice::Publisher *publisher,
                DDS::OpenSplice::DomainParticipant *participant,
                const DDS::DataWriterQos &qos,
                DDS::OpenSplice::Topic *a_topic,
                const char *name,
                DDS::OpenSplice::cxxCopyIn copyIn,
                DDS::OpenSplice::cxxCopyOut copyOut,
                DDS::OpenSplice::cxxCopyOutSeq copyOutSeq) = 0;

            DDS::ReturnCode_t
            nlReq_init(
                DDS::OpenSplice::Publisher *publisher,
                const DDS::DataWriterQos &qos,
                DDS::OpenSplice::Topic *a_topic,
                const char *name);

            virtual DDS::ReturnCode_t
            wlReq_deinit();

        public:
            DDS::ReturnCode_t
            set_qos (
                const DataWriterQos &qos
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_qos (
                DDS::DataWriterQos &qos
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            set_listener (
                DDS::DataWriterListener_ptr a_listener,
                DDS::StatusMask mask
            ) THROW_ORB_EXCEPTIONS;

            DDS::DataWriterListener_ptr
            get_listener (
            ) THROW_ORB_EXCEPTIONS;

            DDS::Topic_ptr
            get_topic (
            ) THROW_ORB_EXCEPTIONS;

            DDS::Publisher_ptr
            get_publisher (
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            wait_for_acknowledgments (
                const Duration_t &max_wait
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_liveliness_lost_status (
                LivelinessLostStatus &status
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_offered_deadline_missed_status (
                OfferedDeadlineMissedStatus &status
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_offered_incompatible_qos_status (
                OfferedIncompatibleQosStatus &status
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_publication_matched_status (
                PublicationMatchedStatus &status
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            assert_liveliness (
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_matched_subscriptions (
                InstanceHandleSeq& subscription_handles
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_matched_subscription_data (
                SubscriptionBuiltinTopicData &subscription_data,
                InstanceHandle_t subscription_handle
            ) THROW_ORB_EXCEPTIONS;

            void
            write_flush () THROW_ORB_EXCEPTIONS;

            void
            set_batch (
                 DDS::Boolean enable
            ) THROW_ORB_EXCEPTIONS;

        }; /* class Publisher */
    }; /* namespace OpenSplice */
}; /* namespace DDS */

#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_DATAWRITER_H */
