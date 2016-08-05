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


/**
 * @file
 */

#ifndef ORG_OPENSPLICE_CORE_GUARD_CONDITION_DELEGATE_HPP_
#define ORG_OPENSPLICE_CORE_GUARD_CONDITION_DELEGATE_HPP_

#include <org/opensplice/core/cond/ConditionDelegate.hpp>

namespace org
{
namespace opensplice
{
namespace core
{
namespace cond
{

class OMG_DDS_API GuardConditionDelegate : public org::opensplice::core::cond::ConditionDelegate
{
public:
    GuardConditionDelegate();

    template<typename FUN>
    GuardConditionDelegate(const FUN& functor) :
            org::opensplice::core::cond::ConditionDelegate(functor),
            myTriggerValue(false)
    {
    }

    ~GuardConditionDelegate();

    void init(org::opensplice::core::ObjectDelegate::weak_ref_type weak_ref);

    virtual bool trigger_value() const;

    void trigger_value(bool value);

    virtual void add_waitset(
            const dds::core::cond::TCondition<ConditionDelegate>& cond,
            org::opensplice::core::cond::WaitSetDelegate *waitset);

    virtual bool remove_waitset(
            org::opensplice::core::cond::WaitSetDelegate *waitset);

private:
    bool myTriggerValue;
};

}
}
}
}

#endif  /* ORG_OPENSPLICE_CORE_GUARD_CONDITION_DELEGATE_HPP_ */
