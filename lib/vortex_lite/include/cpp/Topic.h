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
#ifndef CPP_DDS_OPENSPLICE_TOPIC_H
#define CPP_DDS_OPENSPLICE_TOPIC_H

#include "Entity.h"
#include "TopicDescription.h"
#include "cpp_dcps_if.h"

/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

namespace DDS
{
    namespace OpenSplice
    {
        DDS::Boolean
        set_topic_listener_mask (
            DDS::Object_ptr element,
            void *arg);

        class Publisher;

        class OS_API Topic
            : public virtual ::DDS::Topic,
              public ::DDS::OpenSplice::Entity,
              public ::DDS::OpenSplice::TopicDescription

        {
            friend class ::DDS::OpenSplice::DomainParticipant;
            friend class ::DDS::OpenSplice::Publisher;
            friend class ::DDS::OpenSplice::DataWriter;
            friend class ::DDS::OpenSplice::DataReader;
            friend DDS::Boolean DDS::OpenSplice::set_topic_listener_mask (DDS::Object_ptr element, void *arg);

        private:
            DDS::StatusMask topicListenerInterest;
            DDS::StatusMask participantListenerInterest;

        protected:
            Topic();

            virtual ~Topic();

            ::DDS::ReturnCode_t
            virtual init(
//                    const u_topic uTopic,
                    const dds_entity_t uTopic,
                    DDS::OpenSplice::DomainParticipant *participant,
                    const DDS::Char *topic_name,
                    const DDS::Char *type_name,
                    DDS::OpenSplice::TypeSupportMetaHolder *type_meta_holder);

            ::DDS::ReturnCode_t
            nlReq_init (
//                    const u_topic uTopic,
                    const dds_entity_t uTopic,
                    DDS::OpenSplice::DomainParticipant *participant,
                    const DDS::Char *topic_name,
                    const DDS::Char *type_name,
                    DDS::OpenSplice::TypeSupportMetaHolder *type_meta_holder);

            virtual ::DDS::ReturnCode_t
            wlReq_deinit();

            DDS::ReturnCode_t
            set_participant_listener_mask (
                    ::DDS::StatusMask mask
            ) THROW_ORB_EXCEPTIONS;

        public:
            virtual ::DDS::ReturnCode_t
            get_inconsistent_topic_status (
                    ::DDS::InconsistentTopicStatus & a_status
            ) THROW_ORB_EXCEPTIONS;

            virtual ::DDS::ReturnCode_t
            get_qos (
                    ::DDS::TopicQos & qos
            ) THROW_ORB_EXCEPTIONS;

            virtual ::DDS::ReturnCode_t
            set_qos (
                    const ::DDS::TopicQos & qos
            ) THROW_ORB_EXCEPTIONS;

            virtual ::DDS::TopicListener_ptr
            get_listener (
            ) THROW_ORB_EXCEPTIONS;

            virtual ::DDS::ReturnCode_t
            set_listener (
                    ::DDS::TopicListener_ptr a_listener,
                    ::DDS::StatusMask mask
            ) THROW_ORB_EXCEPTIONS;

            virtual ::DDS::ReturnCode_t
            set_filter (
                    ::DDS::Topic::Filter_fn filter
            ) THROW_ORB_EXCEPTIONS;

            virtual ::DDS::ReturnCode_t
            get_filter (
                    ::DDS::Topic::Filter_fn &filter
            ) THROW_ORB_EXCEPTIONS;

          private:
            Filter_fn cpp_filter;
            static bool trans_filter (const void *csample, void *ctx);
        }; /* class Topic */
    }; /* namespace OpenSplice */
}; /* namespace DDS */

#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_TOPIC_H */
