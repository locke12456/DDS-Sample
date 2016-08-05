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
#ifndef DDS_OPENSPLICE_STRING_MAP_H
#define DDS_OPENSPLICE_STRING_MAP_H

#include "ccpp.h"
#include "vortex_os.h"

OS_CLASS(ut_table);

namespace DDS
{
    namespace OpenSplice
    {
        class StrObjMap
        {
        private:
            ut_table myStrMap;
            DDS::Boolean keepRef;

            static os_equality
            fnCompareElements(const char *element1, const char *element2, void *arg);

            static void
            fnFreeKey(char *element, void *arg);

            static void
            fnFreeValue(DDS::Object_ptr element, void *arg);

            static os_int32
            strObjMapActionWrapper(const char *k, DDS::Object_ptr o, void *arg);

            static DDS::Boolean
            toObjSeq(const char *key, DDS::Object_ptr element, void *arg);

        public:
            StrObjMap(DDS::Boolean keepRef);
            ~StrObjMap();

            DDS::ReturnCode_t
            init();

            DDS::ReturnCode_t
            deinit();

            typedef DDS::Boolean (*StrObjMapActionFunc) (const char *key, DDS::Object_ptr element, void *arg);

            DDS::Boolean
            walk(StrObjMapActionFunc, void *arg);

            const DDS::Object *
            insertElement(const char *key, DDS::Object_ptr element);

            DDS::Object_ptr
            removeElement(const char *key);

            DDS::Object_ptr
            findElement(const char *key);

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

#endif /* DDS_OPENSPLICE_STRING_MAP_H */
