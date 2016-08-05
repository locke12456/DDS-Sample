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

#ifndef ORG_OPENSPLICE_SUB_COHERENT_ACCESS_IMPL_HPP_
#define ORG_OPENSPLICE_SUB_COHERENT_ACCESS_IMPL_HPP_

#include <org/opensplice/core/exception_helper.hpp>

namespace org
{
namespace opensplice
{
namespace sub
{

class CoherentAccessImpl
{
public:
	CoherentAccessImpl() : sub(dds::core::null), ended(false) {}

    CoherentAccessImpl(const dds::sub::Subscriber sub) : sub(sub), ended(false)
    {
        DDS::ReturnCode_t result = sub->sub_->begin_access();
        org::opensplice::core::check_and_throw(result, OSPL_CONTEXT_LITERAL("Calling ::begin_access"));
    }

    void end()
    {
        if(!ended)
        {
            DDS::ReturnCode_t result = sub->sub_->end_access();
            org::opensplice::core::check_and_throw(result, OSPL_CONTEXT_LITERAL("Calling ::end_access"));
        }
    }

    bool operator==(const CoherentAccessImpl& other) const
    {
        return sub == other.sub && ended == other.ended;
    }

    dds::sub::Subscriber sub;
    bool ended;
};

}
}
}

#endif /* ORG_OPENSPLICE_SUB_COHERENT_ACCESS_IMPL_HPP_ */
