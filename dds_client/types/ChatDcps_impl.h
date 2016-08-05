#ifndef CHATDCPS_IMPL_H_
#define CHATDCPS_IMPL_H_

#include "ccpp.h"
#include "ccpp_Chat.h"
#include "TypeSupportMetaHolder.h"
#include "TypeSupport.h"
#include "FooDataWriter_impl.h"
#include "FooDataReader_impl.h"
#include "FooDataReaderView_impl.h"
#include "inc\semadds_export.h"

namespace Chat {

    class OS_SEMADDS_API UserTypeSupportMetaHolder : public ::DDS::OpenSplice::TypeSupportMetaHolder
    {
    public:
        UserTypeSupportMetaHolder ();
        virtual ~UserTypeSupportMetaHolder ();
    
    private:
        ::DDS::OpenSplice::DataWriter * create_datawriter ();
    
        ::DDS::OpenSplice::DataReader * create_datareader ();
    
        ::DDS::OpenSplice::DataReaderView * create_view ();
    };
    
    class OS_SEMADDS_API UserTypeSupport : public virtual UserTypeSupportInterface,
                                                       public ::DDS::OpenSplice::TypeSupport
    {
    public:
        UserTypeSupport ();
    
        virtual ~UserTypeSupport ();
    
    private:
        UserTypeSupport (const UserTypeSupport &);
    
        void operator= (const UserTypeSupport &);
    };
    
    typedef UserTypeSupportInterface_var UserTypeSupport_var;
    typedef UserTypeSupportInterface_ptr UserTypeSupport_ptr;
    
