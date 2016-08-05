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

#ifndef ORG_OPENSPLICE_PUB_COHERENT_SET_DELEGATE_HPP_
#define ORG_OPENSPLICE_PUB_COHERENT_SET_DELEGATE_HPP_

#include <dds/pub/Publisher.hpp>


namespace org
{
namespace opensplice
{
namespace pub
{


class OMG_DDS_API CoherentSetDelegate
{
public:
    CoherentSetDelegate(const dds::pub::Publisher& pub);
    ~CoherentSetDelegate();

    void end();

    bool operator ==(const CoherentSetDelegate& other) const;

private:
    dds::pub::Publisher pub;
    bool ended;
};

}
}
}

#endif /* ORG_OPENSPLICE_PUB_COHERENT_SET_DELEGATE_HPP_ */
