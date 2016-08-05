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
#ifndef SACPP_COUNTER_H
#define SACPP_COUNTER_H

#include "os_abstract.h"
#include "os_atomics.h"
#include "cpp_dcps_if.h"

class OS_API DDS_DCPS_Counter
{
   public:
      DDS_DCPS_Counter(os_uint32 val = 0) {
          pa_st32(&m_value, val);
      };

      operator os_uint32 () {
          return pa_ld32(&m_value);
      };

      DDS_DCPS_Counter & operator = (os_uint32 val) { 
         pa_st32(&m_value, val);
         return *this;
      };

      os_uint32 operator ++ (); // prefix (++a)
      os_uint32 operator -- (); // prefix (--a)

      os_uint32 operator ++ (int); // postfix (a++)
      os_uint32 operator -- (int); // postfix (a--)

   private:

      DDS_DCPS_Counter(const DDS_DCPS_Counter&);
      DDS_DCPS_Counter &operator= (const DDS_DCPS_Counter&);

      pa_uint32_t m_value;
};


/******************************************************************************/
/*                               Inline Methods                               */
/******************************************************************************/

inline os_uint32 DDS_DCPS_Counter::operator ++ (int)
{
   return pa_inc32_nv (&m_value) - 1;
}

inline os_uint32 DDS_DCPS_Counter::operator -- (int)
{
   return pa_dec32_nv (&m_value) + 1;
}

inline os_uint32 DDS_DCPS_Counter::operator ++ ()
{
   return pa_inc32_nv (&m_value);
}

inline os_uint32 DDS_DCPS_Counter::operator -- ()
{
   return pa_dec32_nv (&m_value);
}

#undef OS_API
#endif /* SACPP_COUNTER_H */
