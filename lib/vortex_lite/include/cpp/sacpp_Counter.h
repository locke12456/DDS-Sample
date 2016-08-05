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
#ifndef SACPP_COUNTER_H
#define SACPP_COUNTER_H
#include "cpp_dcps_if.h"
#include "dds.h"

class OS_API DDS_DCPS_Counter
{	
   public:
      DDS_DCPS_Counter(uint32_t val = 0) {
          m_value = val;
      };

      operator uint32_t () {
          return m_value;
      };

      DDS_DCPS_Counter & operator = (uint32_t val) {
         m_value = val;
         return *this;
      };

      uint32_t operator ++ (); // prefix (++a)
      uint32_t operator -- (); // prefix (--a)

      uint32_t operator ++ (int); // postfix (a++)
      uint32_t operator -- (int); // postfix (a--)

   private:

      DDS_DCPS_Counter(const DDS_DCPS_Counter&);
      DDS_DCPS_Counter &operator= (const DDS_DCPS_Counter&);

      uint32_t m_value;
};



/******************************************************************************/
/*                               Inline Methods                               */
/******************************************************************************/
#ifdef _WIN32
inline uint32_t DDS_DCPS_Counter::operator ++ (int)
{
  //@todo improve
  return InterlockedIncrement (&m_value) - 1;
}

inline uint32_t DDS_DCPS_Counter::operator -- (int)
{
  //@todo improve
  return InterlockedDecrement (&m_value) + 1;
}

inline uint32_t DDS_DCPS_Counter::operator ++ ()
{
  //@todo improve
  return InterlockedIncrement (&m_value);
}

inline uint32_t DDS_DCPS_Counter::operator -- ()
{
  //@todo improve
  return InterlockedDecrement (&m_value);
}
#else
inline uint32_t DDS_DCPS_Counter::operator ++ (int)
{
   //@todo improve
   return __sync_add_and_fetch (&m_value, 1) - 1;
}

inline uint32_t DDS_DCPS_Counter::operator -- (int)
{
  //@todo improve
  return __sync_sub_and_fetch (&m_value, 1) + 1;
}

inline uint32_t DDS_DCPS_Counter::operator ++ ()
{
  //@todo improve
  return __sync_add_and_fetch (&m_value, 1);
}

inline uint32_t DDS_DCPS_Counter::operator -- ()
{
  //@todo improve
  return __sync_sub_and_fetch (&m_value, 1);
}
#endif
#undef OS_API
#endif /* SACPP_COUNTER_H */
