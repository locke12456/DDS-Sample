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
#ifndef OSPL_DDS_CORE_TENTITY_IMPL_HPP_
#define OSPL_DDS_CORE_TENTITY_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/core/detail/ReferenceImpl.hpp>
#include <dds/core/TEntity.hpp>
#include <org/opensplice/core/ReportUtils.hpp>

// Implementation

template <typename DELEGATE>
dds::core::TEntity<DELEGATE>::~TEntity()
{
}

template <typename DELEGATE>
void
dds::core::TEntity<DELEGATE>::enable()
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->enable();
}

template <typename DELEGATE>
const dds::core::status::StatusMask
dds::core::TEntity<DELEGATE>::status_changes()
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->status_changes();
}

template <typename DELEGATE>
const dds::core::InstanceHandle
dds::core::TEntity<DELEGATE>::instance_handle() const
{
    ISOCPP_REPORT_STACK_BEGIN();
    return this->delegate()->instance_handle();
}

template <typename DELEGATE>
void
dds::core::TEntity<DELEGATE>::close()
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->close();
}

template <typename DELEGATE>
void
dds::core::TEntity<DELEGATE>::retain()
{
    ISOCPP_REPORT_STACK_BEGIN();
    this->delegate()->retain();
}

// End of implementation

#endif /* OSPL_DDS_CORE_TENTITY_IMPL_HPP_ */
