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

#ifndef ORG_OPENSPLICE_TOPIC_TOPICTRAITS_HPP_
#define ORG_OPENSPLICE_TOPIC_TOPICTRAITS_HPP_

#include <string.h>
#include "u_dataReader.h"

namespace org
{
namespace opensplice
{
namespace topic
{

typedef v_copyin_result (*copyInFunction)(c_base base, const void *, void *);
typedef void            (*copyOutFunction)(const void *, void *);


template <class TOPIC> class TopicTraits
{
public:
    static ::org::opensplice::topic::DataRepresentationId_t getDataRepresentationId()
    {
        return ::org::opensplice::topic::INVALID_REPRESENTATION;
    }

    static ::std::vector<os_uchar> getMetaData()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getTypeHash()
    {
        return ::std::vector<os_uchar>();
    }

    static ::std::vector<os_uchar> getExtentions()
    {
        return ::std::vector<os_uchar>();
    }

    static const char *getKeyList()
    {
        return "ExampleKeylist";
    }

    static const char *getTypeName()
    {
        return "ExampleName";
    }

    static std::string getDescriptor()
    {
        return  "<ExampleType>";
    }

    static copyInFunction getCopyIn()
    {
        return NULL;
    }

    static copyOutFunction getCopyOut()
    {
        return NULL;
    }
};

}
}
}


#endif /* ORG_OPENSPLICE_TOPIC_TOPICTRAITS_HPP_ */
