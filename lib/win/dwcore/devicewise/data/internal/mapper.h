//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/internal/mapper.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_INTERNAL_MAPPER_H_
#define DW_DATA_INTERNAL_MAPPER_H_

#define MAPPER_LICENSE_PRODUCT	2
#define MAPPER_LICENSE_FEATURE	6
#define MAPPER_ATTN_KEY "set_on_map_disable"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	unsigned long long hash;

	int prio;

	int state;
	long long laststatechange;
	int options;

	long long last_fired;
	int status;
	unsigned int count;
	unsigned int failures;
	unsigned int overflows;
	unsigned int count_per_min;
	unsigned int count_per_min_ctr;
	unsigned int write_times[10];

	int write_in_progress;

	char *tags;
	char *description;
	char *user;

	char *src_device;
	DW_DEVICE        *src_dev;
	DW_VARIABLE_DATA src_var;
	DW_SUBSCRIPTION  *src_sub;

	char *dst_device;
	DW_DEVICE        *dst_dev;
	DW_VARIABLE_DATA dst_var;

	void *userctx;

	void *mux;
	
} _DW_MAPPER_ENTRY;

int mapper_update_state(_DW_MAPPER_ENTRY *entry, int new_state);
int mapper_load(_DW_MAPPER_ENTRY *entry);
int mapper_unload(_DW_MAPPER_ENTRY *entry);

int mapper_object_to_xml(const _DW_MAPPER_ENTRY *entry, char **xml);

#ifdef __cplusplus
}
#endif

#endif /*DW_DATA_INTERNAL_MAPPER_H_*/
