#ifndef SEMADDSSPLTYPES_H
#define SEMADDSSPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "ccpp_semadds.h"
#include "semadds_export.h"

extern c_metaObject __semadds_SEMADDS_Types__load (c_base base);

extern const char *SEMADDS_Types_Message_metaDescriptor[];
extern const c_ulong SEMADDS_Types_Message_metaDescriptorArrLength;
extern const c_ulong SEMADDS_Types_Message_metaDescriptorLength;
extern c_metaObject __SEMADDS_Types_Message__load (c_base base);
struct _SEMADDS_Types_Message ;
extern OS_SEMADDS_API v_copyin_result __SEMADDS_Types_Message__copyIn(c_base base, const struct SEMADDS_Types::Message *from, struct _SEMADDS_Types_Message *to);
extern OS_SEMADDS_API void __SEMADDS_Types_Message__copyOut(const void *_from, void *_to);
struct _SEMADDS_Types_Message {
    c_long id;
    c_string message;
};

#undef OS_API
#endif
