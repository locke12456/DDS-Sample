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

#ifndef ORG_OPENSPLICE_DOMAIN_DOMAIN_HPP_
#define ORG_OPENSPLICE_DOMAIN_DOMAIN_HPP_

#include "dds/core/types.hpp"

namespace org
{
namespace opensplice
{
namespace domain
{
/*
 * This domain ID causes the creation of a DomainParticipant to
 * use the domain ID that is provided within the configuration
 * or 0 when no ID was provided (which is the default).
 */
OMG_DDS_API uint32_t default_id();
}
}
}

#endif /* ORG_OPENSPLICE_DOMAIN_DOMAIN_HPP_ */
