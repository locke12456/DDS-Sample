//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Logic Subsystem
//
//-- Filename: devicewise/logic/trigger.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_LOGIC_TRIGGER_H_
#define DW_LOGIC_TRIGGER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define TRIGGER_CHANNEL_ADDED					1
#define TRIGGER_CHANNEL_DELETED					2
#define TRIGGER_CHANNEL_EDITED					3
#define TRIGGER_CHANNEL_STATE_CHANGED			4
#define TRIGGER_CHANNEL_LOADSTATUS_CHANGED		5

typedef void DW_TRIGGER;

DWLOGIC_EXPORT int trigger_create(DW_TRIGGER **trigger, const char *project, const char *name);
DWLOGIC_EXPORT void trigger_free(DW_TRIGGER *trigger);

DWLOGIC_EXPORT int trigger_get_from_memory(const char *project, const char *name, DW_TRIGGER **trigger);
DWLOGIC_EXPORT void trigger_unget_from_memory(DW_TRIGGER *trigger);
DWLOGIC_EXPORT void trigger_foreach_in_memory(btree_fefunc func,void *args);

DWLOGIC_EXPORT int trigger_add(const char *xml, void *secctx, int op);
DWLOGIC_EXPORT int trigger_edit(const char *xml, void *secctx, int op);
DWLOGIC_EXPORT int trigger_del(const char *project, const char *name, void *secctx, int op);
DWLOGIC_EXPORT int trigger_start(const char *project, const char *name, void *secctx, int op);
DWLOGIC_EXPORT int trigger_stop(const char *project, const char *name, void *secctx, int op);
DWLOGIC_EXPORT int trigger_rename(const char *name, const char *new_name);
DWLOGIC_EXPORT int trigger_copy( const char *src_project, const char *src_name, const char *dst_project, const char *dst_name, void *secctx, int op);
DWLOGIC_EXPORT int trigger_exists(const char *project, const char *name);
DWLOGIC_EXPORT int trigger_get_id(const char *project, const char *name);

DWLOGIC_EXPORT int trigger_list(char **xml);
DWLOGIC_EXPORT int trigger_info(const char *project, const char *name, char **xml);

DWLOGIC_EXPORT int trigger_state(const char *project, const char *name);
DWLOGIC_EXPORT int trigger_load_state(const char *project, const char *name);

DWLOGIC_EXPORT int trigger_exec_suspend(void *secctx, int op);
DWLOGIC_EXPORT int trigger_exec_resume(void *secctx, int op);
DWLOGIC_EXPORT int trigger_exec_is_suspended();
DWLOGIC_EXPORT int trigger_report_suspend(void *userctx);
DWLOGIC_EXPORT int trigger_report_resume(void *userctx);
DWLOGIC_EXPORT int trigger_report_is_suspended();
DWLOGIC_EXPORT int trigger_loader_is_starting();

DWLOGIC_EXPORT int   trigger_tec_add_metadata(void *tec, void *item, btree_free item_free_func, unsigned long long hash);
DWLOGIC_EXPORT int   trigger_tec_del_metadata(void *tec, unsigned long long hash);
DWLOGIC_EXPORT void *trigger_tec_get_metadata(void *tec, unsigned long long hash);

typedef void (*trigger_fire_now_callback)(int result_status, int event_status, void *custom);
DWLOGIC_EXPORT int trigger_fire_now(const char *project_name, const char *trigger_name, trigger_fire_now_callback callback, void *custom );

#ifdef __cplusplus
}
#endif

#endif /*DW_LOGIC_TRIGGER_H_*/
