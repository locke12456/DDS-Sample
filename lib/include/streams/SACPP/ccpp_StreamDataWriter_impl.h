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
#ifndef CCPP_STREAMDATAWRITER_H
#define CCPP_STREAMDATAWRITER_H

#include "ccpp_dds_dcps.h"
#include "streams_ccpp.h"
#include "vortex_os.h"
#include "ccpp_StreamsUtils.h"
#include "ccpp_streams_if.h"

namespace DDS {
    namespace Streams {
        extern OS_STREAMS_API StreamDataWriterQos DefaultStreamDataWriterQos;

        class OS_STREAMS_API StreamDataWriter_impl :
            public virtual StreamDataWriter,
            public LOCAL_REFCOUNTED_OBJECT
        {
            private:
                static DDS::DomainParticipant_var participant;
                static os_uint32 nrParticipantUsers;

            protected:
                DDS::Streams::StreamDataWriterQos qos;
                DDS::Publisher_var publisher;
                DDS::Topic_var topic;

                StreamDataWriter_impl(
                    DDS::Publisher_ptr publisher,
                    DDS::DomainId_t domainId,
                    DDS::Streams::StreamDataWriterQos &qos,
                    DDS::TypeSupport_ptr typeSupport,
                    const char *streamName);

                ~StreamDataWriter_impl();

            public:
                static ::DDS::ReturnCode_t get_default_qos(
                    ::DDS::Streams::StreamDataWriterQos & qos) THROW_ORB_EXCEPTIONS;

                virtual ::DDS::ReturnCode_t set_qos(
                    const ::DDS::Streams::StreamDataWriterQos & qos) THROW_ORB_EXCEPTIONS = 0;

                ::DDS::ReturnCode_t get_qos(
                    ::DDS::Streams::StreamDataWriterQos & qos) THROW_ORB_EXCEPTIONS;
        };
    }
}

#undef OS_STREAMS_API

#endif /* CCPP_STREAMDATAWRITER_H */
