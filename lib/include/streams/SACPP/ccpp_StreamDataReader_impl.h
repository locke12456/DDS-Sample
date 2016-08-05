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
#ifndef CCPP_STREAMDATAREADER_H
#define CCPP_STREAMDATAREADER_H

#include "ccpp_dds_dcps.h"
#include "streams_ccpp.h"
#include "vortex_os.h"
#include "ccpp_StreamsUtils.h"
#include "ccpp_streams_if.h"

namespace DDS {
    namespace Streams {
        extern OS_STREAMS_API StreamDataReaderQos DefaultStreamDataReaderQos;

        class OS_STREAMS_API StreamDataReader_impl :
            public virtual StreamDataReader,
            public LOCAL_REFCOUNTED_OBJECT
        {
            private:
                static DDS::DomainParticipant_var participant;
                static os_uint32 nrParticipantUsers;

            protected:
                DDS::Streams::StreamDataReaderQos qos;
                DDS::Subscriber_var subscriber;
                DDS::Topic_var topic;

                StreamDataReader_impl(
                    DDS::Subscriber_ptr subscriber,
                    DDS::DomainId_t domainId,
                    DDS::Streams::StreamDataReaderQos &qos,
                    DDS::TypeSupport_ptr typeSupport,
                    const char *streamName);

                ~StreamDataReader_impl();

            public:
                static ::DDS::ReturnCode_t get_default_qos(
                    ::DDS::Streams::StreamDataReaderQos &qos) THROW_ORB_EXCEPTIONS;

                virtual ::DDS::ReturnCode_t set_qos(
                    const ::DDS::Streams::StreamDataReaderQos &qos) THROW_ORB_EXCEPTIONS = 0;

                ::DDS::ReturnCode_t get_qos(
                    ::DDS::Streams::StreamDataReaderQos &qos) THROW_ORB_EXCEPTIONS;
        };
    }
}

#undef OS_STREAMS_API

#endif /* CCPP_STREAMDATAREADER_H */
