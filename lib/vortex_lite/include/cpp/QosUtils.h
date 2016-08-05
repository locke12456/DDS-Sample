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
#ifndef DDS_OPENSPLICE_QOSUTILS_H
#define DDS_OPENSPLICE_QOSUTILS_H

#include "ccpp.h"
#include "cpp_dcps_if.h"

namespace DDS {
namespace OpenSplice {
namespace Utils {

// Default QoS

struct OS_API FactoryDefaultQosHolder
{
  static const DDS::DataReaderQos * get_dataReaderQos_default();
  static const DDS::DataReaderQos * get_dataReaderQos_use_topic();
  static const DDS::DataWriterQos * get_dataWriterQos_default();
  static const DDS::DataWriterQos * get_dataWriterQos_use_topic();
  static const DDS::DomainParticipantQos * get_domainParticipantQos_default();
  static const DDS::PublisherQos * get_publisherQos_default();
  static const DDS::SubscriberQos * get_subscriberQos_default();
  static const DDS::TopicQos * get_topicQos_default();
};
 
// QoS conversions

OS_API void copyQosIn (const DDS::DataReaderQos        &from, dds_qos_t &to);
OS_API void copyQosIn (const DDS::DataWriterQos        &from, dds_qos_t &to);
OS_API void copyQosIn (const DDS::DomainParticipantQos &from, dds_qos_t &to);
OS_API void copyQosIn (const DDS::PublisherQos         &from, dds_qos_t &to);
OS_API void copyQosIn (const DDS::SubscriberQos        &from, dds_qos_t &to);
OS_API void copyQosIn (const DDS::TopicQos             &from, dds_qos_t &to);

OS_API void copyQosOut (const dds_qos_t &from, DDS::DataReaderQos        &to);
OS_API void copyQosOut (const dds_qos_t &from, DDS::DataWriterQos        &to);
OS_API void copyQosOut (const dds_qos_t &from, DDS::DomainParticipantQos &to);
OS_API void copyQosOut (const dds_qos_t &from, DDS::PublisherQos         &to);
OS_API void copyQosOut (const dds_qos_t &from, DDS::SubscriberQos        &to);
OS_API void copyQosOut (const dds_qos_t &from, DDS::TopicQos             &to);

} /* end namespace Utils */
} /* end namespace OpenSplice */
} /* end namespace DDS */

#undef OS_API
#endif /* DDS_OPENSPLICE_QOSUTILS_H */
