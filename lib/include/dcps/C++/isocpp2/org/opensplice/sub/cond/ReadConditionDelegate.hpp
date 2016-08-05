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

#ifndef ORG_OPENSPLICE_SUB_COND_READCONDITION_DELEGATE_HPP_
#define ORG_OPENSPLICE_SUB_COND_READCONDITION_DELEGATE_HPP_

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

    u_observable get_user_condition();

    bool modify_state_filter(dds::sub::status::DataState& s);

private:
    static unsigned char always_true(void *object, void *arg);

};

}
}
}
}

#endif /* ORG_OPENSPLICE_SUB_COND_READCONDITION_DELEGATE_HPP_ */
