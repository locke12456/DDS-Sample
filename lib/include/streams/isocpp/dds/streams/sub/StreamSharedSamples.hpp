#ifndef DDS_STREAMS_SUB_STREAMSHAREDSAMPLES_HPP_
#define DDS_STREAMS_SUB_STREAMSHAREDSAMPLES_HPP_
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

#include <spec/dds/streams/sub/StreamSharedSamples.hpp>

namespace dds
{
namespace streams
{
namespace sub
{
template <typename T, template <typename Q> class DELEGATE>
StreamSharedSamples<T, DELEGATE>::StreamSharedSamples() : delegate_(new DELEGATE<T>()) { }

template <typename T, template <typename Q> class DELEGATE>
StreamSharedSamples<T, DELEGATE>::StreamSharedSamples(dds::streams::sub::StreamLoanedSamples<T> ls) : delegate_(new DELEGATE<T>(ls)) { }

template <typename T, template <typename Q> class DELEGATE>
StreamSharedSamples<T, DELEGATE>::~StreamSharedSamples() {  }

template <typename T, template <typename Q> class DELEGATE>
StreamSharedSamples<T, DELEGATE>::StreamSharedSamples(const StreamSharedSamples& other)
{
    delegate_ = other.delegate_;
}

template <typename T, template <typename Q> class DELEGATE>
typename StreamSharedSamples<T, DELEGATE>::const_iterator StreamSharedSamples<T, DELEGATE>::begin() const
{
    return delegate()->begin();
}

template <typename T, template <typename Q> class DELEGATE>
typename StreamSharedSamples<T, DELEGATE>::const_iterator StreamSharedSamples<T, DELEGATE>::end() const
{
    return delegate()->end();
}

template <typename T, template <typename Q> class DELEGATE>
const typename StreamSharedSamples<T, DELEGATE>::DELEGATE_REF_T& StreamSharedSamples<T, DELEGATE>::delegate() const
{
    return delegate_;
}

template <typename T, template <typename Q> class DELEGATE>
typename StreamSharedSamples<T, DELEGATE>::DELEGATE_REF_T& StreamSharedSamples<T, DELEGATE>::delegate()
{
    return delegate_;
}

template <typename T, template <typename Q> class DELEGATE>
uint32_t StreamSharedSamples<T, DELEGATE>::length() const
{
    return delegate_->length();
}
}
}
}

#endif /* DDS_STREAMS_SUB_STREAMSHAREDSAMPLES_HPP_ */
