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
#ifndef OSPL_DDS_CORE_REFERENCE_IMPL_HPP_
#define OSPL_DDS_CORE_REFERENCE_IMPL_HPP_

/**
 * @file
 */

/*
 * OMG PSM class declaration
 */
#include <dds/core/Reference.hpp>
#include <org/opensplice/core/ReportUtils.hpp>

// Implementation
template <typename DELEGATE>
dds::core::Reference<DELEGATE>::Reference(dds::core::null_type&) : impl_()
{
}

template <typename DELEGATE>
dds::core::Reference<DELEGATE>::Reference(const Reference& ref) : impl_(ref.impl_)
{
}

template <typename DELEGATE>
template <typename D>
dds::core::Reference<DELEGATE>::Reference(const Reference<D>& ref)
{
    ISOCPP_REPORT_STACK_BEGIN();
    impl_ = OSPL_CXX11_STD_MODULE::dynamic_pointer_cast<DELEGATE_T>(ref.impl_);
    if (impl_ != ref.impl_) {
        throw dds::core::IllegalOperationError(std::string("Attempted invalid cast: ") + typeid(ref).name() + " to " + typeid(*this).name());
    }
}

template <typename DELEGATE>
dds::core::Reference<DELEGATE>::Reference(DELEGATE_T* p) : impl_(p)
{
}

template <typename DELEGATE>
dds::core::Reference<DELEGATE>::Reference(const DELEGATE_REF_T& p) : impl_(p)
{
    //OMG_DDS_LOG("MM", "Reference(DELEGATE_REF_T& p)");
}

template <typename DELEGATE>
dds::core::Reference<DELEGATE>::~Reference()
{
}

template <typename DELEGATE>
dds::core::Reference<DELEGATE>::operator DELEGATE_REF_T() const
{
    ISOCPP_REPORT_STACK_BEGIN();
    ISOCPP_BOOL_CHECK_AND_THROW(impl_, ISOCPP_NULL_REFERENCE_ERROR, "Reference[%d] == dds::core::null", __LINE__);
    return impl_;
}

template <typename DELEGATE>
template <typename R>
bool
dds::core::Reference<DELEGATE>::operator==(const R& ref) const
{
    ISOCPP_REPORT_STACK_BEGIN();
    bool equal = false;
    if (this->is_nil() && ref.is_nil()) {
        /* Both delegates are null. */
        equal = true;
    } else if (!this->is_nil() && !ref.is_nil()) {
        /* Check delegates. */
        equal = (this->delegate() == ref.delegate());
    }
    return equal;
}

template <typename DELEGATE>
template <typename R>
bool
dds::core::Reference<DELEGATE>::operator!=(const R& ref) const
{
    ISOCPP_REPORT_STACK_BEGIN();
    return !(*this == ref);
}

template <typename DELEGATE>
template <typename D>
dds::core::Reference<DELEGATE>&
dds::core::Reference<DELEGATE>::operator=(const Reference<D>& that)
{
    OMG_DDS_STATIC_ASSERT((dds::core::is_base_of<DELEGATE_T, D>::value));
    if(this != (Reference*)&that)
    {
        *this = Reference<DELEGATE_T>(that);
    }
    return *this;
}

template <typename DELEGATE>
template <typename R>
dds::core::Reference<DELEGATE>&
dds::core::Reference<DELEGATE>::operator=(const R& rhs)
{
    OMG_DDS_STATIC_ASSERT((dds::core::is_base_of< DELEGATE_T, typename R::DELEGATE_T>::value));
    if(this != (Reference*)&rhs)
    {
        *this = Reference<DELEGATE_T>(rhs);
    }
    return *this;
}

template <typename DELEGATE>
dds::core::Reference<DELEGATE>&
dds::core::Reference<DELEGATE>::operator=(const null_type)
{
    DELEGATE_REF_T tmp;
    impl_ = tmp;
    return *this;
}

template <typename DELEGATE>
bool
dds::core::Reference<DELEGATE>::is_nil() const
{
    return impl_.get() == 0;
}

template <typename DELEGATE>
bool
dds::core::Reference<DELEGATE>::operator==(const null_type) const
{
    return this->is_nil();
}

template <typename DELEGATE>
bool
dds::core::Reference<DELEGATE>::operator!=(const null_type) const
{
    return !(this->is_nil());
}

template <typename DELEGATE>
const typename dds::core::Reference<DELEGATE>::DELEGATE_REF_T&
dds::core::Reference<DELEGATE>::delegate() const
{
    ISOCPP_BOOL_CHECK_AND_THROW(impl_, ISOCPP_NULL_REFERENCE_ERROR, "Reference[%d] == dds::core::null", __LINE__);
    return impl_;
}

template <typename DELEGATE>
typename dds::core::Reference<DELEGATE>::DELEGATE_REF_T&
dds::core::Reference<DELEGATE>::delegate()
{
    ISOCPP_BOOL_CHECK_AND_THROW(impl_, ISOCPP_NULL_REFERENCE_ERROR, "Reference[%d] == dds::core::null", __LINE__);
    return impl_;
}

template <typename DELEGATE>
DELEGATE*
dds::core::Reference<DELEGATE>::operator->()
{
    ISOCPP_BOOL_CHECK_AND_THROW(impl_, ISOCPP_NULL_REFERENCE_ERROR, "Reference[%d] == dds::core::null", __LINE__);
    return impl_.get();
}

template <typename DELEGATE>
const DELEGATE*
dds::core::Reference<DELEGATE>::operator->() const
{
    ISOCPP_BOOL_CHECK_AND_THROW(impl_, ISOCPP_NULL_REFERENCE_ERROR, "Reference[%d] == dds::core::null", __LINE__);
    return impl_.get();
}

template <typename DELEGATE>
dds::core::Reference<DELEGATE>::operator
const typename dds::core::Reference<DELEGATE>::DELEGATE_REF_T& () const
{
    ISOCPP_BOOL_CHECK_AND_THROW(impl_, ISOCPP_NULL_REFERENCE_ERROR, "Reference[%d] == dds::core::null", __LINE__);
    return impl_;
}

template <typename DELEGATE>
dds::core::Reference<DELEGATE>::operator
typename dds::core::Reference<DELEGATE>::DELEGATE_REF_T& ()
{
    ISOCPP_BOOL_CHECK_AND_THROW(impl_, ISOCPP_NULL_REFERENCE_ERROR, "Reference[%d] == dds::core::null", __LINE__);
    return impl_;
}

template <typename DELEGATE>
void dds::core::Reference<DELEGATE>::set_ref(DELEGATE_T* p)
{
    impl_.reset(p);
}


template <class D> bool operator == (dds::core::null_type, const dds::core::Reference<D>& r)
{
    return r.is_nil();
}

template <class D> bool operator != (dds::core::null_type, const dds::core::Reference<D>& r)
{
    return !r.is_nil();
}

// End of implementation

#endif /* OSPL_DDS_CORE_REFERENCE_IMPL_HPP_ */
