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
#ifndef CPP_DDS_OPENSPLICE_TYPESUPPORT_H
#define CPP_DDS_OPENSPLICE_TYPESUPPORT_H

#include "ccpp.h"
#include "CppSuperClass.h"
#include "TypeSupportMetaHolder.h"
#include "cpp_dcps_if.h"

/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

namespace DDS
{
    namespace OpenSplice
    {
        class OS_API TypeSupport :
              public virtual ::DDS::TypeSupport,
              public ::DDS::OpenSplice::CppSuperClass
        {
            friend class ::DDS::OpenSplice::DomainParticipant;

        protected:
            DDS::OpenSplice::TypeSupportMetaHolder *tsMetaHolder;

            TypeSupport();

            virtual ~TypeSupport();

            DDS::ReturnCode_t
            wlReq_deinit();

            DDS::OpenSplice::TypeSupportMetaHolder *
            get_metaHolder();

        public:
            virtual ::DDS::ReturnCode_t
            register_type(
                ::DDS::DomainParticipant_ptr participant,
                const char * type_name) THROW_ORB_EXCEPTIONS;

            virtual char *
            get_type_name() THROW_ORB_EXCEPTIONS;
        }; /* class TypeSupport */
    }; /* namespace OpenSplice */
}; /* namespace DDS */

#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_TYPESUPPORT_H */
