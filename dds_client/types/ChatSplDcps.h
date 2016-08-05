#ifndef CHATSPLTYPES_H
#define CHATSPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "ccpp_Chat.h"
#include "inc\semadds_export.h"

extern c_metaObject __Chat_Chat__load (c_base base);

extern const char *Chat_User_metaDescriptor[];
extern const c_ulong Chat_User_metaDescriptorArrLength;
extern const c_ulong Chat_User_metaDescriptorLength;
extern c_metaObject __Chat_User__load (c_base base);
struct _Chat_User ;
extern OS_SEMADDS_API v_copyin_result __Chat_User__copyIn(c_base base, const struct Chat::User *from, struct _Chat_User *to);
extern OS_SEMADDS_API void __Chat_User__copyOut(const void *_from, void *_to);
struct _Chat_User {
    c_string name;
    c_long id;
};

extern const char *Chat_Messages_metaDescriptor[];
extern const c_ulong Chat_Messages_metaDescriptorArrLength;
extern const c_ulong Chat_Messages_metaDescriptorLength;
extern c_metaObject __Chat_Messages__load (c_base base);
struct _Chat_Messages ;
extern OS_SEMADDS_API v_copyin_result __Chat_Messages__copyIn(c_base base, const struct Chat::Messages *from, struct _Chat_Messages *to);
extern OS_SEMADDS_API void __Chat_Messages__copyOut(const void *_from, void *_to);
struct _Chat_Messages {
    c_string Message;
    c_long id;
};

#undef OS_API
#endif
