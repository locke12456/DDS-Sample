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
#ifndef SACPP_DDS_DCPS_INTERFACES_H
#define SACPP_DDS_DCPS_INTERFACES_H

/** @file dds_dcps_interfaces.h
 *  @brief Vortex Lite Classic C++ API header
 */
#include "dds_dcps_builtintopics.h"
#include "cpp_dcps_if.h"
#include "dds.h"


namespace DDS
{
   struct Duration_t;
   struct Time_t;
   struct UserDataQosPolicy;
   struct TopicDataQosPolicy;
   struct GroupDataQosPolicy;
   struct TransportPriorityQosPolicy;
   struct LifespanQosPolicy;
   struct DurabilityQosPolicy;
   struct PresentationQosPolicy;
   struct DeadlineQosPolicy;
   struct LatencyBudgetQosPolicy;
   struct OwnershipQosPolicy;
   struct OwnershipStrengthQosPolicy;
   struct LivelinessQosPolicy;
   struct TimeBasedFilterQosPolicy;
   struct PartitionQosPolicy;
   struct ReliabilityQosPolicy;
   struct DestinationOrderQosPolicy;
   struct HistoryQosPolicy;
   struct ResourceLimitsQosPolicy;
   struct WriterDataLifecycleQosPolicy;
   struct ReaderDataLifecycleQosPolicy;
   struct DurabilityServiceQosPolicy;
   struct SubscriptionKeyQosPolicy;
   struct ReaderLifespanQosPolicy;
   struct ShareQosPolicy;
   struct SchedulingClassQosPolicy;
   struct SchedulingPriorityQosPolicy;
   struct SchedulingQosPolicy;
   struct ViewKeyQosPolicy;
   struct DomainParticipantQos;
   struct TopicQos;
   struct DataWriterQos;
   struct PublisherQos;
   struct DataReaderQos;
   struct SubscriberQos;
   struct ParticipantBuiltinTopicData;
   struct TopicBuiltinTopicData;
   struct PublicationBuiltinTopicData;
   struct SubscriptionBuiltinTopicData;
   struct InconsistentTopicStatus;
   struct AllDataDisposedTopicStatus;
   struct SampleLostStatus;
   struct SampleRejectedStatus;
   struct LivelinessLostStatus;
   struct LivelinessChangedStatus;
   struct OfferedDeadlineMissedStatus;
   struct RequestedDeadlineMissedStatus;
   struct QosPolicyCount;
   struct OfferedIncompatibleQosStatus;
   struct RequestedIncompatibleQosStatus;
   struct PublicationMatchedStatus;
   struct SubscriptionMatchedStatus;

   class OS_API Domain;

   typedef Domain * Domain_ptr;
   typedef DDS_DCPSInterface_var <Domain> Domain_var;
   typedef DDS_DCPSInterface_out <Domain> Domain_out;

   class OS_API Listener;

   typedef Listener * Listener_ptr;
   typedef DDS_DCPSInterface_var <Listener> Listener_var;
   typedef DDS_DCPSInterface_out <Listener> Listener_out;


   class OS_API Entity;

   typedef Entity * Entity_ptr;
   typedef DDS_DCPSInterface_var <Entity> Entity_var;
   typedef DDS_DCPSInterface_out <Entity> Entity_out;

   class OS_API QosProviderInterface;

   typedef QosProviderInterface * QosProviderInterface_ptr;
   typedef DDS_DCPSInterface_var <QosProviderInterface> QosProviderInterface_var;
   typedef DDS_DCPSInterface_out <QosProviderInterface> QosProviderInterface_out;

   class OS_API TopicDescription;

   typedef TopicDescription * TopicDescription_ptr;
   typedef DDS_DCPSInterface_var <TopicDescription> TopicDescription_var;
   typedef DDS_DCPSInterface_out <TopicDescription> TopicDescription_out;


   class OS_API Topic;

   typedef Topic * Topic_ptr;
   typedef DDS_DCPSInterface_var <Topic> Topic_var;
   typedef DDS_DCPSInterface_out <Topic> Topic_out;


   class OS_API ContentFilteredTopic;

   typedef ContentFilteredTopic * ContentFilteredTopic_ptr;
   typedef DDS_DCPSInterface_var <ContentFilteredTopic> ContentFilteredTopic_var;
   typedef DDS_DCPSInterface_out <ContentFilteredTopic> ContentFilteredTopic_out;

   class OS_API MultiTopic;
   typedef MultiTopic * MultiTopic_ptr;

/*
   typedef DDS_DCPSInterface_var <MultiTopic> MultiTopic_var;
   typedef DDS_DCPSInterface_out <MultiTopic> MultiTopic_out;
*/

   class OS_API DataWriter;

   typedef DataWriter * DataWriter_ptr;
   typedef DDS_DCPSInterface_var <DataWriter> DataWriter_var;
   typedef DDS_DCPSInterface_out <DataWriter> DataWriter_out;


   class OS_API DataReader;

   typedef DataReader * DataReader_ptr;
   typedef DDS_DCPSInterface_var <DataReader> DataReader_var;
   typedef DDS_DCPSInterface_out <DataReader> DataReader_out;


   class OS_API Subscriber;

   typedef Subscriber * Subscriber_ptr;
   typedef DDS_DCPSInterface_var <Subscriber> Subscriber_var;
   typedef DDS_DCPSInterface_out <Subscriber> Subscriber_out;


   class OS_API Publisher;

   typedef Publisher * Publisher_ptr;
   typedef DDS_DCPSInterface_var <Publisher> Publisher_var;
   typedef DDS_DCPSInterface_out <Publisher> Publisher_out;


   class OS_API TopicListener;

   typedef TopicListener * TopicListener_ptr;
   typedef DDS_DCPSInterface_var <TopicListener> TopicListener_var;
   typedef DDS_DCPSInterface_out <TopicListener> TopicListener_out;


   class OS_API DataWriterListener;

   typedef DataWriterListener * DataWriterListener_ptr;
   typedef DDS_DCPSInterface_var <DataWriterListener> DataWriterListener_var;
   typedef DDS_DCPSInterface_out <DataWriterListener> DataWriterListener_out;


   class OS_API PublisherListener;

   typedef PublisherListener * PublisherListener_ptr;
   typedef DDS_DCPSInterface_var <PublisherListener> PublisherListener_var;
   typedef DDS_DCPSInterface_out <PublisherListener> PublisherListener_out;


   class OS_API DataReaderListener;

   typedef DataReaderListener * DataReaderListener_ptr;
   typedef DDS_DCPSInterface_var <DataReaderListener> DataReaderListener_var;
   typedef DDS_DCPSInterface_out <DataReaderListener> DataReaderListener_out;


   class OS_API SubscriberListener;

   typedef SubscriberListener * SubscriberListener_ptr;
   typedef DDS_DCPSInterface_var <SubscriberListener> SubscriberListener_var;
   typedef DDS_DCPSInterface_out <SubscriberListener> SubscriberListener_out;


   class OS_API DomainParticipantListener;

   typedef DomainParticipantListener * DomainParticipantListener_ptr;
   typedef DDS_DCPSInterface_var <DomainParticipantListener> DomainParticipantListener_var;
   typedef DDS_DCPSInterface_out <DomainParticipantListener> DomainParticipantListener_out;



   class OS_API Condition;

   typedef Condition * Condition_ptr;
   typedef DDS_DCPSInterface_var <Condition> Condition_var;
   typedef DDS_DCPSInterface_out <Condition> Condition_out;


   class OS_API WaitSetInterface;

   typedef WaitSetInterface * WaitSetInterface_ptr;
   typedef DDS_DCPSInterface_var <WaitSetInterface> WaitSetInterface_var;
   typedef DDS_DCPSInterface_out <WaitSetInterface> WaitSetInterface_out;


   class OS_API GuardConditionInterface;

   typedef GuardConditionInterface * GuardConditionInterface_ptr;
   typedef DDS_DCPSInterface_var <GuardConditionInterface> GuardConditionInterface_var;
   typedef DDS_DCPSInterface_out <GuardConditionInterface> GuardConditionInterface_out;


   class OS_API StatusCondition;

   typedef StatusCondition * StatusCondition_ptr;
   typedef DDS_DCPSInterface_var <StatusCondition> StatusCondition_var;
   typedef DDS_DCPSInterface_out <StatusCondition> StatusCondition_out;


   class OS_API ReadCondition;

   typedef ReadCondition * ReadCondition_ptr;
   typedef DDS_DCPSInterface_var <ReadCondition> ReadCondition_var;
   typedef DDS_DCPSInterface_out <ReadCondition> ReadCondition_out;


   class OS_API QueryCondition;

   typedef QueryCondition * QueryCondition_ptr;
   typedef DDS_DCPSInterface_var <QueryCondition> QueryCondition_var;
   typedef DDS_DCPSInterface_out <QueryCondition> QueryCondition_out;


   class OS_API DomainParticipant;

   typedef DomainParticipant * DomainParticipant_ptr;
   typedef DDS_DCPSInterface_var <DomainParticipant> DomainParticipant_var;
   typedef DDS_DCPSInterface_out <DomainParticipant> DomainParticipant_out;


   class OS_API DomainParticipantFactoryInterface;

   typedef DomainParticipantFactoryInterface * DomainParticipantFactoryInterface_ptr;
   typedef DDS_DCPSInterface_var <DomainParticipantFactoryInterface> DomainParticipantFactoryInterface_var;
   typedef DDS_DCPSInterface_out <DomainParticipantFactoryInterface> DomainParticipantFactoryInterface_out;


