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
#ifndef SACPP_USEREXCEPTION_H
#define SACPP_USEREXCEPTION_H

#include "sacpp_dds_basic_types.h"
#include "sacpp_Exception.h"
#include "cpp_dcps_if.h"

class OS_API DDS::UserException : public DDS::Exception
{
public:

   static DDS::UserException* _downcast (DDS::Exception* exc);
   static const DDS::UserException* _downcast (const DDS::Exception* exc);

   virtual UserException *_as_user();
};

#undef OS_API
#endif
