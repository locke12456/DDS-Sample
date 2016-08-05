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
#ifndef CPP_DDS_OPENSPLICE_TYPESUPPORTFACTORY_H
#define CPP_DDS_OPENSPLICE_TYPESUPPORTFACTORY_H

#include "CppSuperClass.h"
#include "cpp_dcps_if.h"

/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

namespace DDS
{
    namespace OpenSplice
    {
        /* Forward declaration. */
        class DomainParticipant;
        class Topic;
        class Publisher;
        class Subscriber;
        class DataWriter;
        class DataReader;
        class DataReaderView;
        class TypeSupport;

        typedef v_copyin_result (*cxxCopyIn)(void *, const void *, void *);
        typedef void (*cxxCopyOut)(const void *, void *);

        /* TODO: This is just a mock class; implement properly. */
        class OS_API TypeSupportMetaHolder :
                public ::DDS::OpenSplice::CppSuperClass
        {
            friend class DDS::OpenSplice::TypeSupport;
            friend class DDS::OpenSplice::Topic;
            friend class DDS::OpenSplice::DomainParticipant;
            friend class DDS::OpenSplice::Subscriber;
            friend class DDS::OpenSplice::Publisher;
            friend class DDS::OpenSplice::DataReader;

        protected:
            const char **metaDescriptor;
            ::DDS::ULong metaDescriptorArrLength;
            ::DDS::ULong metaDescriptorLength;
            const char *keyList;
            const char *typeName;
            const char *internalTypeName;
            cxxCopyIn copyIn;
            cxxCopyOut copyOut;

            TypeSupportMetaHolder(const char *typeName, const char *internalTypeName, const char *keyList);
            virtual ~TypeSupportMetaHolder();

            virtual DDS::ReturnCode_t
            wlReq_deinit();

            virtual const char *
            get_type_name();

            virtual const char *
            get_internal_type_name();

            virtual const char *
            get_key_list();

            virtual char *
            get_meta_descriptor();

            virtual cxxCopyIn
            get_copy_in();

            virtual cxxCopyOut
            get_copy_out();

            virtual DDS::OpenSplice::DataWriter *
            create_datawriter() = 0;

            virtual DDS::OpenSplice::DataReader *
            create_datareader() = 0;

            virtual DDS::OpenSplice::DataReaderView *
            create_view() = 0;
        private:
            void initialize();

        }; /* class TypeSupportMetaHolder */
    } /* namespace OpenSplice */
} /* namespace DDS */

#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_TYPESUPPORTFACTORY_H */
