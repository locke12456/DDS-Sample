//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/notification.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_NOTIFICATION_H_
#define DW_CORE_NOTIFICATION_H_

#ifdef __cplusplus
extern "C" {
#endif

DWCORE_EXPORT int notification_add(const char *xml,void *session);
DWCORE_EXPORT int notification_edit(const char *xml,void *session);
DWCORE_EXPORT int notification_del(const char *name,void *session);
DWCORE_EXPORT int notification_start(const char *name,void *session);
DWCORE_EXPORT int notification_stop(const char *name,void *session);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_NOTIFICATION_H_*/
