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

#ifndef LITE_TOPIC_TBUILTIN_TOPIC_HPP_
#define LITE_TOPIC_TBUILTIN_TOPIC_HPP_


#include <dds/core/detail/conformance.hpp>
#include <dds/core/Value.hpp>
#include <dds/core/policy/CorePolicy.hpp>
#include <dds/topic/BuiltinTopicKey.hpp>

namespace org
{
namespace opensplice
{
namespace topic
{
template <typename D>
class TCMParticipantBuiltinTopicData;

template <typename D>
class TCMPublisherBuiltinTopicData;

template <typename D>
class TCMSubscriberBuiltinTopicData;

template <typename D>
class TCMDataWriterBuiltinTopicData;

template <typename D>
class TCMDataReaderBuiltinTopicData;
}
}
}


/**
 * The CMParticipant topic...
 */
template <typename D>
class org::opensplice::topic::TCMParticipantBuiltinTopicData  : public ::dds::core::Value<D>
{
public:
    const dds::topic::BuiltinTopicKey&        key() const
    {
        return this->delegate().key();
    }
};

/**
 * The CMPublisher topic...
 */
template <typename D>
class org::opensplice::topic::TCMPublisherBuiltinTopicData  : public ::dds::core::Value<D>
{
public:
    const dds::topic::BuiltinTopicKey&        key() const
    {
        return this->delegate().key();
    }
    const dds::topic::BuiltinTopicKey&        participant_key() const
    {
        return this->delegate().participant_key();
    }
    const std::string&                        name() const
    {
        return this->delegate().name();
    }
    const ::dds::core::policy::EntityFactory& entity_factory() const
    {
        return this->delegate().entity_factory();
    }
    const ::dds::core::policy::Partition&     partition() const
    {
        return this->delegate().partition();
    }
};

/**
 * The CMSubscriber topic...
 */
template <typename D>
class org::opensplice::topic::TCMSubscriberBuiltinTopicData  : public ::dds::core::Value<D>
{
public:
    const dds::topic::BuiltinTopicKey&        key() const
    {
        return this->delegate().key();
    }
    const dds::topic::BuiltinTopicKey&        participant_key() const
    {
        return this->delegate().participant_key();
    }
    const std::string&                        name() const
    {
        return this->delegate().name();
    }
    const ::dds::core::policy::EntityFactory& entity_factory() const
    {
        return this->delegate().entity_factory();
    }
    const ::dds::core::policy::Partition&     partition() const
    {
        return this->delegate().partition();
    }
};

/**
 * The CMDataWriter topic...
 */
template <typename D>
class org::opensplice::topic::TCMDataWriterBuiltinTopicData  : public ::dds::core::Value<D>
{
public:
    const dds::topic::BuiltinTopicKey&              key() const
    {
        return this->delegate().key();
    }
    const dds::topic::BuiltinTopicKey&              publisher_key() const
    {
        return this->delegate().publisher_key();
    }
    const std::string&                              name() const
    {
        return this->delegate().name();
    }
    const ::dds::core::policy::History&             history() const
    {
        return this->delegate().history();
    }
    const ::dds::core::policy::ResourceLimits&      resource_limits() const
    {
        return this->delegate().resource_limits();
    }
    const ::dds::core::policy::WriterDataLifecycle& writer_data_lifecycle() const
    {
        return this->delegate().writer_data_lifecycle();
    }
};

/**
 * The CMDataReader topic...
 */
template <typename D>
class org::opensplice::topic::TCMDataReaderBuiltinTopicData  : public ::dds::core::Value<D>
{
public:
    const dds::topic::BuiltinTopicKey&              key() const
    {
        return this->delegate().key();
    }
    const dds::topic::BuiltinTopicKey&              subscriber_key() const
    {
        return this->delegate().subscriber_key();
    }
    const std::string&                              name() const
    {
        return this->delegate().name();
    }
    const ::dds::core::policy::History&             history() const
    {
        return this->delegate().history();
    }
    const ::dds::core::policy::ResourceLimits&      resource_limits() const
    {
        return this->delegate().resource_limits();
    }
    const ::dds::core::policy::ReaderDataLifecycle& reader_data_lifecycle() const
    {
        return this->delegate().reader_data_lifecycle();
    }
};

#endif /* LITE_TOPIC_TBUILTIN_TOPIC_HPP_ */
