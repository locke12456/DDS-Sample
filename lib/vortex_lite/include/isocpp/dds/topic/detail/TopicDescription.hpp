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
#ifndef LITE_DDS_TOPIC_DETAIL_TOPICDESCRIPTION_HPP_
#define LITE_DDS_TOPIC_DETAIL_TOPICDESCRIPTION_HPP_

/**
 * @file
 */

// Implementation

#include <dds/topic/detail/TTopicDescriptionImpl.hpp>
#include <org/opensplice/topic/TopicDescriptionDelegate.hpp>

namespace dds { namespace topic { namespace detail {
  typedef dds::topic::TTopicDescription<org::opensplice::topic::TopicDescriptionDelegate> TopicDescription;
} } }

// End of implementation

#endif /* LITE_DDS_TOPIC_DETAIL_TOPICDESCRIPTION_HPP_ */
