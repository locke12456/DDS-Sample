#ifndef OSPL_DDS_STREAMS_CORE_POLICY_DETAIL_COREPOLICY_HPP_
#define OSPL_DDS_STREAMS_CORE_POLICY_DETAIL_COREPOLICY_HPP_

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

#include <org/opensplice/streams/core/policy/CorePolicy.hpp>
#include <dds/streams/core/policy/TCorePolicy.hpp>

namespace dds
{
namespace streams
{
namespace core
{
namespace policy
{
namespace detail
{

typedef dds::streams::core::policy::TStreamFlush<org::opensplice::streams::core::policy::StreamFlush>
StreamFlush;

}
}
}
}
}

#endif /* OSPL_DDS_STREAMS_CORE_POLICY_DETAIL_COREPOLICY_HPP_ */
