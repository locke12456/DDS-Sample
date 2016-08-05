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
#ifndef LITE_DDS_CORE_COND_TGUARDCONDITION_IMPL_HPP_
#define LITE_DDS_CORE_COND_TGUARDCONDITION_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/core/cond/TGuardCondition.hpp>
#include <org/opensplice/core/cond/GuardConditionDelegate.hpp>
#include <org/opensplice/core/ReportUtils.hpp>

// Implementation
namespace dds
{
namespace core
{
namespace cond
{

template <typename DELEGATE>
TGuardCondition<DELEGATE>::TGuardCondition()
{
    this->set_ref(new DELEGATE);
    this->delegate()->init(this->impl_);
}

template <typename DELEGATE>
template <typename FUN>
TGuardCondition<DELEGATE>::TGuardCondition(FUN& functor)
{
    this->set_ref(new DELEGATE);
    this->delegate()->init(this->impl_);
    this->delegate()->set_handler(functor);
}

template <typename DELEGATE>
TGuardCondition<DELEGATE>::~TGuardCondition()
{
}

template <typename DELEGATE>
void TGuardCondition<DELEGATE>::trigger_value(bool value)
{
    this->delegate()->trigger_value(value);
}

template <typename DELEGATE>
bool TGuardCondition<DELEGATE>::trigger_value()
{
    return TCondition<DELEGATE>::trigger_value();
}

template <typename DELEGATE>
TCondition<DELEGATE>::TCondition(const dds::core::cond::TGuardCondition<org::opensplice::core::cond::GuardConditionDelegate>& h)
{
    if (h.is_nil()) {
        /* We got a null object and are not really able to do a typecheck here. */
        /* So, just set a null object. */
        *this = dds::core::null;
    } else {
        this->::dds::core::Reference<DELEGATE>::impl_ = OSPL_CXX11_STD_MODULE::dynamic_pointer_cast<DELEGATE_T>(h.delegate());
        if (h.delegate() != this->::dds::core::Reference<DELEGATE>::impl_) {
            throw dds::core::IllegalOperationError(std::string("Attempted invalid cast: ") + typeid(h).name() + " to " + typeid(*this).name());
        }
    }
}

template <typename DELEGATE>
TCondition<DELEGATE>&
TCondition<DELEGATE>::operator=(const dds::core::cond::TGuardCondition<org::opensplice::core::cond::GuardConditionDelegate>& rhs)
{
    if (this != (TCondition*)&rhs) {
        if (rhs.is_nil()) {
            /* We got a null object and are not really able to do a typecheck here. */
            /* So, just set a null object. */
            *this = dds::core::null;
        } else {
            TCondition other(rhs);
            /* Dont have to copy when the delegate is the same. */
            if (other.delegate() != this->::dds::core::Reference<DELEGATE>::impl_) {
                *this = other;
            }
        }
    }
    return *this;
}

}
}
}
// End of implementation

#endif /* LITE_DDS_CORE_COND_TGUARDCONDITION_IMPL_HPP_ */
