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
#ifndef OS_LIBRARY_H
#define OS_LIBRARY_H

#include "os_defs.h"

#include "os_if.h"
#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

#if defined (__cplusplus)
extern "C" {
#endif

typedef os_os_library os_library;
typedef os_os_symbol os_symbol;

typedef os_os_libraryAttr os_libraryAttr;

OS_API void         os_libraryAttrInit      (os_libraryAttr *attr) __nonnull_all__;

OS_API os_library   os_libraryOpen          (const char *name,
                                             os_libraryAttr *attr);

OS_API os_result    os_libraryClose         (os_library library);

OS_API os_symbol    os_libraryGetSymbol     (os_library library,
                                             const char *symbolName);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif /*OS_LIBRARY_H*/
