//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/internal/scheduler.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_INTERNAL_SCHEDULE_H_
#define DW_CORE_INTERNAL_SCHEDULE_H_

#define SCHEDULE_CYCLE_PERIOD		100
#define SCHEDULE_TYPE_PERIODIC		1
#define SCHEDULE_TYPE_TIMEBASED		2

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	char *xml;
	int type;
	pool_callback callback;
	void *arg0;
	void *arg1;
	void *arg2;
//-----used by timebased -----//	
	int month;
	int day;
	int wday;
	int occurence;
	int special;
	int *sec;
	int sec_count;
	time_t exec_time;
	long long exec_time_ms;
	int is_alive;
//-----used by periodic -----//	
	int preset;
	int count;
	void *child;
	void **reverse_ptr;
} _SCHEDULE_OBJECT;

int _schedule_xmlparser_parse(void **schedule_object, const char* xml);
void _schedule_calculation_timebased(_SCHEDULE_OBJECT* schedule_object, time_t ctm);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_INTERNAL_SCHEDULE_H_*/
