/*
*                         OpenSplice DDS
*
*   This software and documentation are Copyright 2006 to 2014 PrismTech
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

#ifndef ORG_OPENSPLICE_CORE_USEROBJECT_DELEGATE_HPP_
#define ORG_OPENSPLICE_CORE_USEROBJECT_DELEGATE_HPP_

#include "dds/core/macros.hpp"
#include "dds/core/refmacros.hpp"
#include "org/opensplice/core/Mutex.hpp"

#include "org/opensplice/core/ObjectDelegate.hpp"

#include "vortex_os.h"
#include "u_types.h"

namespace org
{
namespace opensplice
{
namespace core
{

class OMG_DDS_API UserObjectDelegate : public virtual org::opensplice::core::ObjectDelegate
{
public:
    UserObjectDelegate();
    virtual ~UserObjectDelegate();

    void close();

    u_object get_user_handle();

protected:
    u_object userHandle;
};




}
}
}

#endif /* ORG_OPENSPLICE_CORE_USEROBJECT_DELEGATE_HPP_ */
