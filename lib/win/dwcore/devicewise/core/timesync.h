//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/timesync.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_TIMESYNC_H_
#define DW_CORE_TIMESYNC_H_

#ifdef __cplusplus
extern "C" {
#endif

DWCORE_EXPORT int timesync_set(const char *xml, void *secctx, int opt);
DWCORE_EXPORT int timesync_get(char **xml);
DWCORE_EXPORT int timesync_now(void *secctx, int opt);

DWCORE_EXPORT int timesync_ntp_get(const char* server,long long *mstime);
DWCORE_EXPORT int timesync_sntp_get(const char* server,long long *mstime);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_TIMESYNC_H_*/
