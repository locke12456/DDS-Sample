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
#ifndef OSPL_DDS_SUB_TCOHERENTACCESS_IMPL_HPP_
#define OSPL_DDS_SUB_TCOHERENTACCESS_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/sub/TCoherentAccess.hpp>

// Implementation

namespace dds
{
namespace sub
{

template <typename DELEGATE>
TCoherentAccess<DELEGATE>::TCoherentAccess(const dds::sub::Subscriber& sub) : dds::core::Value<DELEGATE>(sub)  {  }

template <typename DELEGATE>
void TCoherentAccess<DELEGATE>::end()
{
    ISOCPP_REPORT_STACK_BEGIN();

    this->delegate().end();
}

template <typename DELEGATE>
TCoherentAccess<DELEGATE>::~TCoherentAccess()
{
    ISOCPP_REPORT_STACK_BEGIN();

    this->delegate().end();
}

}
}

// End of implementation

#endif /* OSPL_DDS_SUB_TCOHERENTACCESS_IMPL_HPP_ */
