//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/alert.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_ALERT_H_
#define DW_CORE_ALERT_H_

#ifdef __cplusplus
extern "C" {
#endif

#define ALERT_TYPE_ERROR		0
#define ALERT_TYPE_WARNING		1
#define ALERT_TYPE_INFO			2
#define ALERT_TYPE_DEBUG		3

#define ALERT_TYPE_CLEAR		99

DWCORE_EXPORT int alert_set(const char *key, int state, const char *component, const char *msg);
DWCORE_EXPORT int alert_set_system(const char *key, int state, const char *component, const char *msg);
DWCORE_EXPORT int alert_clear(const char *key);

DWCORE_EXPORT int alert_count(int *most_severe);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_ALERT_H_*/