    class OS_SEMADDS_API UserDataWriter_impl : public virtual UserDataWriter,
                                                           public ::DDS::OpenSplice::FooDataWriter_impl
    {
        friend class DDS::OpenSplice::Publisher;
        friend class UserTypeSupportMetaHolder;
    
    public:
        virtual ::DDS::InstanceHandle_t register_instance (
            const User & instance_data) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const User & instance_data,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance (
            const User & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const User & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const User & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const User & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const User & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const User & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t writedispose (
            const User & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t writedispose_w_timestamp (
            const User & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            User & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const User & instance_data) THROW_ORB_EXCEPTIONS;
    
    protected:
        UserDataWriter_impl ();
    
        virtual ~UserDataWriter_impl ();
    
        virtual DDS::ReturnCode_t init (
                        DDS::OpenSplice::Publisher *publisher,
                        DDS::OpenSplice::DomainParticipant *participant,
                        const DDS::DataWriterQos &qos,
                        DDS::OpenSplice::Topic *a_topic,
                        const char *name,
                        DDS::OpenSplice::cxxCopyIn copyIn,
                        DDS::OpenSplice::cxxCopyOut copyOut);
    
    private:
        UserDataWriter_impl (const UserDataWriter_impl &);
    
        void operator= (const UserDataWriter &);
    };
    
    class OS_SEMADDS_API UserDataReader_impl : public virtual UserDataReader,
                                                           public ::DDS::OpenSplice::FooDataReader_impl
    {
        friend class DDS::OpenSplice::Subscriber;
        friend class UserTypeSupportMetaHolder;
        friend class UserDataReaderView_impl;
    
    public:
        virtual ::DDS::ReturnCode_t read (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_w_condition (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_w_condition (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            User & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            User & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_instance (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_instance (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            User & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const User & instance) THROW_ORB_EXCEPTIONS;
    
    protected:
        UserDataReader_impl ();
    
        virtual ~UserDataReader_impl ();
    
        DDS::ReturnCode_t init (
                DDS::OpenSplice::Subscriber *subscriber,
                const DDS::DataReaderQos &qos,
                DDS::OpenSplice::TopicDescription *a_topic,
                const char *name,
                DDS::OpenSplice::cxxCopyIn copyIn,
                DDS::OpenSplice::cxxCopyOut copyOut);
    
        static void* dataSeqAlloc (
            void * data_values,
            DDS::ULong len);
    
        static void dataSeqLength (
            void * data_values,
            DDS::ULong len);
    
        static void * dataSeqGetBuffer (
            void * data_values,
            DDS::ULong index);
    
        static void dataSeqCopyOut (
            const void * from,
            void * received_data);
        static void copyDataOut(const void *from, void *to);
    
    private:
        UserDataReader_impl (const UserDataReader &);
        void operator= (const UserDataReader &);
    
        static ::DDS::ReturnCode_t check_preconditions (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples);
    };
    
    class OS_SEMADDS_API UserDataReaderView_impl : public virtual UserDataReaderView,
                                                               public ::DDS::OpenSplice::FooDataReaderView_impl
    {
        friend class DDS::OpenSplice::DataReader;
        friend class UserTypeSupportMetaHolder;
    
    public:
        virtual ::DDS::ReturnCode_t read (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_w_condition (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_w_condition (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            User & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            User & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_instance (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_instance (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            UserSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            User & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const User & instance) THROW_ORB_EXCEPTIONS;
    
    protected:
        UserDataReaderView_impl ();
    
        virtual ~UserDataReaderView_impl ();
    
        virtual DDS::ReturnCode_t init (
            DDS::OpenSplice::DataReader *reader,
            const char *name,
            const DDS::DataReaderViewQos &qos,
            DDS::OpenSplice::cxxCopyIn copyIn,
            DDS::OpenSplice::cxxCopyOut copyOut);
    
    private:
        UserDataReaderView_impl (const UserDataReaderView &);
    
        void operator= (const UserDataReaderView &);
    };
    
    class OS_SEMADDS_API MessagesTypeSupportMetaHolder : public ::DDS::OpenSplice::TypeSupportMetaHolder
    {
    public:
        MessagesTypeSupportMetaHolder ();
        virtual ~MessagesTypeSupportMetaHolder ();
    
    private:
        ::DDS::OpenSplice::DataWriter * create_datawriter ();
    
        ::DDS::OpenSplice::DataReader * create_datareader ();
    
        ::DDS::OpenSplice::DataReaderView * create_view ();
    };
    
    class OS_SEMADDS_API MessagesTypeSupport : public virtual MessagesTypeSupportInterface,
                                                       public ::DDS::OpenSplice::TypeSupport
    {
    public:
        MessagesTypeSupport ();
    
        virtual ~MessagesTypeSupport ();
    
    private:
        MessagesTypeSupport (const MessagesTypeSupport &);
    
        void operator= (const MessagesTypeSupport &);
    };
    
    typedef MessagesTypeSupportInterface_var MessagesTypeSupport_var;
    typedef MessagesTypeSupportInterface_ptr MessagesTypeSupport_ptr;
    
    class OS_SEMADDS_API MessagesDataWriter_impl : public virtual MessagesDataWriter,
                                                           public ::DDS::OpenSplice::FooDataWriter_impl
    {
        friend class DDS::OpenSplice::Publisher;
        friend class MessagesTypeSupportMetaHolder;
    
    public:
        virtual ::DDS::InstanceHandle_t register_instance (
            const Messages & instance_data) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Messages & instance_data,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Messages & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Messages & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Messages & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Messages & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Messages & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Messages & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t writedispose (
            const Messages & instance_data,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t writedispose_w_timestamp (
            const Messages & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Messages & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Messages & instance_data) THROW_ORB_EXCEPTIONS;
    
    protected:
        MessagesDataWriter_impl ();
    
        virtual ~MessagesDataWriter_impl ();
    
        virtual DDS::ReturnCode_t init (
                        DDS::OpenSplice::Publisher *publisher,
                        DDS::OpenSplice::DomainParticipant *participant,
                        const DDS::DataWriterQos &qos,
                        DDS::OpenSplice::Topic *a_topic,
                        const char *name,
                        DDS::OpenSplice::cxxCopyIn copyIn,
                        DDS::OpenSplice::cxxCopyOut copyOut);
    
    private:
        MessagesDataWriter_impl (const MessagesDataWriter_impl &);
    
        void operator= (const MessagesDataWriter &);
    };
    
    class OS_SEMADDS_API MessagesDataReader_impl : public virtual MessagesDataReader,
                                                           public ::DDS::OpenSplice::FooDataReader_impl
    {
        friend class DDS::OpenSplice::Subscriber;
        friend class MessagesTypeSupportMetaHolder;
        friend class MessagesDataReaderView_impl;
    
    public:
        virtual ::DDS::ReturnCode_t read (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_w_condition (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_w_condition (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Messages & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Messages & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_instance (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_instance (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Messages & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Messages & instance) THROW_ORB_EXCEPTIONS;
    
    protected:
        MessagesDataReader_impl ();
    
        virtual ~MessagesDataReader_impl ();
    
        DDS::ReturnCode_t init (
                DDS::OpenSplice::Subscriber *subscriber,
                const DDS::DataReaderQos &qos,
                DDS::OpenSplice::TopicDescription *a_topic,
                const char *name,
                DDS::OpenSplice::cxxCopyIn copyIn,
                DDS::OpenSplice::cxxCopyOut copyOut);
    
        static void* dataSeqAlloc (
            void * data_values,
            DDS::ULong len);
    
        static void dataSeqLength (
            void * data_values,
            DDS::ULong len);
    
        static void * dataSeqGetBuffer (
            void * data_values,
            DDS::ULong index);
    
        static void dataSeqCopyOut (
            const void * from,
            void * received_data);
        static void copyDataOut(const void *from, void *to);
    
    private:
        MessagesDataReader_impl (const MessagesDataReader &);
        void operator= (const MessagesDataReader &);
    
        static ::DDS::ReturnCode_t check_preconditions (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples);
    };
    
    class OS_SEMADDS_API MessagesDataReaderView_impl : public virtual MessagesDataReaderView,
                                                               public ::DDS::OpenSplice::FooDataReaderView_impl
    {
        friend class DDS::OpenSplice::DataReader;
        friend class MessagesTypeSupportMetaHolder;
    
    public:
        virtual ::DDS::ReturnCode_t read (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_w_condition (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_w_condition (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Messages & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Messages & received_data,
            ::DDS::SampleInfo & sample_info) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_instance (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_instance (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            ::DDS::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            MessagesSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Messages & key_holder,
            ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Messages & instance) THROW_ORB_EXCEPTIONS;
    
    protected:
        MessagesDataReaderView_impl ();
    
        virtual ~MessagesDataReaderView_impl ();
    
        virtual DDS::ReturnCode_t init (
            DDS::OpenSplice::DataReader *reader,
            const char *name,
            const DDS::DataReaderViewQos &qos,
            DDS::OpenSplice::cxxCopyIn copyIn,
            DDS::OpenSplice::cxxCopyOut copyOut);
    
    private:
        MessagesDataReaderView_impl (const MessagesDataReaderView &);
    
        void operator= (const MessagesDataReaderView &);
    };
    
}

#undef OS_API
#endif
