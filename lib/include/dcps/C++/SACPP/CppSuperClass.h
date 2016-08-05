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

#ifndef CPP_SUPERCLASS_H_
#define CPP_SUPERCLASS_H_

#include "vortex_os.h"
#include "os_report.h"
#include "u_types.h"

#include "ccpp.h"
#include "cpp_dcps_if.h"


/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

#ifdef NDEBUG
#define CPP_CAST(type,object) static_cast<type>(object)
#else
#define CPP_CAST(type,object) dynamic_cast<type>(object)
#endif

namespace DDS
{
    namespace OpenSplice
    {
        class EntityContainer;

        typedef enum {
            UNDEFINED,

            /* Objects: (1) */
            ERRORINFO,
            DOMAINPARTICIPANTFACTORY,
            TYPESUPPORT,
            TYPESUPPORTMETAHOLDER,
            WAITSET,
            __DOMAIN,

            /* Conditions: (7) */
            CONDITION,
            STATUSCONDITION,
            GUARDCONDITION,
            READCONDITION,
            QUERYCONDITION,

            /* Entities: (12) */
            ENTITY,
            DOMAINPARTICIPANT,
            PUBLISHER,
            SUBSCRIBER,
            DATAWRITER,
            DATAREADER,
            DATAREADERVIEW,

            /* Topic Descriptions: */
            TOPICDESCRIPTION,
            TOPIC,
            CONTENTFILTEREDTOPIC,
            MULTITOPIC,

            OBJECT_COUNT
        } ObjectKind;

        class OS_API CppSuperClassInterface :
                public virtual DDS::LocalObject
        {
        public:
            virtual DDS::ReturnCode_t
            deinit() = 0;

            virtual DDS::ReturnCode_t
            wlReq_deinit() = 0;

            virtual ObjectKind
            get_kind() = 0;

            virtual ObjectKind
            rlReq_get_kind() = 0;

            virtual DDS::ReturnCode_t
            read_lock() = 0;

            virtual DDS::ReturnCode_t
            write_lock() = 0;

            virtual void
            force_write_lock() = 0;

            virtual void
            unlock() = 0;

            virtual DDS::ReturnCode_t
            check() = 0;

            virtual ~CppSuperClassInterface();
        };

        class OS_API CppSuperClass :
                public virtual CppSuperClassInterface,
                public LOCAL_REFCOUNTED_OBJECT
        {
            friend class ::DDS::OpenSplice::EntityContainer;

        private:
            const DDS::ULong    magic;
            const ObjectKind    objKind;
            os_mutex            mutex;
            os_cond             cond;
            DDS::Boolean        deinitialized;

        protected:
            CppSuperClass(
                    ObjectKind kind);

            virtual ~CppSuperClass();

            virtual DDS::ReturnCode_t
            deinit();

            // no lock Required.
            DDS::ReturnCode_t
            nlReq_init();

            // write lock Required.
            virtual DDS::ReturnCode_t
            wlReq_deinit();

            // write lock Required.
            DDS::ReturnCode_t
            wlReq_wait();

            // write lock Required.
            void
            wlReq_trigger();

        public:
            ObjectKind
            get_kind();

            ObjectKind
            rlReq_get_kind();

            DDS::ReturnCode_t
            read_lock();

            DDS::ReturnCode_t
            write_lock();

            void
            force_write_lock();

            void
            unlock();

            DDS::ReturnCode_t
            check();

            static DDS::ReturnCode_t
            uResultToReturnCode(
                    u_result uResult);

            static DDS::ReturnCode_t
            osResultToReturnCode(
                    os_result osResult);

            static u_result
            ReturnCodeTouResult(
                DDS::ReturnCode_t result);
        }; /* class CppSuperClass */
    } /* namespace OpenSplice */
} /* namespace DDS */

#undef OS_API
#endif /* CPP_SUPERCLASS_H_ */