   class OS_API TypeSupport;

   typedef TypeSupport * TypeSupport_ptr;
   typedef DDS_DCPSInterface_var <TypeSupport> TypeSupport_var;
   typedef DDS_DCPSInterface_out <TypeSupport> TypeSupport_out;


   struct SampleInfo;


   typedef DDS::Long DomainId_t;
   typedef DDS::String DomainId_str_t;

   typedef DDS::ULongLong InstanceHandle_t;

   struct InstanceHandleSeq_uniq_ {};
   typedef DDS_DCPSUFLSeq <InstanceHandle_t, struct InstanceHandleSeq_uniq_> InstanceHandleSeq;
   typedef DDS_DCPSSequence_var <InstanceHandleSeq> InstanceHandleSeq_var;
   typedef DDS_DCPSSequence_out <InstanceHandleSeq> InstanceHandleSeq_out;
   typedef DDS::Long ReturnCode_t;

   typedef DDS::Long QosPolicyId_t;

    const DDS::ULongLong HANDLE_NIL = (DDS::ULongLong) 0x0;
    const DDS::Long LENGTH_UNLIMITED = (DDS::Long) -1L;
    const DDS::Long DURATION_INFINITE_SEC = (DDS::Long) 2147483647UL;
    const DDS::ULong DURATION_INFINITE_NSEC = (DDS::ULong) 2147483647UL;
    const DDS::Long DURATION_ZERO_SEC = (DDS::Long) 0UL;
    const DDS::ULong DURATION_ZERO_NSEC = (DDS::ULong) 0UL;
    const DDS::Long TIMESTAMP_INVALID_SEC = (DDS::Long) -1L;
    const DDS::ULong TIMESTAMP_INVALID_NSEC = (DDS::ULong) 4294967295UL;
    const DDS::DomainId_t DOMAIN_ID_DEFAULT = (DDS::DomainId_t) -1;
    const DDS::DomainId_t DOMAIN_ID_INVALID = (DDS::DomainId_t) -1;
    const DDS::Long RETCODE_OK = (DDS::Long) 0UL;
    const DDS::Long RETCODE_ERROR = (DDS::Long) 1UL;
    const DDS::Long RETCODE_UNSUPPORTED = (DDS::Long) 2UL;
    const DDS::Long RETCODE_BAD_PARAMETER = (DDS::Long) 3UL;
    const DDS::Long RETCODE_PRECONDITION_NOT_MET = (DDS::Long) 4UL;
    const DDS::Long RETCODE_OUT_OF_RESOURCES = (DDS::Long) 5UL;
    const DDS::Long RETCODE_NOT_ENABLED = (DDS::Long) 6UL;
    const DDS::Long RETCODE_IMMUTABLE_POLICY = (DDS::Long) 7UL;
    const DDS::Long RETCODE_INCONSISTENT_POLICY = (DDS::Long) 8UL;
    const DDS::Long RETCODE_ALREADY_DELETED = (DDS::Long) 9UL;
    const DDS::Long RETCODE_TIMEOUT = (DDS::Long) 10UL;
    const DDS::Long RETCODE_NO_DATA = (DDS::Long) 11UL;
    const DDS::Long RETCODE_ILLEGAL_OPERATION = (DDS::Long) 12UL;

    typedef DDS::ULong StatusKind;
    typedef DDS::ULong StatusMask;

    const DDS::ULong INCONSISTENT_TOPIC_STATUS = (DDS::ULong) 1UL;
    const DDS::ULong OFFERED_DEADLINE_MISSED_STATUS = (DDS::ULong) 2UL;
    const DDS::ULong REQUESTED_DEADLINE_MISSED_STATUS = (DDS::ULong) 4UL;
    const DDS::ULong OFFERED_INCOMPATIBLE_QOS_STATUS = (DDS::ULong) 32UL;
    const DDS::ULong REQUESTED_INCOMPATIBLE_QOS_STATUS = (DDS::ULong) 64UL;
    const DDS::ULong SAMPLE_LOST_STATUS = (DDS::ULong) 128UL;
    const DDS::ULong SAMPLE_REJECTED_STATUS = (DDS::ULong) 256UL;
    const DDS::ULong DATA_ON_READERS_STATUS = (DDS::ULong) 512UL;
    const DDS::ULong DATA_AVAILABLE_STATUS = (DDS::ULong) 1024UL;
    const DDS::ULong LIVELINESS_LOST_STATUS = (DDS::ULong) 2048UL;
    const DDS::ULong LIVELINESS_CHANGED_STATUS = (DDS::ULong) 4096UL;
    const DDS::ULong PUBLICATION_MATCHED_STATUS = (DDS::ULong) 8192UL;
    const DDS::ULong SUBSCRIPTION_MATCHED_STATUS = (DDS::ULong) 16384UL;

    /* Opensplice Extensions */
    const DDS::ULong ALL_DATA_DISPOSED_TOPIC_STATUS = (DDS::ULong) 0x80000000UL;

   struct InconsistentTopicStatus
   {
      DDS::Long total_count;
      DDS::Long total_count_change;
   };

   typedef DDS_DCPSStruct_var <InconsistentTopicStatus> InconsistentTopicStatus_var;
   typedef InconsistentTopicStatus&InconsistentTopicStatus_out;

   struct AllDataDisposedTopicStatus
   {
      DDS::Long total_count;
      DDS::Long total_count_change;
   };

   typedef DDS_DCPSStruct_var <AllDataDisposedTopicStatus> AllDataDisposedTopicStatus_var;
   typedef AllDataDisposedTopicStatus&AllDataDisposedTopicStatus_out;

   struct SampleLostStatus
   {
      DDS::Long total_count;
      DDS::Long total_count_change;
   };

   typedef DDS_DCPSStruct_var <SampleLostStatus> SampleLostStatus_var;
   typedef SampleLostStatus&SampleLostStatus_out;
   enum SampleRejectedStatusKind
   {
      NOT_REJECTED,
      REJECTED_BY_INSTANCES_LIMIT,
      REJECTED_BY_SAMPLES_LIMIT,
      REJECTED_BY_SAMPLES_PER_INSTANCE_LIMIT
   };

   struct SampleRejectedStatus
   {
      DDS::Long total_count;
      DDS::Long total_count_change;
      SampleRejectedStatusKind last_reason;
      InstanceHandle_t last_instance_handle;
   };

   typedef DDS_DCPSStruct_var <SampleRejectedStatus> SampleRejectedStatus_var;
   typedef SampleRejectedStatus&SampleRejectedStatus_out;

   struct LivelinessLostStatus
   {
      DDS::Long total_count;
      DDS::Long total_count_change;
   };

   typedef DDS_DCPSStruct_var <LivelinessLostStatus> LivelinessLostStatus_var;
   typedef LivelinessLostStatus&LivelinessLostStatus_out;

   struct LivelinessChangedStatus
   {
      DDS::Long alive_count;
      DDS::Long not_alive_count;
      DDS::Long alive_count_change;
      DDS::Long not_alive_count_change;
      InstanceHandle_t last_publication_handle;
   };

   typedef DDS_DCPSStruct_var <LivelinessChangedStatus> LivelinessChangedStatus_var;
   typedef LivelinessChangedStatus&LivelinessChangedStatus_out;

   struct OfferedDeadlineMissedStatus
   {
      DDS::Long total_count;
      DDS::Long total_count_change;
      InstanceHandle_t last_instance_handle;
   };

   typedef DDS_DCPSStruct_var <OfferedDeadlineMissedStatus> OfferedDeadlineMissedStatus_var;
   typedef OfferedDeadlineMissedStatus&OfferedDeadlineMissedStatus_out;

   struct RequestedDeadlineMissedStatus
   {
      DDS::Long total_count;
      DDS::Long total_count_change;
      InstanceHandle_t last_instance_handle;
   };

   typedef DDS_DCPSStruct_var <RequestedDeadlineMissedStatus> RequestedDeadlineMissedStatus_var;
   typedef RequestedDeadlineMissedStatus&RequestedDeadlineMissedStatus_out;

   struct QosPolicyCount
   {
      QosPolicyId_t policy_id;
      DDS::Long count;
   };

   typedef DDS_DCPSStruct_var <QosPolicyCount> QosPolicyCount_var;
   typedef QosPolicyCount&QosPolicyCount_out;
   struct QosPolicyCountSeq_uniq_ {};
   typedef DDS_DCPSUFLSeq <QosPolicyCount, struct QosPolicyCountSeq_uniq_> QosPolicyCountSeq;
   typedef DDS_DCPSSequence_var <QosPolicyCountSeq> QosPolicyCountSeq_var;
   typedef DDS_DCPSSequence_out <QosPolicyCountSeq> QosPolicyCountSeq_out;

   struct OfferedIncompatibleQosStatus
   {
      DDS::Long total_count;
      DDS::Long total_count_change;
      QosPolicyId_t last_policy_id;
      QosPolicyCountSeq policies;
   };

   typedef DDS_DCPSStruct_var <OfferedIncompatibleQosStatus> OfferedIncompatibleQosStatus_var;
   typedef DDS_DCPSStruct_out <OfferedIncompatibleQosStatus> OfferedIncompatibleQosStatus_out;

   struct RequestedIncompatibleQosStatus
   {
      DDS::Long total_count;
      DDS::Long total_count_change;
      QosPolicyId_t last_policy_id;
      QosPolicyCountSeq policies;
   };

   typedef DDS_DCPSStruct_var <RequestedIncompatibleQosStatus> RequestedIncompatibleQosStatus_var;
   typedef DDS_DCPSStruct_out <RequestedIncompatibleQosStatus> RequestedIncompatibleQosStatus_out;

