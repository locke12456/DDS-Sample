/*
*                         Vortex Lite
*
*   This software and documentation are Copyright 2006 to 2014 PrismTech
*   Limited and its licensees. All rights reserved. See file:
*
*                     $LITE_HOME/LICENSE
*
*   for full copyright notice and license terms.
*
*/


/**
 * @file
 */

#ifndef LITE_DOMAIN_DOMAINPARTICIPANT_LISTENER_HPP_
#define LITE_DOMAIN_DOMAINPARTICIPANT_LISTENER_HPP_

#include <dds/domain/DomainParticipantListener.hpp>
#include <org/opensplice/topic/AnyTopicListener.hpp>


namespace org
{
namespace opensplice
{
namespace domain
{

class OMG_DDS_API DomainParticipantListener :
    public virtual dds::domain::DomainParticipantListener,
    public virtual org::opensplice::topic::AnyTopicListener
{
public:
    virtual ~DomainParticipantListener() { }
};


class OMG_DDS_API NoOpDomainParticipantListener :
    public virtual dds::domain::NoOpDomainParticipantListener,
    public virtual org::opensplice::topic::NoOpAnyTopicListener
{
public:
    virtual ~NoOpDomainParticipantListener()  { }
};

}
}
}

#endif /* LITE_DOMAIN_DOMAINPARTICIPANT_LISTENER_HPP_ */
