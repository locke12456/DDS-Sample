//******************************************************************
// 
//  Generated by IDL to C++ Translator
//  
//  File name: semadds.h
//  Source: idl/semadds.idl
//  Generated: Thu Mar 03 11:45:33 2016
//  OpenSplice V6.5.0p1
//  
//******************************************************************
#ifndef _SEMADDS_H_
#define _SEMADDS_H_

#include "sacpp_mapping.h"
#include "semadds_export.h"


namespace SEMADDS_Types
{
   struct Message;

   struct OS_SEMADDS_API Message
   {
         DDS::Long id;
         DDS::String_mgr message;
   };

   typedef DDS_DCPSStruct_var < Message> Message_var;
   typedef DDS_DCPSStruct_out < Message> Message_out;
}




#undef OS_SEMADDS_API

#endif