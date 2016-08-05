//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/filesystem.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_FILESYSTEM_H_
#define DW_CORE_FILESYSTEM_H_

#ifdef __cplusplus
extern "C" {
#endif

#define CHANNEL_FTPSERVER_PRE_ACTIVITY		1
#define CHANNEL_FTPSERVER_POST_ACTIVITY		2

DWCORE_EXPORT int filesystem_del(const char* filename);
DWCORE_EXPORT int filesystem_move(const char* filename, const char* destination);
DWCORE_EXPORT int filesystem_copy(const char* filename, const char* destination);

DWCORE_EXPORT char *filesystem_absolute_path(const char *path);
DWCORE_EXPORT char *filesystem_staging_get_path(const char *path);
DWCORE_EXPORT const char *filesystem_staging_get_location();

DWCORE_EXPORT int filesystem_staging_copy(const char *source, const char *dest);
DWCORE_EXPORT int filesystem_staging_move(const char* source, const char* dest);
DWCORE_EXPORT int filesystem_staging_del(const char *filename);
DWCORE_EXPORT int filesystem_staging_full();

DWCORE_EXPORT int filesystem_staging_create_directory(const char *dirname);
DWCORE_EXPORT int filesystem_staging_del_directory(const char *dirname);

DWCORE_EXPORT int filesystem_get_temp_file(char **name);
DWCORE_EXPORT int filesystem_release_temp_file(char *name);

DWCORE_EXPORT int filesystem_normalize(char *path);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_FILESYSTEM_H_*/
