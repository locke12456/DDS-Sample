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


/**
 * @file
 */

#ifndef LITE_CORE_STATUS_UTILS_HPP_
#define LITE_CORE_STATUS_UTILS_HPP_

#include <dds/core/status/State.hpp>
#include <dds/core/status/Status.hpp>
#include <org/opensplice/core/config.hpp>

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
    const uint32_t vMask);

uint32_t
vEventMaskFromStatusMask (
    const dds::core::status::StatusMask& mask);
}
}
}
}

#endif /* LITE_CORE_STATUS_UTILS_HPP_ */
