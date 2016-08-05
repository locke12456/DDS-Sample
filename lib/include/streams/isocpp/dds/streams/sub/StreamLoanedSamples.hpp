#ifndef DDS_STREAM_SUB_STREAMLOANEDSAMPLES_HPP_
#define DDS_STREAM_SUB_STREAMLOANEDSAMPLES_HPP_
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

#include <spec/dds/streams/sub/StreamLoanedSamples.hpp>

namespace dds
{
namespace streams
{
namespace sub
{

template <typename T, template <typename Q> class DELEGATE>
StreamLoanedSamples<T, DELEGATE>::StreamLoanedSamples() : delegate_(new DELEGATE<T>()) { }

template <typename T, template <typename Q> class DELEGATE>
StreamLoanedSamples<T, DELEGATE>::~StreamLoanedSamples() {  }

template <typename T, template <typename Q> class DELEGATE>
StreamLoanedSamples<T, DELEGATE>::StreamLoanedSamples(const StreamLoanedSamples& other)
{
    delegate_ = other.delegate_;
}

template <typename T, template <typename Q> class DELEGATE>
typename StreamLoanedSamples<T, DELEGATE>::const_iterator StreamLoanedSamples<T, DELEGATE>::begin() const
{
    return delegate()->begin();
}

template <typename T, template <typename Q> class DELEGATE>
typename StreamLoanedSamples<T, DELEGATE>::const_iterator StreamLoanedSamples<T, DELEGATE>::end() const
{
    return delegate()->end();
}

template <typename T, template <typename Q> class DELEGATE>
const typename StreamLoanedSamples<T, DELEGATE>::DELEGATE_REF_T& StreamLoanedSamples<T, DELEGATE>::delegate() const
{
    return delegate_;
}

template <typename T, template <typename Q> class DELEGATE>
typename StreamLoanedSamples<T, DELEGATE>::DELEGATE_REF_T& StreamLoanedSamples<T, DELEGATE>::delegate()
{
    return delegate_;
}

template <typename T, template <typename Q> class DELEGATE>
uint32_t StreamLoanedSamples<T, DELEGATE>::length() const
{
    return delegate_->length();
}

template <typename T, template <typename Q> class DELEGATE>
uint32_t StreamLoanedSamples<T, DELEGATE>::stream() const
{
    return delegate_->stream();
}

}
}
}

#endif /* DDS_STREAM_SUB_STREAMLOANEDSAMPLES_HPP_ */
