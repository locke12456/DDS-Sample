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
#ifndef DDS_OPENSPLICE_OBJECT_SET_H
#define DDS_OPENSPLICE_OBJECT_SET_H

#include "ccpp.h"
#include <set>

namespace DDS
{
  namespace OpenSplice
  {
    class ObjSet
    {
    private:

        struct compareElements;
        std::set <DDS::Object_ptr, compareElements> * myObjSet;
        DDS::Boolean keepRef;

        static DDS::Boolean toObjSeq (DDS::Object_ptr element, void *arg);

    public:

        ObjSet (DDS::Boolean keepRef);
        ~ObjSet ();

        typedef DDS::Boolean (*ObjSetActionFunc) (DDS::Object_ptr elem, void *arg);

        DDS::Boolean walk (ObjSetActionFunc, void *arg);

        DDS::Boolean insertElement (DDS::Object_ptr element);
        DDS::Boolean removeElement (DDS::Object_ptr element);
        DDS::Boolean containsElement (DDS::Object_ptr element);
        DDS::Object_ptr findElement (DDS::Object_ptr element);
        DDS::Long getNrElements ();

        DDS::ObjSeq * getObjSeq ();
        void getObjSeq (DDS::ObjSeq &destination);
        void clear();
    };
  }
}

#endif /* DDS_OPENSPLICE_OBJECT_SET_H */
