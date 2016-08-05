#ifndef OMG_DDS_SUB_DETAIL_READ_CONDITION_HPP_
#define OMG_DDS_SUB_DETAIL_READ_CONDITION_HPP_

/**
 * @cond
 * Ignore this file in the API
 */

namespace org
{
namespace opensplice
{
namespace sub
{
namespace cond
{
class ReadConditionDelegate;
}
}
}
}

namespace dds
{
namespace sub
{
namespace cond
{

template <typename DELEGATE>
class TReadCondition;

namespace detail
{
typedef dds::sub::cond::TReadCondition<org::opensplice::sub::cond::ReadConditionDelegate> ReadCondition;
}
}
}
}

/** @endcond */

#endif /* OMG_DDS_SUB_DETAIL_READ_CONDITION_HPP_ */
