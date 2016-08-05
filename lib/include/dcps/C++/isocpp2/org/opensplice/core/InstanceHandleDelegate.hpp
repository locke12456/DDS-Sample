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

#ifndef ORG_OPENSPLICE_CORE_INSTANCE_HANDLE_HPP_
#define ORG_OPENSPLICE_CORE_INSTANCE_HANDLE_HPP_

#include <dds/core/types.hpp>
#include <org/opensplice/core/config.hpp>

#include "u_instanceHandle.h"

namespace org
{
namespace opensplice
{
namespace core
{
class InstanceHandleDelegate;
}
}
}

class OSPL_ISOCPP_IMPL_API org::opensplice::core::InstanceHandleDelegate
{
public:
    InstanceHandleDelegate();
    InstanceHandleDelegate(u_instanceHandle h);
    InstanceHandleDelegate(v_handle gid);
    ~InstanceHandleDelegate();
public:
    InstanceHandleDelegate(const dds::core::null_type& src);
    InstanceHandleDelegate(const InstanceHandleDelegate& other);


public:
    bool operator==(const InstanceHandleDelegate& that) const;

    bool operator<(const InstanceHandleDelegate& that) const;

    bool operator>(const InstanceHandleDelegate& that) const;

    InstanceHandleDelegate& operator=(const dds::core::null_type& src);
    bool is_nil() const;

public:
    u_instanceHandle handle() const;

private:
    u_instanceHandle handle_;
};

inline std::ostream&
operator << (std::ostream& os,
             const org::opensplice::core::InstanceHandleDelegate& h)
{
    os << h.handle();
    return os;
}
#endif /* ORG_OPENSPLICE_CORE_INSTANCE_HANDLE_HPP_ */
