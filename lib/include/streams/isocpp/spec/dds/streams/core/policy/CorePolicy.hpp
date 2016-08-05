#ifndef SPEC_DDS_STREAMS_CORE_POLICY_CORE_POLICY_HPP_
#define SPEC_DDS_STREAMS_CORE_POLICY_CORE_POLICY_HPP_

/*
*                         OpenSplice DDS
*
*   This software and documentation are Copyright 2006 to 2014 PrismTech
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

#include <dds/core/policy/CorePolicy.hpp>
#include <dds/streams/core/policy/detail/CorePolicy.hpp>

namespace dds
{
namespace streams
{
namespace core
{
namespace policy
{
    typedef dds::streams::core::policy::detail::StreamFlush StreamFlush;
}
}
}
}

#endif /* SPEC_DDS_STREAMS_CORE_POLICY_CORE_POLICY_HPP_ */
