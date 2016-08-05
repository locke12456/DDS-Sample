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
#ifndef CPP_ENTITY_H
#define CPP_ENTITY_H

#include "CppSuperClass.h"
#include "StatusCondition.h"
#include "cpp_dcps_if.h"

#include "dds.h"

/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

//C_CLASS(u_entity);

namespace DDS
{
    namespace OpenSplice
    {
        class OS_API Entity
            : public virtual DDS::Entity,
              public DDS::OpenSplice::CppSuperClass
        {
        friend class DDS::OpenSplice::StatusCondition;

        private:
            dds_entity_t uEntity;       // This is the C API entity
            DDS::StatusMask                      interest;
            DDS::OpenSplice::StatusCondition    *statusCondition;
            DDS::InstanceHandle_t                handle;

        protected:
            Entity(ObjectKind kind);

            virtual ~Entity();

            /* This function should be called from within a claim/release section. */
            DDS::ReturnCode_t
            nlReq_init(dds_entity_t);

            /* This function should be called from within a claim/release section. */
            virtual DDS::ReturnCode_t
            wlReq_deinit();

            /* This function should be called from within a claim/release section. */
            dds_entity_t
            rlReq_get_user_entity();

            DDS::ReturnCode_t
            wlReq_set_listener_mask (
                DDS::StatusMask mask
            ) THROW_ORB_EXCEPTIONS;

            DDS::ReturnCode_t
            set_listener_mask (
                DDS::StatusMask mask
            ) THROW_ORB_EXCEPTIONS;

            DDS::Listener_ptr listener;
            DDS::StatusMask   listenerMask;

        public:

            virtual DDS::StatusCondition_ptr
            get_statuscondition (
            ) THROW_ORB_EXCEPTIONS;

            virtual DDS::StatusMask
            get_status_changes (
            ) THROW_ORB_EXCEPTIONS;

            virtual DDS::InstanceHandle_t
            get_instance_handle (
            ) THROW_ORB_EXCEPTIONS;

            virtual DDS::ReturnCode_t
            nlReq_set_listener (
                DDS::Listener_ptr listener,
                DDS::StatusMask   mask
            ) THROW_ORB_EXCEPTIONS;

            virtual DDS::ReturnCode_t
            wlReq_set_listener (
                DDS::Listener_ptr listener,
                DDS::StatusMask   mask
            ) THROW_ORB_EXCEPTIONS;

            virtual DDS::Listener_ptr
            nlReq_get_listener (
            ) THROW_ORB_EXCEPTIONS;
        }; /* class Entity */
    }; /* namespace OpenSplice */
}; /* namespace DDS */

#undef OS_API
#endif /* CPP_ENTITY_H */
