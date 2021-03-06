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
#ifndef OS_WIN32_LIBARY_H
#define OS_WIN32_LIBARY_H

#if defined (__cplusplus)
extern "C" {
#endif

typedef struct os_os_libraryAttr {
    os_boolean autoTranslate; /* Determines whether the library name is automatically mapped to its platform dependent name*/
} os_os_libraryAttr;

typedef void *os_os_library;
typedef void *os_os_symbol;

#if defined (__cplusplus)
}
#endif

#endif /* OS_WIN32_LIBRARY_H */
