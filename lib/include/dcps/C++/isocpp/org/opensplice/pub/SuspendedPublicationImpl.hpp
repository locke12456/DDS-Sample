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

#ifndef ORG_OPENSPLICE_PUB_SUSPENDED_PUBBLICATIONS_IMPL_HPP_
#define ORG_OPENSPLICE_PUB_SUSPENDED_PUBBLICATIONS_IMPL_HPP_

#include <iostream>
#include <org/opensplice/core/exception_helper.hpp>

namespace org
{
namespace opensplice
{
namespace pub
{
class SuspendedPublicationImpl;
}
}
}

class org::opensplice::pub::SuspendedPublicationImpl
{
public:
	SuspendedPublicationImpl() : pub(dds::core::null), resumed(false) {}

    SuspendedPublicationImpl(const dds::pub::Publisher& pub) : pub(pub), resumed(false)
    {
        DDS::ReturnCode_t result = pub->pub_->suspend_publications();
        org::opensplice::core::check_and_throw(result, OSPL_CONTEXT_LITERAL("Calling ::suspend_publications"));
    }

    void resume()
    {
        if(!resumed)
        {
            DDS::ReturnCode_t result = pub->pub_->resume_publications();
            org::opensplice::core::check_and_throw(result, OSPL_CONTEXT_LITERAL("Calling ::resume_publications"));
        }
    }

    ~SuspendedPublicationImpl()
    {
        this->resume();
    }

    bool operator ==(const SuspendedPublicationImpl& other) const
    {
        return pub == other.pub && resumed == other.resumed;
    }

private:
    dds::pub::Publisher pub;
    bool resumed;
};

#endif /* ORG_OPENSPLICE_PUB_SUSPENDED_PUBBLICATIONS_IMPL_HPP_ */
