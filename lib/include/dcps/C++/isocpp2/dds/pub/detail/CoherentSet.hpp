#ifndef OMG_DDS_PUB_DETAIL_COHERENT_SET_HPP_
#define OMG_DDS_PUB_DETAIL_COHERENT_SET_HPP_

#include <dds/pub/detail/TCoherentSetImpl.hpp>
#include <org/opensplice/pub/CoherentSetDelegate.hpp>

/**
 * @cond
 * Ignore this file in the API
 */

namespace dds {
	namespace pub {
		namespace detail {
			typedef dds::pub::TCoherentSet<org::opensplice::pub::CoherentSetDelegate> CoherentSet;
		}
	}
}

/** @endcond */

#endif /*  OMG_DDS_PUB_DETAIL_COHERENT_SET_HPP_ */
