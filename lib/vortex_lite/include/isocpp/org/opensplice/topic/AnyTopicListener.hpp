/*
*                         Vortex Lite
*
*   This software and documentation are Copyright 2006 to 2015 PrismTech
*   Limited and its licensees. All rights reserved. See file:
*
*                     $LITE_HOME/LICENSE
*
*   for full copyright notice and license terms.
*
*/


#ifndef LITE_TOPIC_ANY_TOPIC_LISTENER_HPP_
#define LITE_TOPIC_ANY_TOPIC_LISTENER_HPP_


#include <dds/topic/AnyTopicListener.hpp>

namespace org
{
namespace opensplice
{
namespace topic
{

class OMG_DDS_API AnyTopicListener
{
public:
    virtual ~AnyTopicListener() { }

public:
#if 0
    virtual void on_all_data_disposed(
        dds::topic::AnyTopic& topic,
        const org::opensplice::core::status::AllDataDisposedTopicStatus& status) = 0;
#endif
};


class OMG_DDS_API NoOpAnyTopicListener : public virtual AnyTopicListener
{
public:
    virtual ~NoOpAnyTopicListener() { }

public:
#if 0
    virtual void on_all_data_disposed(
        dds::topic::AnyTopic&,
        const org::opensplice::core::status::AllDataDisposedTopicStatus&) { }
#endif
};

}
}
}

#endif /* LITE_TOPIC_ANY_TOPIC_LISTENER_HPP_ */
