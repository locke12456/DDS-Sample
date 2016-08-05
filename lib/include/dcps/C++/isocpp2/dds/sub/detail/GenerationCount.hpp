#ifndef OMG_DDS_SUB_DETAIL_GENERATION_COUNT_HPP_
#define OMG_DDS_SUB_DETAIL_GENERATION_COUNT_HPP_

#include <dds/sub/detail/TGenerationCountImpl.hpp>
#include <org/opensplice/sub/GenerationCountImpl.hpp>

/**
 * @cond
 * Ignore this file in the API
 */

namespace dds {
  namespace sub {
    namespace detail {
      typedef dds::sub::TGenerationCount< org::opensplice::sub::GenerationCountImpl > GenerationCount;
    }
  }
}

/** @endcond */

#endif /* OMG_DDS_SUB_DETAIL_GENERATION_COUNT_HPP_ */
