#include "ChatSplDcps.h"
#include "ccpp_Chat.h"

#include <v_copyIn.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__Chat_User__copyIn(
    c_base base,
    const struct ::Chat::User *from,
    struct _Chat_User *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

#ifdef OSPL_BOUNDS_CHECK
    if(from->name){
        to->name = c_stringNew_s(base, from->name);
        if(to->name == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'Chat::User.name' of type 'c_string' is NULL.");
        result = V_COPYIN_RESULT_INVALID;
    }
#else
    to->name = c_stringNew_s(base, from->name);
    if(to->name == NULL) {
        result = V_COPYIN_RESULT_OUT_OF_MEMORY;
    }
#endif
    to->id = (c_long)from->id;
    return result;
}

v_copyin_result
__Chat_Messages__copyIn(
    c_base base,
    const struct ::Chat::Messages *from,
    struct _Chat_Messages *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

#ifdef OSPL_BOUNDS_CHECK
    if(from->Message){
        to->Message = c_stringNew_s(base, from->Message);
        if(to->Message == NULL) {
            result = V_COPYIN_RESULT_OUT_OF_MEMORY;
        }
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'Chat::Messages.Message' of type 'c_string' is NULL.");
        result = V_COPYIN_RESULT_INVALID;
    }
#else
    to->Message = c_stringNew_s(base, from->Message);
    if(to->Message == NULL) {
        result = V_COPYIN_RESULT_OUT_OF_MEMORY;
    }
#endif
    to->id = (c_long)from->id;
    return result;
}

void
__Chat_User__copyOut(
    const void *_from,
    void *_to)
{
    const struct _Chat_User *from = (const struct _Chat_User *)_from;
    struct ::Chat::User *to = (struct ::Chat::User *)_to;
    to->name = DDS::string_dup(from->name ? from->name : "");
    to->id = (::DDS::Long)from->id;
}

void
__Chat_Messages__copyOut(
    const void *_from,
    void *_to)
{
    const struct _Chat_Messages *from = (const struct _Chat_Messages *)_from;
    struct ::Chat::Messages *to = (struct ::Chat::Messages *)_to;
    to->Message = DDS::string_dup(from->Message ? from->Message : "");
    to->id = (::DDS::Long)from->id;
}

