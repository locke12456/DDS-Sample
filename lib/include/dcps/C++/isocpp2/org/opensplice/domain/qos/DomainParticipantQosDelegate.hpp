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

#ifndef ORG_OPENSPLICE_DOMAIN_QOS_DOMAIN_PARTICIPANT_QOS_DELEGATE_HPP_
#define ORG_OPENSPLICE_DOMAIN_QOS_DOMAIN_PARTICIPANT_QOS_DELEGATE_HPP_

#include <dds/core/policy/CorePolicy.hpp>

#include "u_types.h"

struct _DDS_NamedDomainParticipantQos;

namespace org
{
namespace opensplice
{
namespace domain
{
namespace qos
{

class OMG_DDS_API DomainParticipantQosDelegate
{
public:
    DomainParticipantQosDelegate();
    DomainParticipantQosDelegate(const DomainParticipantQosDelegate& other);

    ~DomainParticipantQosDelegate();

    void policy(const dds::core::policy::UserData& ud);
    void policy(const dds::core::policy::EntityFactory& efp);
    void policy(const org::opensplice::core::policy::ListenerScheduling& listener_scheduling);
    void policy(const org::opensplice::core::policy::WatchdogScheduling& watchdog_scheduling);

    template <typename POLICY> const POLICY& policy() const;
    template <typename POLICY> POLICY& policy();

    /* The returned userlayer QoS has to be freed. */
    u_participantQos u_qos() const;
    void u_qos(const u_participantQos qos);

    void named_qos(const struct _DDS_NamedDomainParticipantQos &qos);

    void check() const;

    bool operator ==(const DomainParticipantQosDelegate& other) const;
    DomainParticipantQosDelegate& operator =(const DomainParticipantQosDelegate& other);

private:
    void defaults();

    dds::core::policy::UserData user_data_;
    dds::core::policy::EntityFactory entity_factory_;
    org::opensplice::core::policy::ListenerScheduling listener_scheduling_;
    org::opensplice::core::policy::WatchdogScheduling watchdog_scheduling_;
};



//==============================================================================


template<>
inline const dds::core::policy::UserData&
DomainParticipantQosDelegate::policy<dds::core::policy::UserData> () const
{
    return user_data_;
}
template<>
inline dds::core::policy::UserData&
DomainParticipantQosDelegate::policy<dds::core::policy::UserData> ()
{
    return user_data_;
}


template<>
inline const dds::core::policy::EntityFactory&
DomainParticipantQosDelegate::policy<dds::core::policy::EntityFactory> () const
{
    return entity_factory_;
}
template<>
inline dds::core::policy::EntityFactory&
DomainParticipantQosDelegate::policy<dds::core::policy::EntityFactory> ()
{
    return entity_factory_;
}


template<>
inline const org::opensplice::core::policy::ListenerScheduling&
DomainParticipantQosDelegate::policy<org::opensplice::core::policy::ListenerScheduling> () const
{
    return listener_scheduling_;
}
template<>
inline org::opensplice::core::policy::ListenerScheduling&
DomainParticipantQosDelegate::policy<org::opensplice::core::policy::ListenerScheduling> ()
{
    return listener_scheduling_;
}


template<>
inline const org::opensplice::core::policy::WatchdogScheduling&
DomainParticipantQosDelegate::policy<org::opensplice::core::policy::WatchdogScheduling> () const
{
    return watchdog_scheduling_;
}
template<>
inline org::opensplice::core::policy::WatchdogScheduling&
DomainParticipantQosDelegate::policy<org::opensplice::core::policy::WatchdogScheduling> ()
{
    return watchdog_scheduling_;
}

}
}
}
}

#endif /* ORG_OPENSPLICE_DOMAIN_QOS_DOMAIN_PARTICIPANT_QOS_DELEGATE_HPP_ */
