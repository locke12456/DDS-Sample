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


/**
 * @file
 */

#ifndef LITE_CORE_REPORT_UTILS_HPP_
#define LITE_CORE_REPORT_UTILS_HPP_

#include <string>
#include <sstream>
#include <org/opensplice/core/config.hpp>
#include <dds/core/Exception.hpp>
#include <ios>
#include <stdarg.h>

#define _OS_WARNING 2
#define _OS_ERROR 4

#define ISOCPP_ERROR                       org::opensplice::core::utils::error_code
#define ISOCPP_UNSUPPORTED_ERROR           org::opensplice::core::utils::unsupported_error_code
#define ISOCPP_INVALID_ARGUMENT_ERROR      org::opensplice::core::utils::invalid_argument_code
#define ISOCPP_PRECONDITION_NOT_MET_ERROR  org::opensplice::core::utils::precondition_not_met_error_code
#define ISOCPP_OUT_OF_RESOURCES_ERROR      org::opensplice::core::utils::out_of_resources_error_code
#define ISOCPP_NOT_ENABLED_ERROR           org::opensplice::core::utils::not_enabled_error_code
#define ISOCPP_IMMUTABLE_POLICY_ERROR      org::opensplice::core::utils::immutable_policy_error_code
#define ISOCPP_INCONSISTENT_POLICY_ERROR   org::opensplice::core::utils::inconsistent_policy_error_code
#define ISOCPP_ALREADY_CLOSED_ERROR        org::opensplice::core::utils::already_closed_error_code
#define ISOCPP_TIMEOUT_ERROR               org::opensplice::core::utils::timeout_error_code
#define ISOCPP_NO_DATA_ERROR               org::opensplice::core::utils::no_data_error_code
#define ISOCPP_ILLEGAL_OPERATION_ERROR     org::opensplice::core::utils::illegal_operation_error_code
#define ISOCPP_NULL_REFERENCE_ERROR        org::opensplice::core::utils::null_reference_error_code


#define ISOCPP_REPORT_ERROR(...)                      \
    org::opensplice::core::utils::report (            \
        ISOCPP_ERROR,                                 \
        _OS_ERROR,                                     \
        __FILE__,                                     \
        __LINE__,                                     \
        OS_PRETTY_FUNCTION,                           \
        __VA_ARGS__)

#define ISOCPP_REPORT_WARNING(...)                    \
    org::opensplice::core::utils::report (            \
        0,                                            \
        _OS_WARNING,                                   \
        __FILE__,                                     \
        __LINE__,                                     \
        OS_PRETTY_FUNCTION,                           \
        __VA_ARGS__)

#define ISOCPP_RESULT_CHECK_AND_THROW(code, ...)      \
    org::opensplice::core::utils::check_result_and_throw_exception(    \
        (code),                                       \
        __FILE__,                                     \
        __LINE__,                                     \
        OS_PRETTY_FUNCTION,                           \
        __VA_ARGS__)                                  \


#define ISOCPP_OS_RESULT_CHECK_AND_THROW(code, ...)   \
    org::opensplice::core::utils::check_result_and_throw_exception(    \
        org::opensplice::core::utils::os_result_to_cpp (code),         \
        __FILE__,                                     \
        __LINE__,                                     \
        OS_PRETTY_FUNCTION,                           \
        __VA_ARGS__)                                  \

#define ISOCPP_U_RESULT_CHECK_AND_THROW(code, ...)    \
    org::opensplice::core::utils::check_c99_result_and_throw_exception( \
        code,                                         \
        __FILE__,                                     \
        __LINE__,                                     \
        OS_PRETTY_FUNCTION,                           \
        __VA_ARGS__)                                  \

#define ISOCPP_THROW_EXCEPTION(code, ...)             \
    org::opensplice::core::utils::throw_exception(    \
        (code),                                       \
        __FILE__,                                     \
        __LINE__,                                     \
        OS_PRETTY_FUNCTION,                           \
        __VA_ARGS__)                                  \

#define ISOCPP_BOOL_CHECK_AND_THROW(test, code, ...)  \
    if (!test) {                                      \
        ISOCPP_THROW_EXCEPTION(code, __VA_ARGS__);    \
    }



namespace org
{
namespace opensplice
{
namespace core
{
namespace utils
{

const int32_t error_code                       = 1;
const int32_t unsupported_error_code           = 2;
const int32_t invalid_argument_code            = 3;
const int32_t precondition_not_met_error_code  = 4;
const int32_t out_of_resources_error_code      = 5;
const int32_t not_enabled_error_code           = 6;
const int32_t immutable_policy_error_code      = 7;
const int32_t inconsistent_policy_error_code   = 8;
const int32_t already_closed_error_code        = 9;
const int32_t timeout_error_code               = 10;
const int32_t no_data_error_code               = 11;
const int32_t illegal_operation_error_code     = 12;
const int32_t null_reference_error_code        = 13;



OSPL_ISOCPP_IMPL_API void
report(
    int32_t code,
    int32_t reportType,
    const char *file,
    int32_t line,
    const char *signature,
    const char *format,
    ...);

OSPL_ISOCPP_IMPL_API void
throw_exception(
    int32_t code,
    const char *file,
    int32_t line,
    const char *signature,
    const char *format,
    ...);

OSPL_ISOCPP_IMPL_API void
check_result_and_throw_exception(
    int32_t code,
    const char *file,
    int32_t line,
    const char *signature,
    const char *format,
    ...);

OSPL_ISOCPP_IMPL_API void
check_c99_result_and_throw_exception(
    int32_t code,
    const char *file,
    int32_t line,
    const char *signature,
    const char *format,
    ...);

OSPL_ISOCPP_IMPL_API int32_t
os_result_to_cpp(
    int32_t code
);

}
}
}
}

#endif /* LITE_CORE_REPORT_UTILS_HPP_ */
