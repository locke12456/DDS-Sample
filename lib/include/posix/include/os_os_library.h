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
#ifndef OS_POSIX_LIBARY_H
#define OS_POSIX_LIBARY_H

#if defined (__cplusplus)
extern "C" {
#endif

#if !defined ( _WRS_KERNEL ) || defined ( VXWORKS_55 ) || defined ( VXWORKS_54 )
#include <dlfcn.h>
#endif

typedef struct os_os_libraryAttr {
    os_os_int32 flags;
    os_boolean autoTranslate; /* Determines whether the library name is automatically mapped to its platform dependent name*/
    os_boolean staticLibOnly;
} os_os_libraryAttr;

typedef void *os_os_library;
typedef void *os_os_symbol;
/* typedef void (*os_os_symbol) (void);*/

#if defined (__cplusplus)
}
#endif

#endif /* OS_POSIX_THREAD_H */
