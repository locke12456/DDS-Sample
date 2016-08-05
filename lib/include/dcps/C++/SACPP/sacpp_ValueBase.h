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
#ifndef SACPP_VALUEBASE_H
#define SACPP_VALUEBASE_H

#include "sacpp_dds_basic_types.h"
#include "cpp_dcps_if.h"

namespace DDS
{
   class OS_API ValueBase
   {
      public:
         virtual ValueBase* _add_ref() = 0;

         virtual void _remove_ref() = 0;

         virtual ValueBase* _copy_value() = 0;

         virtual ULong _refcount_value() = 0;

         static ValueBase* _downcast(ValueBase*);

      protected:
         ValueBase();

         ValueBase(const ValueBase&);

         virtual ~ValueBase();

      private:
         void operator=(const ValueBase&);
   };
}
#undef OS_API

#endif /* SACPP_VALUEBASE_H */
