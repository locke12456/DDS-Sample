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

#ifndef LITE_CORE_MUTEX_HPP_
#define LITE_CORE_MUTEX_HPP_

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
    void* mtx;
};

}
}
}



#endif /* LITE_CORE_MUTEX_HPP_ */
