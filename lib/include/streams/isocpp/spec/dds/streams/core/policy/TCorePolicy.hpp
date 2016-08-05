#ifndef SPEC_DDS_STREAMS_CORE_POLICY_TCORE_POLICY_HPP_
#define SPEC_DDS_STREAMS_CORE_POLICY_TCORE_POLICY_HPP_

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

#include <dds/core/Value.hpp>

namespace dds
{
namespace streams
{
namespace core
{
namespace policy
{

/**
 * The StreamFlushQosPolicy can be used to set limits on the stream(s) of the StreamDataWriter
 * it is applied to.
 *
 * By setting the StreamFlushQosPolicy, the StreamDataWriter will
 * automatically flush its stream(s) based on a particular limit. The attributes can be
 * combined, for example a max_delay of 1 second and a max_samples of 100 will
 * result in a flush at least each second or sooner if 100 samples are appended to a
 * stream.
 *
 * The max_delay limit applies to all streams in case a StreamDataWriter
 * manages more than one stream. It is initialized when the first stream is created, and
 * applied to all streams created after that.
 *
 * In case of a manual flush (when the application calls the flush operation), the
 * max_samples limit is reinitialized.
 */
template<typename D>
class TStreamFlush : public dds::core::Value<D>
{
public:
    /**
     * Creates a StreamFlushQosPolicy QoS instance
     */
    TStreamFlush(const dds::core::Duration& max_delay = dds::core::Duration::infinite(),
                 uint32_t max_samples = 64);

    /**
     * Copies a StreamFlushQosPolicy QoS instance
     *
     * @param other the StreamFlushQosPolicy QoS instance to copy
     */
    TStreamFlush(const TStreamFlush& other);

    /**
     * Sets the max delay
     *
     * @param max_delay max delay
     */
    void max_delay(const dds::core::Duration& max_delay);

    /**
     * Gets the max delay
     *
     * @return max delay
     */
    const dds::core::Duration max_delay() const;

    /**
     * Sets the max samples
     *
     * @param max_delay max delay
     */
    void max_samples(uint32_t max_samples);

    /**
     * Gets the max samples
     *
     * @return max samples
     */
    const uint32_t max_samples() const;
};

}
}
}
}

#endif /* SPEC_DDS_STREAMS_CORE_POLICY_TCORE_POLICY_HPP_ */
