//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/syslog.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_SYSLOG_H_
#define ILS_UTIL_SYSLOG_H_

#ifdef __cplusplus
extern "C" {
#endif

#define SYSLOG_LVL_EMERG	0
#define SYSLOG_LVL_ALERT	1
#define SYSLOG_LVL_CRIT		2
#define SYSLOG_LVL_ERR		3
#define SYSLOG_LVL_WARN		4
#define SYSLOG_LVL_NOTICE	5
#define SYSLOG_LVL_INFO		6
#define SYSLOG_LVL_DEBUG	7

#define SYSLOG_FAC_KERN		0
#define SYSLOG_FAC_USER		1

#define SYSLOG_PORT_DEFAULT		514

UTIL_EXPORT int syslog_remote(const char *server, int facility, int level, const char *message);
UTIL_EXPORT int syslog_remote_ex(const char *server, int facility, int level, long long timestamp, const char *hostname, const char *message);

//UTIL_EXPORT int syslog_local(int level, const char *message);

typedef void (*syslog_on_recv_callback)(int facility, int level, long long timestamp, const char *hostname, const char *message, void *custom);

UTIL_EXPORT int syslog_collector_create(void **handle, int port, syslog_on_recv_callback callback, void *custom);
UTIL_EXPORT int syslog_collector_delete(void *handle);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_SYSLOG_H_*/
