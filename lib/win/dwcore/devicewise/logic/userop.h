//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Logic Subsystem
//
//-- Filename: devicewise/logic/userop.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_LOGIC_USEROP_H_
#define DW_LOGIC_USEROP_H_

#ifdef __cplusplus
extern "C" {
#endif

#define USEROP_CHANNEL_PUBLISH_LOAD		1
#define USEROP_CHANNEL_PUBLISH_UNLOAD	2

typedef void (*userop_complete_callback)(int result_code, const char *result_message, void *custom);
DWLOGIC_EXPORT int userop_call_operation(const char *operation, const char *who, JSON *inputs, userop_complete_callback callback, void *custom, char **errMessage);

typedef void (*userop_fefunc)(const char *operation, const char *input_json, const char *desc, void*custom);
DWLOGIC_EXPORT void userop_foreach(userop_fefunc func, void *custom);

DWLOGIC_EXPORT char *userop_get_inputs_for_operation(const char *operation);
DWLOGIC_EXPORT char *userop_get_description_for_operation(const char *operation);

#ifdef __cplusplus
}
#endif

#endif /*DW_LOGIC_USEROP_H_*/