   struct PublicationMatchedStatus
   {
      DDS::Long total_count;
      DDS::Long total_count_change;
      DDS::Long current_count;
      DDS::Long current_count_change;
      InstanceHandle_t last_subscription_handle;
   };

   typedef DDS_DCPSStruct_var <PublicationMatchedStatus> PublicationMatchedStatus_var;
   typedef PublicationMatchedStatus&PublicationMatchedStatus_out;

   struct SubscriptionMatchedStatus
   {
      DDS::Long total_count;
      DDS::Long total_count_change;
      DDS::Long current_count;
      DDS::Long current_count_change;
      InstanceHandle_t last_publication_handle;
   };

   typedef DDS_DCPSStruct_var <SubscriptionMatchedStatus> SubscriptionMatchedStatus_var;
   typedef SubscriptionMatchedStatus&SubscriptionMatchedStatus_out;

   struct ObjSeq_uniq_ {};
   typedef DDS_DCPSUObjSeq <Object, struct ObjSeq_uniq_> ObjSeq;
   typedef DDS_DCPSSequence_var <ObjSeq> ObjSeq_var;
   typedef DDS_DCPSSequence_out <ObjSeq> ObjSeq_out;
   struct TopicSeq_uniq_ {};
   typedef DDS_DCPSUObjSeq <Topic, struct TopicSeq_uniq_> TopicSeq;
   typedef DDS_DCPSSequence_var <TopicSeq> TopicSeq_var;
   typedef DDS_DCPSSequence_out <TopicSeq> TopicSeq_out;
   struct DataReaderSeq_uniq_ {};
   typedef DDS_DCPSUObjSeq <DataReader, struct DataReaderSeq_uniq_> DataReaderSeq;
   typedef DDS_DCPSSequence_var <DataReaderSeq> DataReaderSeq_var;
   typedef DDS_DCPSSequence_out <DataReaderSeq> DataReaderSeq_out;

   namespace OpenSplice
   {
      class Entity ;
      class Topic ;
      class DataWriter ;
      class Publisher ;
      class DomainParticipant ;
      class DataReader ;
      class Subscriber ;
   }

