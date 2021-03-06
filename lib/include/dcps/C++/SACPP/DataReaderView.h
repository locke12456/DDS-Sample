/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2012 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */
#ifndef CPP_DDS_OPENSPLICE_DATAREADERVIEW_H
#define CPP_DDS_OPENSPLICE_DATAREADERVIEW_H

#include "DataReader.h"
#include "Entity.h"
#include "EntityContainer.h"
#include "cpp_dcps_if.h"

namespace DDS {
    namespace OpenSplice {
    class ReadCondition;
    class QueryCondition;

        class OS_API DataReaderView :
            public virtual DDS::DataReaderView,
            public ::DDS::OpenSplice::EntityContainer,
            public ::DDS::OpenSplice::Entity
        {
            friend class DDS::OpenSplice::DataReader;
            friend class DDS::OpenSplice::ReadCondition;
            friend class DDS::OpenSplice::QueryCondition;
        public:
            DDS::ReadCondition_ptr create_readcondition (
                DDS::SampleStateMask sample_states,
                DDS::ViewStateMask view_states,
                DDS::InstanceStateMask instance_states
            ) THROW_ORB_EXCEPTIONS;

            DDS::QueryCondition_ptr create_querycondition (
                DDS::SampleStateMask sample_states,
                DDS::ViewStateMask view_states,
                DDS::InstanceStateMask instance_states,
                const char * query_expression,
                const DDS::StringSeq & query_parameters
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t delete_readcondition (
                DDS::ReadCondition_ptr a_condition
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t delete_contained_entities (
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t set_qos (
                const DDS::DataReaderViewQos & qos
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t get_qos (
                DDS::DataReaderViewQos & qos
            ) THROW_ORB_EXCEPTIONS;

            DDS::StatusCondition_ptr get_statuscondition (
            ) THROW_ORB_EXCEPTIONS;

            DDS::StatusMask get_status_changes (
            ) THROW_ORB_EXCEPTIONS;

            DDS::DataReader_ptr get_datareader (
            ) THROW_ORB_EXCEPTIONS;

        protected:
            DataReaderView ();
            ~DataReaderView ();

            virtual DDS::ReturnCode_t init (
                DDS::OpenSplice::DataReader *reader,
                const char *name,
                const DDS::DataReaderViewQos &qos,
                DDS::OpenSplice::cxxCopyIn copyIn,
                DDS::OpenSplice::cxxCopyOut copyOut) = 0;

            DDS::ReturnCode_t nlReq_init (
                DDS::OpenSplice::DataReader *reader,
                const char *name,
                const DDS::DataReaderViewQos &qos);

            virtual DDS::ReturnCode_t wlReq_deinit ();

            void nlReq_notify_listener(
                DDS::OpenSplice::Entity *sourceEntity,
                DDS::ULong               triggerMask,
                void                    *eventData);

            static DDS::ReturnCode_t
            deinit_condition(
                DDS::OpenSplice::ReadCondition *);

            DDS::DataReader_ptr rlReq_get_datareader ();

        private:
            struct Implementation;
            Implementation *pimpl;
        }; /* class DataReaderView */
    } /* namespace OpenSplice */
} /* namespace DDS */

#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_DATAREADERVIEW_H */
