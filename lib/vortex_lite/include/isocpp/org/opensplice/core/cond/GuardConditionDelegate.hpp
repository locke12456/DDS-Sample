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


/**
 * @file
 */

#ifndef LITE_CORE_GUARD_CONDITION_DELEGATE_HPP_
#define LITE_CORE_GUARD_CONDITION_DELEGATE_HPP_

#include <org/opensplice/core/cond/ConditionDelegate.hpp>

namespace org
{
namespace opensplice
{
namespace core
{
namespace cond
{

class OMG_DDS_API GuardConditionDelegate :
                         public org::opensplice::core::cond::ConditionDelegate
{
public:
    GuardConditionDelegate();

    template<typename FUN>
    GuardConditionDelegate(const FUN& functor) :
       org::opensplice::core::cond::ConditionDelegate(functor)/*,
       myTriggerValue(false)*/
    {
    }

    ~GuardConditionDelegate();

    void init(org::opensplice::core::ObjectDelegate::weak_ref_type weak_ref);

    void close() ;

    virtual bool trigger_value() const;

    void trigger_value(bool value);
};

}
}
}
}

#endif  /* LITE_CORE_GUARD_CONDITION_DELEGATE_HPP_ */
