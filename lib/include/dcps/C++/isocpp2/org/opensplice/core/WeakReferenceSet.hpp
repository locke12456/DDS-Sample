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

#ifndef ORG_OPENSPLICE_CORE_WEAK_REFERENCE_SET_HPP_
#define ORG_OPENSPLICE_CORE_WEAK_REFERENCE_SET_HPP_

#include <dds/core/macros.hpp>

#include <memory>
#include <set>

namespace org
{
namespace opensplice
{
namespace core
{

#if defined(OSPL_USE_CXX11)

template <typename T>
struct WeakReferenceSet
{
    typedef typename std::set<T, std::owner_less<T> > wset;
    typedef typename std::set<T, std::owner_less<T> >::iterator iterator;
};

#else

template <typename T>
struct WeakReferenceSet
{
    typedef typename std::set<T> wset;
    typedef typename std::set<T>::iterator iterator;
};

#endif

}
}
}

#endif /* ORG_OPENSPLICE_CORE_WEAK_REFERENCE_SET_HPP_ */
