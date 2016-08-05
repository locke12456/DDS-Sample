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
#ifndef OSPL_DDS_CORE_TENTITYQOS_IMPL_HPP_
#define OSPL_DDS_CORE_TENTITYQOS_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/core/TEntityQos.hpp>

// Implementation
namespace dds
{
namespace core
{

template <typename DELEGATE>
TEntityQos<DELEGATE>::TEntityQos() : dds::core::Value<DELEGATE>() { }

template <typename DELEGATE>
TEntityQos<DELEGATE>::TEntityQos(const TEntityQos& other)
    : dds::core::Value<DELEGATE>(other.delegate()) { }


/** @cond
 * Somehow, these cause functions duplicates in doxygen documentation.
 */
template <typename DELEGATE>
template <typename T>
TEntityQos<DELEGATE>::TEntityQos(const TEntityQos<T>& qos) :
    dds::core::Value<DELEGATE>(qos.delegate()) { }
/** @endcond */

template <typename DELEGATE>
TEntityQos<DELEGATE>::~TEntityQos() { }


/** @cond
 * Somehow, these cause functions duplicates in doxygen documentation.
 */
template <typename DELEGATE>
template <typename POLICY>
TEntityQos<DELEGATE>& TEntityQos<DELEGATE>::policy(const POLICY& p)
{
    this->dds::core::Value<DELEGATE>::delegate().policy(p);
    return *this;
}

template <typename DELEGATE>
template <typename POLICY>
const POLICY& TEntityQos<DELEGATE>::policy() const
{
    return this->delegate().template policy<POLICY>();
}

template <typename DELEGATE>
template <typename POLICY>
POLICY& TEntityQos<DELEGATE>::policy()
{
    return this->delegate().template policy<POLICY>();
}

template <typename DELEGATE>
template <typename POLICY>
TEntityQos<DELEGATE>& TEntityQos<DELEGATE>::operator << (const POLICY& p)
{
    this->policy(p);
    return *this;
}

template <typename DELEGATE>
template <typename POLICY>
const TEntityQos<DELEGATE>& TEntityQos<DELEGATE>::operator >> (POLICY& p) const
{
    p = this->policy<POLICY>();
    return *this;
}

template <typename DELEGATE>
template <typename T>
TEntityQos<DELEGATE>& TEntityQos<DELEGATE>::operator = (const TEntityQos<T>& other)
{
    if(this != (TEntityQos<DELEGATE>*)&other)
    {
        this->d_ = other.delegate();
    }
    return *this;
}
/** @endcond */

}
}

// End of implementation

#endif /* OSPL_DDS_CORE_TENTITYQOS_IMPL_HPP_ */
