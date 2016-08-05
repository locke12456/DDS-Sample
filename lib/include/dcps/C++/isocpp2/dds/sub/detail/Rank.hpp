#ifndef OMG_DDS_SUB_DETAIL_RANK_HPP
#define OMG_DDS_SUB_DETAIL_RANK_HPP

#include <dds/sub/detail/TRankImpl.hpp>
#include <org/opensplice/sub/RankImpl.hpp>

/**
 * @cond
 * Ignore this file in the API
 */

namespace dds { namespace sub { namespace detail {
  typedef dds::sub::TRank< org::opensplice::sub::RankImpl > Rank;
} } }

/** @endcond */

#endif /* OMG_DDS_SUB_DETAIL_RANK_HPP */
