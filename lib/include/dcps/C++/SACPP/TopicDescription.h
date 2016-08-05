/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2012 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */
#ifndef CPP_DDS_OPENSPLICE_TOPICDESCRIPTION_H
#define CPP_DDS_OPENSPLICE_TOPICDESCRIPTION_H

#include "CppSuperClass.h"
#include "DomainParticipant.h"
#include "cpp_dcps_if.h"

/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

namespace DDS
{
    namespace OpenSplice
    {
        // Forward declarations
        class TypeSupportMetaHolder;
        class DataReader;
        class DataWriter;
        class ContentFilteredTopic;

        class OS_API TopicDescription :
              public virtual ::DDS::TopicDescription,
              public virtual ::DDS::OpenSplice::CppSuperClassInterface
        {
            friend class ::DDS::OpenSplice::DomainParticipant;
            friend class ::DDS::OpenSplice::Subscriber;
            friend class ::DDS::OpenSplice::Publisher;
            friend class ::DDS::OpenSplice::ContentFilteredTopic;
            friend class ::DDS::OpenSplice::DataReader;

        private:
            ::DDS::String_var topic_name;
            ::DDS::String_var type_name;
            ::DDS::String_var expression;
            ::DDS::OpenSplice::TypeSupportMetaHolder *tsMetaHolder;
            ::DDS::Long nrUsers;

        protected:
            ::DDS::OpenSplice::DomainParticipant  *participant;

            TopicDescription();

            virtual ~TopicDescription();

            ::DDS::ReturnCode_t
            nlReq_init(
                    ::DDS::OpenSplice::DomainParticipant *participant,
                    const ::DDS::Char *topic_name,
                    const ::DDS::Char *type_name,
                    const ::DDS::Char *expression,
                    ::DDS::OpenSplice::TypeSupportMetaHolder *ts_meta_holder);

            virtual ::DDS::ReturnCode_t
            wlReq_deinit();

            /* This will acquire the TypeSupportFactory from the Participant first, when needed. */
            virtual ::DDS::OpenSplice::TypeSupportMetaHolder *
            get_typesupport_meta_holder ();

            virtual const char *
            rlReq_get_topic_expression ();

            virtual void
            wlReq_incrNrUsers();

            virtual void
            wlReq_decrNrUsers();

            virtual ::DDS::Long
            rlReq_getNrUsers();

            virtual const char *
            rlReq_getName();

        public:
            virtual char *
            get_type_name (
            ) THROW_ORB_EXCEPTIONS;

            virtual char *
            get_name (
            ) THROW_ORB_EXCEPTIONS;

            virtual ::DDS::DomainParticipant_ptr
            get_participant (
            ) THROW_ORB_EXCEPTIONS;
        }; /* class TopicDescription */
    } /* namespace OpenSplice */
} /* namespace DDS */

#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_TOPICDESCRIPTION_H */
