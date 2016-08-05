#ifndef DDS_TOPIC_DETAIL_QUERY_HPP_
#define DDS_TOPIC_DETAIL_QUERY_HPP_

#include <dds/topic/detail/TFilterImpl.hpp>
#include <org/opensplice/topic/FilterDelegate.hpp>

/**
 * @cond
 * Ignore this file in the API
 */

namespace dds {
namespace topic {
namespace detail {
typedef ::dds::topic::TFilter< ::org::opensplice::topic::FilterDelegate > Filter;
}
}
}

/** @endcond */

#endif /* DDS_TOPIC_DETAIL_QUERY_HPP_ */
