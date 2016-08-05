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


/**
 * @file
 */

#ifndef LITE_SUB_COND_READCONDITION_DELEGATE_HPP_
#define LITE_SUB_COND_READCONDITION_DELEGATE_HPP_

#include <dds/sub/AnyDataReader.hpp>

#include <org/opensplice/core/cond/ConditionDelegate.hpp>
#include <org/opensplice/sub/QueryDelegate.hpp>



namespace org
{
namespace opensplice
{
namespace sub
{
namespace cond
{


class OMG_DDS_API ReadConditionDelegate :
    public virtual org::opensplice::core::cond::ConditionDelegate,
    public virtual org::opensplice::sub::QueryDelegate
{
public:
    ReadConditionDelegate(
            const dds::sub::AnyDataReader& dr,
            const dds::sub::status::DataState& state_filter);

    template<typename FUN>
    ReadConditionDelegate(
            const dds::sub::AnyDataReader& dr,
            const dds::sub::status::DataState& state_filter,
            const FUN& functor)
                :  QueryDelegate(dr, state_filter)
     {
        this->set_handler<FUN>(functor);
     }

    ~ReadConditionDelegate();

    void init(ObjectDelegate::weak_ref_type weak_ref);

    void close();

    virtual bool trigger_value() const;

    dds_condition_t get_user_condition();
};

}
}
}
}

#endif /* LITE_SUB_COND_READCONDITION_DELEGATE_HPP_ */
