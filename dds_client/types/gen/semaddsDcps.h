//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: semaddsDcps.h
//  Source: semaddsDcps.idl
//  Generated: Thu Mar 31 16:25:20 2016
//  OpenSplice 6.6.2p1
//  
//******************************************************************
#ifndef _SEMADDSDCPS_H_
#define _SEMADDSDCPS_H_

#include "sacpp_mapping.h"
#include "dds_dcps.h"
#include "semadds.h"
#include "semadds_export.h"


namespace SEMADDS_Types
{

   class OS_SEMADDS_API MessageTypeSupportInterface;

   typedef MessageTypeSupportInterface * MessageTypeSupportInterface_ptr;
   typedef DDS_DCPSInterface_var < MessageTypeSupportInterface> MessageTypeSupportInterface_var;
   typedef DDS_DCPSInterface_out < MessageTypeSupportInterface> MessageTypeSupportInterface_out;


   class OS_SEMADDS_API MessageDataWriter;

   typedef MessageDataWriter * MessageDataWriter_ptr;
   typedef DDS_DCPSInterface_var < MessageDataWriter> MessageDataWriter_var;
   typedef DDS_DCPSInterface_out < MessageDataWriter> MessageDataWriter_out;


   class OS_SEMADDS_API MessageDataReader;

   typedef MessageDataReader * MessageDataReader_ptr;
   typedef DDS_DCPSInterface_var < MessageDataReader> MessageDataReader_var;
   typedef DDS_DCPSInterface_out < MessageDataReader> MessageDataReader_out;


   class OS_SEMADDS_API MessageDataReaderView;

   typedef MessageDataReaderView * MessageDataReaderView_ptr;
   typedef DDS_DCPSInterface_var < MessageDataReaderView> MessageDataReaderView_var;
   typedef DDS_DCPSInterface_out < MessageDataReaderView> MessageDataReaderView_out;


   class OS_SEMADDS_API SemaEApiTypeSupportInterface;

   typedef SemaEApiTypeSupportInterface * SemaEApiTypeSupportInterface_ptr;
   typedef DDS_DCPSInterface_var < SemaEApiTypeSupportInterface> SemaEApiTypeSupportInterface_var;
   typedef DDS_DCPSInterface_out < SemaEApiTypeSupportInterface> SemaEApiTypeSupportInterface_out;


   class OS_SEMADDS_API SemaEApiDataWriter;

   typedef SemaEApiDataWriter * SemaEApiDataWriter_ptr;
   typedef DDS_DCPSInterface_var < SemaEApiDataWriter> SemaEApiDataWriter_var;
   typedef DDS_DCPSInterface_out < SemaEApiDataWriter> SemaEApiDataWriter_out;


   class OS_SEMADDS_API SemaEApiDataReader;

   typedef SemaEApiDataReader * SemaEApiDataReader_ptr;
   typedef DDS_DCPSInterface_var < SemaEApiDataReader> SemaEApiDataReader_var;
   typedef DDS_DCPSInterface_out < SemaEApiDataReader> SemaEApiDataReader_out;


   class OS_SEMADDS_API SemaEApiDataReaderView;

   typedef SemaEApiDataReaderView * SemaEApiDataReaderView_ptr;
   typedef DDS_DCPSInterface_var < SemaEApiDataReaderView> SemaEApiDataReaderView_var;
   typedef DDS_DCPSInterface_out < SemaEApiDataReaderView> SemaEApiDataReaderView_out;

