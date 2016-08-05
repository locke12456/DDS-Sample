/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2012 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */
#ifndef CPP_DDS_OPENSPLICE_WAITSET_H
#define CPP_DDS_OPENSPLICE_WAITSET_H

#include "CppSuperClass.h"
#include "ObjSet.h"
#include "Condition.h"
#include "StatusCondition.h"
#include "ReadCondition.h"
#include "cpp_dcps_if.h"

namespace DDS
{
    typedef WaitSetInterface_ptr WaitSet_ptr;
    typedef WaitSetInterface_var WaitSet_var;
    typedef WaitSetInterface_out WaitSet_out;

    class GuardCondition;

    class OS_API WaitSet
        : public virtual DDS::WaitSetInterface,
          public DDS::OpenSplice::CppSuperClass
    {
    friend class DDS::GuardCondition;
    friend class DDS::OpenSplice::StatusCondition;
    friend class DDS::OpenSplice::ReadCondition;

    private:
        u_waitset uWaitset;
        DDS::OpenSplice::ObjSet *conditions;
        DDS::OpenSplice::ObjSet *guards;

        DDS::ReturnCode_t
        trigger (
            DDS::Condition_ptr cond);

        DDS::ReturnCode_t
        wlReq_attachGeneralCondition(
            DDS::Condition_ptr condition,
            u_observable uCondition);

        DDS::ReturnCode_t
        wlReq_detachGeneralCondition(
            DDS::OpenSplice::Condition *condition,
            u_observable uCondition);

        DDS::ReturnCode_t
        wlReq_attachGuardCondition(
            GuardCondition *condition);

        DDS::ReturnCode_t
        wlReq_detachGuardCondition(
            GuardCondition *condition);

    protected:
        virtual DDS::ReturnCode_t
        init();

        virtual DDS::ReturnCode_t
        nlReq_init();

        virtual DDS::ReturnCode_t
        wlReq_deinit();

        static DDS::Boolean
        collect_detached_conditions(
            DDS::Object_ptr td,
            struct findObjectArg *arg);

    public:
        static WaitSet_ptr
        _duplicate(WaitSet_ptr obj);

        static WaitSet_ptr
        _narrow(WaitSet_ptr obj);

        static WaitSet_ptr
        _unchecked_narrow(WaitSet_ptr obj);

        static WaitSet_ptr
        _nil (void);

        WaitSet ();

        ~WaitSet ();

        DDS::ReturnCode_t
        wait (
            DDS::ConditionSeq & active_conditions,
            const DDS::Duration_t &timeout
        ) THROW_ORB_EXCEPTIONS;

        DDS::ReturnCode_t
        attach_condition (
            DDS::Condition_ptr cond
        ) THROW_ORB_EXCEPTIONS;

        DDS::ReturnCode_t
        detach_condition (
            DDS::Condition_ptr cond
        ) THROW_ORB_EXCEPTIONS;

        DDS::ReturnCode_t
        wlReq_detach_condition (
            DDS::Condition_ptr cond
        ) THROW_ORB_EXCEPTIONS;

        DDS::ReturnCode_t
        get_conditions (
            DDS::ConditionSeq &attched_conditions
        ) THROW_ORB_EXCEPTIONS;
    };
}
#undef OS_API
#endif
