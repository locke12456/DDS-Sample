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
#ifndef DDS_OPENSPLICE_REPORTUTILS_H
#define DDS_OPENSPLICE_REPORTUTILS_H

#include "ccpp.h"
#include "os_defs.h"
#include "os_report.h"
#include "cpp_dcps_if.h"

#include <stdarg.h>

namespace DDS {
namespace OpenSplice {
namespace Utils {

#define CPP_REPORT_STACK()                  \
    DDS::OpenSplice::Utils::report_stack()

/* Panic must flush report stack immediately */
#define CPP_PANIC(...)                      \
    do {                                    \
        DDS::OpenSplice::Utils::panic (     \
            __FILE__,                       \
            __LINE__,                       \
            OS_PRETTY_FUNCTION,             \
            __VA_ARGS__);                   \
        assert (FALSE);                     \
    } while (0);

#define CPP_REPORT(code, ...)               \
    DDS::OpenSplice::Utils::report (        \
        OS_ERROR,                           \
        __FILE__,                           \
        __LINE__,                           \
        OS_PRETTY_FUNCTION,                 \
        (code),                             \
        __VA_ARGS__)

#define CPP_REPORT_DEPRECATED(...)          \
     DDS::OpenSplice::Utils::report (       \
        OS_API_INFO,                        \
        __FILE__,                           \
        __LINE__,                           \
        OS_PRETTY_FUNCTION,                 \
        DDS::RETCODE_OK,                    \
        __VA_ARGS__)

#define CPP_REPORT_WARNING(...)             \
     DDS::OpenSplice::Utils::report (       \
        OS_WARNING,                         \
        __FILE__,                           \
        __LINE__,                           \
        OS_PRETTY_FUNCTION,                 \
        DDS::RETCODE_OK,                    \
        __VA_ARGS__)

#define CPP_REPORT_FLUSH(condition)         \
    DDS::OpenSplice::Utils::report_flush(   \
        __FILE__,                           \
        __LINE__,                           \
        OS_PRETTY_FUNCTION,                 \
        (condition))

OS_API os_char *
pretty_function(
    const os_char *);

OS_API void
report_stack();

OS_API void
panic(
    const os_char *file,
    os_int32 line,
    const os_char *signature,
    const os_char *format,
    ...);

OS_API void
report(
    os_reportType reportType,
    const os_char *file,
    os_int32 line,
    const os_char *signature,
    DDS::ReturnCode_t code,
    const os_char *format,
    ...);

OS_API void
report_flush(
    const os_char *file,
    os_int32 line,
    const os_char *signature,
    DDS::Boolean flush);

} /* end namespace Utils */
} /* end namespace OpenSplice */
} /* end namespace DDS */

#undef OS_API

#endif /* DDS_OPENSPLICE_REPORTUTILS_H */
