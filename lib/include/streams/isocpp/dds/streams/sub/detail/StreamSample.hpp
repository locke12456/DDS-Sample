#ifndef DDS_STREAMS_SUB_DETAIL_STREAMSAMPLE_HPP_
#define DDS_STREAMS_SUB_DETAIL_STREAMSAMPLE_HPP_
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
 * @internal
 * @bug OSPL-2430 Operator equal of 'data' is not available/implemented
 */

namespace dds
{
namespace streams
{
namespace sub
{
namespace detail
{
template <typename T>
class StreamSample
{
public:
    StreamSample() : has_data_copy_(false) { }

    StreamSample(const T& d) :
    has_data_copy_(true), data_copy_(d)
    {
        data_ptr_ = &data_copy_;
    }

    StreamSample(const StreamSample& other) : has_data_copy_(false)
    {
        copy(other);
    }

    StreamSample& operator=(const StreamSample& other)
    {
        return copy(other);
    }

    StreamSample& copy(const StreamSample& other)
    {
        if(other.has_data_copy_)
        {
            data_copy_ = other.data_copy_;
            data_ptr_ = &data_copy_;
            has_data_copy_ = true;
        }
        else
        {
            data_ptr_ = other.data_ptr_;
        }

        return *this;
    }

public:
    const T& data() const
    {
        return *data_ptr_;
    }

    void data(const T& d)
    {
        data_copy_ = d;
        data_ptr_ = &data_copy_;
        has_data_copy_ = true;
    }

    void data(T* d)
    {
        data_ptr_ = d;
    }

    /** @internal @bug OSPL-2430 No implementation
        * @todo Implementation required - see OSPL-2430
        * @see http://jira.prismtech.com:8080/browse/OSPL-2430 */
    bool operator ==(const StreamSample& other) const
    {
        return false;
    }

private:
    const T* data_ptr_;
    bool has_data_copy_;
    T data_copy_;
};
}
}
}
}

#endif /* DDS_STREAMS_SUB_DETAIL_STREAMSAMPLE_HPP_ */
