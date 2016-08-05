#ifndef DDS_STREAMS_SUB_TSTREAMSAMPLE_HPP_
#define DDS_STREAMS_SUB_TSTREAMSAMPLE_HPP_
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

#include <spec/dds/streams/sub/TStreamSample.hpp>

namespace dds
{
namespace streams
{
namespace sub
{

template <typename T, template <typename Q> class DELEGATE>
StreamSample<T, DELEGATE>::StreamSample() : dds::core::Value< DELEGATE<T> >() {}

template <typename T, template <typename Q> class DELEGATE>
StreamSample<T, DELEGATE>::StreamSample(const T& data) : dds::core::Value< DELEGATE<T> >(data) { }

template <typename T, template <typename Q> class DELEGATE>
StreamSample<T, DELEGATE>::StreamSample(const StreamSample& other) : dds::core::Value< DELEGATE<T> >(other.delegate()) { }

template <typename T, template <typename Q> class DELEGATE>
const typename StreamSample<T, DELEGATE>::DataType& StreamSample<T, DELEGATE>::data() const
{
    return this->delegate().data();
}

template <typename T, template <typename Q> class DELEGATE>
void StreamSample<T, DELEGATE>::data(const DataType& d)
{
    this->delegate().data(d);
}

}
}
}

#endif /* DDS_STREAMS_SUB_TSTREAMSAMPLE_HPP_ */
