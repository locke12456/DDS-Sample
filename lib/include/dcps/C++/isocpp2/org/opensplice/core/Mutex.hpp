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

#ifndef ORG_OPENSPLICE_CORE_MUTEX_HPP_
#define ORG_OPENSPLICE_CORE_MUTEX_HPP_

#include <os_mutex.h>
#include <dds/core/macros.hpp>

namespace org
{
namespace opensplice
{
namespace core
{

class OMG_DDS_API Mutex
{
public:
    Mutex();
    virtual ~Mutex();

    void lock() const;
    bool try_lock() const;
    void unlock() const;
private:
    os_mutex mtx;
};

}
}
}



#endif /* ORG_OPENSPLICE_CORE_MUTEX_HPP_ */
