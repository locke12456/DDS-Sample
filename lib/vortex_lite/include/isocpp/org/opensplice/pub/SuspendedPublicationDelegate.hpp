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

#ifndef LITE_PUB_SUSPENDED_PUBBLICATIONS_DELEGATE_HPP_
#define LITE_PUB_SUSPENDED_PUBBLICATIONS_DELEGATE_HPP_

#include <dds/pub/Publisher.hpp>


namespace org
{
namespace opensplice
{
namespace pub
{


//class OMG_DDS_API SuspendedPublicationDelegate
class SuspendedPublicationDelegate
{
public:
    SuspendedPublicationDelegate(const dds::pub::Publisher& pub);
    ~SuspendedPublicationDelegate();

    void resume();

    bool operator ==(const SuspendedPublicationDelegate& other) const;

private:
    dds::pub::Publisher pub;
    bool resumed;
};

}
}
}

#endif /* LITE_PUB_SUSPENDED_PUBBLICATIONS_DELEGATE_HPP_ */
