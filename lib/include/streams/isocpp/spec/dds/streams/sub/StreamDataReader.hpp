#ifndef SPEC_DDS_STREAMS_SUB_STREAMDATAREADER_HPP_
#define SPEC_DDS_STREAMS_SUB_STREAMDATAREADER_HPP_
/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2014 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */

/**
 * @file
 */

#include <dds/streams/sub/detail/StreamDataReader.hpp>

namespace dds
{
namespace streams
{
namespace sub
{
template < typename T, template <typename Q> class DELEGATE = dds::streams::sub::detail::StreamDataReader >
class StreamDataReader;
}
}
}

#include <dds/streams/sub/TStreamDataReader.hpp>

// = Manipulators
namespace dds
{
namespace streams
{
namespace sub
{
namespace functors
{
typedef dds::streams::sub::functors::detail::MaxSamplesManipulatorFunctor MaxSamplesManipulatorFunctor;
typedef dds::streams::sub::functors::detail::TimeoutManipulatorFunctor TimeoutManipulatorFunctor;
template <typename T>
class FilterManipulatorFunctor : dds::streams::sub::functors::detail::FilterManipulatorFunctor<T> {};
}
}
}
}

namespace dds
{
namespace streams
{
namespace sub
{

template <typename SELECTOR>
SELECTOR& get(SELECTOR& selector);

inline dds::streams::sub::functors::MaxSamplesManipulatorFunctor
max_samples(uint32_t max_samples);

inline dds::streams::sub::functors::TimeoutManipulatorFunctor
timeout(const dds::core::Duration& timeout);

template <typename T>
inline dds::streams::sub::functors::FilterManipulatorFunctor<T>
filter(bool (*filter_func)(T));

}
}
}

#endif /* SPEC_DDS_STREAMS_SUB_STREAMDATAREADER_HPP_ */
