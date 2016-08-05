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
#ifndef SACPP_SYSTEMEXCEPTION_H
#define SACPP_SYSTEMEXCEPTION_H

#include "sacpp_dds_basic_types.h"
#include "sacpp_Exception.h"
#include "cpp_dcps_if.h"

#ifdef minor
#undef minor
#endif

class OS_API DDS::SystemException : public DDS::Exception
{
public:

   SystemException ();
   SystemException (DDS::ULong minor, DDS::CompletionStatus status);

   static DDS::SystemException * _downcast (DDS::Exception*);
   static const DDS::SystemException * _downcast (const DDS::Exception*);

   DDS::ULong minor () const;
   void minor (DDS::ULong minor);

   DDS::CompletionStatus completed () const;
   void completed (DDS::CompletionStatus status);

   virtual SystemException *_as_system();

private:

   DDS::ULong m_minor;
   DDS::CompletionStatus m_status;
};

#undef OS_API
#endif