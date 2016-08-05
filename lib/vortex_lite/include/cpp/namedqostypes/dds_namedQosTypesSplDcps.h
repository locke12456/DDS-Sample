#ifndef DDS_NAMEDQOSTYPESSPLTYPES_H
#define DDS_NAMEDQOSTYPESSPLTYPES_H

#include "ccpp_dds_namedQosTypes.h"
#include "dds_dcps_builtintopicsSplDcps.h"



extern c_metaObject __dds_namedQosTypes_DDS__load (c_base base);

extern const char *DDS_NamedDomainParticipantQos_metaDescriptor[];
extern const DDS::ULong DDS_NamedDomainParticipantQos_metaDescriptorArrLength;
extern c_metaObject __DDS_NamedDomainParticipantQos__load (c_base base);
struct _DDS_NamedDomainParticipantQos ;
extern  DDS::Boolean __DDS_NamedDomainParticipantQos__copyIn(c_base base, const struct DDS::NamedDomainParticipantQos *from, struct _DDS_NamedDomainParticipantQos *to);
extern  void __DDS_NamedDomainParticipantQos__copyOut(const void *_from, void *_to);
struct _DDS_NamedDomainParticipantQos {
    DDS::String name;
    struct _DDS_DomainParticipantQos domainparticipant_qos;
};

extern const char *DDS_NamedPublisherQos_metaDescriptor[];
extern const DDS::ULong DDS_NamedPublisherQos_metaDescriptorArrLength;
extern c_metaObject __DDS_NamedPublisherQos__load (c_base base);
struct _DDS_NamedPublisherQos ;
extern  DDS::Boolean __DDS_NamedPublisherQos__copyIn(c_base base, const struct DDS::NamedPublisherQos *from, struct _DDS_NamedPublisherQos *to);
extern  void __DDS_NamedPublisherQos__copyOut(const void *_from, void *_to);
struct _DDS_NamedPublisherQos {
    DDS::String name;
    struct _DDS_PublisherQos publisher_qos;
};

extern const char *DDS_NamedSubscriberQos_metaDescriptor[];
extern const DDS::ULong DDS_NamedSubscriberQos_metaDescriptorArrLength;
extern c_metaObject __DDS_NamedSubscriberQos__load (c_base base);
struct _DDS_NamedSubscriberQos ;
extern  DDS::Boolean __DDS_NamedSubscriberQos__copyIn(c_base base, const struct DDS::NamedSubscriberQos *from, struct _DDS_NamedSubscriberQos *to);
extern  void __DDS_NamedSubscriberQos__copyOut(const void *_from, void *_to);
struct _DDS_NamedSubscriberQos {
    DDS::String name;
    struct _DDS_SubscriberQos subscriber_qos;
};

extern const char *DDS_NamedTopicQos_metaDescriptor[];
extern const DDS::ULong DDS_NamedTopicQos_metaDescriptorArrLength;
extern c_metaObject __DDS_NamedTopicQos__load (c_base base);
struct _DDS_NamedTopicQos ;
extern  DDS::Boolean __DDS_NamedTopicQos__copyIn(c_base base, const struct DDS::NamedTopicQos *from, struct _DDS_NamedTopicQos *to);
extern  void __DDS_NamedTopicQos__copyOut(const void *_from, void *_to);
struct _DDS_NamedTopicQos {
    DDS::String name;
    struct _DDS_TopicQos topic_qos;
};

extern const char *DDS_NamedDataWriterQos_metaDescriptor[];
extern const DDS::ULong DDS_NamedDataWriterQos_metaDescriptorArrLength;
extern c_metaObject __DDS_NamedDataWriterQos__load (c_base base);
struct _DDS_NamedDataWriterQos ;
extern  DDS::Boolean __DDS_NamedDataWriterQos__copyIn(c_base base, const struct DDS::NamedDataWriterQos *from, struct _DDS_NamedDataWriterQos *to);
extern  void __DDS_NamedDataWriterQos__copyOut(const void *_from, void *_to);
struct _DDS_NamedDataWriterQos {
    DDS::String name;
    struct _DDS_DataWriterQos datawriter_qos;
};

extern const char *DDS_NamedDataReaderQos_metaDescriptor[];
extern const DDS::ULong DDS_NamedDataReaderQos_metaDescriptorArrLength;
extern c_metaObject __DDS_NamedDataReaderQos__load (c_base base);
struct _DDS_NamedDataReaderQos ;
extern  DDS::Boolean __DDS_NamedDataReaderQos__copyIn(c_base base, const struct DDS::NamedDataReaderQos *from, struct _DDS_NamedDataReaderQos *to);
extern  void __DDS_NamedDataReaderQos__copyOut(const void *_from, void *_to);
struct _DDS_NamedDataReaderQos {
    DDS::String name;
    struct _DDS_DataReaderQos datareader_qos;
};

#undef OS_API
#endif
