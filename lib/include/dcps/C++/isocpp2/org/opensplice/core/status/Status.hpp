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

#ifndef ORG_OPENSPLICE_CORE_STATUS_STATUS_HPP_
#define ORG_OPENSPLICE_CORE_STATUS_STATUS_HPP_

#include <org/opensplice/core/status/TStatus.hpp>
#include <org/opensplice/core/status/StatusDelegate.hpp>


namespace org
{
namespace opensplice
{
namespace core
{
namespace status
{

typedef org::opensplice::core::status::TAllDataDisposedTopicStatus<org::opensplice::core::AllDataDisposedTopicStatusDelegate>
AllDataDisposedTopicStatus;

}
}
}
}

#endif /* ORG_OPENSPLICE_CORE_STATUS_STATUS_HPP_ */
