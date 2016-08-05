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
#ifndef CPP_DDS_OPENSPLICE_CONTENTFILTEREDTOPIC_H
#define CPP_DDS_OPENSPLICE_CONTENTFILTEREDTOPIC_H

#include "CppSuperClass.h"
#include "TopicDescription.h"
#include "Topic.h"
#include "cpp_dcps_if.h"

/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

namespace DDS
{
    namespace OpenSplice
    {
        /* TODO: This is just a mock class; implement properly. */
        class OS_API ContentFilteredTopic
            : public virtual ::DDS::ContentFilteredTopic,
              public ::DDS::OpenSplice::CppSuperClass,
              public ::DDS::OpenSplice::TopicDescription

        {
            friend class ::DDS::OpenSplice::DomainParticipant;
            friend class ::DDS::OpenSplice::DataReader;

        protected:
            DDS::OpenSplice::Topic *relatedTopic;
            DDS::String_var filterExpression;
            DDS::StringSeq filterParameters;

            ContentFilteredTopic();

            virtual ~ContentFilteredTopic();

            DDS::ReturnCode_t
            virtual init(
                    DDS::OpenSplice::DomainParticipant *participant,
                    const DDS::Char *topic_name,
                    DDS::OpenSplice::Topic *related_topic,
                    const DDS::Char *filter_expression,
                    const DDS::StringSeq &filter_parameters);

            DDS::ReturnCode_t nlReq_init(
                    DDS::OpenSplice::DomainParticipant *participant,
                    const DDS::Char *topic_name,
                    DDS::OpenSplice::Topic *related_topic,
                    const DDS::Char *filter_expression,
                    const DDS::StringSeq &filter_parameters);

            virtual DDS::ReturnCode_t wlReq_deinit();

        public:
            virtual char *
            get_filter_expression (
            ) THROW_ORB_EXCEPTIONS;

            virtual ::DDS::ReturnCode_t
            get_expression_parameters (
              ::DDS::StringSeq & expression_parameters
            ) THROW_ORB_EXCEPTIONS;

            virtual ::DDS::ReturnCode_t
            set_expression_parameters (
              const ::DDS::StringSeq & expression_parameters
            ) THROW_ORB_EXCEPTIONS;

            virtual ::DDS::Topic_ptr
            get_related_topic (
            ) THROW_ORB_EXCEPTIONS;

        }; /* class ContentFilteredTopic */
    }; /* namespace OpenSplice */
}; /* namespace DDS */

#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_CONTENTFILTEREDTOPIC_H */
