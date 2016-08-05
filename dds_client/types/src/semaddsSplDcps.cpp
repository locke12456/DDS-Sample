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

