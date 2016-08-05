#ifndef DDS_STREAMS_SUB_QOS_DETAIL_STREAM_DATA_READER_QOS_HPP_
#define DDS_STREAMS_SUB_QOS_DETAIL_STREAM_DATA_READER_QOS_HPP_
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
#include <org/opensplice/streams/sub/qos/StreamDataReaderQosImpl.hpp>

namespace dds
{
namespace streams
{
namespace sub
{
namespace qos
{
namespace detail
{

typedef dds::core::TEntityQos<org::opensplice::streams::sub::qos::StreamDataReaderQosImpl> StreamDataReaderQos;

}
}
}
}
}

#endif /* DDS_STREAMS_SUB_QOS_DETAIL_STREAM_DATA_READER_QOS_HPP_ */
