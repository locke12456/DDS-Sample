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


/**
 * @file
 */

#ifndef OSPL_DDS_PUB_DETAIL_FIND_HPP_
#define OSPL_DDS_PUB_DETAIL_FIND_HPP_

#include <string>

#include <dds/pub/DataWriter.hpp>
#include <dds/pub/Publisher.hpp>
#include <org/opensplice/pub/PublisherDelegate.hpp>
#include <org/opensplice/pub/AnyDataWriterDelegate.hpp>

/**
 * @cond
 * Ignore this file in the API
 */

namespace dds
{
namespace pub
{

template <typename WRITER, typename FwdIterator>
uint32_t
find(const dds::pub::Publisher& pub, const std::string& topic_name,
     FwdIterator begin, int32_t max_size)
{
    ISOCPP_REPORT_STACK_BEGIN();
    if(max_size > 0) {
        org::opensplice::pub::AnyDataWriterDelegate::ref_type writer_base = pub.delegate()->find_datawriter(topic_name);
        if (writer_base) {
            /* Cast base writer to typed delegate: */
            typename WRITER::DELEGATE_REF_T writer_typed =
                    OSPL_CXX11_STD_MODULE::dynamic_pointer_cast<typename WRITER::DELEGATE_T>(writer_base);
            WRITER dw(writer_typed);
            if(dw != dds::core::null)
            {
                *begin = dw;
                return 1;
            }
        }
    }
    return 0;
}


template <typename WRITER, typename BinIterator>
uint32_t
find(const dds::pub::Publisher& pub,
     const std::string& topic_name,
     BinIterator begin)
{
    ISOCPP_REPORT_STACK_BEGIN();
    org::opensplice::pub::AnyDataWriterDelegate::ref_type writer_base = pub.delegate()->find_datawriter(topic_name);
    if (writer_base) {
        /* Cast base writer to typed delegate: */
        typename WRITER::DELEGATE_REF_T writer_typed =
                OSPL_CXX11_STD_MODULE::dynamic_pointer_cast<typename WRITER::DELEGATE_T>(writer_base);
        WRITER dw(writer_typed);
        if(dw != dds::core::null)
        {
            *begin = dw;
            return 1;
        }
    }
    return 0;
}


}
}

/** @endcond */

#endif /* OSPL_DDS_PUB_DETAIL_FIND_HPP_ */
