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
#ifndef CPP_DDS_OPENSPLICE_GUARDCONDITION_H
#define CPP_DDS_OPENSPLICE_GUARDCONDITION_H

#include "CppSuperClass.h"
#include "Condition.h"
#include "cpp_dcps_if.h"

namespace DDS
{
  class OS_API GuardCondition : 
    public virtual DDS::GuardConditionInterface,
    public DDS::OpenSplice::Condition
  {
    friend class DDS::WaitSet;

  private:

    DDS::Boolean triggerValue;

  protected:

    DDS::ReturnCode_t nlReq_init ();
    virtual DDS::ReturnCode_t wlReq_deinit ();

  public:

    GuardCondition ();
    ~GuardCondition ();

    virtual ::DDS::Boolean get_trigger_value ();
    ::DDS::ReturnCode_t set_trigger_value (DDS::Boolean value);
  };

  typedef GuardCondition *GuardCondition_ptr;
  typedef GuardConditionInterface_var GuardCondition_var;
  typedef GuardConditionInterface_out GuardCondition_out;
};
#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_GUARDCONDITION_H */
