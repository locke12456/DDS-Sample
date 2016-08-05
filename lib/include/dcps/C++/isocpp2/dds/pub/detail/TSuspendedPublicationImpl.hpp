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
#ifndef OSPL_DDS_PUB_TSUSPENDEDPUBLICATION_IMPL_HPP_
#define OSPL_DDS_PUB_TSUSPENDEDPUBLICATION_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/pub/TSuspendedPublication.hpp>
#include <org/opensplice/core/ReportUtils.hpp>

// Implementation

namespace dds
{
namespace pub
{

template <typename DELEGATE>
TSuspendedPublication<DELEGATE>::TSuspendedPublication(const dds::pub::Publisher& pub) : dds::core::Value<DELEGATE>(pub) { }

template <typename DELEGATE>
void TSuspendedPublication<DELEGATE>::resume()
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate().resume();
}

template <typename DELEGATE>
TSuspendedPublication<DELEGATE>::~TSuspendedPublication()
{
    ISOCPP_REPORT_STACK_BEGIN();
    try {
        this->delegate().resume();
    } catch (...) {
        /* Empty: the exception throw should have already traced an error. */
    }
}

}
}

// End of implementation

#endif /* OSPL_DDS_PUB_TSUSPENDEDPUBLICATION_IMPL_HPP_ */
