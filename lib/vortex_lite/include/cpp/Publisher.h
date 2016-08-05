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
#ifndef CPP_DDS_OPENSPLICE_PUBLISHER_H
#define CPP_DDS_OPENSPLICE_PUBLISHER_H

#include "DomainParticipant.h"
#include "EntityContainer.h"
#include "Entity.h"
#include "Topic.h"
#include "DataWriter.h"
#include "cpp_dcps_if.h"

/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

namespace DDS
{
    namespace OpenSplice
    {
        class OS_API Publisher
            : public virtual DDS::Publisher,
              public ::DDS::OpenSplice::EntityContainer,
              public DDS::OpenSplice::Entity
        {
            friend class DDS::OpenSplice::DomainParticipant;
            friend class DDS::OpenSplice::DataWriter;
            friend class ::DDS::PublisherListener ;

        private:
            DDS::OpenSplice::DomainParticipant *participant;
            DDS::DataWriterQos defaultWriterQos;
            DDS::OpenSplice::ObjSet *writers;

            char *
            create_datawriter_name (
                DDS::OpenSplice::Topic *topic);

            DDS::Boolean
            wlReq_insertWriter(
                    DDS::OpenSplice::DataWriter *writer);

            DDS::Boolean
            wlReq_removeWriter(
                    DDS::OpenSplice::DataWriter *writer);

            typedef struct {
                const char *topicName;
                DDS::OpenSplice::DataWriter *writer;
            } lookupByTopicArg;

            static DDS::Boolean
            rlReq_lookupByTopic (
                DDS::Object_ptr element,
                lookupByTopicArg *arg);

            static DDS::Boolean
            rlReq_writerCheckHandle (
                DDS::Object_ptr object,
                DDS::InstanceHandle_t *argHandle);

        protected:
            Publisher();

            virtual ~Publisher();

            virtual DDS::ReturnCode_t
            init (
                DDS::OpenSplice::DomainParticipant *participant,
                const DDS::Char *name,
                const DDS::PublisherQos &qos
            );

            DDS::ReturnCode_t
            nlReq_init (
                DDS::OpenSplice::DomainParticipant *participant,
                const DDS::Char *name,
                const DDS::PublisherQos &qos
            );

            virtual DDS::ReturnCode_t
            wlReq_deinit();

        public:
            DDS::DataWriter_ptr
            create_datawriter (
                DDS::Topic_ptr a_topic,
                const DDS::DataWriterQos &qos,
                DDS::DataWriterListener_ptr a_listener,
                DDS::StatusMask mask
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            delete_datawriter (
                DDS::DataWriter_ptr a_datawriter
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            delete_contained_entities (
            ) THROW_ORB_EXCEPTIONS;

            DDS::DataWriter_ptr
            lookup_datawriter (
                const char *topic_name
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            set_qos (
                const DDS::PublisherQos &qos
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_qos (
                DDS::PublisherQos &qos
            ) THROW_ORB_EXCEPTIONS;

            DDS::PublisherListener_ptr
            get_listener (
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            set_listener (
                DDS::PublisherListener_ptr a_listener,
                DDS::StatusMask mask
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            suspend_publications (
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            resume_publications (
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            begin_coherent_changes (
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            end_coherent_changes (
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            wait_for_acknowledgments (
                const ::DDS::Duration_t &max_wait
            ) THROW_ORB_EXCEPTIONS;

            DDS::DomainParticipant_ptr
            get_participant (
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            set_default_datawriter_qos (
                const ::DDS::DataWriterQos &qos
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            get_default_datawriter_qos (
                DDS::DataWriterQos &qos
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            copy_from_topic_qos (
                DDS::DataWriterQos &a_datawriter_qos,
                const ::DDS::TopicQos &a_topic_qos
            ) THROW_ORB_EXCEPTIONS;

            DDS::Boolean
            contains_entity (
                DDS::InstanceHandle_t a_handle
            ) THROW_ORB_EXCEPTIONS;

        }; /* class Publisher */
    }; /* namespace OpenSplice */
}; /* namespace DDS */

#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_PUBLISHER_H */
