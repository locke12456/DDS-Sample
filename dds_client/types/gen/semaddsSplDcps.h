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

extern const char *SEMADDS_Types_BoardValue_metaDescriptor[];
extern const c_ulong SEMADDS_Types_BoardValue_metaDescriptorArrLength;
extern const c_ulong SEMADDS_Types_BoardValue_metaDescriptorLength;
extern c_metaObject __SEMADDS_Types_BoardValue__load (c_base base);
struct _SEMADDS_Types_BoardValue ;
extern OS_SEMADDS_API v_copyin_result __SEMADDS_Types_BoardValue__copyIn(c_base base, const struct SEMADDS_Types::BoardValue *from, struct _SEMADDS_Types_BoardValue *to);
extern OS_SEMADDS_API void __SEMADDS_Types_BoardValue__copyOut(const void *_from, void *_to);
struct _SEMADDS_Types_BoardValue {
    c_ulong id;
    c_ulong Value;
};

extern c_metaObject __SEMADDS_Types_APIKind__load (c_base base);
enum _SEMADDS_Types_APIKind {
    _SEMADDS_Types_SemaEApiBoardValue,
    _SEMADDS_Types_SemaEApiCPUValue
};

extern const char *SEMADDS_Types_API_metaDescriptor[];
extern const c_ulong SEMADDS_Types_API_metaDescriptorArrLength;
extern const c_ulong SEMADDS_Types_API_metaDescriptorLength;
extern c_metaObject __SEMADDS_Types_API__load (c_base base);
extern const char * __SEMADDS_Types_API__keys (void);
extern const char * __SEMADDS_Types_API__name (void);
struct _SEMADDS_Types_API {
    enum _SEMADDS_Types_APIKind _d;
    union {
        struct _SEMADDS_Types_BoardValue SemaEApiBoardValue;
        struct _SEMADDS_Types_BoardValue SemaEApiCPUValue;
    } _u;
};

extern const char *SEMADDS_Types_SemaEApi_metaDescriptor[];
extern const c_ulong SEMADDS_Types_SemaEApi_metaDescriptorArrLength;
extern const c_ulong SEMADDS_Types_SemaEApi_metaDescriptorLength;
extern c_metaObject __SEMADDS_Types_SemaEApi__load (c_base base);
struct _SEMADDS_Types_SemaEApi ;
extern OS_SEMADDS_API v_copyin_result __SEMADDS_Types_SemaEApi__copyIn(c_base base, const struct SEMADDS_Types::SemaEApi *from, struct _SEMADDS_Types_SemaEApi *to);
extern OS_SEMADDS_API void __SEMADDS_Types_SemaEApi__copyOut(const void *_from, void *_to);
struct _SEMADDS_Types_SemaEApi {
    c_ulong id;
    struct _SEMADDS_Types_API Api;
};

#undef OS_API
#endif
