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
#ifndef SACPP_DEFAULTVALUEREFCOUNTBASE_H
#define SACPP_DEFAULTVALUEREFCOUNTBASE_H

#include "sacpp_ValueBase.h"
#include "sacpp_Counter.h"
#include "cpp_dcps_if.h"

namespace DDS
{
   class OS_API DefaultValueRefCountBase: public virtual ValueBase
   {
      public:
         virtual ValueBase* _add_ref ();

         virtual void _remove_ref ();

         virtual ULong _refcount_value ();

      protected:
         DefaultValueRefCountBase ();

         virtual ~DefaultValueRefCountBase () {}

      private:
         DDS_DCPS_Counter m_count;
   };
}
#undef OS_API

#endif /* SACPP_DEFAULTVALUEREFCOUNTBASE_H */
