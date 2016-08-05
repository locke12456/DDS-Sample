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
#ifndef OSPL_DDS_TOPIC_TTOPICDESCRIPTION_HPP_
#define OSPL_DDS_TOPIC_TTOPICDESCRIPTION_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/topic/TTopicDescription.hpp>

// Implementation

namespace dds
{
namespace topic
{

template <typename DELEGATE>
TTopicDescription<DELEGATE>::~TTopicDescription()
{
}

template <typename DELEGATE>
const std::string& TTopicDescription<DELEGATE>::name() const
{
    ISOCPP_REPORT_STACK_BEGIN();

    return this->delegate()->name();
}

template <typename DELEGATE>
const std::string& TTopicDescription<DELEGATE>::type_name() const
{
    ISOCPP_REPORT_STACK_BEGIN();

    return this->delegate()->type_name();
}

template <typename DELEGATE>
const dds::domain::DomainParticipant& TTopicDescription<DELEGATE>::domain_participant() const
{
    ISOCPP_REPORT_STACK_BEGIN();

    return this->delegate()->domain_participant();
}

}
}

// End of implementation

#endif /* OSPL_DDS_TOPIC_TTOPICDESCRIPTION_HPP_ */
