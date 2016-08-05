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

#ifndef ORG_OPENSPLICE_DOMAIN_PARTICIPANT_REGISTRY_HPP_
#define ORG_OPENSPLICE_DOMAIN_PARTICIPANT_REGISTRY_HPP_

#include <org/opensplice/core/EntityRegistry.hpp>
#include <org/opensplice/domain/DomainParticipantDelegate.hpp>
#include <dds/domain/TDomainParticipant.hpp>

namespace org
{
namespace opensplice
{
namespace domain
{

class OMG_DDS_API DomainParticipantRegistry {
public:

    static void insert(dds::domain::TDomainParticipant<org::opensplice::domain::DomainParticipantDelegate>& participant);

    static void remove(org::opensplice::domain::DomainParticipantDelegate *delegate);

private:
    static org::opensplice::core::EntityRegistry
               <org::opensplice::domain::DomainParticipantDelegate *,
                dds::domain::TDomainParticipant<org::opensplice::domain::DomainParticipantDelegate> > registry;
};

}
}
}

#endif /* ORG_OPENSPLICE_DOMAIN_PARTICIPANT_REGISTRY_HPP_ */
