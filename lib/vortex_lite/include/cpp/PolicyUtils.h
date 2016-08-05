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
#ifndef DDS_OPENSPLICE_POLICYUTILS_H
#define DDS_OPENSPLICE_POLICYUTILS_H

#include "ccpp.h"

namespace DDS {
namespace OpenSplice {
namespace Utils {

extern const DDS::DeadlineQosPolicy            DeadlineQosPolicy_default;
extern const DDS::DestinationOrderQosPolicy    DestinationOrderQosPolicy_default;
extern const DDS::DurabilityServiceQosPolicy   DurabilityServiceQosPolicy_default;
extern const DDS::DurabilityQosPolicy          DurabilityQosPolicy_default;
extern const DDS::GroupDataQosPolicy           GroupDataQosPolicy_default;
extern const DDS::HistoryQosPolicy             HistoryQosPolicy_default;
extern const DDS::LatencyBudgetQosPolicy       LatencyBudgetQosPolicy_default;
extern const DDS::LifespanQosPolicy            LifespanQosPolicy_default;
extern const DDS::LivelinessQosPolicy          LivelinessQosPolicy_default;
extern const DDS::OwnershipStrengthQosPolicy   OwnershipStrengthQosPolicy_default;
extern const DDS::OwnershipQosPolicy           OwnershipQosPolicy_default;
extern const DDS::PartitionQosPolicy           PartitionQosPolicy_default;
extern const DDS::PresentationQosPolicy        PresentationQosPolicy_default;
extern const DDS::ReaderDataLifecycleQosPolicy ReaderDataLifecycleQosPolicy_default;
extern const DDS::ReliabilityQosPolicy         ReliabilityQosPolicy_default;
extern const DDS::ReliabilityQosPolicy         ReliabilityQosPolicy_writerDefault;
extern const DDS::ResourceLimitsQosPolicy      ResourceLimitsQosPolicy_default;
extern const DDS::TransportPriorityQosPolicy   TransportPriorityQosPolicy_default;
extern const DDS::TimeBasedFilterQosPolicy     TimeBasedFilterQosPolicy_default;
extern const DDS::TopicDataQosPolicy           TopicDataQosPolicy_default;
extern const DDS::UserDataQosPolicy            UserDataQosPolicy_default;
extern const DDS::WriterDataLifecycleQosPolicy WriterDataLifecycleQosPolicy_default;

// Policy conversions

void copyPolicyIn (const DDS::DeadlineQosPolicy            &from, dds_qos_t &to);
void copyPolicyIn (const DDS::DestinationOrderQosPolicy    &from, dds_qos_t &to);
void copyPolicyIn (const DDS::DurabilityQosPolicy          &from, dds_qos_t &to);
void copyPolicyIn (const DDS::DurabilityServiceQosPolicy   &from, dds_qos_t &to);
void copyPolicyIn (const DDS::GroupDataQosPolicy           &from, dds_qos_t &to);
void copyPolicyIn (const DDS::HistoryQosPolicy             &from, dds_qos_t &to);
void copyPolicyIn (const DDS::LatencyBudgetQosPolicy       &from, dds_qos_t &to);
void copyPolicyIn (const DDS::LifespanQosPolicy            &from, dds_qos_t &to);
void copyPolicyIn (const DDS::LivelinessQosPolicy          &from, dds_qos_t &to);
void copyPolicyIn (const DDS::OwnershipQosPolicy           &from, dds_qos_t &to);
void copyPolicyIn (const DDS::OwnershipStrengthQosPolicy   &from, dds_qos_t &to);
void copyPolicyIn (const DDS::PartitionQosPolicy           &from, dds_qos_t &to);
void copyPolicyIn (const DDS::PresentationQosPolicy        &from, dds_qos_t &to);
void copyPolicyIn (const DDS::ReaderDataLifecycleQosPolicy &from, dds_qos_t &to);
void copyPolicyIn (const DDS::ReliabilityQosPolicy         &from, dds_qos_t &to);
void copyPolicyIn (const DDS::ResourceLimitsQosPolicy      &from, dds_qos_t &to);
void copyPolicyIn (const DDS::TimeBasedFilterQosPolicy     &from, dds_qos_t &to);
void copyPolicyIn (const DDS::TopicDataQosPolicy           &from, dds_qos_t &to);
void copyPolicyIn (const DDS::TransportPriorityQosPolicy   &from, dds_qos_t &to);
void copyPolicyIn (const DDS::UserDataQosPolicy            &from, dds_qos_t &to);
void copyPolicyIn (const DDS::WriterDataLifecycleQosPolicy &from, dds_qos_t &to);

void copyPolicyOut (const dds_qos_t &from, DDS::DeadlineQosPolicy            &to);
void copyPolicyOut (const dds_qos_t &from, DDS::DestinationOrderQosPolicy    &to);
void copyPolicyOut (const dds_qos_t &from, DDS::DurabilityQosPolicy          &to);
void copyPolicyOut (const dds_qos_t &from, DDS::DurabilityServiceQosPolicy   &to);
void copyPolicyOut (const dds_qos_t &from, DDS::GroupDataQosPolicy           &to);
void copyPolicyOut (const dds_qos_t &from, DDS::HistoryQosPolicy             &to);
void copyPolicyOut (const dds_qos_t &from, DDS::LatencyBudgetQosPolicy       &to);
void copyPolicyOut (const dds_qos_t &from, DDS::LifespanQosPolicy            &to);
void copyPolicyOut (const dds_qos_t &from, DDS::LivelinessQosPolicy          &to);
void copyPolicyOut (const dds_qos_t &from, DDS::OwnershipQosPolicy           &to);
void copyPolicyOut (const dds_qos_t &from, DDS::OwnershipStrengthQosPolicy   &to);
void copyPolicyOut (const dds_qos_t &from, DDS::PartitionQosPolicy           &to);
void copyPolicyOut (const dds_qos_t &from, DDS::PresentationQosPolicy        &to);
void copyPolicyOut (const dds_qos_t &from, DDS::ReaderDataLifecycleQosPolicy &to);
void copyPolicyOut (const dds_qos_t &from, DDS::ReliabilityQosPolicy         &to);
void copyPolicyOut (const dds_qos_t &from, DDS::ResourceLimitsQosPolicy      &to);
void copyPolicyOut (const dds_qos_t &from, DDS::TimeBasedFilterQosPolicy     &to);
void copyPolicyOut (const dds_qos_t &from, DDS::TopicDataQosPolicy           &to);
void copyPolicyOut (const dds_qos_t &from, DDS::TransportPriorityQosPolicy   &to);
void copyPolicyOut (const dds_qos_t &from, DDS::UserDataQosPolicy            &to);
void copyPolicyOut (const dds_qos_t &from, DDS::WriterDataLifecycleQosPolicy &to);

} /* end namespace Utils */
} /* end namespace OpenSplice */
} /* end namespace DDS */

#endif /* DDS_OPENSPLICE_POLICYUTILS_H */
