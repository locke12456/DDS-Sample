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
#ifndef CPP_DDS_OPENSPLICE_CONDITION_H
#define CPP_DDS_OPENSPLICE_CONDITION_H

#include "CppSuperClass.h"
#include "ObjSet.h"
#include "cpp_dcps_if.h"
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

namespace DDS
{
  class WaitSet;

  namespace OpenSplice
  {
    class OS_API Condition :
      public virtual ::DDS::Condition,
      public ::DDS::OpenSplice::CppSuperClass
    {
    friend class DDS::WaitSet;

    protected:

      DDS::OpenSplice::ObjSet * waitsets;

      Condition (ObjectKind kind);
      virtual ~Condition ();

      DDS::ReturnCode_t nlReq_init ();
      virtual DDS::ReturnCode_t wlReq_deinit ();

    public:

        dds_condition_t uCondition;
          
        virtual DDS::Boolean get_trigger_value () THROW_ORB_EXCEPTIONS = 0;

    private:

      Condition (const Condition &);
      Condition & operator = (const Condition &);
    };
  };
};

#undef OS_API

#endif /* CPP_DDS_OPENSPLICE_CONDITION_H */
