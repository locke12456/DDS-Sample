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

#ifndef LITE_TOPIC_TOPIC_LISTENER_HPP_
#define LITE_TOPIC_TOPIC_LISTENER_HPP_


#include "dds/topic/TopicListener.hpp"

namespace org
{
namespace opensplice
{
namespace topic
{

template <typename T>
class TopicListener : public dds::topic::TopicListener<T>
{
public:
    virtual ~TopicListener() { }

public:
#if 0
    virtual void on_all_data_disposed(
        dds::topic::Topic<T>& topic,
        const org::opensplice::core::status::AllDataDisposedTopicStatus& status) = 0;
#endif
};

template <typename T>
class NoOpTopicListener : public virtual TopicListener<T>
{
public:
    virtual ~NoOpTopicListener() { }

public:
    virtual void on_inconsistent_topic(
        dds::topic::Topic<T>&,
        const dds::core::status::InconsistentTopicStatus&) { }

#if 0
    virtual void on_all_data_disposed(
        dds::topic::Topic<T>&,
        const org::opensplice::core::status::AllDataDisposedTopicStatus&) { }
#endif
};

}
}
}

#endif /* LITE_TOPIC_TOPIC_LISTENER_HPP_ */
