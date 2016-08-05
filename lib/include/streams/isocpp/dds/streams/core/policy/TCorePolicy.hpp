#ifndef OSPL_DDS_STREAMS_CORE_POLICY_TCOREPOLICY_HPP_
#define OSPL_DDS_STREAMS_CORE_POLICY_TCOREPOLICY_HPP_

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

#include <spec/dds/streams/core/policy/TCorePolicy.hpp>

namespace dds
{
namespace streams
{
namespace core
{
namespace policy
{

template <typename D>
TStreamFlush<D>::TStreamFlush(const dds::core::Duration& max_delay, uint32_t max_samples) :
    dds::core::Value<D>(max_delay, max_samples) {}

template <typename D>
TStreamFlush<D>::TStreamFlush(const TStreamFlush& other) :
    dds::core::Value<D>(other.max_delay(), other.max_samples()) {}

template <typename D>
void TStreamFlush<D>::max_delay(const dds::core::Duration& max_delay)
{
    this->delegate().max_delay(max_delay);
}

template <typename D>
const dds::core::Duration TStreamFlush<D>::max_delay() const
{
    return this->delegate().max_delay();
}

template <typename D>
void TStreamFlush<D>::max_samples(uint32_t max_samples)
{
    this->delegate().max_samples(max_samples);
}

template <typename D>
const uint32_t TStreamFlush<D>::max_samples() const
{
    return this->delegate().max_samples();
}

}
}
}
}

#endif /* OSPL_DDS_STREAMS_CORE_POLICY_TCOREPOLICY_HPP_ */
