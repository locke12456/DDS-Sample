#ifndef DDS_STREAMS_SUB_DETAIL_STREAMLOANEDSAMPLES_HPP_
#define DDS_STREAMS_SUB_DETAIL_STREAMLOANEDSAMPLES_HPP_
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

#include <org/opensplice/core/config.hpp>
#include <vector>
#include <dds/streams/sub/StreamSample.hpp>
#include <org/opensplice/core/exception_helper.hpp>
#include <org/opensplice/streams/topic/TopicTraits.hpp>

namespace dds
{
namespace streams
{
namespace sub
{
namespace detail
{

template <typename T>
class StreamLoanedSamples
{
public:
    typedef std::vector< dds::streams::sub::StreamSample<T> > LoanedDataContainer;
    typedef typename std::vector< dds::streams::sub::StreamSample<T> >::iterator iterator;
    typedef typename std::vector< dds::streams::sub::StreamSample<T> >::const_iterator const_iterator;
    typedef typename org::opensplice::streams::topic::stream_topic<T>::type StreamT;

    typedef typename org::opensplice::topic::topic_data_reader<StreamT>::type DR;

public:
    StreamLoanedSamples() { }

    ~StreamLoanedSamples()
    {
        if(reader_)
        {
            DR* raw_reader_t_ = DR::_narrow(reader_.get());
            if(raw_reader_t_ && data_info_.unique())
            {
                DDS::ReturnCode_t result = raw_reader_t_->return_loan(data_info_.get()->data_, data_info_.get()->info_);
                org::opensplice::core::check_and_throw(result, OSPL_CONTEXT_LITERAL("Calling ::return_loan"));
                DDS::release(raw_reader_t_);
            }
        }
    }

public:

    iterator mbegin()
    {
        return samples_.begin();
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
        return static_cast<uint32_t>(samples_.size());
    }

    uint32_t stream() const
    {
        return stream_id_;
    }

    void stream(uint32_t stream_id)
    {
        stream_id_ = stream_id;
    }

    void resize(uint32_t s)
    {
        samples_.resize(s);
    }

    org::opensplice::core::DDS_DR_REF reader_;
    struct data_info_t
    {
        typename org::opensplice::topic::topic_data_seq<StreamT>::type data_;
        DDS::SampleInfoSeq info_;
    };
    typename dds::core::smart_ptr_traits<data_info_t>::ref_type data_info_;
private:
    LoanedDataContainer samples_;
    uint32_t stream_id_;
};

}
}
}
}

#endif /* DDS_STREAMS_SUB_DETAIL_STREAMLOANEDSAMPLES_HPP_ */
