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
#ifndef OSPL_DDS_CORE_COND_DETAIL_CONDITION_HPP_
#define OSPL_DDS_CORE_COND_DETAIL_CONDITION_HPP_

/**
 * @cond
 * Ignore this file in the API
 */

// Implementation

#include <dds/core/cond/detail/TConditionImpl.hpp>
#include <org/opensplice/core/cond/ConditionDelegate.hpp>

namespace dds
{
namespace core
{
namespace cond
{
namespace detail
{
typedef dds::core::cond::TCondition<org::opensplice::core::cond::ConditionDelegate> Condition;
}
}
}
}

// End of implementation

/** @endcond */

#endif /* OSPL_DDS_CORE_COND_DETAIL_CONDITION_HPP_ */
