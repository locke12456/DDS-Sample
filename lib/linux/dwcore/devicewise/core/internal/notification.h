//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/internal/notification.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_INTERNAL_NOTIFICATION_H_
#define DW_CORE_INTERNAL_NOTIFICATION_H_

#define DW_NOTIFICATION_STARTED		1
#define DW_NOTIFICATION_STOPPED		2
#define DW_NOTIFICATION_DISABLED	3 // Not implemented
#define DW_NOTIFICATION_STARTING	4 // Not implemented
#define DW_NOTIFICATION_STOPPING	5 // Not implemented

#define NOTIFCATION_NAME_LEN	256

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	char name[NOTIFCATION_NAME_LEN+1];
	char *type;
	int logcount;
	char* logquery;
	int interval;
	int elapsed;
	int count;
	
	void *smtp_handle;
	char *from;
	char *to;
	char *cc;
	char *bcc;
	char *subject;
	char *msg;
	char *server;
} _NOTIFICATION_OBJECT;

void _notification_btree_free(void *e);
int _notification_object_to_xml(_NOTIFICATION_OBJECT *no, char **xml);
int _notification_sql_to_object(const char *name, _NOTIFICATION_OBJECT **no);
int _notification_object_to_sql(_NOTIFICATION_OBJECT *no);
int _notification_xml_to_object(const char *xml, _NOTIFICATION_OBJECT **object);

int notification_cmd_list(DW_PACKET *packet);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_INTERNAL_NOTIFICATION_H_*/
