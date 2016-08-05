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
#ifndef SACPP_EXCEPTION_H
#define SACPP_EXCEPTION_H

#include "sacpp_dds_basic_types.h"
#include "cpp_dcps_if.h"

class OS_API DDS::Exception
{
   public:

      Exception () {};
      virtual ~Exception () {};

      static DDS::Exception* _downcast (DDS::Exception * e);
      static const DDS::Exception* _downcast (const DDS::Exception * e);

      virtual const char * _name () const = 0;
      virtual const char * _rep_id () const = 0;
      virtual void _raise () const = 0;
      virtual DDS::Exception_ptr _clone () const = 0;

      virtual DDS::UserException * _as_user ();
      virtual DDS::SystemException * _as_system ();
};

#undef OS_API
#endif
