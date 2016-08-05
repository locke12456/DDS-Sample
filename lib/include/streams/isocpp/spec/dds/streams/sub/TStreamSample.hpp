#ifndef SPEC_DDS_STREAMS_SUB_TSTREAMSAMPLE_HPP_
#define SPEC_DDS_STREAMS_SUB_TSTREAMSAMPLE_HPP_
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
namespace sub
{
template <typename T, template <typename Q> class DELEGATE>
class StreamSample;
}
}
}

/**
 * This class encapsulates the data associated with stream samples.
 */
template <typename T, template <typename Q> class DELEGATE>
class dds::streams::sub::StreamSample : public dds::core::Value< DELEGATE<T> >
{
public:
    typedef T DataType;

public:
    /**
     * Create a stream sample with invalid data.
     */
    StreamSample();

    /**
     * Creates a StreamSample instance.
     *
     * @param data the data
     */
    StreamSample(const T& data);

    /**
     * Copies a stream sample instance.
     *
     * @param other the stream sample instance to copy
     */
    StreamSample(const StreamSample& other);

    /**
     * Gets the data.
     *
     * @return the data
     */
    const DataType& data() const;

    /**
     * Sets the data.
     *
     * @param data the data
     */
    void data(const DataType& data);
};

#endif /* SPEC_DDS_STREAMS_SUB_TSTREAMSAMPLE_HPP_ */
