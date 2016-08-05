#ifndef SPEC_DDS_STREAMS_SUB_STREAMSAMPLE_HPP_
#define SPEC_DDS_STREAMS_SUB_STREAMSAMPLE_HPP_
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

#include <dds/streams/sub/detail/StreamSample.hpp>

namespace dds
{
namespace streams
{
namespace sub
{
    template <typename T, template <typename Q> class DELEGATE = dds::streams::sub::detail::StreamSample >
class StreamSample;
}
}
}

#include <dds/streams/sub/TStreamSample.hpp>

#endif /* SPEC_DDS_STREAMS_SUB_STREAMSAMPLE_HPP_ */
