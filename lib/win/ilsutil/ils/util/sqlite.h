//----------------------------------------------------------------
//
//-- Filename: ils/util/sqlite.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_SQLITE_H_
#define ILS_UTIL_SQLITE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	char **results;
	int nrows;
	int ncols;
} SQLITE_RESULT;

typedef struct {
	char *id;
	char *name;
	char *type;
	char *opts;
	int index;
	int all_column_count;
} _AUTOINC;

typedef int (*sqlite_callback)(void *custom, int ncols, char** colnames, char **values);
typedef void (*sqlite_log_func)(const char *sql_stmt, void *custom);

UTIL_EXPORT int sqlite_init();
UTIL_EXPORT const char *sqlite_get_version();

UTIL_EXPORT int sqlite_create(void **handle);
UTIL_EXPORT int sqlite_delete(void *handle);
UTIL_EXPORT int sqlite_open(void *handle, const char *dbname);
UTIL_EXPORT int sqlite_set_log_callback(void *handle, sqlite_log_func func, void *custom);

UTIL_EXPORT const char *sqlite_error(void *handle);
UTIL_EXPORT int sqlite_error_code(void *handle);

UTIL_EXPORT int sqlite_exec(void *handle, const char *fmt, ...);
UTIL_EXPORT int sqlite_exec_ex(void *handle, sqlite_callback callback, void *custom, const char *fmt, ...);
UTIL_EXPORT int sqlite_exec_args(void *handle, const char *fmt, va_list args);
UTIL_EXPORT SQLITE_RESULT *sqlite_select(void *handle, const char *fmt, ...);
UTIL_EXPORT int sqlite_result_count(void *handle);

UTIL_EXPORT const char *sqlite_column(SQLITE_RESULT *rslt, int c);
UTIL_EXPORT const char *sqlite_element(SQLITE_RESULT *rslt, int r, int c);
UTIL_EXPORT void sqlite_free(SQLITE_RESULT *rslt);
UTIL_EXPORT int sqlite_transaction_begin(void *handle);
UTIL_EXPORT int sqlite_transaction_end(void *handle);

//UTIL_EXPORT int sqlite_to_csv(SQLITE_RESULT *rslt, const char *filename);
UTIL_EXPORT int sqlite_to_csv(	void *handle, const char *tablename, int maxrows, int write_header, char delim, char qualifier, const char *filename, 
								int *success, int *error, int *first_rowid, int *last_rowid);
UTIL_EXPORT int sqlite_from_csv(void *handle, const char *tablename, int first_row_is_header, char delim, char qualifier, const char *filename, int *success, int *error);
UTIL_EXPORT int sqlite_backup(void *handle, const char *filename);

UTIL_EXPORT long long sqlite_get_usage();
UTIL_EXPORT long long sqlite_get_watermark();

UTIL_EXPORT int sqlite_table_column_autoincrement(void *handle, const char *tablename, _AUTOINC *autocol);
#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_SQLITE_H_*/
