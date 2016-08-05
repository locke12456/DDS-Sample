#ifndef ORG_OPENSPLICE_STREAMS_PUB_QOS_STREAM_DATA_WRITER_QOS_HPP_
#define ORG_OPENSPLICE_STREAMS_PUB_QOS_STREAM_DATA_WRITER_QOS_HPP_
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

#include <dds/streams/core/policy/CorePolicy.hpp>

namespace org
{
namespace opensplice
{
namespace streams
{
namespace pub
{
namespace qos
{

class OSPL_ISOCPP_IMPL_API StreamDataWriterQosImpl;

}
}
}
}
}

class org::opensplice::streams::pub::qos::StreamDataWriterQosImpl
{
public:
    StreamDataWriterQosImpl();

    StreamDataWriterQosImpl(const StreamDataWriterQosImpl& qos);

    StreamDataWriterQosImpl(dds::streams::core::policy::StreamFlush stream_flush);

    ~StreamDataWriterQosImpl();

    void policy(const dds::streams::core::policy::StreamFlush& stream_flush);

    template <typename POLICY> const POLICY& policy() const;

    template <typename POLICY> POLICY& policy();

    bool operator ==(const StreamDataWriterQosImpl& other) const
    {
        return other.stream_flush_ == stream_flush_;
    }

private:
    dds::streams::core::policy::StreamFlush stream_flush_;
};

namespace org
{
namespace opensplice
{
namespace streams
{
namespace pub
{
namespace qos
{

template<> inline const dds::streams::core::policy::StreamFlush&
StreamDataWriterQosImpl::policy<dds::streams::core::policy::StreamFlush>() const
{
    return stream_flush_;
}

template<> inline dds::streams::core::policy::StreamFlush&
StreamDataWriterQosImpl::policy<dds::streams::core::policy::StreamFlush>()
{
    return stream_flush_;
}

}
}
}
}
}

#endif /* ORG_OPENSPLICE_STREAMS_PUB_QOS_STREAM_DATA_WRITER_QOS_HPP_ */
