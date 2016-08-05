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

#ifndef ORG_OPENSPLICE_CORE_QOSPROVIDERDELEGATE_HPP_
#define ORG_OPENSPLICE_CORE_QOSPROVIDERDELEGATE_HPP_

#include <dds/domain/qos/DomainParticipantQos.hpp>
#include <dds/topic/qos/TopicQos.hpp>
#include <dds/sub/qos/SubscriberQos.hpp>
#include <dds/sub/qos/DataReaderQos.hpp>
#include <dds/pub/qos/PublisherQos.hpp>
#include <dds/pub/qos/DataWriterQos.hpp>

#include "c_typebase.h"

C_CLASS(cmn_qosProvider);
C_CLASS(cmn_qosProviderInputAttr);

namespace org
{
namespace opensplice
{
namespace core
{
class QosProviderDelegate;
}
}
}

class OMG_DDS_API org::opensplice::core::QosProviderDelegate
{
public:
    QosProviderDelegate(const std::string& uri, const std::string& id = "");

    ~QosProviderDelegate();

    dds::domain::qos::DomainParticipantQos
    participant_qos(const char* id);

    dds::topic::qos::TopicQos
    topic_qos(const char* id);

    dds::sub::qos::SubscriberQos
    subscriber_qos(const char* id);

    dds::sub::qos::DataReaderQos
    datareader_qos(const char* id);

    dds::pub::qos::PublisherQos
    publisher_qos(const char* id);

    dds::pub::qos::DataWriterQos
    datawriter_qos(const char* id);

private:
    template <typename FROM, typename TO>
    static void named_qos__copyOut(void *from, void *to);

    cmn_qosProvider qosProvider;
    static const C_STRUCT(cmn_qosProviderInputAttr) qosProviderAttr;
};

#endif /* ORG_OPENSPLICE_CORE_QOSPROVIDERDELEGATE_HPP_ */
