//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Logic Subsystem
//
//-- Filename: devicewise/logic/event.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_LOGIC_EVENT_H_
#define DW_LOGIC_EVENT_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	int status;
	void *context;
	long long timestamp;
	void *items;
} EVENT_COMPLETION;

typedef struct {
	int status;
	void *context;
	long long timestamp;
	void *items;
	int reporting_mode;
} EVENT_NOTIFICATION;

typedef struct {
	void *notification_items;
	void *completion_items;
} EVENT_METADATA;

#define DW_EVT_SIG_DELETE	1
#define DW_EVT_SIG_SHUTDOWN	2

#define DW_EVT_OPT_FIXED_METADATA	16384

typedef void DW_EVENT;
typedef void DW_IEVENT;

typedef void (*event_callback)(DW_EVENT *event, EVENT_NOTIFICATION *notification, void *custom, int pool_id);

typedef int (*event_create_callback)(DW_IEVENT **event, void *context, void *properties, void *userctx);
typedef int (*event_signal_callback)(DW_IEVENT *event, void *context, int sig);
typedef int (*event_complete_callback)(DW_IEVENT *event, EVENT_COMPLETION *completion, void *context);
typedef int (*event_verify_callback)(void *context, void *properties, void *reference_list);
typedef int (*event_query_metadata_callback)(void *context, void *properties, EVENT_METADATA *meta_data);

DWLOGIC_EXPORT int dw_event_type_register(const char *type, const char *name, int name_nls, int desc_nls, int opts, 
					event_create_callback create, event_signal_callback sig, 
					event_verify_callback verify, event_query_metadata_callback query_metadata,
					event_complete_callback complete, void *context);
DWLOGIC_EXPORT int dw_event_type_deregister(const char *type);
DWLOGIC_EXPORT int dw_event_type_info(const char *type, char **xml);
DWLOGIC_EXPORT int dw_event_type_set_group(const char *type, const char *group, int group_nls);
DWLOGIC_EXPORT int dw_event_type_add_property_string  (const char *type, const char *key, const char *name, int name_id, int desc_id, int opts, const char *def);
DWLOGIC_EXPORT int dw_event_type_add_property_other   (const char *type, const char *key, const char *name, int name_id, int desc_id, int opts, const char *ptype, const char *def);
DWLOGIC_EXPORT int dw_event_type_add_property_option  (const char *type, const char *key, const char *name, int name_id, int desc_id, int opts, const char *options, int defopt);
DWLOGIC_EXPORT int dw_event_type_add_property_integer (const char *type, const char *key, const char *name, int name_id, int desc_id, int opts, int defval, int minval, int maxval);
DWLOGIC_EXPORT int dw_event_type_add_property_check   (const char *type, const char *key, const char *name, int name_id, int desc_id, int opts, int defval);
DWLOGIC_EXPORT int dw_event_type_add_condition        (const char *type, const char *key, const char *value, int condition);
DWLOGIC_EXPORT int dw_event_type_add_overview         (const char *type, const char *fmt, const char *arg0, const char *arg1, const char *arg2, const char *arg3, const char *arg4);

DWLOGIC_EXPORT int dw_event_verify(const char *type, void *properties, void *reference_list);
DWLOGIC_EXPORT int dw_event_query_metadata(const char *type, void *properties, EVENT_METADATA *meta_data);

DWLOGIC_EXPORT int dw_event_create(DW_EVENT **handle, const char *type, void *properties, void *userctx,
					event_callback callback, void *custom);
DWLOGIC_EXPORT int dw_event_signal(DW_EVENT *handle, int sig);

DWLOGIC_EXPORT int dw_event_notify(DW_IEVENT *handle, EVENT_NOTIFICATION *notification);
DWLOGIC_EXPORT int dw_event_complete(DW_EVENT *handle, EVENT_COMPLETION *completion);

DWLOGIC_EXPORT int dw_event_notification_create(EVENT_NOTIFICATION **notification);
DWLOGIC_EXPORT int dw_event_notification_delete(EVENT_NOTIFICATION *notification);
DWLOGIC_EXPORT int dw_event_notification_clear(EVENT_NOTIFICATION *notification);
DWLOGIC_EXPORT int dw_event_notification_populate(EVENT_NOTIFICATION *notification, EVENT_METADATA *metadata);

DWLOGIC_EXPORT int dw_event_completion_create(EVENT_COMPLETION **completion);
DWLOGIC_EXPORT int dw_event_completion_delete(EVENT_COMPLETION *completion);
DWLOGIC_EXPORT int dw_event_completion_clear(EVENT_COMPLETION *completion);
DWLOGIC_EXPORT int dw_event_completion_populate(EVENT_COMPLETION *completion, EVENT_METADATA *metadata);

DWLOGIC_EXPORT int dw_event_metadata_create(EVENT_METADATA **meta_data);
DWLOGIC_EXPORT int dw_event_metadata_delete(EVENT_METADATA *meta_data);
DWLOGIC_EXPORT int dw_event_metadata_clear(EVENT_METADATA *meta_data);
DWLOGIC_EXPORT int dw_event_metadata_add_notification_item(EVENT_METADATA *meta_data, DW_VARIABLE_INFO *vinfo);
DWLOGIC_EXPORT int dw_event_metadata_add_completion_item(EVENT_METADATA *meta_data, DW_VARIABLE_INFO *vinfo);

#ifdef __cplusplus
}
#endif

#endif /*EW_CORE_EVENT_H_*/
