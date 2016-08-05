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
#ifndef OSPL_DDS_TOPIC_DETAIL_TOPICDESCRIPTION_HPP_
#define OSPL_DDS_TOPIC_DETAIL_TOPICDESCRIPTION_HPP_

/**
 * @file
 */

// Implementation

#include <dds/topic/detail/TTopicDescriptionImpl.hpp>
#include <org/opensplice/topic/TopicDescriptionDelegate.hpp>

/**
 * @cond
 * Ignore this file in the API
 */

namespace dds { namespace topic { namespace detail {
  typedef dds::topic::TTopicDescription<org::opensplice::topic::TopicDescriptionDelegate> TopicDescription;
} } }

/** @endcond */

// End of implementation

#endif /* OSPL_DDS_TOPIC_DETAIL_TOPICDESCRIPTION_HPP_ */
