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

#ifndef ORG_OPENSPLICE_CORE_STATUS_UTILS_HPP_
#define ORG_OPENSPLICE_CORE_STATUS_UTILS_HPP_

#include <dds/core/status/State.hpp>
#include <org/opensplice/core/config.hpp>

#include "u_user.h"

namespace org
{
namespace opensplice
{
namespace core
{
namespace utils
{

/*
 * Status conversions
 */
dds::core::status::StatusMask
vEventMaskToStatusMask (
    const v_eventMask vMask,
    const v_kind      vKind);

v_eventMask
vEventMaskFromStatusMask (
    const dds::core::status::StatusMask& mask);

}
}
}
}

#endif /* ORG_OPENSPLICE_CORE_STATUS_UTILS_HPP_ */
