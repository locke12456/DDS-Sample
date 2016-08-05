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
#ifndef LITE_DDS_SUB_COND_QUERYCONDITION_IMPL_HPP_
#define LITE_DDS_SUB_COND_QUERYCONDITION_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/sub/cond/QueryCondition.hpp>

// Implementation

namespace dds
{
namespace sub
{
namespace cond
{

template <typename FUN>
QueryCondition::QueryCondition(
    const dds::sub::Query& query,
    const dds::sub::status::DataState& status, const FUN& functor)
    : dds::sub::cond::TReadCondition<DELEGATE>(new DELEGATE(query.delegate().data_reader(), query.delegate(), status, functor))
{
	this->delegate()->init(this->impl_);
}

template <typename T>
QueryCondition::QueryCondition(
    const dds::sub::DataReader<T>& dr,
    const std::string& expression,
    const std::vector<std::string>& params,
    const dds::sub::status::DataState& status)
    : dds::sub::cond::TReadCondition<DELEGATE>(new DELEGATE(dds::sub::AnyDataReader(dr), expression, params, status))
{
	this->delegate()->init(this->impl_);
}


template <typename T, typename FUN>
QueryCondition::QueryCondition(const dds::sub::DataReader<T>& dr,
    const std::string& expression,
    const std::vector<std::string>& params,
    const dds::sub::status::DataState& status,
    const FUN& functor)
    : dds::sub::cond::TReadCondition<DELEGATE>(new DELEGATE(dds::sub::AnyDataReader(dr), expression, params, status, functor))
{
	this->delegate()->init(this->impl_);
}

template<typename FWIterator>
void QueryCondition::parameters(const FWIterator& begin, const FWIterator end)
{
    std::vector<std::string> params(begin, end);
    this->delegate()->parameters(params);
}

}
}
}

// End of implementation

#endif /* LITE_DDS_SUB_COND_QUERYCONDITION_IMPL_HPP_ */
