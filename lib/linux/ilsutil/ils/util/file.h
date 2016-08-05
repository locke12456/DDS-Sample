//----------------------------------------------------------------
//
//-- Filename: ils/util/file.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_FILE_H_
#define ILS_UTIL_FILE_H_

#ifdef __cplusplus
extern "C" {
#endif
	
#define FILE_MODE_READ		1
#define FILE_MODE_WRITE		2
#define FILE_MODE_EXE		4
	
UTIL_EXPORT int file_chmod(const char *src, int mode);
UTIL_EXPORT int file_move(const char *src, const char *dst);
UTIL_EXPORT int file_copy(const char *src, const char *dst);
UTIL_EXPORT int file_delete(const char *src);

UTIL_EXPORT void file_roll(const char *filename, int max);
UTIL_EXPORT int file_lock(const char *filename, int *id);
UTIL_EXPORT int file_unlock(const char *filename, int id);

UTIL_EXPORT int file_is_valid_name(const char *name, int allow_transversal);
UTIL_EXPORT char *file_path_normalize(char *path);
UTIL_EXPORT char *file_absolute_path(const char *path);

UTIL_EXPORT int filestream_open(void **handle, const char *filename);
UTIL_EXPORT int filestream_read(void *handle, char *ch);
UTIL_EXPORT int filestream_close(void *handle);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_FILE_H_*/
