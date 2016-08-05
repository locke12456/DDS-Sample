#ifndef ORG_OPENSPLICE_STREAMS_CORE_POLICY_CORE_POLICY_IMPL_HPP_
#define ORG_OPENSPLICE_STREAMS_CORE_POLICY_CORE_POLICY_IMPL_HPP_

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

#include <dds/core/Duration.hpp>
namespace org
{
namespace opensplice
{
namespace streams
{
namespace core
{
namespace policy
{

class StreamFlush
{
public:
    StreamFlush() : max_samples_(0) {}

    StreamFlush(const dds::core::Duration& max_delay, uint32_t max_samples) :
        max_delay_(max_delay), max_samples_(max_samples) {}

    void max_delay(const dds::core::Duration& max_delay)
    {
        max_delay_ = max_delay;
    }

    dds::core::Duration max_delay() const
    {
        return max_delay_;
    }

    dds::core::Duration& max_delay()
    {
        return max_delay_;
    }

    void max_samples(uint32_t max_samples)
    {
        max_samples_ = max_samples;
    }

    uint32_t max_samples() const
    {
        return max_samples_;
    }

    uint32_t max_samples()
    {
        return max_samples_;
    }

    bool operator==(const StreamFlush& other) const
    {
        return other.max_delay() == max_delay_ && other.max_samples() == max_samples_;
    }

private:
    dds::core::Duration max_delay_;
    uint32_t max_samples_;
};

}
}
}
}
}

#endif /* ORG_OPENSPLICE_STREAMS_CORE_POLICY_CORE_POLICY_IMPL_HPP_ */
