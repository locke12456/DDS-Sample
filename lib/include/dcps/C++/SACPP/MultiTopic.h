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
#ifndef CPP_DDS_OPENSPLICE_MULTITOPIC_H
#define CPP_DDS_OPENSPLICE_MULTITOPIC_H

#include "CppSuperClass.h"
#include "TopicDescription.h"
#include "cpp_dcps_if.h"

/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

namespace DDS
{
    namespace OpenSplice
    {
        /* TODO: This is just a mock class; implement properly. */
        class OS_API MultiTopic
            : public virtual ::DDS::MultiTopic,
              public ::DDS::OpenSplice::CppSuperClass,
              public ::DDS::OpenSplice::TopicDescription
        {
            friend class ::DDS::OpenSplice::DomainParticipant;

        protected:
            MultiTopic();

            virtual ~MultiTopic();

            ::DDS::ReturnCode_t
            virtual init(
                    DDS::OpenSplice::DomainParticipant *participant,
                    const DDS::Char *topic_name,
                    const DDS::Char *type_name,
                    const DDS::Char *subscription_expression,
                    const DDS::StringSeq &expression_parameters);

            ::DDS::ReturnCode_t
            nlReq_init(
                    DDS::OpenSplice::DomainParticipant *participant,
                    const DDS::Char *topic_name,
                    const DDS::Char *type_name,
                    const DDS::Char *subscription_expression,
                    const DDS::StringSeq &expression_parameters);

            virtual ::DDS::ReturnCode_t
            wlReq_deinit();

        public:
            virtual char * get_subscription_expression (
            ) THROW_ORB_EXCEPTIONS;

            virtual ::DDS::ReturnCode_t get_expression_parameters (
                    ::DDS::StringSeq & expression_parameters
            ) THROW_ORB_EXCEPTIONS;

            virtual ::DDS::ReturnCode_t set_expression_parameters (
                    const ::DDS::StringSeq & expression_parameters
            ) THROW_ORB_EXCEPTIONS;

        }; /* class MultiTopic */
    }; /* namespace OpenSplice */
}; /* namespace DDS */

#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_MULTITOPIC_H */
