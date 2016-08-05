//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/ftp.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_FTP_H_
#define ILS_UTIL_FTP_H_

#ifdef __cplusplus
extern "C" {
#endif

// CLIENT FUNCTIONS

UTIL_EXPORT int ftp_connect(void **handle, const char *host);
UTIL_EXPORT int ftp_connect2(void **handle, const char *host, int active_mode);
UTIL_EXPORT int ftp_disconnect(void *handle);

UTIL_EXPORT int ftp_login(void *handle, const char *user, const char *pass);

UTIL_EXPORT int ftp_get(void *handle, const char *remote_file, const char *local_file);
UTIL_EXPORT int ftp_put(void *handle, const char *local_file, const char *remote_file);
UTIL_EXPORT int ftp_del(void *handle, const char *remote_file);

// SERVER FUNCTIONS
#define FTP_SERVER_READ_ACCESS		1
#define FTP_SERVER_WRITE_ACCESS		2

typedef int (*ftp_server_auth_callback)(const char *username, const char *password, const char *where);
typedef void (*ftp_server_cmd_callback)(const void *client, const char *cmd, const char *cmdline);
typedef void (*ftp_server_post_cmd_callback)(const void *client, const char *cmd, const char *cmdline, int status);
UTIL_EXPORT const char *ftp_server_client_directory(const void *client);
UTIL_EXPORT const char *ftp_server_client_username(const void *client);
UTIL_EXPORT const char *ftp_server_client_address(const void *client);

UTIL_EXPORT int ftp_server_start(	void **handle, unsigned short port, const char *root_folder, 
									ftp_server_auth_callback auth_callback, ftp_server_cmd_callback pre_cmd_callback, ftp_server_post_cmd_callback post_cmd_callback);
UTIL_EXPORT int ftp_server_set_public_ip(void *handle, const char *public_ip);
UTIL_EXPORT void ftp_server_stop(	void *handle);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_FTP_H_*/
