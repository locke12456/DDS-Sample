#ifndef ORG_OPENSPLICE_STREAMS_TOPIC_TOPICTRAITS_HPP_
#define ORG_OPENSPLICE_STREAMS_TOPIC_TOPICTRAITS_HPP_
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

namespace org
{
namespace opensplice
{
namespace streams
{
namespace topic
{

template <typename Topic>
struct stream_topic { };

}
}
}
}

/**
 * @internal Maps Topic type struct specializations through to
 * their corresponding stream topics
 * @param TOPIC The CCPP topic type.
 */
#define REGISTER_STREAM_TOPIC_TRAITS(TOPIC)                    \
    namespace org { namespace opensplice { namespace streams { namespace topic {        \
    template<> struct stream_topic<TOPIC> {                \
        typedef TOPIC##StreamSample type; \
    };                                    \
    } } } }

#endif /* ORG_OPENSPLICE_STREAMS_TOPIC_TOPICTRAITS_HPP_ */
