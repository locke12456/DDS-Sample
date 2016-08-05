//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/internal/vargroup.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_INTERNAL_VARGROUP_H_
#define DW_DATA_INTERNAL_VARGROUP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <devicewise/core/core.h>
#include <devicewise/data/smart.h>

#define DW_VARGROUP_NAME_LEN		64

#define DW_VARGROUP_STARTED			1
#define DW_VARGROUP_STOPPED			2

#define DW_VARITEM_ACTIVE			1
#define DW_VARITEM_LOADING			2
#define DW_VARITEM_DISABLED			3
#define DW_VARITEM_INACTIVE			4
#define DW_VARITEM_DELETING			5

typedef struct {
//		Definition Values
	char name[DW_VARGROUP_NAME_LEN+4];
	int prio;
	DW_VARIABLE_INFO *vinfo;
	void *mux;					// item mux
	void *rwlock;				// subscription rwlock
	void *subscriptions;
	void *varlist;

//		Database Values
	int state;
	char *user;
	long long last_modified;
	long long last_state_changed;

//		Runtime Values
	int id;
	int inactive_count;
	void *userctx;
	long long last_updated;
} _DW_VARGROUP_ENTRY;

typedef struct {
	char var_name[DW_VARIABLE_NAME_LEN+4];
	char dev_name[DW_DEVICE_NAME_LEN+4];
	int state;
	int last_error;
	int bitno;

	DW_DEVICE *dev;
	void *sub;
	_DW_VARGROUP_ENTRY *entry;
} _DW_VARGROUP_ITEM;

typedef struct {
	_DW_VARGROUP_ENTRY *entry;
	_vargroup_publish callback;
	void *custom;
} _DW_VARGROUP_SUB;

int _vargroup_import(const char *item, const char *xml, void *secctx, int opt);
int _vargroup_verify(const char *item, void *secctx, int opt);
int _vargroup_export(const char *item, char **xml, void *secctx, int opt);

int vargroup_validate(_DW_VARGROUP_ENTRY *vargroup, void *secctx, int opt);
int vargroup_add(_DW_VARGROUP_ENTRY *vargroup, void *secctx, int opt);
int vargroup_edit(_DW_VARGROUP_ENTRY *vargroup, void *secctx, int opt);
int vargroup_del(const char *vargroup_name, void *secctx, int opt);
int vargroup_start(const char *vargroup_name, void *secctx, int opt);
int vargroup_stop(const char *vargroup_name, void *secctx, int opt);
int vargroup_clr_err(const char *vargroup_name, void *secctx, int opt);

void vargroup_free(_DW_VARGROUP_ENTRY *entry);
void _vargroup_free(_DW_VARGROUP_ENTRY *entry);
void vargroup_item_free(_DW_VARGROUP_ITEM *item);

int vargroup_item_load(_DW_VARGROUP_ITEM *item);
int vargroup_load_all_disabled();
void vargroup_pool_loader(int id, void *a, void *b, void *c);
void vargroup_retry_inactives(int id, void *a, void *b, void *c);

int vargroup_object_to_xml(const _DW_VARGROUP_ENTRY *entry, char **xml);
int vargroup_xml_to_object(const char *xml, _DW_VARGROUP_ENTRY **entry);
int vargroup_object_to_sql(const _DW_VARGROUP_ENTRY *entry);
int vargroup_get_xml(const char *vargroup_name, char **xml);
int vargroup_sql_del(const char *vargroup_name);
int vargroup_state_update(_DW_VARGROUP_ENTRY *entry, int new_state);

#ifdef __cplusplus
}
#endif

#endif /*DW_DATA_INTERNAL_VARGROUP_H_*/