   struct MessageSeq_uniq_ {};
   typedef DDS_DCPSUVLSeq < Message, struct MessageSeq_uniq_> MessageSeq;
   typedef DDS_DCPSSequence_var < MessageSeq> MessageSeq_var;
   typedef DDS_DCPSSequence_out < MessageSeq> MessageSeq_out;
   class OS_SEMADDS_API MessageTypeSupportInterface
   :
      virtual public DDS::TypeSupport
   { 
   public:
      typedef MessageTypeSupportInterface_ptr _ptr_type;
      typedef MessageTypeSupportInterface_var _var_type;

      static MessageTypeSupportInterface_ptr _duplicate (MessageTypeSupportInterface_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static MessageTypeSupportInterface_ptr _narrow (DDS::Object_ptr obj);
      static MessageTypeSupportInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static MessageTypeSupportInterface_ptr _nil () { return 0; }
      static const char * _local_id;
      MessageTypeSupportInterface_ptr _this () { return this; }


   protected:
      MessageTypeSupportInterface () {};
      ~MessageTypeSupportInterface () {};
   private:
      MessageTypeSupportInterface (const MessageTypeSupportInterface &);
      MessageTypeSupportInterface & operator = (const MessageTypeSupportInterface &);
   };

   class OS_SEMADDS_API MessageDataWriter
   :
      virtual public DDS::DataWriter
   { 
   public:
      typedef MessageDataWriter_ptr _ptr_type;
      typedef MessageDataWriter_var _var_type;

      static MessageDataWriter_ptr _duplicate (MessageDataWriter_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static MessageDataWriter_ptr _narrow (DDS::Object_ptr obj);
      static MessageDataWriter_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static MessageDataWriter_ptr _nil () { return 0; }
      static const char * _local_id;
      MessageDataWriter_ptr _this () { return this; }

      virtual DDS::LongLong register_instance (const Message& instance_data) = 0;
      virtual DDS::LongLong register_instance_w_timestamp (const Message& instance_data, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long unregister_instance (const Message& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long unregister_instance_w_timestamp (const Message& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long write (const Message& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long write_w_timestamp (const Message& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long dispose (const Message& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long dispose_w_timestamp (const Message& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long writedispose (const Message& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long writedispose_w_timestamp (const Message& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long get_key_value (Message& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const Message& instance_data) = 0;

   protected:
      MessageDataWriter () {};
      ~MessageDataWriter () {};
   private:
      MessageDataWriter (const MessageDataWriter &);
      MessageDataWriter & operator = (const MessageDataWriter &);
   };

   class OS_SEMADDS_API MessageDataReader
   :
      virtual public DDS::DataReader
   { 
   public:
      typedef MessageDataReader_ptr _ptr_type;
      typedef MessageDataReader_var _var_type;

      static MessageDataReader_ptr _duplicate (MessageDataReader_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static MessageDataReader_ptr _narrow (DDS::Object_ptr obj);
      static MessageDataReader_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static MessageDataReader_ptr _nil () { return 0; }
      static const char * _local_id;
      MessageDataReader_ptr _this () { return this; }

      virtual DDS::Long read (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_w_condition (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_w_condition (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long read_next_sample (Message& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long take_next_sample (Message& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long read_instance (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_instance (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_next_instance (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance_w_condition (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_next_instance_w_condition (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long return_loan (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::Long get_key_value (Message& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const Message& instance) = 0;

   protected:
      MessageDataReader () {};
      ~MessageDataReader () {};
   private:
      MessageDataReader (const MessageDataReader &);
      MessageDataReader & operator = (const MessageDataReader &);
   };

   class OS_SEMADDS_API MessageDataReaderView
   :
      virtual public DDS::DataReaderView
   { 
   public:
      typedef MessageDataReaderView_ptr _ptr_type;
      typedef MessageDataReaderView_var _var_type;

      static MessageDataReaderView_ptr _duplicate (MessageDataReaderView_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static MessageDataReaderView_ptr _narrow (DDS::Object_ptr obj);
      static MessageDataReaderView_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static MessageDataReaderView_ptr _nil () { return 0; }
      static const char * _local_id;
      MessageDataReaderView_ptr _this () { return this; }

      virtual DDS::Long read (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_w_condition (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_w_condition (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long read_next_sample (Message& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long take_next_sample (Message& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long read_instance (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_instance (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_next_instance (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance_w_condition (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_next_instance_w_condition (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long return_loan (MessageSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::Long get_key_value (Message& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const Message& instance) = 0;

   protected:
      MessageDataReaderView () {};
      ~MessageDataReaderView () {};
   private:
      MessageDataReaderView (const MessageDataReaderView &);
      MessageDataReaderView & operator = (const MessageDataReaderView &);
   };

   struct SemaEApiSeq_uniq_ {};
   typedef DDS_DCPSUFLSeq < SemaEApi, struct SemaEApiSeq_uniq_> SemaEApiSeq;
   typedef DDS_DCPSSequence_var < SemaEApiSeq> SemaEApiSeq_var;
   typedef DDS_DCPSSequence_out < SemaEApiSeq> SemaEApiSeq_out;
   class OS_SEMADDS_API SemaEApiTypeSupportInterface
   :
      virtual public DDS::TypeSupport
   { 
   public:
      typedef SemaEApiTypeSupportInterface_ptr _ptr_type;
      typedef SemaEApiTypeSupportInterface_var _var_type;

      static SemaEApiTypeSupportInterface_ptr _duplicate (SemaEApiTypeSupportInterface_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static SemaEApiTypeSupportInterface_ptr _narrow (DDS::Object_ptr obj);
      static SemaEApiTypeSupportInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static SemaEApiTypeSupportInterface_ptr _nil () { return 0; }
      static const char * _local_id;
      SemaEApiTypeSupportInterface_ptr _this () { return this; }


   protected:
      SemaEApiTypeSupportInterface () {};
      ~SemaEApiTypeSupportInterface () {};
   private:
      SemaEApiTypeSupportInterface (const SemaEApiTypeSupportInterface &);
      SemaEApiTypeSupportInterface & operator = (const SemaEApiTypeSupportInterface &);
   };

   class OS_SEMADDS_API SemaEApiDataWriter
   :
      virtual public DDS::DataWriter
   { 
   public:
      typedef SemaEApiDataWriter_ptr _ptr_type;
      typedef SemaEApiDataWriter_var _var_type;

      static SemaEApiDataWriter_ptr _duplicate (SemaEApiDataWriter_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static SemaEApiDataWriter_ptr _narrow (DDS::Object_ptr obj);
      static SemaEApiDataWriter_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static SemaEApiDataWriter_ptr _nil () { return 0; }
      static const char * _local_id;
      SemaEApiDataWriter_ptr _this () { return this; }

      virtual DDS::LongLong register_instance (const SemaEApi& instance_data) = 0;
      virtual DDS::LongLong register_instance_w_timestamp (const SemaEApi& instance_data, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long unregister_instance (const SemaEApi& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long unregister_instance_w_timestamp (const SemaEApi& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long write (const SemaEApi& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long write_w_timestamp (const SemaEApi& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long dispose (const SemaEApi& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long dispose_w_timestamp (const SemaEApi& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long writedispose (const SemaEApi& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long writedispose_w_timestamp (const SemaEApi& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long get_key_value (SemaEApi& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const SemaEApi& instance_data) = 0;

   protected:
      SemaEApiDataWriter () {};
      ~SemaEApiDataWriter () {};
   private:
      SemaEApiDataWriter (const SemaEApiDataWriter &);
      SemaEApiDataWriter & operator = (const SemaEApiDataWriter &);
   };

   class OS_SEMADDS_API SemaEApiDataReader
   :
      virtual public DDS::DataReader
   { 
   public:
      typedef SemaEApiDataReader_ptr _ptr_type;
      typedef SemaEApiDataReader_var _var_type;

      static SemaEApiDataReader_ptr _duplicate (SemaEApiDataReader_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static SemaEApiDataReader_ptr _narrow (DDS::Object_ptr obj);
      static SemaEApiDataReader_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static SemaEApiDataReader_ptr _nil () { return 0; }
      static const char * _local_id;
      SemaEApiDataReader_ptr _this () { return this; }

      virtual DDS::Long read (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_w_condition (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_w_condition (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long read_next_sample (SemaEApi& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long take_next_sample (SemaEApi& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long read_instance (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_instance (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_next_instance (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance_w_condition (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_next_instance_w_condition (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long return_loan (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::Long get_key_value (SemaEApi& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const SemaEApi& instance) = 0;

   protected:
      SemaEApiDataReader () {};
      ~SemaEApiDataReader () {};
   private:
      SemaEApiDataReader (const SemaEApiDataReader &);
      SemaEApiDataReader & operator = (const SemaEApiDataReader &);
   };

   class OS_SEMADDS_API SemaEApiDataReaderView
   :
      virtual public DDS::DataReaderView
   { 
   public:
      typedef SemaEApiDataReaderView_ptr _ptr_type;
      typedef SemaEApiDataReaderView_var _var_type;

      static SemaEApiDataReaderView_ptr _duplicate (SemaEApiDataReaderView_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static SemaEApiDataReaderView_ptr _narrow (DDS::Object_ptr obj);
      static SemaEApiDataReaderView_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static SemaEApiDataReaderView_ptr _nil () { return 0; }
      static const char * _local_id;
      SemaEApiDataReaderView_ptr _this () { return this; }

      virtual DDS::Long read (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_w_condition (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_w_condition (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long read_next_sample (SemaEApi& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long take_next_sample (SemaEApi& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long read_instance (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_instance (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_next_instance (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance_w_condition (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_next_instance_w_condition (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long return_loan (SemaEApiSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::Long get_key_value (SemaEApi& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const SemaEApi& instance) = 0;

   protected:
      SemaEApiDataReaderView () {};
      ~SemaEApiDataReaderView () {};
   private:
      SemaEApiDataReaderView (const SemaEApiDataReaderView &);
      SemaEApiDataReaderView & operator = (const SemaEApiDataReaderView &);
   };

}




#undef OS_SEMADDS_API

#endif