//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Logic Subsystem
//
//-- Filename: devicewise/logic/internal/trigger.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_LOGIC_INTERNAL_TRIGGER_H_
#define DW_LOGIC_INTERNAL_TRIGGER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define DW_TRIGGER_NAME_LEN		64
#define DW_TRIGGER_MAX_ACTIONS	256
#define DW_TRIGGER_MAX_ROUTES	32
#define DW_TRIGGER_FREELIST		8

#define DW_TRIGGER_LOADED		1
#define DW_TRIGGER_UNLOADED		2
#define DW_TRIGGER_LOADING		3
#define DW_TRIGGER_UNLOADING	4

#define TRIGGER_SCOPE_LOCAL		1
#define TRIGGER_SCOPE_STATIC	2
#define TRIGGER_SCOPE_GLOBAL	3
#define TRIGGER_SCOPE_DEVICE	4
#define TRIGGER_SCOPE_CONSTANT	5
#define TRIGGER_SCOPE_MACRO		6
#define TRIGGER_SCOPE_EVENT		7

#define TRIGGER_REPORT_NOT_SET			0
#define TRIGGER_REPORT_OFF				1
#define TRIGGER_REPORT_ON				2
#define TRIGGER_REPORT_ONERR			4
#define TRIGGER_REPORT_ONTIMEOUT		8

#define TRIGGER_REPORT_NEXT_OFF			0
#define TRIGGER_REPORT_NEXT				1
#define TRIGGER_REPORT_NEXT_SUBTRIGGER	2

//#define TRIGGER_LIC_PRODUCT		2
//#define TRIGGER_LIC_FEATURE		5

#define TRIGGER_ATTN_KEY	"set_on_trig_disable"
#define TRIGGER_OF_ATTN_KEY	"set_on_trig_overflow"

#define DW_TRIGGER_OPT_REF				16
#define DW_TRIGGER_OPT_IGNORE_PROJECT	32

#define TRIGGER_DEFAULT_CONSTANT_DELIM ','

struct _DW_TRIGGER_STATUS_s;

typedef struct {
	char *device;
	DW_VARIABLE_INFO *vinfo;
	long long hash;
	int ondemand;
} _DW_TRIGGER_DV;

typedef struct {
	char *name;
	int index;
} _DW_TRIGGER_LV;

typedef struct {
	char *name;
	DW_VARIABLE_INFO *vinfo;
} _DW_TRIGGER_SV;

typedef struct {
	char *macro;
} _DW_TRIGGER_MV;

typedef struct {
	char *value;
	char delim;
} _DW_TRIGGER_CV;

typedef struct {
	char *name;
	char *ofs;
	//int type;
	//int length;
	DW_VARIABLE_INFO *vinfo;
} _DW_TRIGGER_EV;

typedef struct {
	btree_free free_func;
	void *object;
} _TRIGGER_FREE_LIST;
		
typedef struct {
	int scope;
	union {
		_DW_TRIGGER_DV DeviceVariable;
		_DW_TRIGGER_LV LocalVariable;
		_DW_TRIGGER_SV StaticVariable;
		_DW_TRIGGER_MV MacroVariable;
		_DW_TRIGGER_CV ConstantVariable;
		_DW_TRIGGER_EV EventVariable;
	} data;
	DW_VARIABLE_INFO *logical_info;
	char *logical_name;
	int count;
	_TRIGGER_FREE_LIST freelist[DW_TRIGGER_FREELIST];
	int freelist_idx;
} _TRIGGER_ACTION_VARIABLE;

typedef struct {
	int id;
	int has_routes;
	int default_error_route;
	char *type;
	char *comment;
	char *context;
	void *properties;
	void *input_list;
	void *output_list;
	ACTION_METADATA *meta_data;
	DW_ACTION *action_handle;
	unsigned short routes[DW_TRIGGER_MAX_ROUTES];
} _TRIGGER_ACTION;

