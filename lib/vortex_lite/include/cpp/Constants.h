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

#ifndef CONTANTS_H_
#define CONTANTS_H_

#include "ccpp.h"
#include "DomainParticipantFactory.h"
#include "QosUtils.h"
#include "cpp_dcps_if.h"

#define TheParticipantFactory               (::DDS::DomainParticipantFactory::get_instance())

#define PARTICIPANT_QOS_DEFAULT             (*::DDS::OpenSplice::Utils::FactoryDefaultQosHolder::get_domainParticipantQos_default())
#define TOPIC_QOS_DEFAULT                   (*::DDS::OpenSplice::Utils::FactoryDefaultQosHolder::get_topicQos_default())
#define PUBLISHER_QOS_DEFAULT               (*::DDS::OpenSplice::Utils::FactoryDefaultQosHolder::get_publisherQos_default())
#define SUBSCRIBER_QOS_DEFAULT              (*::DDS::OpenSplice::Utils::FactoryDefaultQosHolder::get_subscriberQos_default())
#define DATAWRITER_QOS_DEFAULT              (*::DDS::OpenSplice::Utils::FactoryDefaultQosHolder::get_dataWriterQos_default())
#define DATAREADER_QOS_DEFAULT              (*::DDS::OpenSplice::Utils::FactoryDefaultQosHolder::get_dataReaderQos_default())
#define DATAWRITER_QOS_USE_TOPIC_QOS        (*::DDS::OpenSplice::Utils::FactoryDefaultQosHolder::get_dataWriterQos_use_topic())
#define DATAREADER_QOS_USE_TOPIC_QOS        (*::DDS::OpenSplice::Utils::FactoryDefaultQosHolder::get_dataReaderQos_use_topic())

namespace DDS
{
  OS_API extern const ::DDS::Duration_t DURATION_ZERO;
  OS_API extern const ::DDS::Duration_t DURATION_INFINITE;

  OS_API extern const ::DDS::Time_t TIMESTAMP_INVALID;
  OS_API extern const ::DDS::Time_t TIMESTAMP_CURRENT;

  // Note: ANY_STATUS is deprecated, please use spec version specific constants.
  OS_API extern const ::DDS::StatusKind ANY_STATUS;
  // STATUS_MASK_ANY_V1_2 is all standardised status bits as of V1.2 of the
  // specification.
  OS_API extern const ::DDS::StatusKind STATUS_MASK_ANY_V1_2;
  OS_API extern const ::DDS::StatusKind STATUS_MASK_NONE;
}
#undef OS_API


#endif /* CONTANTS_H_ */
