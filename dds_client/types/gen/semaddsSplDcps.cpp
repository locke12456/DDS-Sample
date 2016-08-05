#include "semaddsSplDcps.h"
#include "ccpp_semadds.h"

#include <v_copyIn.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__SEMADDS_Types_Message__copyIn(
    c_base base,
    const struct ::SEMADDS_Types::Message *from,
    struct _SEMADDS_Types_Message *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->id = (c_long)from->id;
#ifdef OSPL_BOUNDS_CHECK
    if(from->message){
        to->message = c_stringNew_s(base, from->message);
        if(to->message == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'SEMADDS_Types::Message.message' of type 'c_string' is NULL.");
        result = V_COPYIN_RESULT_INVALID;
    }
#else
    to->message = c_stringNew_s(base, from->message);
    if(to->message == NULL) {
        result = V_COPYIN_RESULT_OUT_OF_MEMORY;
    }
#endif
    return result;
}

v_copyin_result
__SEMADDS_Types_BoardValue__copyIn(
    c_base base,
    const struct ::SEMADDS_Types::BoardValue *from,
    struct _SEMADDS_Types_BoardValue *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->id = (c_ulong)from->id;
    to->Value = (c_ulong)from->Value;
    return result;
}

v_copyin_result
__SEMADDS_Types_API__copyIn(
    c_base base,
    const ::SEMADDS_Types::API *from,
    struct _SEMADDS_Types_API *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

#ifdef OSPL_BOUNDS_CHECK
    if((((c_long)(from->_d())) >= 0) && (((c_long)(from->_d())) < 2)){
        to->_d = (enum _SEMADDS_Types_APIKind)from->_d();
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Element of 'SEMADDS_Types.API' of type 'API' is out of range.");
        result = V_COPYIN_RESULT_INVALID;
    }
#else
    to->_d = (enum _SEMADDS_Types_APIKind)from->_d();
#endif
    switch (to->_d) {
    case _SEMADDS_Types_SemaEApiBoardValue:
        if(V_COPYIN_RESULT_IS_OK(result)){
            extern v_copyin_result __SEMADDS_Types_BoardValue__copyIn(c_base, const ::SEMADDS_Types::BoardValue *, _SEMADDS_Types_BoardValue *);
            const ::SEMADDS_Types::BoardValue &x = from->SemaEApiBoardValue();
            result = __SEMADDS_Types_BoardValue__copyIn(base, &x, &to->_u.SemaEApiBoardValue);
        }
        break;
    case _SEMADDS_Types_SemaEApiCPUValue:
        if(V_COPYIN_RESULT_IS_OK(result)){
            extern v_copyin_result __SEMADDS_Types_BoardValue__copyIn(c_base, const ::SEMADDS_Types::BoardValue *, _SEMADDS_Types_BoardValue *);
            const ::SEMADDS_Types::BoardValue &x = from->SemaEApiCPUValue();
            result = __SEMADDS_Types_BoardValue__copyIn(base, &x, &to->_u.SemaEApiCPUValue);
        }
        break;
    }
    return result;
}

v_copyin_result
__SEMADDS_Types_SemaEApi__copyIn(
    c_base base,
    const struct ::SEMADDS_Types::SemaEApi *from,
    struct _SEMADDS_Types_SemaEApi *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->id = (c_ulong)from->id;
    if(V_COPYIN_RESULT_IS_OK(result)){
        extern v_copyin_result __SEMADDS_Types_API__copyIn(c_base, const ::SEMADDS_Types::API *, _SEMADDS_Types_API *);
        result = __SEMADDS_Types_API__copyIn(base, &from->Api, &to->Api);
    }
    return result;
}

void
__SEMADDS_Types_Message__copyOut(
    const void *_from,
    void *_to)
{
    const struct _SEMADDS_Types_Message *from = (const struct _SEMADDS_Types_Message *)_from;
    struct ::SEMADDS_Types::Message *to = (struct ::SEMADDS_Types::Message *)_to;
    to->id = (::DDS::Long)from->id;
    to->message = DDS::string_dup(from->message ? from->message : "");
}

void
__SEMADDS_Types_BoardValue__copyOut(
    const void *_from,
    void *_to)
{
    const struct _SEMADDS_Types_BoardValue *from = (const struct _SEMADDS_Types_BoardValue *)_from;
    struct ::SEMADDS_Types::BoardValue *to = (struct ::SEMADDS_Types::BoardValue *)_to;
    to->id = (::DDS::ULong)from->id;
    to->Value = (::DDS::ULong)from->Value;
}

void
__SEMADDS_Types_API__copyOut(
    const void *_from,
    void *_to)
{
    const struct _SEMADDS_Types_API *from = (const struct _SEMADDS_Types_API *)_from;
    ::SEMADDS_Types::API *to = (::SEMADDS_Types::API *)_to;
    switch (from->_d) {
    case _SEMADDS_Types_SemaEApiBoardValue:
        {
            extern void __SEMADDS_Types_BoardValue__copyOut(const void *, void *);
            ::SEMADDS_Types::BoardValue *x = new ::SEMADDS_Types::BoardValue();
            __SEMADDS_Types_BoardValue__copyOut((const void *)&from->_u.SemaEApiBoardValue, (void *)x);
            to->SemaEApiBoardValue(*x);
            delete x;        }
        break;
    case _SEMADDS_Types_SemaEApiCPUValue:
        {
            extern void __SEMADDS_Types_BoardValue__copyOut(const void *, void *);
            ::SEMADDS_Types::BoardValue *x = new ::SEMADDS_Types::BoardValue();
            __SEMADDS_Types_BoardValue__copyOut((const void *)&from->_u.SemaEApiCPUValue, (void *)x);
            to->SemaEApiCPUValue(*x);
            delete x;        }
        break;
    }
    to->_d((::SEMADDS_Types::APIKind)from->_d);
}

void
__SEMADDS_Types_SemaEApi__copyOut(
    const void *_from,
    void *_to)
{
    const struct _SEMADDS_Types_SemaEApi *from = (const struct _SEMADDS_Types_SemaEApi *)_from;
    struct ::SEMADDS_Types::SemaEApi *to = (struct ::SEMADDS_Types::SemaEApi *)_to;
    to->id = (::DDS::ULong)from->id;
    {
        extern void __SEMADDS_Types_API__copyOut(const void *, void *);
        __SEMADDS_Types_API__copyOut((const void *)&from->Api, (void *)&to->Api);
    }
}

