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
#ifndef OSPL_DDS_CORE_COND_TCONDITION_IMPL_HPP_
#define OSPL_DDS_CORE_COND_TCONDITION_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/core/detail/ReferenceImpl.hpp>
#include <dds/core/cond/TCondition.hpp>
#include <org/opensplice/core/ReportUtils.hpp>

// Implementation
namespace dds
{
namespace core
{
namespace cond
{

template <typename DELEGATE>
TCondition<DELEGATE>::~TCondition()
{
}

/** @cond
 * Somehow, these cause functions duplicates in doxygen documentation.
 */
template <typename DELEGATE>
template <typename Functor>
void TCondition<DELEGATE>::handler(Functor& func)
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->set_handler(func);
}

template <typename DELEGATE>
template <typename Functor>
void TCondition<DELEGATE>::handler(const Functor& func)
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->set_handler(func);
}
/** @endcond */

template <typename DELEGATE>
void TCondition<DELEGATE>::reset_handler()
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->reset_handler();
}

template <typename DELEGATE>
void TCondition<DELEGATE>::dispatch()
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->dispatch();
}

template <typename DELEGATE>
bool TCondition<DELEGATE>::trigger_value() const
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->trigger_value();
}

}
}
}
// End of implementation

#endif /* OSPL_DDS_CORE_COND_TCONDITION_IMPL_HPP_ */
