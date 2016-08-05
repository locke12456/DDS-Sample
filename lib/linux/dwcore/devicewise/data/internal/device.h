//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/internal/device.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_INTERNAL_DEVICE_H_
#define DW_DATA_INTERNAL_DEVICE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define DEVICE_LIC_PRODUCT	4
#define DEVICE_LIC_FEATURE	16
#define DEVICE_LIC_ALL_PRODUCT	4
#define DEVICE_LIC_ALL_FEATURE	5

typedef struct {
	int id;
	char *type;
	int type_nlsid;
	char *family;
	int family_nlsid;
	char *category;
	int category_nlsid;
	short lic_prod;
	short lic_feature;
	int options;
	int display_order;
	char *xml;
	void *propdescs;
	char types[32][DW_DEVICE_TYPE_TYPE_LEN+4];
	DW_DRIVER *driver;
} DW_DEVICE_TYPE;

typedef struct {
	char *variable;
	long long first_timestamp;
	long long last_timestamp;
	int status;
	int exstatus;
	int repeat_count;
} _DEVICE_ERROR;

typedef struct {
	int status;
	int exstatus;
	int err_repeated;
	int work_queue_depth;
	int total_work_queue_items;
	int work_queue_times[10];
	long long last_error_time;
	long long last_read_time;
	int read_times[10];
	int total_reads;
	long long last_write_time;
	int write_times[10];
	int total_writes;
	int start_time;
	int stop_time;
	void *err_list;
} _DW_DEVICE_RTSTATUS;

typedef struct {
	DW_DEVICE base;
	int state;
	int options;
	int error_history_count;
	int error_log_all;
	int ref_count;
	long long last_modified;
	long long last_state_change;
	_DW_DEVICE_RTSTATUS *rtstatus;
	char *desc;
	void *driver;
	void *lock;
	void *var_list;
	void *struct_list;
	void *cmd_list;
	void *prop_btree;
	void *attrib_btree;
	void *mapped_desc_btree;
	char *model_xml_cache;
	void *work_queue;
	int   work_queue_dwell_time;
	int   work_in_progress;
	void *work_in_progress_mux;
} _DW_DEVICE;

typedef struct {
	char *name;
	char *value;
} _DEVICE_PROPERTY;

typedef struct {
	char *name;
	char *desc;
} _DEVICE_DESCRIPTION;

#define DEVICE_ATTR_STATIC	1
#define DEVICE_ATTR_DYN_STR	2
#define DEVICE_ATTR_DYN_INT	3
typedef struct {
	char name[DW_DEVICE_ATTRIB_LEN+4];
	int name_nls;
	int type;
	char  value[DW_DEVICE_ATTRIB_LEN+4];
	const char *value_str;
	const int  *value_int;
} _DEVICE_ATTRIBUTE;

void device_init();

int device_clear_definition(DW_DEVICE *dev);
int device_clr_status(DW_DEVICE *dev);

int device_audit_log_diffs(_DW_DEVICE *new_dev,_DW_DEVICE *old_dev, void *session);

int device_xml_to_object(const char *xml, DW_DEVICE **def);
int device_object_to_xml(DW_DEVICE *def, char **xml, int options);

int device_sql_to_object(const char *name, DW_DEVICE **def);
int device_object_to_sql(DW_DEVICE *def);
int device_sql_copy(const char *old_dev,const char *new_dev);

void device_object_dump(void *logger, int level, DW_DEVICE *def);

int device_cmd_list(DW_PACKET *packet);

DWDATA_EXPORT int device_type_get_object(int id, DW_DEVICE_TYPE **type);

long long device_error_hash(const void *a);

void device_memory_add(_DW_DEVICE *dev);
void device_memory_remove(_DW_DEVICE *dev);

#ifdef __cplusplus
}
#endif

#endif /*DW_INTERNAL_DEVICE_H_*/
