//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/sqlite.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_SQLITE_H_
#define DW_CORE_SQLITE_H_

#ifdef __cplusplus
extern "C" {
#endif
	
DWCORE_EXPORT int sqlite_exec_multi(void *db1, void *db2, const char *fmt, ...);
DWCORE_EXPORT int sqlite_append_table(void *src, const char *src_table, void *dst, const char *dst_table);
	
#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_SQLITE_H_*/
