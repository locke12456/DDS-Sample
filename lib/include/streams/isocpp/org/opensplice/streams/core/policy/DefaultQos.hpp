#ifndef ORG_OPENSPLICE_STREAMS_CORE_POLICY_DEFAULTQOS_HPP_
#define ORG_OPENSPLICE_STREAMS_CORE_POLICY_DEFAULTQOS_HPP_
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

#include <dds/topic/qos/TopicQos.hpp>
#include <dds/sub/qos/DataReaderQos.hpp>
#include <dds/pub/qos/DataWriterQos.hpp>
#include <dds/core/policy/CorePolicy.hpp>

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

OSPL_ISOCPP_IMPL_API dds::topic::qos::TopicQos default_topic_qos();

OSPL_ISOCPP_IMPL_API dds::sub::qos::DataReaderQos default_datareader_qos();

OSPL_ISOCPP_IMPL_API dds::pub::qos::DataWriterQos default_datawriter_qos();

}
}
}
}
}

#endif /* ORG_OPENSPLICE_STREAMS_CORE_POLICY_DEFAULTQOS_HPP_ */
