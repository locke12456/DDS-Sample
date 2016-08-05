//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Logic Subsystem
//
//-- Filename: devicewise/logic/internal/action.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_LOGIC_INTERNAL_ACTION_H_
#define DW_LOGIC_INTERNAL_ACTION_H_

#ifdef __cplusplus
extern "C" {
#endif

#define DW_ACTION_TYPE_LEN	64
#define DW_ACTION_RESULT_DEFAULT_ERROR	2

typedef struct {
	char type[DW_ACTION_TYPE_LEN+4];
	char name[DW_ACTION_TYPE_LEN+4];
	char group[DW_ACTION_TYPE_LEN+4];
	int name_nls;
	int desc_nls;
	int group_nls;
	int options;
	int default_error_route;
	void *propdescs;
	void *results;
	char *overview_format;
	char *overview_args[5];
	action_create_callback         create;
	action_delete_callback         delete;
	action_notify_callback         notify;
	action_verify_callback         verify;
	action_query_metadata_callback query_metadata;
	void *context;
} _ACTION_TYPE;

typedef struct {
	int return_code;
	char name[DW_ACTION_TYPE_LEN+4];
	int name_id;
	int desc_id;
	int options;
	int default_goto;
} _ACTION_RESULT;

typedef struct {
	void *handle;
	_ACTION_TYPE *type;
	action_complete_callback complete;
} _ACTION;

#ifdef __cplusplus
}
#endif

#endif /*DW_LOGIC_INTERNAL_ACTION_H_*/
