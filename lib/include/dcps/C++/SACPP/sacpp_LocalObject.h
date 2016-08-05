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
#ifndef SACPP_LOCALOBJECT_H
#define SACPP_LOCALOBJECT_H

#include "sacpp_Object.h"
#include "cpp_dcps_if.h"

class OS_API DDS::LocalObject : virtual public DDS::Object
{
   friend void DDS::release(DDS::LocalObject * p);

public:

   static DDS::LocalObject_ptr _duplicate(DDS::LocalObject_ptr obj);
   static DDS::LocalObject_ptr _narrow(DDS::LocalObject_ptr obj);
   static DDS::LocalObject_ptr _nil();

   virtual void _add_ref();
   virtual void _remove_ref();
   virtual DDS::Boolean _is_a(const char * id);
   virtual DDS::ULong _hash(DDS::ULong maximum);

   virtual DDS::Boolean _is_equivalent(const DDS::Object * obj);

   virtual DDS::Boolean is_local_object();

   LocalObject();

protected:

   virtual ~LocalObject ();
};

inline DDS::LocalObject_ptr DDS::LocalObject::_nil()
{
   return NULL;
}

inline DDS::LocalObject_ptr
DDS::LocalObject::_narrow(DDS::LocalObject *obj)
{
   return (obj?_duplicate(obj):NULL);
}

inline DDS::LocalObject_ptr
DDS::LocalObject::_duplicate(DDS::LocalObject * p)
{
   if (p && (p->m_count != ~0U)) {
      p->m_count++;
   }

   return p;
}

#undef OS_API
#endif /* SACPP_LOCALOBJECT_H */
