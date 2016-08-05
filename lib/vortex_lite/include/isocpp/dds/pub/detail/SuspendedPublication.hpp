#ifndef OMG_DDS_PUB_DETAIL_SUSPENDED_PUBLICATION_HPP_
#define OMG_DDS_PUB_DETAIL_SUSPENDED_PUBLICATION_HPP_

#include <dds/pub/detail/TSuspendedPublicationImpl.hpp>
#include <org/opensplice/pub/SuspendedPublicationDelegate.hpp>

namespace dds { namespace pub { namespace detail {
    typedef dds::pub::TSuspendedPublication<org::opensplice::pub::SuspendedPublicationDelegate> SuspendedPublication;
} } }

#endif /*  OMG_DDS_PUB_DETAIL_SUSPENDED_PUBLICATION_HPP_ */
