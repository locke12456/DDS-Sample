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
#ifndef CPP_DDS_OPENSPLICE_READCONDITION_H
#define CPP_DDS_OPENSPLICE_READCONDITION_H

#include "Entity.h"
#include "DataReader.h"
#include "FooDataReader_impl.h"
#include "CppSuperClass.h"
#include "cpp_dcps_if.h"
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

namespace DDS
{
    namespace OpenSplice
    {
        class OS_API ReadCondition
            : public virtual ::DDS::ReadCondition,
              public ::DDS::OpenSplice::Condition
        {
            friend class DDS::OpenSplice::Entity;
            friend class DDS::WaitSet;
            friend class DDS::OpenSplice::DataReader;
            friend class DDS::OpenSplice::FooDataReader_impl;

            protected:
                DDS::SampleStateMask sample_states;
                DDS::ViewStateMask view_states;
                DDS::InstanceStateMask instance_states;
                DDS::OpenSplice::Entity *reader;


                ReadCondition();
                ReadCondition(DDS::OpenSplice::ObjectKind);

                ~ReadCondition();

                DDS::ReturnCode_t
                init (DDS::OpenSplice::Entity *,
                        DDS::SampleStateMask,
                        DDS::ViewStateMask,
                        DDS::InstanceStateMask);

                DDS::ReturnCode_t
                nlReq_init (DDS::OpenSplice::Entity *,
                        DDS::SampleStateMask,
                        DDS::ViewStateMask,
                        DDS::InstanceStateMask);

                DDS::ReturnCode_t nlReq_init
                (
                  DDS::SampleStateMask,
                  DDS::ViewStateMask,
                  DDS::InstanceStateMask
                );

                virtual DDS::ReturnCode_t
                wlReq_deinit();

               dds_condition_t&
               get_user_query();

                DDS::ReturnCode_t
                read (
                    DDS::OpenSplice::Entity *,
                    void *,
                    DDS::SampleInfoSeq &,
                    const long);


                DDS::ReturnCode_t
                take (
                    DDS::OpenSplice::Entity *,
                    void *,
                    DDS::SampleInfoSeq &,
                    const long);

                virtual DDS::ReturnCode_t
                read_next_instance (
                    DDS::OpenSplice::Entity *,
                    void *,
                    DDS::SampleInfoSeq &,
                    const long,
                    DDS::InstanceHandle_t,
                    void*);

                virtual DDS::ReturnCode_t
                take_next_instance (
                    DDS::OpenSplice::Entity *,
                    void *,
                    DDS::SampleInfoSeq &,
                    const long,
                    DDS::InstanceHandle_t,
                    void*);

            public:

                DDS::Boolean
                get_trigger_value() THROW_ORB_EXCEPTIONS;
                DDS::SampleStateMask
                get_sample_state_mask() THROW_ORB_EXCEPTIONS;

                DDS::ViewStateMask
                get_view_state_mask() THROW_ORB_EXCEPTIONS;

                DDS::InstanceStateMask
                get_instance_state_mask() THROW_ORB_EXCEPTIONS;

                DDS::DataReader_ptr
                get_datareader() THROW_ORB_EXCEPTIONS;
        };
    }; /* namespace OpenSplice */
}; /* namespace DDS */
#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_READCONDITION_H */
