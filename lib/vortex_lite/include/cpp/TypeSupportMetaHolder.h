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
#ifndef CPP_DDS_OPENSPLICE_TYPESUPPORTFACTORY_H
#define CPP_DDS_OPENSPLICE_TYPESUPPORTFACTORY_H

#include "CppSuperClass.h"
#include "cpp_dcps_if.h"

#include "dds/impl.h"

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
        class TypeSupport;

        typedef void (*cxxCopyIn)( const void *, void * );
        typedef void (*cxxCopyOut)( const void *, void * );
        typedef void (*cxxCopyOutSeq)(void *[], void *, int );
        typedef void *(*cxxAllocator)();
        typedef void (*cxxDeallocator)(void *);

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

            const dds_topic_descriptor_t *metaDescriptor;
            ::DDS::ULong metaDescriptorArrLength;
            const char *keyList;
            const char *typeName;
            const char *internalTypeName;
            cxxCopyIn copyIn;
            cxxCopyOut copyOut;
            cxxCopyOutSeq copyOutSeq;
            cxxAllocator allocator;
            cxxDeallocator deallocator;

            TypeSupportMetaHolder(const char *typeName, const char *internalTypeName, const char *keyList);
            virtual ~TypeSupportMetaHolder();

            virtual DDS::ReturnCode_t
            wlReq_deinit();

            virtual const char * get_type_name();

            virtual const char * get_key_list();

            virtual const dds_topic_descriptor_t *
            get_meta_descriptor();

            virtual cxxCopyIn
            get_copy_in();

            virtual cxxCopyOut
            get_copy_out();

            virtual cxxCopyOutSeq
            get_copy_out_seq();

            virtual cxxAllocator
            get_allocator();

            virtual cxxDeallocator
            get_deallocator();

            virtual DDS::OpenSplice::DataWriter *
            create_datawriter() = 0;

            virtual DDS::OpenSplice::DataReader *
            create_datareader() = 0;

        private:
            void initialize();

        }; /* class TypeSupportMetaHolder */
    }; /* namespace OpenSplice */
}; /* namespace DDS */

#undef OS_API
#endif /* CPP_DDS_OPENSPLICE_TYPESUPPORTFACTORY_H */
