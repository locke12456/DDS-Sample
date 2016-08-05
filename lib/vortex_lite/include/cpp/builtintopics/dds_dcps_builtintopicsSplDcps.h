#ifndef DDS_DCPS_BUILTINTOPICSSPLTYPES_H
#define DDS_DCPS_BUILTINTOPICSSPLTYPES_H

#include "ccpp_dds_dcps_builtintopics.h"
#include "dds_builtinTopicsSplDcps.h"



extern c_metaObject __dds_dcps_builtintopics_DDS__load (c_base base);

extern const char *DDS_Time_t_metaDescriptor[];
extern const DDS::ULong DDS_Time_t_metaDescriptorArrLength;
extern c_metaObject __DDS_Time_t__load (c_base base);
struct _DDS_Time_t ;
extern  DDS::Boolean __DDS_Time_t__copyIn(c_base base, const struct DDS::Time_t *from, struct _DDS_Time_t *to);
extern  void __DDS_Time_t__copyOut(const void *_from, void *_to);
struct _DDS_Time_t {
    DDS::Long sec;
    DDS::ULong nanosec;
};

extern const char *DDS_DomainParticipantQos_metaDescriptor[];
extern const DDS::ULong DDS_DomainParticipantQos_metaDescriptorArrLength;
extern c_metaObject __DDS_DomainParticipantQos__load (c_base base);
struct _DDS_DomainParticipantQos ;
extern  DDS::Boolean __DDS_DomainParticipantQos__copyIn(c_base base, const struct DDS::DomainParticipantQos *from, struct _DDS_DomainParticipantQos *to);
extern  void __DDS_DomainParticipantQos__copyOut(const void *_from, void *_to);
struct _DDS_DomainParticipantQos {
    struct _DDS_UserDataQosPolicy user_data;
    struct _DDS_SchedulingQosPolicy watchdog_scheduling;
    struct _DDS_SchedulingQosPolicy listener_scheduling;
};

extern const char *DDS_TopicQos_metaDescriptor[];
extern const DDS::ULong DDS_TopicQos_metaDescriptorArrLength;
extern c_metaObject __DDS_TopicQos__load (c_base base);
struct _DDS_TopicQos ;
extern  DDS::Boolean __DDS_TopicQos__copyIn(c_base base, const struct DDS::TopicQos *from, struct _DDS_TopicQos *to);
extern  void __DDS_TopicQos__copyOut(const void *_from, void *_to);
struct _DDS_TopicQos {
    struct _DDS_TopicDataQosPolicy topic_data;
    struct _DDS_DurabilityQosPolicy durability;
    struct _DDS_DurabilityServiceQosPolicy durability_service;
    struct _DDS_DeadlineQosPolicy deadline;
    struct _DDS_LatencyBudgetQosPolicy latency_budget;
    struct _DDS_LivelinessQosPolicy liveliness;
    struct _DDS_ReliabilityQosPolicy reliability;
    struct _DDS_DestinationOrderQosPolicy destination_order;
    struct _DDS_HistoryQosPolicy history;
    struct _DDS_ResourceLimitsQosPolicy resource_limits;
    struct _DDS_TransportPriorityQosPolicy transport_priority;
    struct _DDS_LifespanQosPolicy lifespan;
    struct _DDS_OwnershipQosPolicy ownership;
};

