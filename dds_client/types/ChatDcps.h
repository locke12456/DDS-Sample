//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: ChatDcps.h
//  Source: ChatDcps.idl
//  Generated: Tue May 24 12:35:14 2016
//  OpenSplice 6.6.2p1
//  
//******************************************************************
#ifndef _CHATDCPS_H_
#define _CHATDCPS_H_

#include "sacpp_mapping.h"
#include "Chat.h"
#include "dds_dcps.h"
#include "inc\semadds_export.h"


namespace Chat
{

   class OS_SEMADDS_API UserTypeSupportInterface;

   typedef UserTypeSupportInterface * UserTypeSupportInterface_ptr;
   typedef DDS_DCPSInterface_var < UserTypeSupportInterface> UserTypeSupportInterface_var;
   typedef DDS_DCPSInterface_out < UserTypeSupportInterface> UserTypeSupportInterface_out;


   class OS_SEMADDS_API UserDataWriter;

   typedef UserDataWriter * UserDataWriter_ptr;
   typedef DDS_DCPSInterface_var < UserDataWriter> UserDataWriter_var;
   typedef DDS_DCPSInterface_out < UserDataWriter> UserDataWriter_out;


   class OS_SEMADDS_API UserDataReader;

   typedef UserDataReader * UserDataReader_ptr;
   typedef DDS_DCPSInterface_var < UserDataReader> UserDataReader_var;
   typedef DDS_DCPSInterface_out < UserDataReader> UserDataReader_out;


   class OS_SEMADDS_API UserDataReaderView;

   typedef UserDataReaderView * UserDataReaderView_ptr;
   typedef DDS_DCPSInterface_var < UserDataReaderView> UserDataReaderView_var;
   typedef DDS_DCPSInterface_out < UserDataReaderView> UserDataReaderView_out;


   class OS_SEMADDS_API MessagesTypeSupportInterface;

   typedef MessagesTypeSupportInterface * MessagesTypeSupportInterface_ptr;
   typedef DDS_DCPSInterface_var < MessagesTypeSupportInterface> MessagesTypeSupportInterface_var;
   typedef DDS_DCPSInterface_out < MessagesTypeSupportInterface> MessagesTypeSupportInterface_out;


   class OS_SEMADDS_API MessagesDataWriter;

   typedef MessagesDataWriter * MessagesDataWriter_ptr;
   typedef DDS_DCPSInterface_var < MessagesDataWriter> MessagesDataWriter_var;
   typedef DDS_DCPSInterface_out < MessagesDataWriter> MessagesDataWriter_out;


   class OS_SEMADDS_API MessagesDataReader;

   typedef MessagesDataReader * MessagesDataReader_ptr;
   typedef DDS_DCPSInterface_var < MessagesDataReader> MessagesDataReader_var;
   typedef DDS_DCPSInterface_out < MessagesDataReader> MessagesDataReader_out;


   class OS_SEMADDS_API MessagesDataReaderView;

   typedef MessagesDataReaderView * MessagesDataReaderView_ptr;
   typedef DDS_DCPSInterface_var < MessagesDataReaderView> MessagesDataReaderView_var;
   typedef DDS_DCPSInterface_out < MessagesDataReaderView> MessagesDataReaderView_out;

