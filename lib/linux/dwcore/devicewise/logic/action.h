//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Logic Subsystem
//
//-- Filename: devicewise/logic/action.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_LOGIC_ACTION_H_
#define DW_LOGIC_ACTION_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void DW_ACTION;
typedef void DW_IACTION;

// Applies to results.
#define DW_OPT_DEF_ERROR	1

typedef struct {
	int status;
	int exstatus;
	void *context;
	void *items;
} ACTION_COMPLETION;

typedef struct {
	int id;
	void *userctx;
	void *tec;
	void *items;
	int reporting_mode;
	const char *trigger_name;
	const char *project_name;
} ACTION_NOTIFICATION;

typedef struct {
	void *input_items;
	void *output_items;
} ACTION_METADATA;

typedef int (*action_create_callback)(DW_IACTION **iaction, void *context, void *properties);
typedef int (*action_delete_callback)(DW_IACTION *iaction, void *context);
typedef int (*action_verify_callback)(void *context, void *properties, void *reference_list);
typedef int (*action_query_metadata_callback)(void *context, void *properties, ACTION_METADATA *meta_data);
typedef int (*action_notify_callback)(DW_IACTION *iaction, void *context, DW_ACTION *action, 
					ACTION_NOTIFICATION *notification, ACTION_COMPLETION *completion);

typedef void (*action_complete_callback)(DW_ACTION *action, ACTION_COMPLETION *completion, int pool_id);

// Functions used to register a new type of action 
DWLOGIC_EXPORT int dw_action_type_register(const char *type, const char *name, int name_nls, int desc_nls, int opts, 
						action_create_callback create, action_delete_callback deletea, 
						action_notify_callback notify, action_verify_callback verify, 
						action_query_metadata_callback query_metadata, void *context);
DWLOGIC_EXPORT int dw_action_type_deregister(const char *type);
DWLOGIC_EXPORT int dw_action_type_info(const char *type, char **xml);
DWLOGIC_EXPORT int dw_action_type_get_default_error_route(const char *type);
DWLOGIC_EXPORT int dw_action_type_set_group(const char *type, const char *group, int group_nls);
DWLOGIC_EXPORT int dw_action_type_add_property_string  (const char *type, const char *key, const char *name, int name_id, int desc_id, int opts, const char *def);
DWLOGIC_EXPORT int dw_action_type_add_property_other   (const char *type, const char *key, const char *name, int name_id, int desc_id, int opts, const char *ptype, const char *def);
DWLOGIC_EXPORT int dw_action_type_add_property_option  (const char *type, const char *key, const char *name, int name_id, int desc_id, int opts, const char *options, int defopt);
DWLOGIC_EXPORT int dw_action_type_add_property_integer (const char *type, const char *key, const char *name, int name_id, int desc_id, int opts, int defval, int minval, int maxval);
DWLOGIC_EXPORT int dw_action_type_add_property_check   (const char *type, const char *key, const char *name, int name_id, int desc_id, int opts, int defval);
DWLOGIC_EXPORT int dw_action_type_add_result           (const char *type, int return_code, const char *name, int name_id, int desc_id, int default_goto, int opts);
DWLOGIC_EXPORT int dw_action_type_add_condition        (const char *type, const char *key, const char *value, int condition);
DWLOGIC_EXPORT int dw_action_type_add_overview         (const char *type, const char *fmt, const char *arg0, const char *arg1, const char *arg2, const char *arg3, const char *arg4);

// Runtime functions to create an instance of an action.
DWLOGIC_EXPORT int dw_action_create(DW_ACTION **handle, const char *type, void *properties,
						action_complete_callback complete);
DWLOGIC_EXPORT int dw_action_delete(DW_ACTION *handle);
DWLOGIC_EXPORT int dw_action_verify(const char *type, void *properties, void *reference_list);
DWLOGIC_EXPORT int dw_action_query_metadata(const char *type, void *properties, ACTION_METADATA *meta_data);
DWLOGIC_EXPORT int dw_action_notify(DW_ACTION *handle,
						ACTION_NOTIFICATION *notification, ACTION_COMPLETION *completion);
	
DWLOGIC_EXPORT int dw_action_complete(DW_ACTION *handle,ACTION_COMPLETION *completion,int pool_id);

DWLOGIC_EXPORT int dw_action_notification_create(ACTION_NOTIFICATION **notification);
DWLOGIC_EXPORT int dw_action_notification_delete(ACTION_NOTIFICATION *notification);
DWLOGIC_EXPORT int dw_action_notification_clear(ACTION_NOTIFICATION *notification);
DWLOGIC_EXPORT int dw_action_notification_populate(ACTION_NOTIFICATION *notification, ACTION_METADATA *metadata);

DWLOGIC_EXPORT int dw_action_completion_create(ACTION_COMPLETION **completion);
DWLOGIC_EXPORT int dw_action_completion_delete(ACTION_COMPLETION *completion);
DWLOGIC_EXPORT int dw_action_completion_clear(ACTION_COMPLETION *completion);
DWLOGIC_EXPORT int dw_action_completion_populate(ACTION_COMPLETION *completion, ACTION_METADATA *metadata);

DWLOGIC_EXPORT int dw_action_metadata_create(ACTION_METADATA **meta_data);
DWLOGIC_EXPORT int dw_action_metadata_delete(ACTION_METADATA *meta_data);
DWLOGIC_EXPORT int dw_action_metadata_clear(ACTION_METADATA *meta_data);
DWLOGIC_EXPORT int dw_action_metadata_add_input(ACTION_METADATA *meta_data, DW_VARIABLE_INFO *vinfo);
DWLOGIC_EXPORT int dw_action_metadata_add_output(ACTION_METADATA *meta_data, DW_VARIABLE_INFO *vinfo);

#ifdef __cplusplus
}
#endif

#endif /*DW_LOGIC_ACTION_H_*/
