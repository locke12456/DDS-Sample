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
#ifndef CPP_DDS_OPENSPLICE_DOMAIN_H
#define CPP_DDS_OPENSPLICE_DOMAIN_H

#include "u_domain.h"
#include "CppSuperClass.h"
#include "DomainParticipantFactory.h"
#include "cpp_dcps_if.h"

namespace DDS
{
    namespace OpenSplice
    {
        class OS_API Domain
            : public virtual DDS::Domain,
              public DDS::OpenSplice::CppSuperClass
        {
            friend class DDS::DomainParticipantFactory;

            private:
                u_domain uDomain;

            protected:
                Domain();

                virtual ~Domain();

                virtual DDS::ReturnCode_t
                init (
                    DDS::DomainId_t domainId);

                DDS::ReturnCode_t nlReq_init(
                    DDS::DomainId_t domainId);

                virtual DDS::ReturnCode_t wlReq_deinit();

            public:
                DDS::DomainId_t
                get_domain_id () THROW_ORB_EXCEPTIONS;

                DDS::ReturnCode_t
                create_persistent_snapshot (
                    const DDS::Char *partition_expression,
                    const DDS::Char *topic_expression,
                    const DDS::Char *URI
                ) THROW_ORB_EXCEPTIONS;
        };
    };
};
#undef OS_API
#endif
