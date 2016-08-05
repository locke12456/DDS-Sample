/*
 *                         Vortex Lite
 *
 *   This software and documentation are Copyright 2006 to 2015 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $LITE_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */
#ifndef LITE_DDS_SUB_DETAIL_FIND_HPP_
#define LITE_DDS_SUB_DETAIL_FIND_HPP_

/**
 * @file
 */

// Implementation
#include <string>
#include <vector>

#include <dds/sub/DataReader.hpp>
#include <dds/sub/Subscriber.hpp>
#include <dds/sub/status/DataState.hpp>
#include <dds/topic/TopicDescription.hpp>

#include <org/opensplice/sub/SubscriberDelegate.hpp>
#include <org/opensplice/sub/BuiltinSubscriberDelegate.hpp>
#include <org/opensplice/sub/AnyDataReaderDelegate.hpp>

namespace dds
{
namespace sub
{



namespace detail
{


/*********************************************************************
 * To be able to properly copy found readers into the given iterators
 * (which are related to typed DataReaders or AnyDataReaders), we have
 * to specialize the find() template functions.
 * But template functions specialization is not supported by C++. So,
 * we have to use these helper classes to get the specialization.
 *********************************************************************/

typedef std::vector<org::opensplice::sub::AnyDataReaderDelegate::ref_type> base_readers_vector;
typedef std::vector<org::opensplice::sub::AnyDataReaderDelegate::ref_type>::iterator base_readers_iterator;

/*
 * Copy helper class for typed readers.
 */
template <typename READER, typename ITERATOR>
class ReadersCopySpecialization
{
public:
    static
    bool copy(base_readers_iterator base_iter, ITERATOR typed_iter) {
        bool copied = false;
        try {
            /* Cast base reader to typed delegate: */
            typename READER::DELEGATE_REF_T reader_typed =
                    OSPL_CXX11_STD_MODULE::dynamic_pointer_cast<typename READER::DELEGATE_T>(*base_iter);
            READER dr(reader_typed);
            if(dr != dds::core::null)
            {
                *typed_iter = dr;
                copied = true;
            }
        } catch (...) {
            /* Ignore, because subscriber can have returned readers that are of
             * different types. */
        }
        return copied;
    }
};

/*
 * Copy helper class for any readers.
 */
template <typename ITERATOR>
class ReadersCopySpecialization<dds::sub::AnyDataReader, ITERATOR>
{
public:
    static
    bool copy(base_readers_iterator base_iter, ITERATOR any_iter) {
        *any_iter = (*base_iter)->wrapper_to_any();
        return true;
    }
};


/*
 * Copy helper class for list of readers.
 */
template <typename READER, typename ITERATOR>
class ReadersCopy
{
public:
    static
    uint32_t copy(base_readers_vector base_readers,
                  ITERATOR begin,
                  uint32_t max_size)
    {
        uint32_t size = 0;
        base_readers_iterator iter;
        for (iter = base_readers.begin(); (size < max_size) && (iter != base_readers.end()); ++iter) {
            if (ReadersCopySpecialization<READER, ITERATOR>::copy(iter, begin)) {
                begin++;
                size++;
            }
        }
        return size;
    }

    static
    uint32_t copy(base_readers_vector base_readers,
                  ITERATOR begin)
    {
        uint32_t size = 0;
        base_readers_iterator iter;
        for (iter = base_readers.begin(); iter != base_readers.end(); ++iter) {
            if (ReadersCopySpecialization<READER, ITERATOR>::copy(iter, begin)) {
                begin++;
                size++;
            }
        }
        return size;
    }
};

} /* namespace detail */



template <typename READER, typename FwdIterator>
uint32_t
find(const dds::sub::Subscriber& sub,
     const std::string &topic_name,
     FwdIterator begin, uint32_t max_size)
{
    uint32_t size = 0;
    if (max_size > 0) {
        detail::base_readers_vector base_readers;
        base_readers = sub.delegate()->find_datareaders(topic_name);
        size = detail::ReadersCopy<READER, FwdIterator>::copy(base_readers, begin, max_size);
    }
    return size;
}

template <typename READER, typename BinIterator>
uint32_t
find(const dds::sub::Subscriber& sub,
     const std::string &topic_name,
     BinIterator begin)
{
    uint32_t size = 0;
    detail::base_readers_vector base_readers;
    base_readers = sub.delegate()->find_datareaders(topic_name);
    size = detail::ReadersCopy<READER, BinIterator>::copy(base_readers, begin);
    return size;
}

template <typename READER, typename T, typename FwdIterator>
uint32_t
find(const dds::sub::Subscriber& sub,
     const dds::topic::TopicDescription& topic_description,
     FwdIterator begin, uint32_t max_size)
{
    return find<READER, T, FwdIterator>(sub, topic_description.name(), begin, max_size);
}

template <typename READER, typename T, typename BinIterator>
uint32_t
find(const dds::sub::Subscriber& sub,
     const dds::topic::TopicDescription& topic_description,
     BinIterator begin)
{
    return find<READER, T, BinIterator>(sub, topic_description.name(), begin);
}

template <typename READER, typename FwdIterator>
uint32_t
find(const dds::sub::Subscriber& sub,
     const dds::sub::status::DataState& rs,
     FwdIterator begin, uint32_t max_size)
{
    uint32_t size = 0;
    if (max_size > 0) {
        detail::base_readers_vector base_readers;
        base_readers = sub.delegate()->get_datareaders(rs);
        size = detail::ReadersCopy<READER, FwdIterator>::copy(base_readers, begin, max_size);
    }
    return size;
}

template <typename READER, typename BinIterator>
uint32_t
find(const dds::sub::Subscriber& sub,
     const dds::sub::status::DataState& rs,
     BinIterator begin)
{
    uint32_t size = 0;
    detail::base_readers_vector base_readers;
    base_readers = sub.delegate()->get_datareaders(rs);
    size = detail::ReadersCopy<READER, BinIterator>::copy(base_readers, begin);
    return size;
}

}
}

#endif /* LITE_DDS_SUB_DETAIL_FIND_HPP_ */