   struct UserSeq_uniq_ {};
   typedef DDS_DCPSUVLSeq < User, struct UserSeq_uniq_> UserSeq;
   typedef DDS_DCPSSequence_var < UserSeq> UserSeq_var;
   typedef DDS_DCPSSequence_out < UserSeq> UserSeq_out;
   class OS_SEMADDS_API UserTypeSupportInterface
   :
      virtual public DDS::TypeSupport
   { 
   public:
      typedef UserTypeSupportInterface_ptr _ptr_type;
      typedef UserTypeSupportInterface_var _var_type;

      static UserTypeSupportInterface_ptr _duplicate (UserTypeSupportInterface_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static UserTypeSupportInterface_ptr _narrow (DDS::Object_ptr obj);
      static UserTypeSupportInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static UserTypeSupportInterface_ptr _nil () { return 0; }
      static const char * _local_id;
      UserTypeSupportInterface_ptr _this () { return this; }


   protected:
      UserTypeSupportInterface () {};
      ~UserTypeSupportInterface () {};
   private:
      UserTypeSupportInterface (const UserTypeSupportInterface &);
      UserTypeSupportInterface & operator = (const UserTypeSupportInterface &);
   };

   class OS_SEMADDS_API UserDataWriter
   :
      virtual public DDS::DataWriter
   { 
   public:
      typedef UserDataWriter_ptr _ptr_type;
      typedef UserDataWriter_var _var_type;

      static UserDataWriter_ptr _duplicate (UserDataWriter_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static UserDataWriter_ptr _narrow (DDS::Object_ptr obj);
      static UserDataWriter_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static UserDataWriter_ptr _nil () { return 0; }
      static const char * _local_id;
      UserDataWriter_ptr _this () { return this; }

      virtual DDS::LongLong register_instance (const User& instance_data) = 0;
      virtual DDS::LongLong register_instance_w_timestamp (const User& instance_data, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long unregister_instance (const User& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long unregister_instance_w_timestamp (const User& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long write (const User& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long write_w_timestamp (const User& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long dispose (const User& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long dispose_w_timestamp (const User& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long writedispose (const User& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long writedispose_w_timestamp (const User& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long get_key_value (User& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const User& instance_data) = 0;

   protected:
      UserDataWriter () {};
      ~UserDataWriter () {};
   private:
      UserDataWriter (const UserDataWriter &);
      UserDataWriter & operator = (const UserDataWriter &);
   };

   class OS_SEMADDS_API UserDataReader
   :
      virtual public DDS::DataReader
   { 
   public:
      typedef UserDataReader_ptr _ptr_type;
      typedef UserDataReader_var _var_type;

      static UserDataReader_ptr _duplicate (UserDataReader_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static UserDataReader_ptr _narrow (DDS::Object_ptr obj);
      static UserDataReader_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static UserDataReader_ptr _nil () { return 0; }
      static const char * _local_id;
      UserDataReader_ptr _this () { return this; }

      virtual DDS::Long read (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_w_condition (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_w_condition (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long read_next_sample (User& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long take_next_sample (User& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long read_instance (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_instance (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_next_instance (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance_w_condition (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_next_instance_w_condition (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long return_loan (UserSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::Long get_key_value (User& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const User& instance) = 0;

   protected:
      UserDataReader () {};
      ~UserDataReader () {};
   private:
      UserDataReader (const UserDataReader &);
      UserDataReader & operator = (const UserDataReader &);
   };

   class OS_SEMADDS_API UserDataReaderView
   :
      virtual public DDS::DataReaderView
   { 
   public:
      typedef UserDataReaderView_ptr _ptr_type;
      typedef UserDataReaderView_var _var_type;

      static UserDataReaderView_ptr _duplicate (UserDataReaderView_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static UserDataReaderView_ptr _narrow (DDS::Object_ptr obj);
      static UserDataReaderView_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static UserDataReaderView_ptr _nil () { return 0; }
      static const char * _local_id;
      UserDataReaderView_ptr _this () { return this; }

      virtual DDS::Long read (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_w_condition (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_w_condition (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long read_next_sample (User& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long take_next_sample (User& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long read_instance (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_instance (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_next_instance (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance_w_condition (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_next_instance_w_condition (UserSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long return_loan (UserSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::Long get_key_value (User& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const User& instance) = 0;

   protected:
      UserDataReaderView () {};
      ~UserDataReaderView () {};
   private:
      UserDataReaderView (const UserDataReaderView &);
      UserDataReaderView & operator = (const UserDataReaderView &);
   };

   struct MessagesSeq_uniq_ {};
   typedef DDS_DCPSUVLSeq < Messages, struct MessagesSeq_uniq_> MessagesSeq;
   typedef DDS_DCPSSequence_var < MessagesSeq> MessagesSeq_var;
   typedef DDS_DCPSSequence_out < MessagesSeq> MessagesSeq_out;
   class OS_SEMADDS_API MessagesTypeSupportInterface
   :
      virtual public DDS::TypeSupport
   { 
   public:
      typedef MessagesTypeSupportInterface_ptr _ptr_type;
      typedef MessagesTypeSupportInterface_var _var_type;

      static MessagesTypeSupportInterface_ptr _duplicate (MessagesTypeSupportInterface_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static MessagesTypeSupportInterface_ptr _narrow (DDS::Object_ptr obj);
      static MessagesTypeSupportInterface_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static MessagesTypeSupportInterface_ptr _nil () { return 0; }
      static const char * _local_id;
      MessagesTypeSupportInterface_ptr _this () { return this; }


   protected:
      MessagesTypeSupportInterface () {};
      ~MessagesTypeSupportInterface () {};
   private:
      MessagesTypeSupportInterface (const MessagesTypeSupportInterface &);
      MessagesTypeSupportInterface & operator = (const MessagesTypeSupportInterface &);
   };

   class OS_SEMADDS_API MessagesDataWriter
   :
      virtual public DDS::DataWriter
   { 
   public:
      typedef MessagesDataWriter_ptr _ptr_type;
      typedef MessagesDataWriter_var _var_type;

      static MessagesDataWriter_ptr _duplicate (MessagesDataWriter_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static MessagesDataWriter_ptr _narrow (DDS::Object_ptr obj);
      static MessagesDataWriter_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static MessagesDataWriter_ptr _nil () { return 0; }
      static const char * _local_id;
      MessagesDataWriter_ptr _this () { return this; }

      virtual DDS::LongLong register_instance (const Messages& instance_data) = 0;
      virtual DDS::LongLong register_instance_w_timestamp (const Messages& instance_data, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long unregister_instance (const Messages& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long unregister_instance_w_timestamp (const Messages& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long write (const Messages& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long write_w_timestamp (const Messages& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long dispose (const Messages& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long dispose_w_timestamp (const Messages& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long writedispose (const Messages& instance_data, DDS::LongLong handle) = 0;
      virtual DDS::Long writedispose_w_timestamp (const Messages& instance_data, DDS::LongLong handle, const DDS::Time_t& source_timestamp) = 0;
      virtual DDS::Long get_key_value (Messages& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const Messages& instance_data) = 0;

   protected:
      MessagesDataWriter () {};
      ~MessagesDataWriter () {};
   private:
      MessagesDataWriter (const MessagesDataWriter &);
      MessagesDataWriter & operator = (const MessagesDataWriter &);
   };

   class OS_SEMADDS_API MessagesDataReader
   :
      virtual public DDS::DataReader
   { 
   public:
      typedef MessagesDataReader_ptr _ptr_type;
      typedef MessagesDataReader_var _var_type;

      static MessagesDataReader_ptr _duplicate (MessagesDataReader_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static MessagesDataReader_ptr _narrow (DDS::Object_ptr obj);
      static MessagesDataReader_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static MessagesDataReader_ptr _nil () { return 0; }
      static const char * _local_id;
      MessagesDataReader_ptr _this () { return this; }

      virtual DDS::Long read (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_w_condition (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_w_condition (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long read_next_sample (Messages& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long take_next_sample (Messages& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long read_instance (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_instance (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_next_instance (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance_w_condition (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_next_instance_w_condition (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long return_loan (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::Long get_key_value (Messages& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const Messages& instance) = 0;

   protected:
      MessagesDataReader () {};
      ~MessagesDataReader () {};
   private:
      MessagesDataReader (const MessagesDataReader &);
      MessagesDataReader & operator = (const MessagesDataReader &);
   };

   class OS_SEMADDS_API MessagesDataReaderView
   :
      virtual public DDS::DataReaderView
   { 
   public:
      typedef MessagesDataReaderView_ptr _ptr_type;
      typedef MessagesDataReaderView_var _var_type;

      static MessagesDataReaderView_ptr _duplicate (MessagesDataReaderView_ptr obj);
      DDS::Boolean _local_is_a (const char * id);

      static MessagesDataReaderView_ptr _narrow (DDS::Object_ptr obj);
      static MessagesDataReaderView_ptr _unchecked_narrow (DDS::Object_ptr obj);
      static MessagesDataReaderView_ptr _nil () { return 0; }
      static const char * _local_id;
      MessagesDataReaderView_ptr _this () { return this; }

      virtual DDS::Long read (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_w_condition (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_w_condition (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long read_next_sample (Messages& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long take_next_sample (Messages& received_data, DDS::SampleInfo& sample_info) = 0;
      virtual DDS::Long read_instance (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_instance (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long take_next_instance (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ULong sample_states, DDS::ULong view_states, DDS::ULong instance_states) = 0;
      virtual DDS::Long read_next_instance_w_condition (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long take_next_instance_w_condition (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq, DDS::Long max_samples, DDS::LongLong a_handle, DDS::ReadCondition_ptr a_condition) = 0;
      virtual DDS::Long return_loan (MessagesSeq& received_data, DDS::SampleInfoSeq& info_seq) = 0;
      virtual DDS::Long get_key_value (Messages& key_holder, DDS::LongLong handle) = 0;
      virtual DDS::LongLong lookup_instance (const Messages& instance) = 0;

   protected:
      MessagesDataReaderView () {};
      ~MessagesDataReaderView () {};
   private:
      MessagesDataReaderView (const MessagesDataReaderView &);
      MessagesDataReaderView & operator = (const MessagesDataReaderView &);
   };

}




#undef OS_SEMADDS_API

#endif
