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

#ifndef LITE_CORE_ENTITY_SET_HPP_
#define LITE_CORE_ENTITY_SET_HPP_

#include <dds/core/InstanceHandle.hpp>

#include <org/opensplice/core/EntityDelegate.hpp>
#include <org/opensplice/core/Mutex.hpp>
#include <org/opensplice/core/WeakReferenceSet.hpp>

#include <vector>
#include <memory>
#include <set>

namespace org
{
namespace opensplice
{
namespace core
{

class EntitySet
{
public:
    typedef std::vector<org::opensplice::core::ObjectDelegate::weak_ref_type>::iterator vectorIterator;
    typedef std::vector<org::opensplice::core::ObjectDelegate::weak_ref_type>           vector;

    /**
     *  @internal Inserts a EntityDelegate into the set.
     * @param entity The org::opensplice::core::EntityDelegate to store
     */
    void insert(org::opensplice::core::EntityDelegate& entity);

    /**
     *  @internal Erases a EntityDelegate from the set.
     * @param entity The org::opensplice::core::EntityDelegate to delete
     */
    void erase(org::opensplice::core::EntityDelegate& entity);

    /**
     *  @internal Check if Entity with specific handle is part of the set.
     * @param handle The dds::core::InstanceHandle to search for
     */
    bool contains(const dds::core::InstanceHandle& handle);

    /**
     *  @internal Call close() of all the Entities within the set (outside lock).
     */
    void all_close();

    /**
     *  @internal Call retain() of all the Entities within the set (outside lock).
     */
    void all_retain();

    /**
     *  @internal Call enable() of all the Entities within the set (outside lock).
     */
    void all_enable();

    /**
     *  @internal Copy internal set into a vector.
     */
    vector copy();

private:
    WeakReferenceSet<ObjectDelegate::weak_ref_type>::wset entities;
    Mutex mutex;
};

}
}
}


#endif /* LITE_CORE_ENTITY_SET_HPP_ */