extern const char *DDS_DataWriterQos_metaDescriptor[];
extern const DDS::ULong DDS_DataWriterQos_metaDescriptorArrLength;
extern c_metaObject __DDS_DataWriterQos__load (c_base base);
struct _DDS_DataWriterQos ;
extern  DDS::Boolean __DDS_DataWriterQos__copyIn(c_base base, const struct DDS::DataWriterQos *from, struct _DDS_DataWriterQos *to);
extern  void __DDS_DataWriterQos__copyOut(const void *_from, void *_to);
struct _DDS_DataWriterQos {
    struct _DDS_DurabilityQosPolicy durability;
    struct _DDS_DeadlineQosPolicy deadline;
    struct _DDS_LatencyBudgetQosPolicy latency_budget;
    struct _DDS_LivelinessQosPolicy liveliness;
    struct _DDS_ReliabilityQosPolicy reliability;
    struct _DDS_DestinationOrderQosPolicy destination_order;
    struct _DDS_HistoryQosPolicy history;
    struct _DDS_ResourceLimitsQosPolicy resource_limits;
    struct _DDS_TransportPriorityQosPolicy transport_priority;
    struct _DDS_LifespanQosPolicy lifespan;
    struct _DDS_UserDataQosPolicy user_data;
    struct _DDS_OwnershipQosPolicy ownership;
    struct _DDS_OwnershipStrengthQosPolicy ownership_strength;
    struct _DDS_WriterDataLifecycleQosPolicy writer_data_lifecycle;
};

extern const char *DDS_PublisherQos_metaDescriptor[];
extern const DDS::ULong DDS_PublisherQos_metaDescriptorArrLength;
extern c_metaObject __DDS_PublisherQos__load (c_base base);
struct _DDS_PublisherQos ;
extern  DDS::Boolean __DDS_PublisherQos__copyIn(c_base base, const struct DDS::PublisherQos *from, struct _DDS_PublisherQos *to);
extern  void __DDS_PublisherQos__copyOut(const void *_from, void *_to);
struct _DDS_PublisherQos {
    struct _DDS_PresentationQosPolicy presentation;
    struct _DDS_PartitionQosPolicy partition;
    struct _DDS_GroupDataQosPolicy group_data;
};

extern const char *DDS_DataReaderQos_metaDescriptor[];
extern const DDS::ULong DDS_DataReaderQos_metaDescriptorArrLength;
extern c_metaObject __DDS_DataReaderQos__load (c_base base);
struct _DDS_DataReaderQos ;
extern  DDS::Boolean __DDS_DataReaderQos__copyIn(c_base base, const struct DDS::DataReaderQos *from, struct _DDS_DataReaderQos *to);
extern  void __DDS_DataReaderQos__copyOut(const void *_from, void *_to);
struct _DDS_DataReaderQos {
    struct _DDS_DurabilityQosPolicy durability;
    struct _DDS_DeadlineQosPolicy deadline;
    struct _DDS_LatencyBudgetQosPolicy latency_budget;
    struct _DDS_LivelinessQosPolicy liveliness;
    struct _DDS_ReliabilityQosPolicy reliability;
    struct _DDS_DestinationOrderQosPolicy destination_order;
    struct _DDS_HistoryQosPolicy history;
    struct _DDS_ResourceLimitsQosPolicy resource_limits;
    struct _DDS_UserDataQosPolicy user_data;
    struct _DDS_OwnershipQosPolicy ownership;
    struct _DDS_TimeBasedFilterQosPolicy time_based_filter;
    struct _DDS_ReaderDataLifecycleQosPolicy reader_data_lifecycle;
    struct _DDS_SubscriptionKeyQosPolicy subscription_keys;
    struct _DDS_ReaderLifespanQosPolicy reader_lifespan;
    struct _DDS_ShareQosPolicy share;
};

extern const char *DDS_SubscriberQos_metaDescriptor[];
extern const DDS::ULong DDS_SubscriberQos_metaDescriptorArrLength;
extern c_metaObject __DDS_SubscriberQos__load (c_base base);
struct _DDS_SubscriberQos ;
extern  DDS::Boolean __DDS_SubscriberQos__copyIn(c_base base, const struct DDS::SubscriberQos *from, struct _DDS_SubscriberQos *to);
extern  void __DDS_SubscriberQos__copyOut(const void *_from, void *_to);
struct _DDS_SubscriberQos {
    struct _DDS_PresentationQosPolicy presentation;
    struct _DDS_PartitionQosPolicy partition;
    struct _DDS_GroupDataQosPolicy group_data;
    struct _DDS_ShareQosPolicy share;
};

#undef OS_API
#endif
