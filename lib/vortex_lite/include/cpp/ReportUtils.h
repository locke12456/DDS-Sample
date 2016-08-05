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
#ifndef DDS_OPENSPLICE_REPORTUTILS_H
#define DDS_OPENSPLICE_REPORTUTILS_H

#include "ccpp.h"

#include <stdarg.h>

namespace DDS {
namespace OpenSplice {
namespace Utils {

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
        __FILE__,                           \
        __LINE__,                           \
        OS_PRETTY_FUNCTION,                 \
        code,                               \
        __VA_ARGS__)

#define CPP_REPORT_FLUSH(condition)         \
    DDS::OpenSplice::Utils::report_flush(   \
        __FILE__,                           \
        __LINE__,                           \
        OS_PRETTY_FUNCTION,                 \
        (condition))

char *
pretty_function(
    const char *);

void
panic(
    const char *file,
    int32_t line,
    const char *signature,
    const char *format,
    ...);

void
report(
    const char *file,
    int32_t line,
    const char *signature,
    DDS::ReturnCode_t code,
    const char *format,
    ...);

void
report_flush(
    const char *file,
    int32_t line,
    const char *signature,
    DDS::Boolean flush);

} /* end namespace Utils */
} /* end namespace OpenSplice */
} /* end namespace DDS */

#endif /* DDS_OPENSPLICE_REPORTUTILS_H */
