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
#ifndef OSPL_DDS_SUB_DETAIL_SHARED_SAMPLES_HPP_
#define OSPL_DDS_SUB_DETAIL_SHARED_SAMPLES_HPP_

/**
 * @cond
 * Ignore this file in the API
 */

#include <dds/sub/LoanedSamples.hpp>

// Implementation

namespace dds
{
namespace sub
{
namespace detail
{

template <typename T>
class SharedSamples
{
public:
    typedef typename std::vector< dds::sub::Sample<T, Sample> >::iterator iterator;
    typedef typename std::vector< dds::sub::Sample<T, Sample> >::const_iterator const_iterator;

public:
    SharedSamples() { }

    SharedSamples(dds::sub::LoanedSamples<T> ls) : samples_(ls) { }

    ~SharedSamples()
    {

    }

public:

    iterator mbegin()
    {
        return samples_->begin();
    }

    const_iterator begin() const
    {
        return samples_.begin();
    }

    const_iterator end() const
    {
        return samples_.end();
    }

    uint32_t length() const
    {
        /** @internal @todo Possible RTF size issue ? */
        return static_cast<uint32_t>(samples_.length());
    }

    void resize(uint32_t s)
    {
        samples_.resize(s);
    }

private:
    dds::sub::LoanedSamples<T> samples_;
};

}
}
}

/** @endcond */

// End of implementation

#endif /* OSPL_DDS_SUB_DETAIL_SHARED_SAMPLES_HPP_ */
