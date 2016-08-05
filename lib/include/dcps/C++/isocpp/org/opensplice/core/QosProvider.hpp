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

#ifndef ORG_OPENSPLICE_CORE_QOSPROVIDER_HPP_
#define ORG_OPENSPLICE_CORE_QOSPROVIDER_HPP_

#include <org/opensplice/core/config.hpp>

C_CLASS(cmn_qosProvider);
C_CLASS(cmn_qosProviderInputAttr);

namespace org
{
namespace opensplice
{
namespace core
{
class QosProvider;
}
}
}

class OSPL_ISOCPP_IMPL_API org::opensplice::core::QosProvider
{
public:
    explicit QosProvider(const std::string& uri);

    explicit QosProvider(const std::string& uri, const std::string& id);

    ~QosProvider();

    dds::domain::qos::DomainParticipantQos
    participant_qos();

    dds::domain::qos::DomainParticipantQos
    participant_qos(const std::string& id);

    dds::topic::qos::TopicQos
    topic_qos();

    dds::topic::qos::TopicQos
    topic_qos(const std::string& id);

    dds::sub::qos::SubscriberQos
    subscriber_qos();

    dds::sub::qos::SubscriberQos
    subscriber_qos(const std::string& id);

    dds::sub::qos::DataReaderQos
    datareader_qos();

    dds::sub::qos::DataReaderQos
    datareader_qos(const std::string& id);

    dds::pub::qos::PublisherQos
    publisher_qos();

    dds::pub::qos::PublisherQos
    publisher_qos(const std::string& id);

    dds::pub::qos::DataWriterQos
    datawriter_qos();

    dds::pub::qos::DataWriterQos
    datawriter_qos(const std::string& id);

    private:
    cmn_qosProvider qosProvider;

    const C_STRUCT(cmn_qosProviderInputAttr) * getQosProviderInputAttr();
};

#endif /* ORG_OPENSPLICE_CORE_QOSPROVIDER_HPP_ */
