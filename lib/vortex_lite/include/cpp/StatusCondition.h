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
#ifndef CPP_DDS_OPENSPLICE_STATUSCONDITION_H
#define CPP_DDS_OPENSPLICE_STATUSCONDITION_H

#include "CppSuperClass.h"
#include "Condition.h"
#include "cpp_dcps_if.h"

namespace DDS
{
  namespace OpenSplice
  {
    class Entity;

    class OS_API StatusCondition :
      public virtual ::DDS::StatusCondition,
      public ::DDS::OpenSplice::Condition
    {
    friend class DDS::OpenSplice::Entity;
    friend class DDS::WaitSet;

    private:

      DDS::OpenSplice::Entity * entity;
      DDS::StatusMask enabledStatusMask;

    protected:

      StatusCondition ();
      virtual ~StatusCondition ();

      virtual DDS::ReturnCode_t init (DDS::OpenSplice::Entity *entity);
      DDS::ReturnCode_t nlReq_init (DDS::OpenSplice::Entity *entity);
      virtual DDS::ReturnCode_t wlReq_deinit();

    public:

      DDS::Boolean get_trigger_value () THROW_ORB_EXCEPTIONS;

      DDS::StatusMask get_enabled_statuses () THROW_ORB_EXCEPTIONS;

      DDS::ReturnCode_t set_enabled_statuses
        (DDS::StatusMask mask) THROW_ORB_EXCEPTIONS;

      DDS::Entity_ptr get_entity () THROW_ORB_EXCEPTIONS;
    };
  };
};

#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_STATUSCONDITION_H */
