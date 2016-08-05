//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/diskwatch.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_DISKWATCH_H_
#define DW_CORE_DISKWATCH_H_

#ifdef __cplusplus
extern "C" {
#endif

#define DISKWATCH_CODE_NORMAL		0
#define DISKWATCH_CODE_FULL			1
#define DISKWATCH_CODE_RECOVER		2

DWCORE_EXPORT int diskwatch_get(DW_PACKET *pkt);
DWCORE_EXPORT char *diskwatch_get_logical(const char *path);
DWCORE_EXPORT char *diskwatch_get_physical(const char *path);
DWCORE_EXPORT int diskwatch_get_state_by_path(const char *path);
DWCORE_EXPORT int diskwatch_get_state(const char *logical_name);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_DISKWATCH_H_*/
