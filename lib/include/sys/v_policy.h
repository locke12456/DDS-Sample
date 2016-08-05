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
#ifndef V_POLICY_H
#define V_POLICY_H

#include "kernelModuleI.h"

#if defined (__cplusplus)
extern "C" {
#endif

#include "os_if.h"
#include "v_kernel.h"

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

#define V_POLICY_BIT_USERDATA          (0x00000001U << V_USERDATAPOLICY_ID)
#define V_POLICY_BIT_DURABILITY        (0x00000001U << V_DURABILITYPOLICY_ID)
#define V_POLICY_BIT_DURABILITYSERVICE (0x00000001U << V_DURABILITYSERVICEPOLICY_ID)
#define V_POLICY_BIT_PRESENTATION      (0x00000001U << V_PRESENTATIONPOLICY_ID)
#define V_POLICY_BIT_DEADLINE          (0x00000001U << V_DEADLINEPOLICY_ID)
#define V_POLICY_BIT_LATENCY           (0x00000001U << V_LATENCYPOLICY_ID)
#define V_POLICY_BIT_OWNERSHIP         (0x00000001U << V_OWNERSHIPPOLICY_ID)
#define V_POLICY_BIT_STRENGTH          (0x00000001U << V_STRENGTHPOLICY_ID)
#define V_POLICY_BIT_LIVELINESS        (0x00000001U << V_LIVELINESSPOLICY_ID)
#define V_POLICY_BIT_PACING            (0x00000001U << V_PACINGPOLICY_ID)
#define V_POLICY_BIT_PARTITION         (0x00000001U << V_PARTITIONPOLICY_ID)
#define V_POLICY_BIT_RELIABILITY       (0x00000001U << V_RELIABILITYPOLICY_ID)
#define V_POLICY_BIT_ORDERBY           (0x00000001U << V_ORDERBYPOLICY_ID)
#define V_POLICY_BIT_HISTORY           (0x00000001U << V_HISTORYPOLICY_ID)
#define V_POLICY_BIT_RESOURCE          (0x00000001U << V_RESOURCEPOLICY_ID)
#define V_POLICY_BIT_ENTITYFACTORY     (0x00000001U << V_ENTITYFACTORYPOLICY_ID)
#define V_POLICY_BIT_WRITERLIFECYCLE   (0x00000001U << V_WRITERLIFECYCLEPOLICY_ID)
#define V_POLICY_BIT_READERLIFECYCLE   (0x00000001U << V_READERLIFECYCLEPOLICY_ID)
#define V_POLICY_BIT_TOPICDATA         (0x00000001U << V_TOPICDATAPOLICY_ID)
#define V_POLICY_BIT_GROUPDATA         (0x00000001U << V_GROUPDATAPOLICY_ID)
#define V_POLICY_BIT_TRANSPORT         (0x00000001U << V_TRANSPORTPOLICY_ID)
#define V_POLICY_BIT_LIFESPAN          (0x00000001U << V_LIFESPANPOLICY_ID)
#define V_POLICY_BIT_USERKEY           (0x00000001U << V_USERKEYPOLICY_ID)
#define V_POLICY_BIT_SHARE             (0x00000001U << V_SHAREPOLICY_ID)
#define V_POLICY_BIT_READERLIFESPAN    (0x00000001U << V_READERLIFESPANPOLICY_ID)
#define V_POLICY_BIT_SCHEDULING        (0x00000001U << V_SCHEDULINGPOLICY_ID)

  /*********************************************
   *** policy compatibility: external variant
   *********************************************/

#define v_reliabilityPolicyCompatible(offered, requested)\
    ((offered).kind >= (requested).kind)

#define v_reliabilityPolicyEqual(p1,p2)\
    (((p1).kind == (p2).kind) &&\
     ((p1).synchronous == (p2).synchronous) && \
     (c_timeCompare((p1).max_blocking_time,(p2).max_blocking_time) == C_EQ))

#define v_reliabilityPolicyValid(p)\
    (((p).kind == V_RELIABILITY_BESTEFFORT) ||\
     (((p).kind == V_RELIABILITY_RELIABLE) && c_timeValid((p).max_blocking_time)))
/* The construction above only checks max_blocking_time when the kind
   is RELIABLE */

#define v_durabilityPolicyCompatible(offered,requested)\
    (offered.kind >= requested.kind)

#define v_durabilityPolicyEqual(p1,p2)\
    ((p1).kind == (p2).kind)

#define v_durabilityPolicyValid(p)\
    (((p).kind == V_DURABILITY_VOLATILE) ||\
     ((p).kind == V_DURABILITY_TRANSIENT_LOCAL) ||\
     ((p).kind == V_DURABILITY_TRANSIENT) ||\
     ((p).kind == V_DURABILITY_PERSISTENT))

/* The construction used for v_durabilityPolicyValid only checks
   service_cleanup_delay when kind is not VOLATILE */
#define v_durabilityServicePolicyEqual(p1,p2)\
     ((c_timeCompare((p1).service_cleanup_delay, (p2).service_cleanup_delay) == C_EQ) && \
      ((p1).history_kind == (p2).history_kind) &&\
      ((p1).history_kind ==  V_HISTORY_KEEPALL ? TRUE : ((p1).history_depth == (p2).history_depth)) &&\
      ((p1).max_samples == (p2).max_samples) &&\
      ((p1).max_instances == (p2).max_instances) &&\
      ((p1).max_samples_per_instance == (p2).max_samples_per_instance))

#define v_durabilityServicePolicyValid(p)\
    ((((p).max_samples == V_LENGTH_UNLIMITED) ||\
      ((p).max_samples > 0)) &&\
     (((p).max_instances == V_LENGTH_UNLIMITED) ||\
      ((p).max_instances > 0)) &&\
     (((p).max_samples_per_instance == V_LENGTH_UNLIMITED) ||\
      ((p).max_samples_per_instance > 0)) &&\
     (((p).history_kind == V_HISTORY_KEEPLAST) ||\
      ((p).history_kind == V_HISTORY_KEEPALL)) &&\
     (((p).history_depth == V_LENGTH_UNLIMITED) ||\
      ((p).history_depth > 0)) &&\
       c_timeValid((p).service_cleanup_delay))

#define v_presentationPolicyCompatible(offered,requested)\
    ((offered.access_scope >= requested.access_scope) && \
     ((requested.coherent_access == FALSE) || \
      (offered.coherent_access == requested.coherent_access)) &&\
     ((requested.ordered_access == FALSE) || \
      (offered.ordered_access == requested.ordered_access)))

#define v_presentationPolicyEqual(p1,p2)\
    (((p1).access_scope == (p2).access_scope) &&\
     ((p1).coherent_access == (p2).coherent_access) &&\
     ((p1).ordered_access == (p2).ordered_access))

#define v_presentationPolicyValid(p)\
    ((((p).access_scope == V_PRESENTATION_INSTANCE) ||\
      ((p).access_scope == V_PRESENTATION_TOPIC) ||\
      ((p).access_scope == V_PRESENTATION_GROUP)) &&\
     (((p).coherent_access == TRUE) || ((p).coherent_access == FALSE)) &&\
     (((p).ordered_access == TRUE) || ((p).ordered_access == FALSE)))

/* offered <= requested
 * Take account for INFINITE
 */
#define v_latencyPolicyCompatible(offered,requested)\
    ((c_timeCompare(requested.duration, C_TIME_INFINITE) == C_EQ) ||\
     (c_timeCompare(offered.duration,requested.duration) != C_GT)) /* <= */

#define v_latencyPolicyEqual(p1,p2)\
    (c_timeCompare((p1).duration,(p2).duration) == C_EQ)

#define v_latencyPolicyValid(p)\
    (c_timeValid((p).duration))

#define v_orderbyPolicyCompatible(offered,requested)\
    (offered.kind >= requested.kind)

#define v_orderbyPolicyEqual(p1,p2)\
    ((p1).kind == (p2).kind)

#define v_orderbyPolicyValid(p)\
    (((p).kind == V_ORDERBY_RECEPTIONTIME) ||\
     ((p).kind == V_ORDERBY_SOURCETIME))

/* offered <= requested
 * Take account for INFINITE
 */
#define v_deadlinePolicyCompatible(offered,requested)\
    ((c_timeCompare(requested.period, C_TIME_INFINITE) == C_EQ) ||\
     (c_timeCompare(offered.period, requested.period) != C_GT)) /* <= */

#define v_deadlinePolicyEqual(p1,p2)\
    (c_timeCompare((p1).period, (p2).period) == C_EQ)

#define v_deadlinePolicyValid(p)\
    (c_timeValid((p).period))

/* offered <= requested
 * Take account for INFINITE
 */
#define v_livelinessPolicyCompatible(offered,requested)\
    ((offered.kind >= requested.kind) &&\
     ((c_timeCompare(requested.lease_duration, C_TIME_INFINITE) == C_EQ) ||\
      (c_timeCompare(offered.lease_duration,requested.lease_duration) != C_GT))) /* <= */

#define v_livelinessPolicyEqual(p1,p2)\
    (((p1).kind == (p2).kind) &&\
     (c_timeCompare((p1).lease_duration,(p2).lease_duration) == C_EQ))

#define v_livelinessPolicyValid(p)\
    ((((p).kind == V_LIVELINESS_AUTOMATIC) ||\
      ((p).kind == V_LIVELINESS_PARTICIPANT) ||\
      ((p).kind == V_LIVELINESS_TOPIC)) &&\
     (c_timeValid((p).lease_duration)))

#define v_historyPolicyEqual(p1,p2)\
    (((p1).kind == (p2).kind) &&\
     ((p1).depth == (p2).depth))

#define v_historyPolicyValid(p)\
    ((((p).kind == V_HISTORY_KEEPLAST) ||\
      ((p).kind == V_HISTORY_KEEPALL)) &&\
     (((p).depth == V_LENGTH_UNLIMITED) ||\
      ((p).depth > 0)))

#define v_resourcePolicyEqual(p1,p2)\
    (((p1).max_samples == (p2).max_samples) &&\
     ((p1).max_instances == (p2).max_instances) &&\
     ((p1).max_samples_per_instance == (p2).max_samples_per_instance))

#define v_resourcePolicyValid(p)\
    ((((p).max_samples == V_LENGTH_UNLIMITED) ||\
      ((p).max_samples > 0)) &&\
     (((p).max_instances == V_LENGTH_UNLIMITED) ||\
      ((p).max_instances > 0)) &&\
     (((p).max_samples_per_instance == V_LENGTH_UNLIMITED) ||\
      ((p).max_samples_per_instance > 0)))

#define v_resourcePolicyIsUnlimited(p)\
    (((p).max_samples == V_LENGTH_UNLIMITED) &&\
     ((p).max_instances == V_LENGTH_UNLIMITED) &&\
     ((p).max_samples_per_instance == V_LENGTH_UNLIMITED))

#define v_transportPolicyEqual(p1,p2)\
    ((p1).value == (p2).value)

#define v_transportPolicyValid(p)\
    (TRUE)

#define v_lifespanPolicyEqual(p1,p2)\
    (c_timeCompare((p1).duration,(p2).duration) == C_EQ)

#define v_lifespanPolicyValid(p)\
    (c_timeValid((p).duration))

#define v_ownershipPolicyCompatible(p1,p2)\
    ((p1).kind == (p2).kind) /* this is not an error! see page 2-105 of OMG spec */

#define v_ownershipPolicyEqual(p1,p2)\
    ((p1).kind == (p2).kind)

#define v_ownershipPolicyValid(p)\
    (((p).kind == V_OWNERSHIP_SHARED) ||\
     ((p).kind == V_OWNERSHIP_EXCLUSIVE))

#define v_strengthPolicyEqual(p1,p2)\
    ((p1).value == (p2).value)

#define v_strengthPolicyValid(p)\
    (TRUE)

#define v_writerLifecyclePolicyEqual(p1,p2)\
    (((p1).autodispose_unregistered_instances == (p2).autodispose_unregistered_instances) &&\
     (c_timeCompare((p1).autopurge_suspended_samples_delay,(p2).autopurge_suspended_samples_delay) == C_EQ) &&\
     (c_timeCompare((p1).autounregister_instance_delay,(p2).autounregister_instance_delay) == C_EQ))

#define v_writerLifecyclePolicyValid(p)\
    ((((p).autodispose_unregistered_instances == TRUE) ||\
      ((p).autodispose_unregistered_instances == FALSE)) &&\
     (c_timeValid((p).autopurge_suspended_samples_delay)) &&\
     (c_timeValid((p).autounregister_instance_delay)))

#define v_entityFactoryPolicyEqual(p1,p2)\
    ((p1).autoenable_created_entities == (p2).autoenable_created_entities)

#define v_entityFactoryPolicyValid(p)\
    (((p).autoenable_created_entities == TRUE) ||\
     ((p).autoenable_created_entities == FALSE))

#define v_readerLifecyclePolicyEqual(p1,p2)\
    ((c_timeCompare((p1).autopurge_nowriter_samples_delay,(p2).autopurge_nowriter_samples_delay) == C_EQ) && \
     (c_timeCompare((p1).autopurge_disposed_samples_delay,(p2).autopurge_disposed_samples_delay) == C_EQ) && \
     ((p1).autopurge_dispose_all == (p2).autopurge_dispose_all) && \
     ((p1).enable_invalid_samples == (p2).enable_invalid_samples) && \
     ((p1).invalid_sample_visibility == (p2).invalid_sample_visibility))

#define v_readerLifecyclePolicyValid(p)\
    (c_timeValid((p).autopurge_nowriter_samples_delay) && \
     c_timeValid((p).autopurge_disposed_samples_delay) && \
     (((p).autopurge_dispose_all == TRUE) || \
      ((p).autopurge_dispose_all == FALSE)) && \
     (((p).enable_invalid_samples == TRUE) || \
      ((p).enable_invalid_samples == FALSE)))

#define v_pacingPolicyEqual(p1,p2)\
    (c_timeCompare((p1).minSeperation,(p2).minSeperation) == C_EQ)

#define v_pacingPolicyValid(p)\
    (c_timeValid((p).minSeperation))

#define v_userDataPolicyEqual(p1,p2)\
    (((p1).size == (p2).size) && ((p1).size == 0 || ((p1).size > 0 && (memcmp((p1).value,(p2).value,(c_ulong)(p1).size) == 0))))

#define v_userDataPolicyValid(p)\
    ((((p).size == 0) && ((p).value == NULL)) || \
     (((p).size != 0) && ((p).value != NULL)))

#define v_topicDataPolicyEqual(p1,p2)\
    (((p1).size == (p2).size) && ((p1).size == 0 || ((p1).size > 0 && (memcmp((p1).value,(p2).value,(c_ulong)(p1).size) == 0))))

#define v_topicDataPolicyValid(p)\
    ((((p).size == 0) && ((p).value == NULL)) || \
     (((p).size != 0) && ((p).value != NULL)))

#define v_groupDataPolicyEqual(p1,p2)\
    (((p1).size == (p2).size) && ((p1).size == 0 || ((p1).size > 0 && (memcmp((p1).value,(p2).value,(c_ulong)(p1).size) == 0))))

#define v_groupDataPolicyValid(p)\
    ((((p).size == 0) && ((p).value == NULL)) || \
     (((p).size != 0) && ((p).value != NULL)))

#define v_partitionPolicyEqual(p1,p2)\
    (((p1) != NULL) && ((p2) != NULL) && (strcmp((p1),(p2)) == 0))

#define v_keyPolicyEqual(p1,p2)\
    (((p1).expression != NULL) && ((p2).expression != NULL) && (strcmp((p1).expression,(p2).expression) == 0))

#define v_readerLifespanPolicyCompatible(offered,requested)\
    ((!requested.used) ||\
     ((c_timeCompare(offered.duration, C_TIME_INFINITE) == C_EQ) &&\
      (c_timeCompare(requested.duration, C_TIME_INFINITE) == C_EQ)) ||\
     ((c_timeCompare(offered.duration, C_TIME_INFINITE) != C_EQ) &&\
      ((c_timeCompare(offered.duration,requested.duration) == C_EQ) ||\
       (c_timeCompare(offered.duration,requested.duration) == C_LT))))

#define v_readerLifespanPolicyEqual(p1,p2)\
    (((p1).used == (p2).used) &&\
     (((p1).used && (c_timeCompare((p1).duration,(p2).duration) == C_EQ)) || !(p1).used))

#define v_readerLifespanPolicyValid(p)\
    ((((p).used == FALSE) || ((p).used == TRUE)) && c_timeValid((p).duration))

#define v_sharePolicyEqual(p1,p2)\
    (((p1).enable == (p2).enable) && \
     (((p1).enable == FALSE) || (((p1).name != NULL) && ((p2).name != NULL) && (strcmp((p1).name,(p2).name) == 0))))

#define v_sharePolicyValid(p)\
    (((p).enable == FALSE) || (((p).enable == TRUE) && ((p).name != NULL)))

#define v_userKeyPolicyEqual(p1,p2)\
    (((p1).enable == (p2).enable) && \
     (((p1).enable == FALSE) || \
      (((p1).expression != NULL) && ((p2).expression != NULL) && (strcmp((p1).expression,(p2).expression) == 0))))

#define v_userKeyPolicyValid(p)\
    (((p).enable == FALSE) || (((p).enable == TRUE) && ((p).expression != NULL)))

#define v_schedulingPolicyEqual(p1,p2)\
    (((p1).kind == (p2).kind) && \
     ((p1).priority == (p2).priority) && \
     ((p1).priorityKind == (p2).priorityKind))

#define v_schedulingPolicyValid(p) \
   ((((p).kind == V_SCHED_DEFAULT) || \
     ((p).kind == V_SCHED_TIMESHARING) || \
     ((p).kind == V_SCHED_REALTIME)) && \
    (((p).priorityKind == V_SCHED_PRIO_ABSOLUTE) || \
      (p).priorityKind == V_SCHED_PRIO_RELATIVE))

  /*********************************************
   *** policy compatibility: internal variant
   *********************************************/

#define v_reliabilityPolicyICompatible(offered, requested) v_reliabilityPolicyCompatible((offered).v,(requested).v)
#define v_reliabilityPolicyIEqual(p1,p2) v_reliabilityPolicyEqual((p1).v,(p2).v)
#define v_reliabilityPolicyIValid(p) v_reliabilityPolicyValid((p).v)
#define v_durabilityPolicyICompatible(offered,requested) v_durabilityPolicyCompatible((offered).v,(requested).v)
#define v_durabilityPolicyIEqual(p1,p2) v_durabilityPolicyEqual((p1).v,(p2).v)
#define v_durabilityPolicyIValid(p) v_durabilityPolicyValid((p).v)
#define v_durabilityServicePolicyIEqual(p1,p2) v_durabilityServicePolicyEqual((p1).v,(p2).v)
#define v_durabilityServicePolicyIValid(p) v_durabilityServicePolicyValid((p).v)
#define v_presentationPolicyICompatible(offered,requested) v_presentationPolicyCompatible((offered).v,(requested).v)
#define v_presentationPolicyIEqual(p1,p2) v_presentationPolicyEqual((p1).v,(p2).v)
#define v_presentationPolicyIValid(p) v_presentationPolicyValid((p).v)
#define v_latencyPolicyICompatible(offered,requested) v_latencyPolicyCompatible((offered).v,(requested).v)
#define v_latencyPolicyIEqual(p1,p2) v_latencyPolicyEqual((p1).v,(p2).v)
#define v_latencyPolicyIValid(p) v_latencyPolicyValid((p).v)
#define v_orderbyPolicyICompatible(offered,requested) v_orderbyPolicyCompatible((offered).v,(requested).v)
#define v_orderbyPolicyIEqual(p1,p2) v_orderbyPolicyEqual((p1).v,(p2).v)
#define v_orderbyPolicyIValid(p) v_orderbyPolicyValid((p).v)
#define v_deadlinePolicyICompatible(offered,requested) v_deadlinePolicyCompatible((offered).v,(requested).v)
#define v_deadlinePolicyIEqual(p1,p2) v_deadlinePolicyEqual((p1).v,(p2).v)
#define v_deadlinePolicyIValid(p) v_deadlinePolicyValid((p).v)
#define v_livelinessPolicyICompatible(offered,requested) v_livelinessPolicyCompatible((offered).v,(requested).v)
#define v_livelinessPolicyIEqual(p1,p2) v_livelinessPolicyEqual((p1).v,(p2).v)
#define v_livelinessPolicyIValid(p) v_livelinessPolicyValid((p).v)
#define v_historyPolicyIEqual(p1,p2) v_historyPolicyEqual((p1).v,(p2).v)
#define v_historyPolicyIValid(p) v_historyPolicyValid((p).v)
#define v_resourcePolicyIEqual(p1,p2) v_resourcePolicyEqual((p1).v,(p2).v)
#define v_resourcePolicyIValid(p) v_resourcePolicyValid((p).v)
#define v_resourcePolicyIIsUnlimited(p) v_resourcePolicyIsUnlimited((p).v)
#define v_transportPolicyIEqual(p1,p2) v_transportPolicyEqual((p1).v,(p2).v)
#define v_transportPolicyIValid(p) v_transportPolicyValid((p).v)
#define v_lifespanPolicyIEqual(p1,p2) v_lifespanPolicyEqual((p1).v,(p2).v)
#define v_lifespanPolicyIValid(p) v_lifespanPolicyValid((p).v)
#define v_ownershipPolicyICompatible(p1,p2) v_ownershipPolicyCompatible((p1).v,(p2).v)
#define v_ownershipPolicyIEqual(p1,p2) v_ownershipPolicyEqual((p1).v,(p2).v)
#define v_ownershipPolicyIValid(p) v_ownershipPolicyValid((p).v)
#define v_strengthPolicyIEqual(p1,p2) v_strengthPolicyEqual((p1).v,(p2).v)
#define v_strengthPolicyIValid(p) v_strengthPolicyValid((p).v)
#define v_writerLifecyclePolicyIEqual(p1,p2) v_writerLifecyclePolicyEqual((p1).v,(p2).v)
#define v_writerLifecyclePolicyIValid(p) v_writerLifecyclePolicyValid((p).v)
#define v_entityFactoryPolicyIEqual(p1,p2) v_entityFactoryPolicyEqual((p1).v,(p2).v)
#define v_entityFactoryPolicyIValid(p) v_entityFactoryPolicyValid((p).v)
#define v_readerLifecyclePolicyIEqual(p1,p2) v_readerLifecyclePolicyEqual((p1).v,(p2).v)
#define v_readerLifecyclePolicyIValid(p) v_readerLifecyclePolicyValid((p).v)
#define v_pacingPolicyIEqual(p1,p2) v_pacingPolicyEqual((p1).v,(p2).v)
#define v_pacingPolicyIValid(p) v_pacingPolicyValid((p).v)
#define v_userDataPolicyIEqual(p1,p2) v_userDataPolicyEqual((p1).v,(p2).v)
#define v_userDataPolicyIValid(p) v_userDataPolicyValid((p).v)
#define v_topicDataPolicyIEqual(p1,p2) v_topicDataPolicyEqual((p1).v,(p2).v)
#define v_topicDataPolicyIValid(p) v_topicDataPolicyValid((p).v)
#define v_groupDataPolicyIEqual(p1,p2) v_groupDataPolicyEqual((p1).v,(p2).v)
#define v_groupDataPolicyIValid(p) v_groupDataPolicyValid((p).v)
#define v_partitionPolicyIEqual(p1,p2) v_partitionPolicyEqual((p1).v,(p2).v)
#define v_keyPolicyIEqual(p1,p2) v_keyPolicyEqual((p1).v,(p2).v)
#define v_readerLifespanPolicyICompatible(offered,requested) v_readerLifespanPolicyCompatible((offered).v,(requested).v)
#define v_readerLifespanPolicyIEqual(p1,p2) v_readerLifespanPolicyEqual((p1).v,(p2).v)
#define v_readerLifespanPolicyIValid(p) v_readerLifespanPolicyValid((p).v)
#define v_sharePolicyIEqual(p1,p2) v_sharePolicyEqual((p1).v,(p2).v)
#define v_sharePolicyIValid(p) v_sharePolicyValid((p).v)
#define v_userKeyPolicyIEqual(p1,p2) v_userKeyPolicyEqual((p1).v,(p2).v)
#define v_userKeyPolicyIValid(p) v_userKeyPolicyValid((p).v)
#define v_schedulingPolicyIEqual(p1,p2) v_schedulingPolicyEqual((p1).v,(p2).v)
#define v_schedulingPolicyIValid(p) v_schedulingPolicyValid((p).v)

OS_API void
v_policyReportInvalid(
    c_ulong mask);

OS_API void
v_policyReportImmutable(
    c_ulong mask, c_ulong immutable);

OS_API v_result v_policyConvToExt_type_name (c_base base, c_string *dst, const C_STRUCT(c_type) *topic_type);
OS_API void v_policyConvToExt_topic_name (c_string *dst, const char *topic_name);
OS_API void v_policyConvToExt_durability (struct v_durabilityPolicy *dst, const v_durabilityPolicyI *src);
OS_API void v_policyConvToExt_durability_service (struct v_durabilityServicePolicy *dst, const v_durabilityServicePolicyI *src);
OS_API void v_policyConvToExt_deadline (struct v_deadlinePolicy *dst, const v_deadlinePolicyI *src);
OS_API void v_policyConvToExt_latency_budget (struct v_latencyPolicy *dst, const v_latencyPolicyI *src);
OS_API void v_policyConvToExt_liveliness (struct v_livelinessPolicy *dst, const v_livelinessPolicyI *src);
OS_API void v_policyConvToExt_reliability (struct v_reliabilityPolicy *dst, const v_reliabilityPolicyI *src);
OS_API void v_policyConvToExt_transport_priority (struct v_transportPolicy *dst, const v_transportPolicyI *src);
OS_API void v_policyConvToExt_lifespan (struct v_lifespanPolicy *dst, const v_lifespanPolicyI *src);
OS_API void v_policyConvToExt_reader_lifespan (struct v_readerLifespanPolicy *dst, const v_readerLifespanPolicyI *src);
OS_API void v_policyConvToExt_time_based_filter (struct v_pacingPolicy *dst, const v_pacingPolicyI *src);
OS_API void v_policyConvToExt_destination_order (struct v_orderbyPolicy *dst, const v_orderbyPolicyI *src);
OS_API void v_policyConvToExt_history (struct v_historyPolicy *dst, const v_historyPolicyI *src);
OS_API void v_policyConvToExt_resource_limits (struct v_resourcePolicy *dst, const v_resourcePolicyI *src);
OS_API void v_policyConvToExt_ownership (struct v_ownershipPolicy *dst, const v_ownershipPolicyI *src);
OS_API void v_policyConvToExt_ownership_strength (struct v_strengthPolicy *dst, const v_strengthPolicyI *src);
OS_API void v_policyConvToExt_presentation (struct v_presentationPolicy *dst, const v_presentationPolicyI *src);
OS_API void v_policyConvToExt_writer_data_lifecycle (struct v_writerLifecyclePolicy *dst, const v_writerLifecyclePolicyI *src);
OS_API void v_policyConvToExt_reader_data_lifecycle (struct v_readerLifecyclePolicy *dst, const v_readerLifecyclePolicyI *src);
OS_API void v_policyConvToExt_subscription_keys (struct v_userKeyPolicy *dst, const v_userKeyPolicyI *src);
OS_API void v_policyConvToExt_share (c_base base, struct v_sharePolicy *dst, const v_sharePolicyI *src);
OS_API v_result v_policyConvToExt_topic_data (c_base base, struct v_builtinTopicDataPolicy *dst, const v_topicDataPolicyI *src);
OS_API v_result v_policyConvToExt_group_data (c_base base, struct v_builtinGroupDataPolicy *dst, const v_groupDataPolicyI *src);
OS_API v_result v_policyConvToExt_user_data (c_base base, struct v_builtinUserDataPolicy *dst, const v_userDataPolicyI *src);
OS_API v_result v_policyConvToExt_partition (c_base base, struct v_builtinPartitionPolicy *dst, const v_partitionPolicyI *src);
OS_API void v_policyConvToExt_entity_factory (struct v_entityFactoryPolicy *dst, const v_entityFactoryPolicyI *src);
OS_API v_result v_policyConvToExt_topic_meta_data (c_base base, c_string *meta_data, c_string *key_list, const C_STRUCT(c_type) *topic_type, const char *topic_key_expr);
OS_API void v_policyConvToInt_durability (v_durabilityPolicyI *dst, const struct v_durabilityPolicy *src);
OS_API void v_policyConvToInt_durability_service (v_durabilityServicePolicyI *dst, const struct v_durabilityServicePolicy *src);
OS_API void v_policyConvToInt_deadline (v_deadlinePolicyI *dst, const struct v_deadlinePolicy *src);
OS_API void v_policyConvToInt_latency_budget (v_latencyPolicyI *dst, const struct v_latencyPolicy *src);
OS_API void v_policyConvToInt_liveliness (v_livelinessPolicyI *dst, const struct v_livelinessPolicy *src);
OS_API void v_policyConvToInt_reliability (v_reliabilityPolicyI *dst, const struct v_reliabilityPolicy *src);
OS_API void v_policyConvToInt_transport_priority (v_transportPolicyI *dst, const struct v_transportPolicy *src);
OS_API void v_policyConvToInt_lifespan (v_lifespanPolicyI *dst, const struct v_lifespanPolicy *src);
OS_API void v_policyConvToInt_destination_order (v_orderbyPolicyI *dst, const struct v_orderbyPolicy *src);
OS_API void v_policyConvToInt_history (v_historyPolicyI *dst, const struct v_historyPolicy *src);
OS_API void v_policyConvToInt_resource_limits (v_resourcePolicyI *dst, const struct v_resourcePolicy *src);
OS_API void v_policyConvToInt_ownership (v_ownershipPolicyI *dst, const struct v_ownershipPolicy *src);
OS_API v_result v_policyConvToInt_topic_data (c_base base, v_topicDataPolicyI *dst, const struct v_builtinTopicDataPolicy *src);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif /* V_POLICY_H */
