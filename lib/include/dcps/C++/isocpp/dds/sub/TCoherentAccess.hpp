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
#ifndef OSPL_DDS_SUB_TCOHERENTACCESS_HPP_
#define OSPL_DDS_SUB_TCOHERENTACCESS_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <spec/dds/sub/TCoherentAccess.hpp>

// Implementation
namespace dds
{
namespace sub
{

template <typename D>
TCoherentAccess<D>::~TCoherentAccess(void)
{
    this->delegate().end();
}

template <typename D>
TCoherentAccess<D>::TCoherentAccess(const dds::sub::Subscriber& sub) : dds::core::Value<D>(sub) { }

template <typename D>
void TCoherentAccess<D>::end()
{
    this->delegate().end();
}
}
}
// End of implementation

#endif /* OSPL_DDS_SUB_TCOHERENTACCESS_HPP_ */
