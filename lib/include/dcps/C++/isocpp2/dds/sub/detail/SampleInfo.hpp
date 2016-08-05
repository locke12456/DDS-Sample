#ifndef OMG_DDS_SUB_DETAIL_SAMPLE_INFO_HPP_
#define OMG_DDS_SUB_DETAIL_SAMPLE_INFO_HPP_

#include <dds/sub/detail/TSampleInfoImpl.hpp>
#include <org/opensplice/sub/SampleInfoImpl.hpp>

/**
 * @cond
 * Ignore this file in the API
 */

namespace dds { namespace sub { namespace detail {
  typedef dds::sub::TSampleInfo<org::opensplice::sub::SampleInfoImpl> SampleInfo;
} } }

/** @endcond */

#endif /* OMG_DDS_SUB_DETAIL_SAMPLE_INFO_HPP_ */

