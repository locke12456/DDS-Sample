#ifndef DDS_STREAMS_PUB_QOS_DETAIL_STREAM_DATA_WRITER_QOS_HPP_
#define DDS_STREAMS_PUB_QOS_DETAIL_STREAM_DATA_WRITER_QOS_HPP_
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

#include <dds/core/TEntityQos.hpp>
#include <org/opensplice/streams/pub/qos/StreamDataWriterQosImpl.hpp>

namespace dds
{
namespace streams
{
namespace pub
{
namespace qos
{
namespace detail
{

typedef dds::core::TEntityQos<org::opensplice::streams::pub::qos::StreamDataWriterQosImpl> StreamDataWriterQos;

}
}
}
}
}

#endif /* DDS_STREAMS_PUB_QOS_DETAIL_STREAM_DATA_WRITER_QOS_HPP_ */
