#ifndef ORG_OPENSPLICE_STREAMS_SUB_QOS_STREAM_DATA_READER_QOS_HPP_
#define ORG_OPENSPLICE_STREAMS_SUB_QOS_STREAM_DATA_READER_QOS_HPP_
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
namespace sub
{
namespace qos
{

class OSPL_ISOCPP_IMPL_API StreamDataReaderQosImpl;

}
}
}
}
}

class org::opensplice::streams::sub::qos::StreamDataReaderQosImpl
{
public:
    StreamDataReaderQosImpl();

    StreamDataReaderQosImpl(const StreamDataReaderQosImpl& qos);

    ~StreamDataReaderQosImpl();

    template <typename POLICY> const POLICY& policy() const;

    template <typename POLICY> POLICY& policy();

    bool operator ==(const StreamDataReaderQosImpl& other) const
    {
        return true;
    }

private:
};

#endif /* ORG_OPENSPLICE_STREAMS_SUB_QOS_STREAM_DATA_READER_QOS_HPP_ */
