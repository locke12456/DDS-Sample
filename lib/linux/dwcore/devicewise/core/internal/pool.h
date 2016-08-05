//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/internal/pool.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_INTERNAL_FILESYSTEM_H_
#define DW_CORE_INTERNAL_FILESYSTEM_H_

typedef struct {
	long long next_exec_time;
	pool_callback pc;
	void *a;
	void *b;
	void *c;
	int interval;
	char who[64];
	int is_pending;
} _POOL_WORK_ITEM;

typedef struct {
	int id;
	_POOL_WORK_ITEM *current_item;
	char what[64];
	char where[128];
} _POOL_WORKER_OBJECT;

typedef struct {
	void *work_queue;
	int max_work_items;
	int cur_work_items;
	int queued_work_items;
	int has_logged_warning;
	char who[64 + 1];
} _POOL_LIMITER_OBJECT;

#endif /*DW_CORE_INTERNAL_PLUGIN_H_*/
