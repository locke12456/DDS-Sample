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
#ifndef CCPP_H
#define CCPP_H

#include "dds.h"

#define OS_STRUCT(name)  struct name##_s
#define OS_EXTENDS(type) OS_STRUCT(type) _parent
#define OS_CLASS(name)   typedef OS_STRUCT(name) *name

OS_CLASS(c_type);
OS_CLASS(c_base);
typedef enum c_metaKind {
    M_UNDEFINED,
    M_ANNOTATION, M_ATTRIBUTE, M_CLASS, M_COLLECTION, M_CONSTANT, M_CONSTOPERAND,
    M_ENUMERATION, M_EXCEPTION, M_EXPRESSION, M_INTERFACE,
    M_LITERAL, M_MEMBER, M_MODULE, M_OPERATION, M_PARAMETER,
    M_PRIMITIVE, M_RELATION, M_BASE, M_STRUCTURE, M_TYPEDEF,
    M_UNION, M_UNIONCASE,
    M_COUNT
} c_metaKind;
OS_CLASS(c_baseObject);
OS_STRUCT(c_baseObject) {
    c_metaKind kind;
};
OS_CLASS(c_metaObject);
OS_STRUCT(c_metaObject) {
    OS_EXTENDS(c_baseObject);
    c_metaObject definedIn;
    char* name;
};

#if defined(__GNUC__)
#   define OS_PRETTY_FUNCTION __PRETTY_FUNCTION__
#elif defined(__clang__)
#   define OS_PRETTY_FUNCTION __PRETTY_FUNCTION__
#elif defined(__ghs__)
#   define OS_PRETTY_FUNCTION __PRETTY_FUNCTION__
#elif (defined(__SUNPRO_C) && __SUNPRO_C >= 0x5100)
#   define OS_PRETTY_FUNCTION __PRETTY_FUNCTION__
#elif (defined(__SUNPRO_CC) && __SUNPRO_CC >= 0x5120)
#   define OS_PRETTY_FUNCTION __PRETTY_FUNCTION__
#elif defined(__FUNCSIG__)
#   define OS_PRETTY_FUNCTION __FUNCSIG__
#elif defined(__vxworks)
#   define OS_PRETTY_FUNCTION __PRETTY_FUNCTION__
#else
#   define OS_PRETTY_FUNCTION OS_FUNCTION
#endif

#include "dds_dcps.h"
#include "orb_abstraction.h"

#endif /* CCPP_H */

