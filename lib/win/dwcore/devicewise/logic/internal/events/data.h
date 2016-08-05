//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/logic/internal/events/data.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_LOGIC_INTERNAL_EVENTS_DATA_H_
#define DW_LOGIC_INTERNAL_EVENTS_DATA_H_

#include <devicewise/logic/event.h>

#define DATAEVENT_ONCHANGE				0
#define DATAEVENT_EQUAL_TO				1
#define DATAEVENT_LESS_THAN				2
#define DATAEVENT_GREATER_THAN			3
#define DATAEVENT_LESS_THAN_EQUAL		4
#define DATAEVENT_GREATER_THAN_EQUAL	5


#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	int	event_type;
	int data_type;
	int size;
	int value_strlen;

	void *tolerance;
	void *deadband;
	void *value;
	void *lastvalue;

	int qos;

	char on_edge;
	char in_condition;
	char has_never_fired;
	char fire_on_start;
	char is_alive;

	long long lasttime;

	DW_SUBSCRIPTION  *sub;
	DW_DEVICE        *dev;
	DW_VARIABLE_DATA *var;

	DW_DEVICE        *cond_dev;
	DW_VARIABLE_DATA *cond_var;

	DW_DEVICE        *deadband_dev;
	DW_VARIABLE_DATA *deadband_var;

	DW_DEVICE        *tolerance_dev;
	DW_VARIABLE_DATA *tolerance_var;

} _DATAEVENT_OBJECT;

int _dataevent_parse_xml(const char *xml, _DATAEVENT_OBJECT **event);
int _dataevent_verify_xml(const char *xml, void *reference_list);

#ifdef __cplusplus
}
#endif

#endif /*DW_LOGIC_INTERNAL_EVENTS_DATA_H_*/
