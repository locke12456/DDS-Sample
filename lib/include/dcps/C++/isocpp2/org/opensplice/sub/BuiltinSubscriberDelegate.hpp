/*
*                         OpenSplice DDS
*
*   This software and documentation are Copyright 2006 to 2015 PrismTech
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

#ifndef ORG_OPENSPLICE_SUB_BUILTIN_SUBSCRIBER_DELEGATE_HPP_
#define ORG_OPENSPLICE_SUB_BUILTIN_SUBSCRIBER_DELEGATE_HPP_

#include <dds/core/types.hpp>
#include <dds/domain/DomainParticipant.hpp>

#include <org/opensplice/ForwardDeclarations.hpp>
#include <org/opensplice/sub/SubscriberDelegate.hpp>
#include <org/opensplice/sub/AnyDataReaderDelegate.hpp>
#include <org/opensplice/core/Mutex.hpp>



namespace org
{
namespace opensplice
{
namespace sub
{

class OMG_DDS_API BuiltinSubscriberDelegate : public org::opensplice::sub::SubscriberDelegate
{
public:
    BuiltinSubscriberDelegate(
            const dds::domain::DomainParticipant& dp,
            const dds::sub::qos::SubscriberQos& qos);

    virtual ~BuiltinSubscriberDelegate() {};

    std::vector<AnyDataReaderDelegate::ref_type>
    find_datareaders(const std::string& topic_name);

public:
    static SubscriberDelegate::ref_type
    get_builtin_subscriber(const dds::domain::DomainParticipant& dp);

    static AnyDataReaderDelegate::ref_type
    get_builtin_reader(SubscriberDelegate& subscriber, const std::string& topic_name);

private:
    static org::opensplice::core::Mutex builtinLock;

};

}
}
}


#endif /* ORG_OPENSPLICE_SUB_BUILTIN_SUBSCRIBER_DELEGATE_HPP_ */
