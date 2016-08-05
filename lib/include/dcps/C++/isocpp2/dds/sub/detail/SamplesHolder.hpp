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
#ifndef OSPL_DDS_SUB_DETAIL_SAMPLES_HOLDER_HPP_
#define OSPL_DDS_SUB_DETAIL_SAMPLES_HOLDER_HPP_

/**
 * @file
 */

#include <dds/sub/LoanedSamples.hpp>

/**
 * @cond
 * Ignore this file in the API
 */

namespace dds
{
namespace sub
{
namespace detail
{
template <typename T>
class LoanedSamplesHolder : public SamplesHolder
{
public:
    LoanedSamplesHolder(dds::sub::LoanedSamples<T>& samples) : samples_(samples), index(0)
    {
    }

    void set_length(uint32_t len) {
        this->samples_.delegate()->resize(len);
    }

    uint32_t get_length() const {
        return this->index;
    }

    SamplesHolder& operator++(int)
    {
        this->index++;
        return *this;
    }

    void *data()
    {
        return (*this->samples_.delegate())[this->index].delegate().data_ptr();
    }

    detail::SampleInfo* info()
    {
        return (*this->samples_.delegate())[this->index].delegate().info_ptr();
    }

private:
    dds::sub::LoanedSamples<T>& samples_;
    uint32_t index;
};



template <typename T, typename SamplesFWIterator>
class SamplesFWInteratorHolder : public SamplesHolder
{
public:
    SamplesFWInteratorHolder(SamplesFWIterator& it) : iterator(it), length(0)
    {
    }

    void set_length(uint32_t len) {
        this->length = len;

    }

    uint32_t get_length() const {
        return this->length;
    }

    SamplesHolder& operator++(int)
    {
        ++this->iterator;
        return *this;
    }

    void *data()
    {
        return (*iterator).delegate().data_ptr();
    }

    detail::SampleInfo* info()
    {
        return (*iterator).delegate().info_ptr();
    }

private:
    SamplesFWIterator& iterator;
    uint32_t length;

};

template <typename T, typename SamplesBIIterator>
class SamplesBIIteratorHolder : public SamplesHolder
{
public:
    SamplesBIIteratorHolder(SamplesBIIterator& it) : iterator(it), length(0)
    {
    }

    void set_length(uint32_t len) {
        this->length = len;
    }

    uint32_t get_length() const {
        return this->length;
    }

    SamplesHolder& operator++(int)
    {
        *this->iterator = this->sample;
        ++this->iterator;
        return *this;
    }

    void *data()
    {
        return this->sample.delegate().data_ptr();
    }

    detail::SampleInfo* info()
    {
        return this->sample.delegate().info_ptr();
    }

private:
    SamplesBIIterator& iterator;
    dds::sub::Sample<T, dds::sub::detail::Sample> sample;
    uint32_t length;

};

}
}
}


/** @endcond */

#endif /* OSPL_DDS_SUB_DETAIL_SAMPLES_HOLDER_HPP_ */
