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
#ifndef OSPL_DDS_CORE_COND_TWAITSET_HPP_
#define OSPL_DDS_CORE_COND_TWAITSET_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/core/cond/TWaitSet.hpp>
#include <org/opensplice/core/ReportUtils.hpp>

// Implementation
namespace dds
{
namespace core
{
namespace cond
{
template <typename DELEGATE>
TWaitSet<DELEGATE>::TWaitSet()
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->set_ref(new DELEGATE);
    this->delegate()->init(this->impl_);
}

template <typename DELEGATE>
TWaitSet<DELEGATE>::~TWaitSet() { }

template <typename DELEGATE>
const typename TWaitSet<DELEGATE>::ConditionSeq TWaitSet<DELEGATE>::wait(const dds::core::Duration& timeout)
{
    ISOCPP_REPORT_STACK_BEGIN();
    ConditionSeq triggered;
    return this->wait(triggered, timeout);
}

template <typename DELEGATE>
const typename TWaitSet<DELEGATE>::ConditionSeq TWaitSet<DELEGATE>::wait()
{
    ISOCPP_REPORT_STACK_BEGIN();
    ConditionSeq triggered;
    return this->wait(triggered, dds::core::Duration::infinite());
}

template <typename DELEGATE>
typename TWaitSet<DELEGATE>::ConditionSeq& TWaitSet<DELEGATE>::wait(ConditionSeq& triggered, const dds::core::Duration& timeout)
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->wait(triggered, timeout);
}

template <typename DELEGATE>
typename TWaitSet<DELEGATE>::ConditionSeq& TWaitSet<DELEGATE>::wait(ConditionSeq& triggered)
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->wait(triggered, dds::core::Duration::infinite());
}

template <typename DELEGATE>
void TWaitSet<DELEGATE>::dispatch()
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->dispatch(dds::core::Duration::infinite());
}

template <typename DELEGATE>
void TWaitSet<DELEGATE>::dispatch(const dds::core::Duration& timeout)
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->dispatch(timeout);
}

template <typename DELEGATE>
TWaitSet<DELEGATE>& TWaitSet<DELEGATE>::operator +=(const dds::core::cond::Condition& cond)
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->attach_condition(cond);
    return *this;
}

template <typename DELEGATE>
TWaitSet<DELEGATE>& TWaitSet<DELEGATE>::operator -=(const dds::core::cond::Condition& cond)
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->detach_condition(cond);
    return *this;
}

template <typename DELEGATE>
TWaitSet<DELEGATE>& TWaitSet<DELEGATE>::attach_condition(const dds::core::cond::Condition& cond)
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->attach_condition(cond);
    return *this;
}

template <typename DELEGATE>
bool TWaitSet<DELEGATE>::detach_condition(const dds::core::cond::Condition& cond)
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->detach_condition(cond.delegate().get());
}

template <typename DELEGATE>
const typename TWaitSet<DELEGATE>::ConditionSeq TWaitSet<DELEGATE>::conditions() const
{
    ISOCPP_REPORT_STACK_BEGIN();
    ConditionSeq conds;
    return this->conditions(conds);
}

template <typename DELEGATE>
typename TWaitSet<DELEGATE>::ConditionSeq& TWaitSet<DELEGATE>::conditions(ConditionSeq& conds) const
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->conditions(conds);
}

}
}
}

// End of implementation

#endif /* OSPL_DDS_CORE_COND_TWAITSET_HPP_ */
