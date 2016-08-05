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

#ifndef ORG_OPENSPLICE_PUB_COHERENT_SET_IMPL_HPP_
#define ORG_OPENSPLICE_PUB_COHERENT_SET_IMPL_HPP_

#include <iostream>
#include <org/opensplice/core/exception_helper.hpp>

namespace org
{
namespace opensplice
{
namespace pub
{
class CoherentSetImpl;
}
}
}

class org::opensplice::pub::CoherentSetImpl
{
public:
	CoherentSetImpl() : pub(dds::core::null), ended(false) {}

    CoherentSetImpl(const dds::pub::Publisher& pub) : pub(pub), ended(false)
    {
        DDS::ReturnCode_t result = pub->pub_->begin_coherent_changes();
        org::opensplice::core::check_and_throw(result, OSPL_CONTEXT_LITERAL("Calling ::begin_coherent_changes"));
    }

    void end()
    {
        if(!ended)
        {
            DDS::ReturnCode_t result = pub->pub_->end_coherent_changes();
            org::opensplice::core::check_and_throw(result, OSPL_CONTEXT_LITERAL("Calling ::end_coherent_changes"));
            ended = true;
        }
    }

    ~CoherentSetImpl()
    {
        this->end();
    }

    bool operator ==(const CoherentSetImpl& other) const
    {
        return pub == other.pub && ended == other.ended;
    }

private:
    dds::pub::Publisher pub;
    bool ended;
};

#endif /* OMG_IDDS_PUB_COHERENT_SET_IMPL_HPP_ */
