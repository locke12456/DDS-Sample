#ifndef OMG_DDS_SUB_DETAIL_COHERENT_ACCESS_HPP_
#define OMG_DDS_SUB_DETAIL_COHERENT_ACCESS_HPP_

#include <dds/sub/detail/TCoherentAccessImpl.hpp>
#include <org/opensplice/sub/CoherentAccessDelegate.hpp>

/**
 * @cond
 * Ignore this file in the API
 */

namespace dds { namespace sub { namespace detail {
  typedef ::dds::sub::TCoherentAccess<org::opensplice::sub::CoherentAccessDelegate> CoherentAccess;
} } }

/** @endcond */

#endif /* OMG_DDS_SUB_DETAIL_COHERENT_ACCESS_HPP_ */
