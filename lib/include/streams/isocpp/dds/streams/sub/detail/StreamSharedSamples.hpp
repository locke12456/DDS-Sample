#ifndef DDS_STREAMS_SUB_DETAIL_STREAMSHAREDSAMPLES_HPP_
#define DDS_STREAMS_SUB_DETAIL_STREAMSHAREDSAMPLES_HPP_
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

#include <dds/streams/sub/StreamLoanedSamples.hpp>

// Implementation

namespace dds
{
namespace streams
{
namespace sub
{
namespace detail
{

template <typename T>
class StreamSharedSamples
{
public:
    typedef typename std::vector< dds::streams::sub::StreamSample<T> >::iterator iterator;
    typedef typename std::vector< dds::streams::sub::StreamSample<T> >::const_iterator const_iterator;

public:
    StreamSharedSamples() { }

    StreamSharedSamples(dds::streams::sub::StreamLoanedSamples<T> ls) : samples_(ls) { }

    ~StreamSharedSamples()
    {

    }

public:

    iterator mbegin()
    {
        return samples_->mbegin();
    }

    const_iterator begin() const
    {
        return samples_.begin();
    }

    const_iterator end() const
    {
        return samples_.end();
    }

    uint32_t length() const
    {
        /** @internal @todo Possible RTF size issue ? */
        return static_cast<uint32_t>(samples_.length());
    }

    void resize(uint32_t s)
    {
        samples_.resize(s);
    }

private:
    dds::streams::sub::StreamLoanedSamples<T> samples_;
};

}
}
}
}

#endif /* DDS_STREAMS_SUB_DETAIL_STREAMSHAREDSAMPLES_HPP_ */
