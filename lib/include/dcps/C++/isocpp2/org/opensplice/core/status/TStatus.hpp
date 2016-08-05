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

#ifndef ORG_OPENSPLICE_CORE_STATUS_TSTATUS_HPP_
#define ORG_OPENSPLICE_CORE_STATUS_TSTATUS_HPP_

namespace org
{
namespace opensplice
{
namespace core
{
namespace status
{


/**
 *
 */
template <typename D>
class TAllDataDisposedTopicStatus : public dds::core::Value<D>
{
public:
    TAllDataDisposedTopicStatus() : dds::core::Value<D>() { }

public:
    /**
     * @return Total cumulative count of dispose all data events on the the Topic.
     */
    int32_t total_count() const
    {
        return this->delegate().total_count();
    }

    /**
     * @return The incremental number of dispose all data events since the last time the listener
     * was called or the status was read.
     */
    int32_t total_count_change() const
    {
        return this->delegate().total_count_change();
    }
};



}
}
}
}


#endif /* ORG_OPENSPLICE_CORE_STATUS_TSTATUS_HPP_ */