typedef struct {
	char name[DW_TRIGGER_NAME_LEN+4];
	char project[DW_TRIGGER_NAME_LEN+4];
	int id;
	int max_pending;
	int report_mode;
	int report_apply_to_subtrigger;
	int queue_size;

	void *userctx;
	char *refname;

	struct _DW_TRIGGER_STATUS_s *status;
	
	char *context;
	char *description;
	char *buildinfo;
	
	char event_type[DW_EVENT_TYPE_LEN+4];
	void *event_properties;
	EVENT_METADATA *event_metadata;
	DW_EVENT *event_handle;
	
	int max_exec_time_warning;
	int has_missing_variables;
	DW_VARIABLE_BLOCK *read_block;
	DW_VARIABLE_BLOCK *write_block;
	
	void *local_variable_btree;
	void *static_variable_btree;
	void *static_variable_rwlock;
	
	int action_unwired_fatal;
	int action_first;
	void *actions;
} _DW_TRIGGER;

typedef struct _DW_TRIGGER_STATUS_s {
	char name[DW_TRIGGER_NAME_LEN+4];
	char project[DW_TRIGGER_NAME_LEN+4];
	char event_type[DW_EVENT_TYPE_LEN+4];
	int id;
	int state;
	int load_state;
	int report_next;
	int err_has_been_logged;
	
	//metadata for list
	long long laststatechange;
	long long lastmodified;
	char *context;
    char *lastuser;

	// moved queue and pending here for hot edit.
	void *mux;
	void *queue;
	int max_pending;

	long long last_fired;
	int count_success;
	int count_pending;
	int count_in_queue;
	int count_failure;
	int count_overflow;
	int exec_time[10];
	unsigned int exec_index;
	int exec_max;
	int exec_min;
	int exec_last;

	int last_error;
	int last_error_count;
	long long last_error_time;
	long long first_error_time;

	int queue_watermark;
	long long queue_watermark_timestamp;
} _DW_TRIGGER_STATUS;

typedef struct {
	int trigger_id;
	_DW_TRIGGER *trigger;
	int   save_report;
	void *report;
	
	int report_mode;
	int report_inherited_mode;
	int report_inheriting_mode;

	void *logger;
	void *mux;
	
	int last_error;
	int exec_error;
	long long execution_timestamp;

	int ref_count;

	void *exec_metadata;
	
	EVENT_NOTIFICATION *notification;
	EVENT_COMPLETION *completion;

	DW_VARIABLE_BLOCK_INSTANCE *read_instance;
	DW_VARIABLE_BLOCK_INSTANCE *write_instance;
	
	DW_VARIABLE_INFO **local_variable_vinfos;
	DW_VARIABLE_DATA **local_variable_vars;
	
	_TRIGGER_ACTION *current_action;
} _TRIGGER_EXECUTION_CONTEXT;

typedef struct {
	_DW_TRIGGER *trigger;
	EVENT_NOTIFICATION *notification;
	EVENT_COMPLETION *completion;
	void *logger;
	DW_EVENT *evt;
} _TRIGGER_QUEUED_ITEM;

long long trigger_hash(const char *project, const char *trigger);

int trigger_check_security(_DW_TRIGGER *trigger,const char *user);

int trigger_load(_DW_TRIGGER *trigger);
int trigger_unload(_DW_TRIGGER *trigger, int final_state);
int trigger_unload_inline(_DW_TRIGGER *trigger, int final_state);

int trigger_set_state(const char *project, const char *name, int state);
int trigger_set_user(const char *project, const char *name, const char *user);
int trigger_get_user(const char *project, const char *name, char **user);
int trigger_set_load_state(const char *project, const char *name, int state);

int trigger_get_avg_exec(const _DW_TRIGGER_STATUS *rtstatus);
_DW_TRIGGER_STATUS *trigger_get_status_object(const char *project, const char *name);
void trigger_clear_rt_status(const char *project, const char *trigger, void *secctx, int op);
int trigger_queue_purge(const char *project, const char *name, void *secctx, int opt);
void trigger_queue_check(_DW_TRIGGER_STATUS *tstatus);

int trigger_xml_to_object(const char *xml, _DW_TRIGGER **trigger, int opts);
int trigger_object_to_xml(_DW_TRIGGER *trigger, char **xml);

