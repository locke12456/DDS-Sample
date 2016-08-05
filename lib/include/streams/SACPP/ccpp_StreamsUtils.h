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
#ifndef CCPP_STREAMSUTILS_H_
#define CCPP_STREAMSUTILS_H_

#include "streams_ccpp.h"
#include "os_mutex.h"
#include "ccpp_streams_if.h"

namespace DDS {
    namespace Streams {
        class LocalFactoryMutex {
            public:
                os_mutex lfMutex;
                LocalFactoryMutex();
                ~LocalFactoryMutex();
        };

        extern OS_STREAMS_API const DDS::SubscriberQos default_subscriber_qos;
        extern OS_STREAMS_API const DDS::PublisherQos default_publisher_qos;
        extern OS_STREAMS_API const DDS::TopicQos default_topic_qos;
        extern OS_STREAMS_API const DDS::DataWriterQos default_datawriter_qos;
        extern OS_STREAMS_API const DDS::DataReaderQos default_datareader_qos;
    }
}

#undef OS_STREAMS_API

#endif /* CCPP_STREAMSUTILS_H_ */


