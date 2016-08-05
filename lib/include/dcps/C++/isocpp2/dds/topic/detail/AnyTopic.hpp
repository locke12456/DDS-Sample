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
#ifndef OMG_DDS_TOPIC_DETAIL_ANY_TOPIC_HPP_
#define OMG_DDS_TOPIC_DETAIL_ANY_TOPIC_HPP_

/**
 * @cond
 * Ignore this file in the API
 */

// Implementation

#include <dds/topic/detail/TAnyTopicImpl.hpp>
#include <org/opensplice/topic/AnyTopicDelegate.hpp>

namespace dds { namespace topic { namespace detail {
  typedef dds::topic::TAnyTopic<org::opensplice::topic::AnyTopicDelegate> AnyTopic;
} } }

// End of implementation

/** @endcond */

#endif /* OMG_DDS_TOPIC_DETAIL_ANY_TOPIC_HPP_ */
