/*
 * Query.hpp
 *
 *  Created on: Oct 10, 2012
 *      Author: angelo
 */

#ifndef DDS_SUB_DETAIL_QUERY_HPP_
#define DDS_SUB_DETAIL_QUERY_HPP_

#include <dds/sub/TQuery.hpp>
#include <org/opensplice/sub/QueryDelegate.hpp>

/**
 * @cond
 * Ignore this file in the API
 */

namespace dds
{
namespace sub
{
namespace detail
{
typedef dds::sub::TQuery<org::opensplice::sub::QueryDelegate> Query;
}
}
}

/** @endcond */

#endif /* DDS_SUB_DETAIL_QUERY_HPP_ */