void trigger_object_dump(void *logger, int level, _DW_TRIGGER *trigger);

int trigger_sql_to_object(const char *project, const char *name, _DW_TRIGGER **trigger);
int trigger_sql_to_xml(const char *project, const char *name, char **xml);
int trigger_object_to_sql(_DW_TRIGGER *trigger);

int trigger_add_to_memory(DW_TRIGGER *trigger);
int trigger_delete_from_memory(DW_TRIGGER *trigger);
//int trigger_get_from_memory(const char *project, const char *name, DW_TRIGGER **trigger);
//void trigger_unget_from_memory(DW_TRIGGER *trigger);
//void trigger_foreach_in_memory(btree_fefunc func,void *args);

int trigger_macro_get(const char *macro,DW_VARIABLE_DATA *var,_TRIGGER_EXECUTION_CONTEXT *tec);
int trigger_macro_list(char **xml);

int trigger_cmd_list(const char *project, DW_PACKET *packet);
int trigger_cmd_enum(const char *project, const char *type, DW_PACKET *packet);

//trigger reporting
int trigger_report_create(void **report);
int trigger_report_delete(void *report);
int trigger_report_init(void *report, const char *project, const char *trigger, const _TRIGGER_EXECUTION_CONTEXT *tec);
int trigger_report_event_notification(void *report, const char *type, EVENT_NOTIFICATION *notification);
int trigger_report_initial_static_values(void *report, void *static_variable_btree);
int trigger_report_initial_local_values(void *report, void *local_variable_btree);
int trigger_report_static_change(void *report, DW_VARIABLE_DATA *var);
int trigger_report_local_change(void *report, DW_VARIABLE_DATA *var);
int trigger_report_block_pre_read(void *report);
int trigger_report_block_read(void *report, DW_VARIABLE_BLOCK_INSTANCE *instance);
int trigger_report_action_notification(void *report, int id, const char *type, void *properties, ACTION_NOTIFICATION *notification);
int trigger_report_action_completion(void *report, ACTION_COMPLETION *completion);
int trigger_report_block_pre_write(void *report,DW_VARIABLE_BLOCK_INSTANCE *instance);
int trigger_report_block_write(void *report, DW_VARIABLE_BLOCK_INSTANCE *instance);
int trigger_report_event_completion(void *report, EVENT_COMPLETION *completion);
int trigger_report_end(void *report);
int trigger_report_next(const char *project, const char *trigger, int include_subtriggers, void *session);
int trigger_report_list(const char *project, const char *trigger, DW_PACKET *out_pkt);
int trigger_report_get(int id, char **xml, void *session);
int trigger_report_db_delete(const char *project, const char *trigger, int rowid_start, int rowid_end, void *session);
int trigger_report_set_config(const int *max_size, const int *max_sequence, int *max_entries, void *session);
int trigger_report_get_config(int *current_size, int *max_size, int *max_sequence, int *max_entries);

//trigger actions
int trigger_action_create(_TRIGGER_ACTION **action, int id, const char *type);
void trigger_action_delete(_TRIGGER_ACTION *action);
void trigger_action_object_to_xml(const void *item, void *writer);
void trigger_action_dump(const void *item, void *custom);
void trigger_action_item_dump(const void *item, void *custom);
void trigger_action_item_free(void *a);

//trigger events
void trigger_event_callback(DW_EVENT *event, EVENT_NOTIFICATION *notification, void *custom, int pool_id);
void trigger_action_callback(DW_ACTION *action, ACTION_COMPLETION *completion, int pool_id);

//trigger project linkages
int trigger_delete_for_project(const char *project, void *secctx, int op);
int trigger_load_all_for_project(const char *project, void *userctx);
int trigger_unload_all_for_project(const char *project);

int trigger_cmd_processor(	DW_PACKET *in_pkt, 
							const void **in_argv, int *in_lens, int in_argc, 
							DW_PACKET *out_pkt, 
							void *session, void *custom);

#ifdef __cplusplus
}
#endif

#endif /*DW_LOGIC_INTERNAL_TRIGGER_H_*/
