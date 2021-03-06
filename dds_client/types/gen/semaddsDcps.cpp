//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: semaddsDcps.cpp
//  Source: semaddsDcps.idl
//  Generated: Thu Mar 31 16:25:20 2016
//  OpenSplice 6.6.2p1
//  
//******************************************************************

#include "semaddsDcps.h"

#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPSUFLSeq < SEMADDS_Types::SemaEApi, struct SemaEApiSeq_uniq_>;
#endif
#if DDS_USE_EXPLICIT_TEMPLATES
template class DDS_DCPSUVLSeq < SEMADDS_Types::Message, struct MessageSeq_uniq_>;
#endif

const char * SEMADDS_Types::MessageTypeSupportInterface::_local_id = "IDL:SEMADDS_Types/MessageTypeSupportInterface:1.0";

SEMADDS_Types::MessageTypeSupportInterface_ptr SEMADDS_Types::MessageTypeSupportInterface::_duplicate (SEMADDS_Types::MessageTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean SEMADDS_Types::MessageTypeSupportInterface::_local_is_a (const char * _id)
{
   if (strcmp (_id, SEMADDS_Types::MessageTypeSupportInterface::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::TypeSupport NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

SEMADDS_Types::MessageTypeSupportInterface_ptr SEMADDS_Types::MessageTypeSupportInterface::_narrow (DDS::Object_ptr p)
{
   SEMADDS_Types::MessageTypeSupportInterface_ptr result = NULL;
   if (p && p->_is_a (SEMADDS_Types::MessageTypeSupportInterface::_local_id))
   {
      result = dynamic_cast < SEMADDS_Types::MessageTypeSupportInterface_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

SEMADDS_Types::MessageTypeSupportInterface_ptr SEMADDS_Types::MessageTypeSupportInterface::_unchecked_narrow (DDS::Object_ptr p)
{
   SEMADDS_Types::MessageTypeSupportInterface_ptr result;
   result = dynamic_cast < SEMADDS_Types::MessageTypeSupportInterface_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * SEMADDS_Types::MessageDataWriter::_local_id = "IDL:SEMADDS_Types/MessageDataWriter:1.0";

SEMADDS_Types::MessageDataWriter_ptr SEMADDS_Types::MessageDataWriter::_duplicate (SEMADDS_Types::MessageDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean SEMADDS_Types::MessageDataWriter::_local_is_a (const char * _id)
{
   if (strcmp (_id, SEMADDS_Types::MessageDataWriter::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataWriter NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

SEMADDS_Types::MessageDataWriter_ptr SEMADDS_Types::MessageDataWriter::_narrow (DDS::Object_ptr p)
{
   SEMADDS_Types::MessageDataWriter_ptr result = NULL;
   if (p && p->_is_a (SEMADDS_Types::MessageDataWriter::_local_id))
   {
      result = dynamic_cast < SEMADDS_Types::MessageDataWriter_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

SEMADDS_Types::MessageDataWriter_ptr SEMADDS_Types::MessageDataWriter::_unchecked_narrow (DDS::Object_ptr p)
{
   SEMADDS_Types::MessageDataWriter_ptr result;
   result = dynamic_cast < SEMADDS_Types::MessageDataWriter_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * SEMADDS_Types::MessageDataReader::_local_id = "IDL:SEMADDS_Types/MessageDataReader:1.0";

SEMADDS_Types::MessageDataReader_ptr SEMADDS_Types::MessageDataReader::_duplicate (SEMADDS_Types::MessageDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean SEMADDS_Types::MessageDataReader::_local_is_a (const char * _id)
{
   if (strcmp (_id, SEMADDS_Types::MessageDataReader::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReader NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

SEMADDS_Types::MessageDataReader_ptr SEMADDS_Types::MessageDataReader::_narrow (DDS::Object_ptr p)
{
   SEMADDS_Types::MessageDataReader_ptr result = NULL;
   if (p && p->_is_a (SEMADDS_Types::MessageDataReader::_local_id))
   {
      result = dynamic_cast < SEMADDS_Types::MessageDataReader_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

SEMADDS_Types::MessageDataReader_ptr SEMADDS_Types::MessageDataReader::_unchecked_narrow (DDS::Object_ptr p)
{
   SEMADDS_Types::MessageDataReader_ptr result;
   result = dynamic_cast < SEMADDS_Types::MessageDataReader_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * SEMADDS_Types::MessageDataReaderView::_local_id = "IDL:SEMADDS_Types/MessageDataReaderView:1.0";

SEMADDS_Types::MessageDataReaderView_ptr SEMADDS_Types::MessageDataReaderView::_duplicate (SEMADDS_Types::MessageDataReaderView_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean SEMADDS_Types::MessageDataReaderView::_local_is_a (const char * _id)
{
   if (strcmp (_id, SEMADDS_Types::MessageDataReaderView::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReaderView NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

SEMADDS_Types::MessageDataReaderView_ptr SEMADDS_Types::MessageDataReaderView::_narrow (DDS::Object_ptr p)
{
   SEMADDS_Types::MessageDataReaderView_ptr result = NULL;
   if (p && p->_is_a (SEMADDS_Types::MessageDataReaderView::_local_id))
   {
      result = dynamic_cast < SEMADDS_Types::MessageDataReaderView_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

SEMADDS_Types::MessageDataReaderView_ptr SEMADDS_Types::MessageDataReaderView::_unchecked_narrow (DDS::Object_ptr p)
{
   SEMADDS_Types::MessageDataReaderView_ptr result;
   result = dynamic_cast < SEMADDS_Types::MessageDataReaderView_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * SEMADDS_Types::SemaEApiTypeSupportInterface::_local_id = "IDL:SEMADDS_Types/SemaEApiTypeSupportInterface:1.0";

SEMADDS_Types::SemaEApiTypeSupportInterface_ptr SEMADDS_Types::SemaEApiTypeSupportInterface::_duplicate (SEMADDS_Types::SemaEApiTypeSupportInterface_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean SEMADDS_Types::SemaEApiTypeSupportInterface::_local_is_a (const char * _id)
{
   if (strcmp (_id, SEMADDS_Types::SemaEApiTypeSupportInterface::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::TypeSupport NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

SEMADDS_Types::SemaEApiTypeSupportInterface_ptr SEMADDS_Types::SemaEApiTypeSupportInterface::_narrow (DDS::Object_ptr p)
{
   SEMADDS_Types::SemaEApiTypeSupportInterface_ptr result = NULL;
   if (p && p->_is_a (SEMADDS_Types::SemaEApiTypeSupportInterface::_local_id))
   {
      result = dynamic_cast < SEMADDS_Types::SemaEApiTypeSupportInterface_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

SEMADDS_Types::SemaEApiTypeSupportInterface_ptr SEMADDS_Types::SemaEApiTypeSupportInterface::_unchecked_narrow (DDS::Object_ptr p)
{
   SEMADDS_Types::SemaEApiTypeSupportInterface_ptr result;
   result = dynamic_cast < SEMADDS_Types::SemaEApiTypeSupportInterface_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * SEMADDS_Types::SemaEApiDataWriter::_local_id = "IDL:SEMADDS_Types/SemaEApiDataWriter:1.0";

SEMADDS_Types::SemaEApiDataWriter_ptr SEMADDS_Types::SemaEApiDataWriter::_duplicate (SEMADDS_Types::SemaEApiDataWriter_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean SEMADDS_Types::SemaEApiDataWriter::_local_is_a (const char * _id)
{
   if (strcmp (_id, SEMADDS_Types::SemaEApiDataWriter::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataWriter NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

SEMADDS_Types::SemaEApiDataWriter_ptr SEMADDS_Types::SemaEApiDataWriter::_narrow (DDS::Object_ptr p)
{
   SEMADDS_Types::SemaEApiDataWriter_ptr result = NULL;
   if (p && p->_is_a (SEMADDS_Types::SemaEApiDataWriter::_local_id))
   {
      result = dynamic_cast < SEMADDS_Types::SemaEApiDataWriter_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

SEMADDS_Types::SemaEApiDataWriter_ptr SEMADDS_Types::SemaEApiDataWriter::_unchecked_narrow (DDS::Object_ptr p)
{
   SEMADDS_Types::SemaEApiDataWriter_ptr result;
   result = dynamic_cast < SEMADDS_Types::SemaEApiDataWriter_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * SEMADDS_Types::SemaEApiDataReader::_local_id = "IDL:SEMADDS_Types/SemaEApiDataReader:1.0";

SEMADDS_Types::SemaEApiDataReader_ptr SEMADDS_Types::SemaEApiDataReader::_duplicate (SEMADDS_Types::SemaEApiDataReader_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean SEMADDS_Types::SemaEApiDataReader::_local_is_a (const char * _id)
{
   if (strcmp (_id, SEMADDS_Types::SemaEApiDataReader::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReader NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

SEMADDS_Types::SemaEApiDataReader_ptr SEMADDS_Types::SemaEApiDataReader::_narrow (DDS::Object_ptr p)
{
   SEMADDS_Types::SemaEApiDataReader_ptr result = NULL;
   if (p && p->_is_a (SEMADDS_Types::SemaEApiDataReader::_local_id))
   {
      result = dynamic_cast < SEMADDS_Types::SemaEApiDataReader_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

SEMADDS_Types::SemaEApiDataReader_ptr SEMADDS_Types::SemaEApiDataReader::_unchecked_narrow (DDS::Object_ptr p)
{
   SEMADDS_Types::SemaEApiDataReader_ptr result;
   result = dynamic_cast < SEMADDS_Types::SemaEApiDataReader_ptr> (p);
   if (result) result->m_count++;
   return result;
}

const char * SEMADDS_Types::SemaEApiDataReaderView::_local_id = "IDL:SEMADDS_Types/SemaEApiDataReaderView:1.0";

SEMADDS_Types::SemaEApiDataReaderView_ptr SEMADDS_Types::SemaEApiDataReaderView::_duplicate (SEMADDS_Types::SemaEApiDataReaderView_ptr p)
{
   if (p) p->m_count++;
   return p;
}

DDS::Boolean SEMADDS_Types::SemaEApiDataReaderView::_local_is_a (const char * _id)
{
   if (strcmp (_id, SEMADDS_Types::SemaEApiDataReaderView::_local_id) == 0)
   {
      return true;
   }

   typedef DDS::DataReaderView NestedBase_1;

   if (NestedBase_1::_local_is_a (_id))
   {
      return true;
   }

   return false;
}

SEMADDS_Types::SemaEApiDataReaderView_ptr SEMADDS_Types::SemaEApiDataReaderView::_narrow (DDS::Object_ptr p)
{
   SEMADDS_Types::SemaEApiDataReaderView_ptr result = NULL;
   if (p && p->_is_a (SEMADDS_Types::SemaEApiDataReaderView::_local_id))
   {
      result = dynamic_cast < SEMADDS_Types::SemaEApiDataReaderView_ptr> (p);
      if (result) result->m_count++;
   }
   return result;
}

SEMADDS_Types::SemaEApiDataReaderView_ptr SEMADDS_Types::SemaEApiDataReaderView::_unchecked_narrow (DDS::Object_ptr p)
{
   SEMADDS_Types::SemaEApiDataReaderView_ptr result;
   result = dynamic_cast < SEMADDS_Types::SemaEApiDataReaderView_ptr> (p);
   if (result) result->m_count++;
   return result;
}



