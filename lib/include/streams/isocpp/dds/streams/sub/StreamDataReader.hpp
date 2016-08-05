#ifndef DDS_STREAMS_SUB_DATAREADER_HPP_
#define DDS_STREAMS_SUB_DATAREADER_HPP_
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

#include <spec/dds/streams/sub/StreamDataReader.hpp>

namespace dds
{
namespace streams
{
namespace sub
{

template <typename SELECTOR>
SELECTOR& get(SELECTOR& selector)
{
    selector.get();
    return selector;
}

inline dds::streams::sub::functors::MaxSamplesManipulatorFunctor
max_samples(uint32_t max_samples)
{
    return dds::streams::sub::functors::MaxSamplesManipulatorFunctor(max_samples);
}

inline dds::streams::sub::functors::TimeoutManipulatorFunctor
timeout(const dds::core::Duration& timeout)
{
    return dds::streams::sub::functors::TimeoutManipulatorFunctor(timeout);
}

template <typename T>
inline dds::streams::sub::functors::FilterManipulatorFunctor<T>
filter(bool (*filter_func)(T))
{
    return dds::streams::sub::functors::FilterManipulatorFunctor<T>(filter_func);
}

}
}
}

#endif /* DDS_STREAMS_SUB_DATAREADER_HPP_ */
