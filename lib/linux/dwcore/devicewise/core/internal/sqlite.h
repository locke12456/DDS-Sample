//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/internal/sqlite.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_INTERNAL_SQLITE_H_
#define DW_CORE_INTERNAL_SQLITE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define SQLITE_DB_SYSTEM	1
#define SQLITE_DB_APP		2
#define SQLITE_DB_TRANS		3
#define SQLITE_DB_USER		4
#define SQLITE_DB_LOG		5

DWCORE_EXPORT int sqlite_get_database(int id, void **db);

int sqlite_lock_system_tables();
int sqlite_unlock_system_tables();
const char *sqlite_get_trans_db_path();

#ifdef __cplusplus
}
#endif


#endif /*DW_CORE_INTERNAL_SQLITE_H_*/