   class OS_API Listener
   :
      virtual public DDS::LocalObject
   {
      friend class ::DDS::OpenSplice::Entity ;

   public:
      typedef Listener_ptr _ptr_type;
      typedef Listener_var _var_type;

      static Listener_ptr _duplicate (Listener_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static Listener_ptr _narrow (DDS::Object_ptr obj);
      static Listener_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static Listener_ptr _nil () { return NULL; }
      static const char * _local_id;
      Listener_ptr _this () { return this; }

   protected:
      Listener () {};
      ~Listener () {};
      virtual void _set_mask( DDS::StatusMask mask, bool inh = true ) = 0 ;
      dds_listener_t _listener ;

   private:
      Listener (const Listener &);
      Listener & operator = (const Listener &);
   };

extern "C"
{
   void topic_on_inconsistent_topic( void *cpp_listener,
                             dds_inconsistent_topic_status_t * status);
}

 class OS_API TopicListener
   :
      virtual public Listener
   {
      friend class ::DDS::OpenSplice::Topic ;
      friend void ::DDS::topic_on_inconsistent_topic( void *cpp_listener,
                                     dds_inconsistent_topic_status_t *status ) ;
   public:
      typedef TopicListener_ptr _ptr_type;
      typedef TopicListener_var _var_type;

      static TopicListener_ptr _duplicate (TopicListener_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static TopicListener_ptr _narrow (DDS::Object_ptr obj);
      static TopicListener_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static TopicListener_ptr _nil () { return NULL; }
      static const char * _local_id;
      TopicListener_ptr _this () { return this; }

      virtual void on_inconsistent_topic (Topic_ptr the_topic, const InconsistentTopicStatus& status) = 0;

   protected:
      TopicListener () ;
      ~TopicListener () ;
      dds_topiclistener_t *c_topic_listener ;
      DDS::StatusMask _mask ;
      DDS::StatusMask _mergedmask ;

   private:
      TopicListener (const TopicListener &);
      TopicListener & operator = (const TopicListener &);

      Topic_ptr topic ;
      DomainParticipantListener_var _participant_listener ;
      void _set_mask( DDS::StatusMask mask, bool inh ) ;
   };


extern "C"
{
   void datawriter_on_offered_deadline_missed( void *cpp_listener,
                              dds_offered_deadline_missed_status_t *status ) ;
   void datawriter_on_offered_incompatible_qos( void *cpp_listener,
                              dds_offered_incompatible_qos_status_t *status ) ;
   void datawriter_on_liveliness_lost( void *cpp_listener,
                                     dds_liveliness_lost_status_t *status ) ;
   void datawriter_on_publication_matched( void *cpp_listener,
                                 dds_publication_matched_status_t *status ) ;
}

   class OS_API DataWriterListener
   :
      virtual public Listener
   {
      friend class ::DDS::OpenSplice::DataWriter ;
      friend class ::DDS::OpenSplice::Publisher ;
      friend void ::DDS::datawriter_on_offered_deadline_missed( void *,
                                     dds_offered_deadline_missed_status_t * ) ;
      friend void ::DDS::datawriter_on_offered_incompatible_qos( void *,
                                     dds_offered_incompatible_qos_status_t * ) ;
      friend void ::DDS::datawriter_on_liveliness_lost( void *,
                                     dds_liveliness_lost_status_t * ) ;
      friend void ::DDS::datawriter_on_publication_matched( void *,
                                 dds_publication_matched_status_t * ) ;
    public:
      typedef DataWriterListener_ptr _ptr_type;
      typedef DataWriterListener_var _var_type;

      static DataWriterListener_ptr _duplicate (DataWriterListener_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static DataWriterListener_ptr _narrow (DDS::Object_ptr obj);
      static DataWriterListener_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static DataWriterListener_ptr _nil () { return NULL; }
      static const char * _local_id;
      DataWriterListener_ptr _this () { return this; }

      virtual void on_offered_deadline_missed (DataWriter_ptr writer, const OfferedDeadlineMissedStatus& status) = 0;
      virtual void on_offered_incompatible_qos (DataWriter_ptr writer, const OfferedIncompatibleQosStatus& status) = 0;
      virtual void on_liveliness_lost (DataWriter_ptr writer, const LivelinessLostStatus& status) = 0;
      virtual void on_publication_matched (DataWriter_ptr writer, const PublicationMatchedStatus& status) = 0;

   protected:
      DataWriterListener () ;
      ~DataWriterListener () ;
      dds_writerlistener_t *c_writer_listener ;
      DDS::StatusMask _mask ;
      DDS::StatusMask _mergedmask ;

   private:
      DataWriterListener (const DataWriterListener &);
      DataWriterListener & operator = (const DataWriterListener &);

      DataWriter_ptr writer ;
      PublisherListener_var _publisher_listener ;
      void _set_mask( DDS::StatusMask mask, bool inh ) ;
   };


 class OS_API PublisherListener
   :
      virtual public DataWriterListener
   {
      friend class ::DDS::OpenSplice::Publisher ;
      friend class ::DDS::OpenSplice::DomainParticipant ;
      friend class ::DDS::DataWriterListener ;
      friend void ::DDS::datawriter_on_offered_deadline_missed( void *,
                                     dds_offered_deadline_missed_status_t * ) ;
      friend void ::DDS::datawriter_on_offered_incompatible_qos( void *,
                                     dds_offered_incompatible_qos_status_t * ) ;
      friend void ::DDS::datawriter_on_liveliness_lost( void *,
                                     dds_liveliness_lost_status_t * ) ;
      friend void ::DDS::datawriter_on_publication_matched( void *,
                                 dds_publication_matched_status_t * ) ;

   public:
      typedef PublisherListener_ptr _ptr_type;
      typedef PublisherListener_var _var_type;

      static PublisherListener_ptr _duplicate (PublisherListener_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static PublisherListener_ptr _narrow (DDS::Object_ptr obj);
      static PublisherListener_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static PublisherListener_ptr _nil () { return NULL; }
      static const char * _local_id;
      PublisherListener_ptr _this () { return this; }

   protected:
      PublisherListener () ;
      ~PublisherListener () ;
      dds_publisherlistener_t *c_publisher_listener ;
      DDS::StatusMask _mask ;
      DDS::StatusMask _mergedmask ;

   private:
      PublisherListener (const PublisherListener &);
      PublisherListener & operator = (const PublisherListener &);

      Publisher_ptr publisher ;
      DomainParticipantListener_var _participant_listener ;
      void _set_mask( DDS::StatusMask mask, bool inh ) ;
   };

extern "C"
{
   void datareader_on_requested_deadline_missed( void *cpp_listener,
                             dds_requested_deadline_missed_status_t * status);
   void datareader_on_requested_incompatible_qos( void *cpp_listener,
                             dds_requested_incompatible_qos_status_t * status);
   void datareader_on_sample_rejected( void *cpp_listener,
                             dds_sample_rejected_status_t * status);
   void datareader_on_liveliness_changed( void *cpp_listener,
                                  dds_liveliness_changed_status_t * status);
   void datareader_on_data_available( void *cpp_listener ) ;
   void datareader_on_subscription_matched( void *cpp_listener,
                                  dds_subscription_matched_status_t * status);
   void datareader_on_sample_lost( void *cpp_listener,
                                  dds_sample_lost_status_t * status);
}

   class OS_API DataReaderListener
   :
      virtual public Listener
   {
      friend class DDS::OpenSplice::DataReader ;
      friend class DDS::OpenSplice::Subscriber ;
      friend class SubscriberListener ;
      friend void ::DDS::datareader_on_requested_deadline_missed( void *,
                             dds_requested_deadline_missed_status_t * );
      friend void ::DDS::datareader_on_requested_incompatible_qos( void *,
                             dds_requested_incompatible_qos_status_t * );
      friend void ::DDS::datareader_on_sample_rejected( void *,
                             dds_sample_rejected_status_t *);
      friend void ::DDS::datareader_on_liveliness_changed( void *,
                                  dds_liveliness_changed_status_t * );
      friend void ::DDS::datareader_on_data_available( void * ) ;
      friend void ::DDS::datareader_on_subscription_matched( void *,
                                  dds_subscription_matched_status_t * );
      friend void ::DDS::datareader_on_sample_lost( void *,
                                  dds_sample_lost_status_t * );

   public:
      typedef DataReaderListener_ptr _ptr_type;
      typedef DataReaderListener_var _var_type;

      static DataReaderListener_ptr _duplicate (DataReaderListener_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static DataReaderListener_ptr _narrow (DDS::Object_ptr obj);
      static DataReaderListener_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static DataReaderListener_ptr _nil () { return NULL; }
      static const char * _local_id;
      DataReaderListener_ptr _this () { return this; }

      virtual void on_requested_deadline_missed (DataReader_ptr reader, const RequestedDeadlineMissedStatus& status) = 0;
      virtual void on_requested_incompatible_qos (DataReader_ptr reader, const RequestedIncompatibleQosStatus& status) = 0;
      virtual void on_sample_rejected (DataReader_ptr reader, const SampleRejectedStatus& status) = 0;
      virtual void on_liveliness_changed (DataReader_ptr reader, const LivelinessChangedStatus& status) = 0;
      virtual void on_data_available (DataReader_ptr reader) = 0;
      virtual void on_subscription_matched (DataReader_ptr reader, const SubscriptionMatchedStatus& status) = 0;
      virtual void on_sample_lost (DataReader_ptr reader, const SampleLostStatus& status) = 0;

   protected:
      DataReaderListener () ;
      ~DataReaderListener () ;
      dds_readerlistener_t *c_reader_listener ;
      DDS::StatusMask _mask ;
      DDS::StatusMask _mergedmask ;

   private:
      DataReaderListener (const DataReaderListener &);
      DataReaderListener & operator = (const DataReaderListener &);

      DataReader_ptr reader ;
      SubscriberListener_var _subscriber_listener ;
      void _set_mask( DDS::StatusMask mask, bool inh ) ;
      void _merge_from_s() ;
   };

extern "C"
{
   void subscriber_on_data_readers( void *cpp_listener ) ;
}

   class OS_API SubscriberListener
   :
      virtual public DataReaderListener
   {
      friend class DDS::OpenSplice::Subscriber ;
      friend class DDS::OpenSplice::DomainParticipant ;
      friend class DDS::DataReaderListener ;
      friend void ::DDS::datareader_on_requested_deadline_missed( void *,
                             dds_requested_deadline_missed_status_t * );
      friend void ::DDS::datareader_on_requested_incompatible_qos( void *,
                             dds_requested_incompatible_qos_status_t * );
      friend void ::DDS::datareader_on_sample_rejected( void *,
                             dds_sample_rejected_status_t *);
      friend void ::DDS::datareader_on_liveliness_changed( void *,
                                  dds_liveliness_changed_status_t * );
      friend void ::DDS::datareader_on_data_available( void * ) ;
      friend void ::DDS::datareader_on_subscription_matched( void *,
                                  dds_subscription_matched_status_t * );
      friend void ::DDS::datareader_on_sample_lost( void *,
                                  dds_sample_lost_status_t * );
      friend void ::DDS::subscriber_on_data_readers( void * ) ;
   public:
      typedef SubscriberListener_ptr _ptr_type;
      typedef SubscriberListener_var _var_type;

      static SubscriberListener_ptr _duplicate (SubscriberListener_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static SubscriberListener_ptr _narrow (DDS::Object_ptr obj);
      static SubscriberListener_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static SubscriberListener_ptr _nil () { return NULL; }
      static const char * _local_id;
      SubscriberListener_ptr _this () { return this; }

      virtual void on_data_on_readers (Subscriber_ptr subs) = 0;

   protected:
      SubscriberListener () ;
      ~SubscriberListener () ;
      dds_subscriberlistener_t *c_subscriber_listener ;
      DDS::StatusMask _mask ;
      DDS::StatusMask _mergedmask ;

   private:
      SubscriberListener (const SubscriberListener &);
      SubscriberListener & operator = (const SubscriberListener &);

      static bool mergeReaderListeners( DDS::Object_ptr object, void *arg );

      Subscriber_ptr subscriber ;
      DomainParticipantListener_var _participant_listener ;
      void _set_mask( DDS::StatusMask mask, bool inh ) ;
   };


   class OS_API DomainParticipantListener
   :
      virtual public TopicListener,
      virtual public PublisherListener,
      virtual public SubscriberListener
   {
      friend class DDS::OpenSplice::DomainParticipant ;
      friend class DDS::TopicListener ;
      friend class DDS::DataWriterListener ;
      friend class DDS::PublisherListener ;
      friend class DDS::SubscriberListener ;
      friend void ::DDS::datareader_on_requested_deadline_missed( void *,
                             dds_requested_deadline_missed_status_t * );
      friend void ::DDS::datareader_on_requested_incompatible_qos( void *,
                             dds_requested_incompatible_qos_status_t * );
      friend void ::DDS::datareader_on_sample_rejected( void *,
                             dds_sample_rejected_status_t *);
      friend void ::DDS::datareader_on_liveliness_changed( void *,
                                  dds_liveliness_changed_status_t * );
      friend void ::DDS::datareader_on_data_available( void * ) ;
      friend void ::DDS::datareader_on_subscription_matched( void *,
                                  dds_subscription_matched_status_t * );
      friend void ::DDS::datareader_on_sample_lost( void *,
                                  dds_sample_lost_status_t * );
      friend void ::DDS::subscriber_on_data_readers( void * ) ;
      friend void ::DDS::datawriter_on_offered_deadline_missed( void *,
                                     dds_offered_deadline_missed_status_t * ) ;
      friend void ::DDS::datawriter_on_offered_incompatible_qos( void *,
                                     dds_offered_incompatible_qos_status_t * ) ;
      friend void ::DDS::datawriter_on_liveliness_lost( void *,
                                     dds_liveliness_lost_status_t * ) ;
      friend void ::DDS::datawriter_on_publication_matched( void *,
                                 dds_publication_matched_status_t * ) ;
      friend void ::DDS::topic_on_inconsistent_topic( void *cpp_listener,
                                     dds_inconsistent_topic_status_t *status ) ;

   public:
      typedef DomainParticipantListener_ptr _ptr_type;
      typedef DomainParticipantListener_var _var_type;

      static DomainParticipantListener_ptr _duplicate (DomainParticipantListener_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static DomainParticipantListener_ptr _narrow (DDS::Object_ptr obj);
      static DomainParticipantListener_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static DomainParticipantListener_ptr _nil () { return NULL; }
      static const char * _local_id;
      DomainParticipantListener_ptr _this () { return this; }

   protected:
      DomainParticipantListener () ;
      ~DomainParticipantListener () ;
      DDS::StatusMask _mask ;
      DDS::StatusMask _mergedmask ;

   private:
      DomainParticipantListener (const DomainParticipantListener &);
      DomainParticipantListener & operator = (const DomainParticipantListener &);

      dds_participantlistener_t *c_participant_listener ;
      DomainParticipant_ptr participant ;
      void _set_mask( DDS::StatusMask mask, bool inh ) ;
   };


   class OS_API Condition
   :
      virtual public DDS::LocalObject
   {
   public:
      typedef Condition_ptr _ptr_type;
      typedef Condition_var _var_type;

      static Condition_ptr _duplicate (Condition_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static Condition_ptr _narrow (DDS::Object_ptr obj);
      static Condition_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static Condition_ptr _nil () { return NULL; }
      static const char * _local_id;
      Condition_ptr _this () { return this; }

      virtual DDS::Boolean get_trigger_value () = 0;

   protected:
      Condition () {};
      ~Condition () {};
   private:
      Condition (const Condition &);
      Condition & operator = (const Condition &);
   };


   struct ConditionSeq_uniq_ {};
   typedef DDS_DCPSUObjSeq <Condition, struct ConditionSeq_uniq_> ConditionSeq;
   typedef DDS_DCPSSequence_var <ConditionSeq> ConditionSeq_var;
   typedef DDS_DCPSSequence_out <ConditionSeq> ConditionSeq_out;
   class OS_API WaitSetInterface
   :
      virtual public DDS::LocalObject
   {
   public:
      typedef WaitSetInterface_ptr _ptr_type;
      typedef WaitSetInterface_var _var_type;

      static WaitSetInterface_ptr _duplicate (WaitSetInterface_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static WaitSetInterface_ptr _narrow (DDS::Object_ptr obj);
      static WaitSetInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static WaitSetInterface_ptr _nil () { return NULL; }
      static const char * _local_id;
      WaitSetInterface_ptr _this () { return this; }

      virtual ReturnCode_t wait (ConditionSeq& active_conditions, const Duration_t& timeout) = 0;
      virtual ReturnCode_t attach_condition (Condition_ptr cond) = 0;
      virtual ReturnCode_t detach_condition (Condition_ptr cond) = 0;
      virtual ReturnCode_t get_conditions (ConditionSeq& attached_conditions) = 0;

   protected:
      WaitSetInterface () {};
      ~WaitSetInterface () {};
   private:
      WaitSetInterface (const WaitSetInterface &);
      WaitSetInterface & operator = (const WaitSetInterface &);
   };


   class OS_API GuardConditionInterface
   :
      virtual public Condition
   {
   public:
      typedef GuardConditionInterface_ptr _ptr_type;
      typedef GuardConditionInterface_var _var_type;

      static GuardConditionInterface_ptr _duplicate (GuardConditionInterface_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static GuardConditionInterface_ptr _narrow (DDS::Object_ptr obj);
      static GuardConditionInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static GuardConditionInterface_ptr _nil () { return NULL; }
      static const char * _local_id;
      GuardConditionInterface_ptr _this () { return this; }

      virtual ReturnCode_t set_trigger_value (DDS::Boolean value) = 0;

   protected:
      GuardConditionInterface () {};
      ~GuardConditionInterface () {};
   private:
      GuardConditionInterface (const GuardConditionInterface &);
      GuardConditionInterface & operator = (const GuardConditionInterface &);
   };


   class OS_API StatusCondition
   :
      virtual public Condition
   {
   public:
      typedef StatusCondition_ptr _ptr_type;
      typedef StatusCondition_var _var_type;

      static StatusCondition_ptr _duplicate (StatusCondition_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static StatusCondition_ptr _narrow (DDS::Object_ptr obj);
      static StatusCondition_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static StatusCondition_ptr _nil () { return NULL; }
      static const char * _local_id;
      StatusCondition_ptr _this () { return this; }

      virtual StatusMask get_enabled_statuses () = 0;
      virtual ReturnCode_t set_enabled_statuses (StatusMask mask) = 0;
      virtual Entity_ptr get_entity () = 0;

   protected:
      StatusCondition () {};
      ~StatusCondition () {};
   private:
      StatusCondition (const StatusCondition &);
      StatusCondition & operator = (const StatusCondition &);
   };


   typedef DDS::ULong SampleStateKind;

   struct SampleStateSeq_uniq_ {};
   typedef DDS_DCPSUFLSeq <SampleStateKind, struct SampleStateSeq_uniq_> SampleStateSeq;
   typedef DDS_DCPSSequence_var <SampleStateSeq> SampleStateSeq_var;
   typedef DDS_DCPSSequence_out <SampleStateSeq> SampleStateSeq_out;
    const DDS::ULong READ_SAMPLE_STATE = (DDS::ULong) 1UL;
    const DDS::ULong NOT_READ_SAMPLE_STATE = (DDS::ULong) 2UL;
   typedef DDS::ULong SampleStateMask;

    const DDS::ULong ANY_SAMPLE_STATE = (DDS::ULong) 65535UL;
   typedef DDS::ULong ViewStateKind;

   struct ViewStateSeq_uniq_ {};
   typedef DDS_DCPSUFLSeq <ViewStateKind, struct ViewStateSeq_uniq_> ViewStateSeq;
   typedef DDS_DCPSSequence_var <ViewStateSeq> ViewStateSeq_var;
   typedef DDS_DCPSSequence_out <ViewStateSeq> ViewStateSeq_out;
    const DDS::ULong NEW_VIEW_STATE = (DDS::ULong) 1UL;
    const DDS::ULong NOT_NEW_VIEW_STATE = (DDS::ULong) 2UL;
   typedef DDS::ULong ViewStateMask;

    const DDS::ULong ANY_VIEW_STATE = (DDS::ULong) 65535UL;
   typedef DDS::ULong InstanceStateKind;

   struct InstanceStateSeq_uniq_ {};
   typedef DDS_DCPSUFLSeq <InstanceStateKind, struct InstanceStateSeq_uniq_> InstanceStateSeq;
   typedef DDS_DCPSSequence_var <InstanceStateSeq> InstanceStateSeq_var;
   typedef DDS_DCPSSequence_out <InstanceStateSeq> InstanceStateSeq_out;
    const DDS::ULong ALIVE_INSTANCE_STATE = (DDS::ULong) 1UL;
    const DDS::ULong NOT_ALIVE_DISPOSED_INSTANCE_STATE = (DDS::ULong) 2UL;
    const DDS::ULong NOT_ALIVE_NO_WRITERS_INSTANCE_STATE = (DDS::ULong) 4UL;
   typedef DDS::ULong InstanceStateMask;

    const DDS::ULong ANY_INSTANCE_STATE = (DDS::ULong) 65535UL;
    const DDS::ULong NOT_ALIVE_INSTANCE_STATE = (DDS::ULong) 6UL;
   class OS_API ReadCondition
   :
      virtual public Condition
   {
   public:
      typedef ReadCondition_ptr _ptr_type;
      typedef ReadCondition_var _var_type;

      static ReadCondition_ptr _duplicate (ReadCondition_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static ReadCondition_ptr _narrow (DDS::Object_ptr obj);
      static ReadCondition_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static ReadCondition_ptr _nil () { return NULL; }
      static const char * _local_id;
      ReadCondition_ptr _this () { return this; }

      virtual SampleStateMask get_sample_state_mask () = 0;
      virtual ViewStateMask get_view_state_mask () = 0;
      virtual InstanceStateMask get_instance_state_mask () = 0;
      virtual DataReader_ptr get_datareader () = 0;

   protected:
      ReadCondition () {};
      ~ReadCondition () {};
   private:
      ReadCondition (const ReadCondition &);
      ReadCondition & operator = (const ReadCondition &);
   };


   class OS_API QueryCondition
   :
      virtual public ReadCondition
   {
   public:
      typedef QueryCondition_ptr _ptr_type;
      typedef QueryCondition_var _var_type;

      static QueryCondition_ptr _duplicate (QueryCondition_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static QueryCondition_ptr _narrow (DDS::Object_ptr obj);
      static QueryCondition_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static QueryCondition_ptr _nil () { return NULL; }
      static const char * _local_id;
      QueryCondition_ptr _this () { return this; }

      virtual DDS::String get_query_expression () = 0;
      virtual ReturnCode_t get_query_parameters (StringSeq& query_parameters) = 0;
      virtual ReturnCode_t set_query_parameters (const StringSeq& query_parameters) = 0;

   protected:
      QueryCondition () {};
      ~QueryCondition () {};
   private:
      QueryCondition (const QueryCondition &);
      QueryCondition & operator = (const QueryCondition &);
   };


    const DDS::String USERDATA_QOS_POLICY_NAME = (DDS::String) "UserData";
    const DDS::String DURABILITY_QOS_POLICY_NAME = (DDS::String) "Durability";
    const DDS::String PRESENTATION_QOS_POLICY_NAME = (DDS::String) "Presentation";
    const DDS::String DEADLINE_QOS_POLICY_NAME = (DDS::String) "Deadline";
    const DDS::String LATENCYBUDGET_QOS_POLICY_NAME = (DDS::String) "LatencyBudget";
    const DDS::String OWNERSHIP_QOS_POLICY_NAME = (DDS::String) "Ownership";
    const DDS::String OWNERSHIPSTRENGTH_QOS_POLICY_NAME = (DDS::String) "OwnershipStrength";
    const DDS::String LIVELINESS_QOS_POLICY_NAME = (DDS::String) "Liveliness";
    const DDS::String TIMEBASEDFILTER_QOS_POLICY_NAME = (DDS::String) "TimeBasedFilter";
    const DDS::String PARTITION_QOS_POLICY_NAME = (DDS::String) "Partition";
    const DDS::String RELIABILITY_QOS_POLICY_NAME = (DDS::String) "Reliability";
    const DDS::String DESTINATIONORDER_QOS_POLICY_NAME = (DDS::String) "DestinationOrder";
    const DDS::String HISTORY_QOS_POLICY_NAME = (DDS::String) "History";
    const DDS::String RESOURCELIMITS_QOS_POLICY_NAME = (DDS::String) "ResourceLimits";
    const DDS::String ENTITYFACTORY_QOS_POLICY_NAME = (DDS::String) "EntityFactory";
    const DDS::String WRITERDATALIFECYCLE_QOS_POLICY_NAME = (DDS::String) "WriterDataLifecycle";
    const DDS::String READERDATALIFECYCLE_QOS_POLICY_NAME = (DDS::String) "ReaderDataLifecycle";
    const DDS::String TOPICDATA_QOS_POLICY_NAME = (DDS::String) "TopicData";
    const DDS::String GROUPDATA_QOS_POLICY_NAME = (DDS::String) "GroupData";
    const DDS::String TRANSPORTPRIORITY_QOS_POLICY_NAME = (DDS::String) "TransportPriority";
    const DDS::String LIFESPAN_QOS_POLICY_NAME = (DDS::String) "Lifespan";
    const DDS::String DURABILITYSERVICE_QOS_POLICY_NAME = (DDS::String) "DurabilityService";
    const DDS::String SUBSCRIPTIONKEY_QOS_POLICY_NAME        = (DDS::String)"SubscriptionKey";
    const DDS::String VIEWKEY_QOS_POLICY_NAME                = (DDS::String)"ViewKey";
    const DDS::String READERLIFESPAN_QOS_POLICY_NAME         = (DDS::String)"ReaderLifespan";
    const DDS::String SHARE_QOS_POLICY_NAME                  = (DDS::String)"Share";
    const DDS::String SCHEDULING_QOS_POLICY_NAME = (DDS::String) "Scheduling";

    const DDS::Long INVALID_QOS_POLICY_ID = (DDS::Long) 0UL;
    const DDS::Long USERDATA_QOS_POLICY_ID = (DDS::Long) 1UL;
    const DDS::Long DURABILITY_QOS_POLICY_ID = (DDS::Long) 2UL;
    const DDS::Long PRESENTATION_QOS_POLICY_ID = (DDS::Long) 3UL;
    const DDS::Long DEADLINE_QOS_POLICY_ID = (DDS::Long) 4UL;
    const DDS::Long LATENCYBUDGET_QOS_POLICY_ID = (DDS::Long) 5UL;
    const DDS::Long OWNERSHIP_QOS_POLICY_ID = (DDS::Long) 6UL;
    const DDS::Long OWNERSHIPSTRENGTH_QOS_POLICY_ID = (DDS::Long) 7UL;
    const DDS::Long LIVELINESS_QOS_POLICY_ID = (DDS::Long) 8UL;
    const DDS::Long TIMEBASEDFILTER_QOS_POLICY_ID = (DDS::Long) 9UL;
    const DDS::Long PARTITION_QOS_POLICY_ID = (DDS::Long) 10UL;
    const DDS::Long RELIABILITY_QOS_POLICY_ID = (DDS::Long) 11UL;
    const DDS::Long DESTINATIONORDER_QOS_POLICY_ID = (DDS::Long) 12UL;
    const DDS::Long HISTORY_QOS_POLICY_ID = (DDS::Long) 13UL;
    const DDS::Long RESOURCELIMITS_QOS_POLICY_ID = (DDS::Long) 14UL;
    const DDS::Long ENTITYFACTORY_QOS_POLICY_ID = (DDS::Long) 15UL;
    const DDS::Long WRITERDATALIFECYCLE_QOS_POLICY_ID = (DDS::Long) 16UL;
    const DDS::Long READERDATALIFECYCLE_QOS_POLICY_ID = (DDS::Long) 17UL;
    const DDS::Long TOPICDATA_QOS_POLICY_ID = (DDS::Long) 18UL;
    const DDS::Long GROUPDATA_QOS_POLICY_ID = (DDS::Long) 19UL;
    const DDS::Long TRANSPORTPRIORITY_QOS_POLICY_ID = (DDS::Long) 20UL;
    const DDS::Long LIFESPAN_QOS_POLICY_ID = (DDS::Long) 21UL;
    const DDS::Long DURABILITYSERVICE_QOS_POLICY_ID = (DDS::Long) 22UL;
    const DDS::Long SUBSCRIPTIONKEY_QOS_POLICY_ID       = (DDS::Long)23UL;
    const DDS::Long VIEWKEY_QOS_POLICY_ID               = (DDS::Long)24UL;
    const DDS::Long READERLIFESPAN_QOS_POLICY_ID        = (DDS::Long)25UL;
    const DDS::Long SHARE_QOS_POLICY_ID                 = (DDS::Long)26UL;
    const DDS::Long SCHEDULING_QOS_POLICY_ID = (DDS::Long) 27UL;
   class OS_API Entity
   :
      virtual public DDS::LocalObject
   {
   public:
      typedef Entity_ptr _ptr_type;
      typedef Entity_var _var_type;

      static Entity_ptr _duplicate (Entity_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static Entity_ptr _narrow (DDS::Object_ptr obj);
      static Entity_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static Entity_ptr _nil () { return NULL; }
      static const char * _local_id;
      Entity_ptr _this () { return this; }

      virtual StatusCondition_ptr get_statuscondition () = 0;
      virtual StatusMask get_status_changes () = 0;
      virtual InstanceHandle_t get_instance_handle () = 0;

   protected:
      Entity () {};
      ~Entity () {};
   private:
      Entity (const Entity &);
      Entity & operator = (const Entity &);
   };


   class OS_API DomainParticipant
   :
      virtual public Entity
   {
   public:
      typedef DomainParticipant_ptr _ptr_type;
      typedef DomainParticipant_var _var_type;

      static DomainParticipant_ptr _duplicate (DomainParticipant_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static DomainParticipant_ptr _narrow (DDS::Object_ptr obj);
      static DomainParticipant_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static DomainParticipant_ptr _nil () { return NULL; }
      static const char * _local_id;
      DomainParticipant_ptr _this () { return this; }

      virtual Publisher_ptr create_publisher (const PublisherQos& qos, PublisherListener_ptr a_listener, StatusMask mask) = 0;
      virtual ReturnCode_t delete_publisher (Publisher_ptr p) = 0;
      virtual Subscriber_ptr create_subscriber (const SubscriberQos& qos, SubscriberListener_ptr a_listener, StatusMask mask) = 0;
      virtual ReturnCode_t delete_subscriber (Subscriber_ptr s) = 0;
      virtual Subscriber_ptr get_builtin_subscriber () = 0;
      virtual Topic_ptr create_topic (const DDS::Char* topic_name, const DDS::Char* type_name, const TopicQos& qos, TopicListener_ptr a_listener, StatusMask mask) = 0;
      virtual ReturnCode_t delete_topic (Topic_ptr a_topic) = 0;
      virtual Topic_ptr find_topic (const DDS::Char* topic_name, const Duration_t& timeout) = 0;
      virtual TopicDescription_ptr lookup_topicdescription (const DDS::Char* name) = 0;
      virtual ContentFilteredTopic_ptr create_contentfilteredtopic (const DDS::Char* name, Topic_ptr related_topic, const DDS::Char* filter_expression, const StringSeq& filter_parameters) = 0;
      virtual ReturnCode_t delete_contentfilteredtopic (ContentFilteredTopic_ptr a_contentfilteredtopic) = 0;
      virtual MultiTopic_ptr create_multitopic (const DDS::Char* name, const DDS::Char* type_name, const DDS::Char* subscription_expression, const StringSeq& expression_parameters) = 0;
      virtual ReturnCode_t delete_multitopic (MultiTopic_ptr a_multitopic) = 0;
      virtual ReturnCode_t delete_contained_entities () = 0;
      virtual ReturnCode_t set_qos (const DomainParticipantQos& qos) = 0;
      virtual ReturnCode_t get_qos (DomainParticipantQos& qos) = 0;
      virtual ReturnCode_t set_listener (DomainParticipantListener_ptr a_listener, StatusMask mask) = 0;
      virtual DomainParticipantListener_ptr get_listener () = 0;
      virtual ReturnCode_t ignore_participant (InstanceHandle_t handle) = 0;
      virtual ReturnCode_t ignore_topic (InstanceHandle_t handle) = 0;
      virtual ReturnCode_t ignore_publication (InstanceHandle_t handle) = 0;
      virtual ReturnCode_t ignore_subscription (InstanceHandle_t handle) = 0;
      virtual DDS::DomainId_t get_domain_id () = 0;
      virtual ReturnCode_t assert_liveliness () = 0;
      virtual ReturnCode_t set_default_publisher_qos (const PublisherQos& qos) = 0;
      virtual ReturnCode_t get_default_publisher_qos (PublisherQos& qos) = 0;
      virtual ReturnCode_t set_default_subscriber_qos (const SubscriberQos& qos) = 0;
      virtual ReturnCode_t get_default_subscriber_qos (SubscriberQos& qos) = 0;
      virtual ReturnCode_t set_default_topic_qos (const TopicQos& qos) = 0;
      virtual ReturnCode_t get_default_topic_qos (TopicQos& qos) = 0;
      virtual ReturnCode_t get_discovered_participants (InstanceHandleSeq& participant_handles) = 0;
      virtual ReturnCode_t get_discovered_participant_data (ParticipantBuiltinTopicData& participant_data, InstanceHandle_t participant_handle) = 0;
      virtual ReturnCode_t get_discovered_topics (InstanceHandleSeq& topic_handles) = 0;
      virtual ReturnCode_t get_discovered_topic_data (TopicBuiltinTopicData& topic_data, InstanceHandle_t topic_handle) = 0;
      virtual DDS::Boolean contains_entity (InstanceHandle_t a_handle) = 0;
      virtual ReturnCode_t get_current_time (Time_t& current_time) = 0;

   protected:
      DomainParticipant () {};
      ~DomainParticipant () {};
   private:
      DomainParticipant (const DomainParticipant &);
      DomainParticipant & operator = (const DomainParticipant &);
   };


   class OS_API Domain
   :
      virtual public DDS::LocalObject
   {
   public:
      typedef Domain_ptr _ptr_type;
      typedef Domain_var _var_type;

      static Domain_ptr _duplicate (Domain_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static Domain_ptr _narrow (DDS::Object_ptr obj);
      static Domain_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static Domain_ptr _nil () { return NULL; }
      static const char * _local_id;
      Domain_ptr _this () { return this; }

      virtual DDS::DomainId_t get_domain_id() = 0;

   protected:
      Domain () {};
      ~Domain () {};
   private:
      Domain (const Domain &);
      Domain & operator = (const Domain &);
   };

   class OS_API DomainParticipantFactoryInterface
   :
      virtual public DDS::LocalObject
   {
   public:
      typedef DomainParticipantFactoryInterface_ptr _ptr_type;
      typedef DomainParticipantFactoryInterface_var _var_type;

      static DomainParticipantFactoryInterface_ptr _duplicate (DomainParticipantFactoryInterface_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static DomainParticipantFactoryInterface_ptr _narrow (DDS::Object_ptr obj);
      static DomainParticipantFactoryInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static DomainParticipantFactoryInterface_ptr _nil () { return NULL; }
      static const char * _local_id;
      DomainParticipantFactoryInterface_ptr _this () { return this; }

      virtual DomainParticipant_ptr create_participant (DDS::DomainId_t domainId, const DomainParticipantQos& qos, DomainParticipantListener_ptr a_listener, StatusMask mask) = 0;

      virtual ReturnCode_t delete_participant (DomainParticipant_ptr a_participant) = 0;
      virtual DomainParticipant_ptr lookup_participant (DDS::DomainId_t domainId) = 0;
      virtual ReturnCode_t set_default_participant_qos (const DomainParticipantQos& qos) = 0;
      virtual ReturnCode_t get_default_participant_qos (DomainParticipantQos& qos) = 0;
      virtual ReturnCode_t delete_contained_entities () = 0;

   protected:
      DomainParticipantFactoryInterface () {};
      ~DomainParticipantFactoryInterface () {};
   private:
      DomainParticipantFactoryInterface (const DomainParticipantFactoryInterface &);
      DomainParticipantFactoryInterface & operator = (const DomainParticipantFactoryInterface &);
   };


   class OS_API TypeSupport
   :
      virtual public DDS::LocalObject
   {
   public:
      typedef TypeSupport_ptr _ptr_type;
      typedef TypeSupport_var _var_type;

      static TypeSupport_ptr _duplicate (TypeSupport_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static TypeSupport_ptr _narrow (DDS::Object_ptr obj);
      static TypeSupport_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static TypeSupport_ptr _nil () { return NULL; }
      static const char * _local_id;
      TypeSupport_ptr _this () { return this; }

      virtual ReturnCode_t register_type (DomainParticipant_ptr domain, const DDS::Char* type_name) = 0;
      virtual DDS::String get_type_name () = 0;

   protected:
      TypeSupport () {};
      ~TypeSupport () {};
   private:
      TypeSupport (const TypeSupport &);
      TypeSupport & operator = (const TypeSupport &);
   };


   class OS_API TopicDescription
   :
       virtual public DDS::LocalObject
   {
   public:
      typedef TopicDescription_ptr _ptr_type;
      typedef TopicDescription_var _var_type;

      static TopicDescription_ptr _duplicate (TopicDescription_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static TopicDescription_ptr _narrow (DDS::Object_ptr obj);
      static TopicDescription_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static TopicDescription_ptr _nil () { return NULL; }
      static const char * _local_id;
      TopicDescription_ptr _this () { return this; }

      virtual DDS::String get_type_name () = 0;
      virtual DDS::String get_name () = 0;
      virtual DomainParticipant_ptr get_participant () = 0;

   protected:
      TopicDescription () {};
      ~TopicDescription () {};
   private:
      TopicDescription (const TopicDescription &);
      TopicDescription & operator = (const TopicDescription &);
   };


   class OS_API Topic
   :
      virtual public Entity,
      virtual public TopicDescription
   {
   public:
      typedef Topic_ptr _ptr_type;
      typedef Topic_var _var_type;
/**
 * Filter function definition
 * @param sample The candidate sample
 * @returns Return true if the sample should be passed to the DataReaders,
 *   false if it is to be filtered out.
 */
      typedef bool (*Filter_fn) (const void * sample);

      static Topic_ptr _duplicate (Topic_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static Topic_ptr _narrow (DDS::Object_ptr obj);
      static Topic_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static Topic_ptr _nil () { return NULL; }
      static const char * _local_id;
      Topic_ptr _this () { return this; }

      virtual ReturnCode_t get_inconsistent_topic_status (InconsistentTopicStatus& a_status) = 0;
      virtual ReturnCode_t get_qos (TopicQos& qos) = 0;
      virtual ReturnCode_t set_qos (const TopicQos& qos) = 0;
      virtual TopicListener_ptr get_listener () = 0;
      virtual ReturnCode_t set_listener (TopicListener_ptr a_listener, StatusMask mask) = 0;
/**
 * Sets a filter on a topic.
 * @param filter The filter function used to filter topic samples.
 */
      virtual ReturnCode_t set_filter (Filter_fn filter) = 0;
/**
 * Gets a topic's filter.
 * @param filter Is set on exit to the topic filter function.
 */
      virtual ReturnCode_t get_filter (Filter_fn &filter) = 0;

   protected:
      Topic () {};
      ~Topic () {};
   private:
      Topic (const Topic &);
      Topic & operator = (const Topic &);
   };


   class OS_API ContentFilteredTopic
   :
      virtual public TopicDescription
   {
   public:
      typedef ContentFilteredTopic_ptr _ptr_type;
      typedef ContentFilteredTopic_var _var_type;

      static ContentFilteredTopic_ptr _duplicate (ContentFilteredTopic_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static ContentFilteredTopic_ptr _narrow (DDS::Object_ptr obj);
      static ContentFilteredTopic_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static ContentFilteredTopic_ptr _nil () { return NULL; }
      static const char * _local_id;
      ContentFilteredTopic_ptr _this () { return this; }

      virtual DDS::String get_filter_expression () = 0;
      virtual ReturnCode_t get_expression_parameters (StringSeq& expression_parameters) = 0;
      virtual ReturnCode_t set_expression_parameters (const StringSeq& expression_parameters) = 0;
      virtual Topic_ptr get_related_topic () = 0;

   protected:
      ContentFilteredTopic () {};
      ~ContentFilteredTopic () {};
   private:
      ContentFilteredTopic (const ContentFilteredTopic &);
      ContentFilteredTopic & operator = (const ContentFilteredTopic &);
   };

/*
   class OS_API MultiTopic
   :
      virtual public TopicDescription
   {
   public:
      typedef MultiTopic_ptr _ptr_type;
      typedef MultiTopic_var _var_type;

      static MultiTopic_ptr _duplicate (MultiTopic_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static MultiTopic_ptr _narrow (DDS::Object_ptr obj);
      static MultiTopic_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static MultiTopic_ptr _nil () { return NULL; }
      static const char * _local_id;
      MultiTopic_ptr _this () { return this; }

      virtual DDS::String get_subscription_expression () = 0;
      virtual ReturnCode_t get_expression_parameters (StringSeq& expression_parameters) = 0;
      virtual ReturnCode_t set_expression_parameters (const StringSeq& expression_parameters) = 0;

   protected:
      MultiTopic () {};
      ~MultiTopic () {};
   private:
      MultiTopic (const MultiTopic &);
      MultiTopic & operator = (const MultiTopic &);
   };
*/

   class OS_API Publisher
   :
      virtual public Entity
   {
   public:
      typedef Publisher_ptr _ptr_type;
      typedef Publisher_var _var_type;

      static Publisher_ptr _duplicate (Publisher_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static Publisher_ptr _narrow (DDS::Object_ptr obj);
      static Publisher_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static Publisher_ptr _nil () { return NULL; }
      static const char * _local_id;
      Publisher_ptr _this () { return this; }

      virtual DataWriter_ptr create_datawriter (Topic_ptr a_topic, const DataWriterQos& qos, DataWriterListener_ptr a_listener, StatusMask mask) = 0;
      virtual ReturnCode_t delete_datawriter (DataWriter_ptr a_datawriter) = 0;
      virtual DataWriter_ptr lookup_datawriter (const DDS::Char* topic_name) = 0;
      virtual ReturnCode_t delete_contained_entities () = 0;
      virtual ReturnCode_t set_qos (const PublisherQos& qos) = 0;
      virtual ReturnCode_t get_qos (PublisherQos& qos) = 0;
      virtual ReturnCode_t set_listener (PublisherListener_ptr a_listener, StatusMask mask) = 0;
      virtual PublisherListener_ptr get_listener () = 0;
      virtual ReturnCode_t suspend_publications () = 0;
      virtual ReturnCode_t resume_publications () = 0;
      virtual ReturnCode_t begin_coherent_changes () = 0;
      virtual ReturnCode_t end_coherent_changes () = 0;
      virtual ReturnCode_t wait_for_acknowledgments (const Duration_t& max_wait) = 0;
      virtual DomainParticipant_ptr get_participant () = 0;
      virtual ReturnCode_t set_default_datawriter_qos (const DataWriterQos& qos) = 0;
      virtual ReturnCode_t get_default_datawriter_qos (DataWriterQos& qos) = 0;
      virtual ReturnCode_t copy_from_topic_qos (DataWriterQos& a_datawriter_qos, const TopicQos& a_topic_qos) = 0;

   protected:
      Publisher () {};
      ~Publisher () {};
   private:
      Publisher (const Publisher &);
      Publisher & operator = (const Publisher &);
   };


   class OS_API DataWriter
   :
      virtual public Entity
   {
   public:
      typedef DataWriter_ptr _ptr_type;
      typedef DataWriter_var _var_type;

      static DataWriter_ptr _duplicate (DataWriter_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static DataWriter_ptr _narrow (DDS::Object_ptr obj);
      static DataWriter_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static DataWriter_ptr _nil () { return NULL; }
      static const char * _local_id;
      DataWriter_ptr _this () { return this; }

      virtual ReturnCode_t set_qos (const DataWriterQos& qos) = 0;
      virtual ReturnCode_t get_qos (DataWriterQos& qos) = 0;
      virtual ReturnCode_t set_listener (DataWriterListener_ptr a_listener, StatusMask mask) = 0;
      virtual DataWriterListener_ptr get_listener () = 0;
      virtual Topic_ptr get_topic () = 0;
      virtual Publisher_ptr get_publisher () = 0;
      virtual ReturnCode_t get_liveliness_lost_status (LivelinessLostStatus& status) = 0;
      virtual ReturnCode_t get_offered_deadline_missed_status (OfferedDeadlineMissedStatus& status) = 0;
      virtual ReturnCode_t get_offered_incompatible_qos_status (OfferedIncompatibleQosStatus& status) = 0;
      virtual ReturnCode_t get_publication_matched_status (PublicationMatchedStatus& status) = 0;
      virtual void write_flush () = 0;
      virtual void set_batch (Boolean enable) = 0;

   protected:
      DataWriter () {};
      ~DataWriter () {};
   private:
      DataWriter (const DataWriter &);
      DataWriter & operator = (const DataWriter &);
   };


   class OS_API Subscriber
   :
      virtual public Entity
   {
   public:
      typedef Subscriber_ptr _ptr_type;
      typedef Subscriber_var _var_type;

      static Subscriber_ptr _duplicate (Subscriber_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static Subscriber_ptr _narrow (DDS::Object_ptr obj);
      static Subscriber_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static Subscriber_ptr _nil () { return NULL; }
      static const char * _local_id;
      Subscriber_ptr _this () { return this; }

      virtual DataReader_ptr create_datareader (TopicDescription_ptr a_topic, const DataReaderQos& qos, DataReaderListener_ptr a_listener, StatusMask mask) = 0;
      virtual ReturnCode_t delete_datareader (DataReader_ptr a_datareader) = 0;
      virtual ReturnCode_t delete_contained_entities () = 0;
      virtual DataReader_ptr lookup_datareader (const DDS::Char* topic_name) = 0;
      virtual ReturnCode_t get_datareaders (DataReaderSeq& readers, SampleStateMask sample_states, ViewStateMask view_states, InstanceStateMask instance_states) = 0;
      virtual ReturnCode_t notify_datareaders () = 0;
      virtual ReturnCode_t set_qos (const SubscriberQos& qos) = 0;
      virtual ReturnCode_t get_qos (SubscriberQos& qos) = 0;
      virtual ReturnCode_t set_listener (SubscriberListener_ptr a_listener, StatusMask mask) = 0;
      virtual SubscriberListener_ptr get_listener () = 0;
      virtual ReturnCode_t begin_access () = 0;
      virtual ReturnCode_t end_access () = 0;
      virtual DomainParticipant_ptr get_participant () = 0;
      virtual ReturnCode_t set_default_datareader_qos (const DataReaderQos& qos) = 0;
      virtual ReturnCode_t get_default_datareader_qos (DataReaderQos& qos) = 0;
      virtual ReturnCode_t copy_from_topic_qos (DataReaderQos& a_datareader_qos, const TopicQos& a_topic_qos) = 0;

   protected:
      Subscriber () {};
      ~Subscriber () {};
   private:
      Subscriber (const Subscriber &);
      Subscriber & operator = (const Subscriber &);
   };

   class OS_API QosProviderInterface
   :
      virtual public DDS::LocalObject
   {
   public:
      typedef QosProviderInterface_ptr _ptr_type;
      typedef QosProviderInterface_var _var_type;

      static QosProviderInterface_ptr _duplicate (QosProviderInterface_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static QosProviderInterface_ptr _narrow (DDS::Object_ptr obj);
      static QosProviderInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static QosProviderInterface_ptr _nil () { return NULL; }
      static const char * _local_id;
      QosProviderInterface_ptr _this () { return this; }

      virtual ReturnCode_t get_participant_qos (
         DomainParticipantQos &qos,
         const char *id) = 0;

      virtual ::DDS::ReturnCode_t get_topic_qos (
         TopicQos &qos,
         const char *id) = 0;

      virtual ::DDS::ReturnCode_t get_subscriber_qos (
         SubscriberQos &qos,
         const char *id) = 0;

      virtual ::DDS::ReturnCode_t get_datareader_qos (
         DataReaderQos &qos,
         const char *id) = 0;

      virtual ::DDS::ReturnCode_t get_publisher_qos (
         PublisherQos &qos,
         const char *id) = 0;

      virtual ::DDS::ReturnCode_t get_datawriter_qos (
         DataWriterQos &qos,
         const char *id) = 0;

   protected:
      QosProviderInterface () {};
      ~QosProviderInterface () {};
   private:
      QosProviderInterface (const QosProviderInterface &);
      QosProviderInterface & operator = (const QosProviderInterface &);
   };

   struct Property;

   typedef Property * Property_ptr;
   typedef DDS_DCPSInterface_var <Property> Property_var;
   typedef DDS_DCPSInterface_out <Property> Property_out;

   struct  Property
   {
     typedef Property_var _var_type;
     typedef Property_out _out_type;

     String_mgr name;
     String_mgr value;
   };

   class OS_API DataReader
   :
      virtual public Entity
   {
   public:
      typedef DataReader_ptr _ptr_type;
      typedef DataReader_var _var_type;

      static DataReader_ptr _duplicate (DataReader_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static DataReader_ptr _narrow (DDS::Object_ptr obj);
      static DataReader_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static DataReader_ptr _nil () { return NULL; }
      static const char * _local_id;
      DataReader_ptr _this () { return this; }

      virtual ReadCondition_ptr create_readcondition (SampleStateMask sample_states, ViewStateMask view_states, InstanceStateMask instance_states) = 0;
      virtual QueryCondition_ptr create_querycondition (SampleStateMask sample_states, ViewStateMask view_states, InstanceStateMask instance_states, const DDS::Char* query_expression, const StringSeq& query_parameters) = 0;
      virtual ReturnCode_t delete_readcondition (ReadCondition_ptr a_condition) = 0;
      virtual ReturnCode_t delete_contained_entities () = 0;
      virtual ReturnCode_t set_qos (const DataReaderQos& qos) = 0;
      virtual ReturnCode_t get_qos (DataReaderQos& qos) = 0;
      virtual ReturnCode_t set_listener (DataReaderListener_ptr a_listener, StatusMask mask) = 0;
      virtual DataReaderListener_ptr get_listener () = 0;
      virtual TopicDescription_ptr get_topicdescription () = 0;
      virtual Subscriber_ptr get_subscriber () = 0;
      virtual ReturnCode_t get_sample_rejected_status (SampleRejectedStatus& status) = 0;
      virtual ReturnCode_t get_liveliness_changed_status (LivelinessChangedStatus& status) = 0;
      virtual ReturnCode_t get_requested_deadline_missed_status (RequestedDeadlineMissedStatus& status) = 0;
      virtual ReturnCode_t get_requested_incompatible_qos_status (RequestedIncompatibleQosStatus& status) = 0;
      virtual ReturnCode_t get_subscription_matched_status (SubscriptionMatchedStatus& status) = 0;
      virtual ReturnCode_t get_sample_lost_status (SampleLostStatus& status) = 0;
      virtual ReturnCode_t wait_for_historical_data (const Duration_t& max_wait) = 0;
      virtual ReturnCode_t wait_for_historical_data_w_condition (const DDS::Char* filter_expression, const StringSeq& filter_parameters, const Time_t& min_source_timestamp, const Time_t& max_source_timestamp, const ResourceLimitsQosPolicy& resource_limits, const Duration_t& max_wait) = 0;
      virtual ReturnCode_t get_matched_publications (InstanceHandleSeq& publication_handles) = 0;
      virtual ReturnCode_t get_matched_publication_data (PublicationBuiltinTopicData& publication_data, InstanceHandle_t publication_handle) = 0;

   protected:
      DataReader () {};
      ~DataReader () {};
   private:
      DataReader (const DataReader &);
      DataReader & operator = (const DataReader &);
   };



   struct SampleInfo
   {
      SampleStateKind sample_state;
      ViewStateKind view_state;
      InstanceStateKind instance_state;
      DDS::Long disposed_generation_count;
      DDS::Long no_writers_generation_count;
      DDS::Long sample_rank;
      DDS::Long generation_rank;
      DDS::Long absolute_generation_rank;
      Time_t source_timestamp;
      InstanceHandle_t instance_handle;
      InstanceHandle_t publication_handle;
      DDS::Boolean valid_data;
      Time_t reception_timestamp;
   };

   typedef DDS_DCPSStruct_var <SampleInfo> SampleInfo_var;
   typedef SampleInfo&SampleInfo_out;
   struct SampleInfoSeq_uniq_ {};
   typedef DDS_DCPSUFLSeq <SampleInfo, struct SampleInfoSeq_uniq_> SampleInfoSeq;
   typedef DDS_DCPSSequence_var <SampleInfoSeq> SampleInfoSeq_var;
   typedef DDS_DCPSSequence_out <SampleInfoSeq> SampleInfoSeq_out;
}
template <>
DDS::BuiltinTopicKey_t_slice* DDS_DCPS_ArrayHelper<DDS::BuiltinTopicKey_t, DDS::BuiltinTopicKey_t_slice, DDS::BuiltinTopicKey_t_uniq_>::alloc ();
template <>
void DDS_DCPS_ArrayHelper<DDS::BuiltinTopicKey_t, DDS::BuiltinTopicKey_t_slice, DDS::BuiltinTopicKey_t_uniq_>::copy (DDS::BuiltinTopicKey_t_slice *to, const DDS::BuiltinTopicKey_t_slice* from);
template <>
void DDS_DCPS_ArrayHelper<DDS::BuiltinTopicKey_t, DDS::BuiltinTopicKey_t_slice, DDS::BuiltinTopicKey_t_uniq_>::free (DDS::BuiltinTopicKey_t_slice *ptr);



#undef OS_API
#endif /* SACPP_DDS_DCPS_INTERFACES_H */
