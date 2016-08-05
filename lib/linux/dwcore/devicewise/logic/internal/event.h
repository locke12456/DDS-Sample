//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Logic Subsystem
//
//-- Filename: devicewise/logic/internal/event.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_LOGIC_INTERNAL_EVENT_H_
#define DW_LOGIC_INTERNAL_EVENT_H_

#ifdef __cplusplus
extern "C" {
#endif

#define DW_EVENT_TYPE_LEN	64
#define DW_EVENT_OPT_DEAD	1

typedef struct {
	char type[DW_EVENT_TYPE_LEN+4];
	char name[DW_EVENT_TYPE_LEN+4];
	char group[DW_EVENT_TYPE_LEN+4];
	int name_nls;
	int desc_nls;
	int group_nls;
	void *propdescs;
	void *mux;
	int ref_count;
	char *overview_format;
	char *overview_args[5];
	event_create_callback create;
	event_signal_callback signal;
	event_verify_callback verify;
	event_complete_callback complete;
	event_query_metadata_callback query_metadata;
	void *context;
	int options;
} _EVENT_TYPE;

typedef struct {
	void *handle;
	int id;
	_EVENT_TYPE *type;
	void *userctx;
	event_callback callback;
	void *custom;
} _EVENT;

#ifdef __cplusplus
}
#endif

#endif /*DW_LOGIC_INTERNAL_EVENT_H_*/
