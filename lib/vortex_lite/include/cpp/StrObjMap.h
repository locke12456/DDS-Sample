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
#ifndef DDS_OPENSPLICE_STRING_MAP_H
#define DDS_OPENSPLICE_STRING_MAP_H

#include "ccpp.h"
#include <map>

namespace DDS
{
  namespace OpenSplice
  {
    class StrObjMap
    {
    private:

      struct compareElements;

      std::map<char*, DDS::Object_ptr, compareElements>* myStrMap;
      DDS::Boolean keepRef;

    public:

      StrObjMap (DDS::Boolean keepRef);
      ~StrObjMap ();

      typedef DDS::Boolean (*StrObjMapActionFunc)
        (const char *key, DDS::Object_ptr element, void *arg);

      DDS::Boolean walk (StrObjMapActionFunc, void *arg);
      DDS::Object_ptr insertElement (const char *key, DDS::Object_ptr element);
      DDS::Object_ptr findElement (const char *key);
      void clear ();
    };
  }
}

#endif /* DDS_OPENSPLICE_STRING_MAP_H */
