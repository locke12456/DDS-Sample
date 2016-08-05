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

#ifndef LITE_CORE_COND_CONDITION_DELEGATE_HPP_
#define LITE_CORE_COND_CONDITION_DELEGATE_HPP_

#include <org/opensplice/core/UserObjectDelegate.hpp>
#include <org/opensplice/core/cond/FunctorHolder.hpp>
#include <org/opensplice/core/Mutex.hpp>
#include <org/opensplice/core/ScopedLock.hpp>
#include <org/opensplice/core/ReportUtils.hpp>

#include <set>

namespace dds
{
namespace core
{
namespace cond
{
template <typename DELEGATE> class TCondition;
}
}
}

namespace org
{
namespace opensplice
{
namespace core
{
namespace cond
{

class WaitSetDelegate;

class OMG_DDS_API ConditionDelegate :
                      public virtual org::opensplice::core::UserObjectDelegate
{
public:
    typedef ::dds::core::smart_ptr_traits< ConditionDelegate >::ref_type
                                                                      ref_type;
    typedef ::dds::core::smart_ptr_traits< ConditionDelegate >::weak_ref_type
                                                                 weak_ref_type;

    ConditionDelegate();

    ~ConditionDelegate();

    void init(ObjectDelegate::weak_ref_type weak_ref);

    void close();

    virtual bool trigger_value() const = 0;

    template <typename FUN>
    void set_handler(FUN& functor)
    {
        org::opensplice::core::ScopedObjectLock scopedLock(*this);

        if (this->myFunctor)
        {
            delete this->myFunctor;
        }
        myFunctor =
           new org::opensplice::core::cond::FunctorHolder<FUN>(functor);
    }

    void reset_handler();

    virtual void dispatch();

    virtual dds_condition_t get_user_condition();

    dds::core::cond::TCondition<ConditionDelegate> wrapper();

private:
    org::opensplice::core::cond::FunctorHolderBase *myFunctor;
};

}
}
}
}

#endif /* LITE_CORE_COND_CONDITION_DELEGATE_HPP_ */
