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

#ifndef LITE_SUB_GENERATION_COUNT_IMPL_HPP_
#define LITE_SUB_GENERATION_COUNT_IMPL_HPP_

namespace org
{
namespace opensplice
{
namespace sub
{
class GenerationCountImpl;
}
}
}

class org::opensplice::sub::GenerationCountImpl
{
public:
    GenerationCountImpl() : d_(0), nw_(0) { }
    GenerationCountImpl(int32_t d, int32_t nw) : d_(d), nw_(nw) { }

public:
    inline int32_t disposed() const
    {
        return d_;
    }

    inline void disposed(int32_t d)
    {
        this->d_ = d;
    }

    inline int32_t no_writers() const
    {
        return nw_;
    }

    inline void no_writers(int32_t nw)
    {
        this->nw_ = nw;
    }


    bool operator ==(const GenerationCountImpl& other) const
    {
        return other.d_ == d_ && other.nw_ == nw_;
    }

private:
    int32_t d_, nw_;
};

#endif /* LITE_SUB_GENERATION_COUNT_IMPL_HPP_ */
