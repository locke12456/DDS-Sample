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
#ifndef OMG_DDS_PUB_DETAIL_ANYDATAWRITER_HPP_
#define OMG_DDS_PUB_DETAIL_ANYDATAWRITER_HPP_

#include <dds/pub/detail/TAnyDataWriterImpl.hpp>
#include <org/opensplice/pub/AnyDataWriterDelegate.hpp>

/**
 * @cond
 * Ignore this file in the API
 */

namespace dds { namespace pub { namespace detail {
  typedef dds::pub::TAnyDataWriter<org::opensplice::pub::AnyDataWriterDelegate> AnyDataWriter;
} } }

/** @endcond */

#endif /* OMG_DDS_PUB_DETAIL_ANYDATAWRITER_HPP_ */
