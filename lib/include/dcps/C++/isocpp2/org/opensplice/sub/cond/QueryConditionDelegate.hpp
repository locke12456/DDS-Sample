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

#ifndef ORG_OPENSPLICE_SUB_COND_QUERYCONDITION_DELEGATE_HPP_
#define ORG_OPENSPLICE_SUB_COND_QUERYCONDITION_DELEGATE_HPP_

#include <org/opensplice/sub/cond/ReadConditionDelegate.hpp>

namespace org
{
namespace opensplice
{
namespace sub
{
namespace cond
{

class OMG_DDS_API QueryConditionDelegate :
    public org::opensplice::sub::cond::ReadConditionDelegate
{
public:
    typedef QueryDelegate::iterator iterator;
    typedef QueryDelegate::const_iterator const_iterator;

public:
    QueryConditionDelegate(
            const dds::sub::AnyDataReader& dr,
            const std::string& query_expression,
            const dds::sub::status::DataState& state_filter);

    QueryConditionDelegate(
            const dds::sub::AnyDataReader& dr,
            const std::string& expression,
            const std::vector<std::string>& params,
            const dds::sub::status::DataState& data_state);

    template<typename FUN>
    QueryConditionDelegate(
            const dds::sub::AnyDataReader& dr,
            const std::string& expression,
            const dds::sub::status::DataState& data_state,
            const FUN& functor) :
                QueryDelegate(dr, expression, data_state),
                ReadConditionDelegate(dr, data_state)
    {
        this->set_handler<FUN>(functor);
    }

    template<typename FUN>
    QueryConditionDelegate(
            const dds::sub::AnyDataReader& dr,
            const std::string& expression,
            const std::vector<std::string>& params,
            const dds::sub::status::DataState& data_state,
            const FUN& functor) :
                QueryDelegate(dr, expression, params, data_state),
                ReadConditionDelegate(dr, data_state)
    {
        this->set_handler<FUN>(functor);
    }

    ~QueryConditionDelegate();

    void init(ObjectDelegate::weak_ref_type weak_ref);
};

}
}
}
}

#endif /* ORG_OPENSPLICE_SUB_COND_QUERYCONDITION_DELEGATE_HPP_ */
