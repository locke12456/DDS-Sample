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
#ifndef OSPL_DDS_CORE_WEAK_REFERENCE_IMPL_HPP_
#define OSPL_DDS_CORE_WEAK_REFERENCE_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/core/detail/ReferenceImpl.hpp>
#include <dds/core/WeakReference.hpp>


// Implementation
namespace dds
{
namespace core
{

template <typename T>
WeakReference<T>::WeakReference() { }

template <typename T>
WeakReference<T>::WeakReference(const T& t)
{
    if (!t.is_nil()) {
        impl_ = t.delegate();
    }
}


template <typename T>
WeakReference<T>::~WeakReference() { }

template <typename T>
bool WeakReference<T>::expired()
{
    return impl_.expired();
}

template <typename T>
T WeakReference<T>::lock()
{
    return T(impl_.lock());
}
}
}
// End of implementation

#endif /* OSPL_DDS_CORE_WEAK_REFERENCE_IMPL_HPP_ */
