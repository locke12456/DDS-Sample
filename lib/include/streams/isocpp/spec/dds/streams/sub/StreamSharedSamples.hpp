#ifndef SPEC_DDS_STREAMS_SUB_STREAMS_SHARED_SAMPLES_HPP_
#define SPEC_DDS_STREAMS_SUB_STREAMS_SHARED_SAMPLES_HPP_
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

#include <dds/core/Reference.hpp>
#include <dds/streams/sub/StreamSample.hpp>
#include <dds/streams/sub/StreamLoanedSamples.hpp>
#include <dds/streams/sub/detail/StreamSharedSamples.hpp>

namespace dds
{
namespace streams
{
namespace sub
{
template <typename T,
template <typename Q> class DELEGATE = detail::StreamSharedSamples>
class StreamSharedSamples;
}
}
}

/**
 * The class StreamSharedSamples is used as a container safe
 * and sharable version of the StreamLoanedSamples class.
 *
 *
 */
template <typename T,
template <typename Q> class DELEGATE>
class dds::streams::sub::StreamSharedSamples
{
public:
    typedef T                     DataType;
    typedef typename DELEGATE<T>::const_iterator        const_iterator;

    typedef typename dds::core::smart_ptr_traits< DELEGATE<T> >::ref_type DELEGATE_REF_T;

public:
    /**
     * Constructs a StreamSharedSamples instance.
     */
    StreamSharedSamples();

    /**
     * Constructs an instance of StreamSharedSamples and
     * removes the ownership of the loan from the StreamLoanedSamples.
     * As a result the destruction of the StreamLoanedSamples object
     * will have no effect on loaned data. Loaned data will be returned
     * automatically once the delegate of this reference type will have a
     * zero reference count.
     *
     * @param ls the loaned samples
     *
     */
    StreamSharedSamples(dds::streams::sub::StreamLoanedSamples<T> ls);

    /**
     * Copies a StreamSharedSamples instance.
     */
    StreamSharedSamples(const StreamSharedSamples& other);

    ~StreamSharedSamples();

public:
    /**
     * Gets an iterator pointing to the beginning of the samples.
     *
     * @return an iterator pointing to the beginning of the samples
     */
    const_iterator begin() const;

    /**
     * Gets an iterator pointing to the beginning of the samples.
     *
     * @return an iterator pointing to the beginning of the samples
     */
    const_iterator  end() const;

    /**
     * Gets the delegate.
     *
     * @return the delegate
     */
    const DELEGATE_REF_T& delegate() const;

    /**
     * Gets the delegate.
     *
     * @return the delegate
     */
    DELEGATE_REF_T& delegate();

    /**
     * Returns the number of samples.
     *
     * @return the number of samples
     */
    uint32_t length() const;

private:
    DELEGATE_REF_T delegate_;
};

#endif /* SPEC_DDS_STREAMS_SUB_STREAMS_SHARED_SAMPLES_HPP_ */
