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
#ifndef OSPL_DDS_CORE_COND_DETAIL_GUARDCONDITION_HPP_
#define OSPL_DDS_CORE_COND_DETAIL_GUARDCONDITION_HPP_

/**
 * @cond
 * Ignore this file in the API
 */

// Implementation

namespace org
{
namespace opensplice
{
namespace core
{
namespace cond
{
class GuardConditionDelegate;
}
}
}
}

namespace dds
{
namespace core
{
namespace cond
{

template <typename DELEGATE>
class TGuardCondition;

namespace detail
{
typedef dds::core::cond::TGuardCondition<org::opensplice::core::cond::GuardConditionDelegate> GuardCondition;
}
}
}
}

// End of implementation

/** @endcond */

#endif /* OSPL_DDS_CORE_COND_DETAIL_GUARDCONDITION_HPP_ */
