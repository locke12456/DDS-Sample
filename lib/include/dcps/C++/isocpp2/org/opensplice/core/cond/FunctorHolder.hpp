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

#ifndef ORG_OPENSPLICE_CORE_COND_FUNCTOR_HOLDER_HPP_
#define ORG_OPENSPLICE_CORE_COND_FUNCTOR_HOLDER_HPP_

namespace dds
{
namespace core
{
namespace cond
{
template <typename DELEGATE> class TCondition;
}
}
}

namespace org
{
namespace opensplice
{
namespace core
{
namespace cond
{

class ConditionDelegate;

class FunctorHolderBase
{
public:
    FunctorHolderBase() { };

    virtual ~FunctorHolderBase() { };

    virtual void dispatch(dds::core::cond::TCondition<org::opensplice::core::cond::ConditionDelegate> &condition) = 0;
};

template <typename FUN>
class FunctorHolder : public FunctorHolderBase
{
public:
    /* Remove const to be able to call non-const functors. */
    FunctorHolder(FUN &functor) : myFunctor(functor)
    {
    }

    virtual ~FunctorHolder() { };

    void dispatch(dds::core::cond::TCondition<org::opensplice::core::cond::ConditionDelegate> &condition)
    {
        myFunctor(condition);
    }

private:
    FUN &myFunctor;
};

template <typename FUN>
class ConstFunctorHolder : public FunctorHolderBase
{
public:
    /* Remove const to be able to call non-const functors. */
    ConstFunctorHolder(const FUN &functor) : myFunctor(functor)
    {
    }

    virtual ~ConstFunctorHolder() { };

    void dispatch(dds::core::cond::TCondition<org::opensplice::core::cond::ConditionDelegate> &condition)
    {
        myFunctor(condition);
    }

private:
    const FUN &myFunctor;
};

}
}
}
}

#endif  /* ORG_OPENSPLICE_CORE_COND_FUNCTOR_HOLDER_HPP_ */
