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
#ifndef DDS_OPENSPLICE_OBJECT_SET_H
#define DDS_OPENSPLICE_OBJECT_SET_H

#include "ccpp.h"
#include "vortex_os.h"

OS_CLASS(ut_set);

namespace DDS
{
    namespace OpenSplice
    {
        class ObjSet
        {
        private:
            ut_set myObjSet;
            DDS::Boolean keepRef;

            static os_equality
            fnCompareElements(const DDS::Object_ptr element1, const DDS::Object_ptr element2, void *arg);

            static void
            fnFreeValue(DDS::Object_ptr element, void *arg);

            static os_int32
            objSetActionWrapper(DDS::Object_ptr o, void *arg);

            static DDS::Boolean
            toObjSeq(DDS::Object_ptr element, void *arg);

        public:
            ObjSet(DDS::Boolean keepRef);
            ~ObjSet();

            DDS::ReturnCode_t
            init();

            DDS::ReturnCode_t
            deinit();

            typedef DDS::Boolean (*ObjSetActionFunc) (DDS::Object_ptr element, void *arg);

            DDS::Boolean
            walk(ObjSetActionFunc, void *arg);

            DDS::Boolean
            insertElement(DDS::Object_ptr element);

            DDS::Boolean
            removeElement(DDS::Object_ptr element);

            DDS::Boolean
            containsElement(DDS::Object_ptr element);

            DDS::Object_ptr
            findElement(DDS::Object_ptr element);

            DDS::Long
            getNrElements();

            DDS::ObjSeq *
            getObjSeq();

            void
            getObjSeq(DDS::ObjSeq &destination);

            void
            clear();
        };
    }
}

#endif /* DDS_OPENSPLICE_OBJECT_SET_H */
