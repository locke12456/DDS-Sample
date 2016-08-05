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
#ifndef CPP_DDS_OPENSPLICE_FOODATAWRITER_IMPL_H
#define CPP_DDS_OPENSPLICE_FOODATAWRITER_IMPL_H

#include "u_types.h"
#include "DataWriter.h"
#include "TypeSupportMetaHolder.h"
#include "cpp_dcps_if.h"

namespace DDS {
    namespace OpenSplice {

        class OS_API FooDataWriter_impl
            : public DDS::OpenSplice::DataWriter
        {

        private:
            DDS::OpenSplice::cxxCopyIn copyIn;
            DDS::OpenSplice::cxxCopyOut copyOut;
            DDS::OpenSplice::DomainParticipant *participant;

            static v_copyin_result
            rlReq_copyIn (
                c_type type,
                void *data,
                void *to);

        protected:
            FooDataWriter_impl();
            ~FooDataWriter_impl();

            DDS::ReturnCode_t
            nlReq_init(
                DDS::OpenSplice::Publisher *publisher,
                DDS::OpenSplice::DomainParticipant *participant,
                const DDS::DataWriterQos &qos,
                DDS::OpenSplice::Topic *a_topic,
                const char *name,
                DDS::OpenSplice::cxxCopyIn copyIn,
                DDS::OpenSplice::cxxCopyOut copyOut);

            virtual DDS::ReturnCode_t
            wlReq_deinit();

            ::DDS::InstanceHandle_t
            register_instance(
                const void * instance_data) THROW_ORB_EXCEPTIONS;

            ::DDS::InstanceHandle_t
            register_instance_w_timestamp(
                const void * instance_data,
                const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

            ::DDS::ReturnCode_t
            unregister_instance(
                const void * instance_data,
                ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

            ::DDS::ReturnCode_t
            unregister_instance_w_timestamp(
                const void * instance_data,
                ::DDS::InstanceHandle_t handle,
                const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

            ::DDS::ReturnCode_t
            write(
                const void * instance_data,
                ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

            ::DDS::ReturnCode_t
            write_w_timestamp(
                const void * instance_data,
                ::DDS::InstanceHandle_t handle,
                const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

            ::DDS::ReturnCode_t
            dispose(
                const void * instance_data,
                ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

            ::DDS::ReturnCode_t
            dispose_w_timestamp(
                const void * instance_data,
                ::DDS::InstanceHandle_t handle,
                const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

            ::DDS::ReturnCode_t
            writedispose(
                const void * instance_data,
                ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

            ::DDS::ReturnCode_t
            writedispose_w_timestamp(
                const void * instance_data,
                ::DDS::InstanceHandle_t handle,
                const ::DDS::Time_t & source_timestamp) THROW_ORB_EXCEPTIONS;

            ::DDS::ReturnCode_t
            get_key_value(
                void * key_holder,
                ::DDS::InstanceHandle_t handle) THROW_ORB_EXCEPTIONS;

            ::DDS::InstanceHandle_t
            lookup_instance (
                const void * instance_data) THROW_ORB_EXCEPTIONS;
        };
    } /* namespace OpenSplice */
} /* namespace DDS */

#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_FOODATAWRITER_IMPL_H */
