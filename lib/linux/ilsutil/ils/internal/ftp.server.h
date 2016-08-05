//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//-- INTERNAL HEADER, NOT FOR DISTRIBUTION
//
//-- Filename: ils/internal/ftp.server.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_INTERNAL_FTP_SERVER_H_
#define ILS_INTERNAL_FTP_SERVER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define FTP_CLIENTNAME_LEN		128
#define FTP_CMDNAME_LEN			128
#define FTP_ADDR_LEN			32
#define FTP_MAX_BAD_COMMAND		5

typedef int (*ftp_server_exec_callback)(void *client_object, const char *cmd, const char *args);

typedef struct {
	char name[FTP_CMDNAME_LEN+4];
	ftp_server_exec_callback exec_callback;
} _FTP_COMMAND;

typedef struct {
	char *public_ip;
	unsigned short port;
	void *socket;
	void *session_btree;
	int timeout;
	int ref_count;
	char *root_folder;
	char *root_folder_abs;
	ftp_server_auth_callback auth_callback;
	ftp_server_cmd_callback pre_cmd_callback;
	ftp_server_post_cmd_callback post_cmd_callback;
	int stop_now;
	void *mutex;
	void *socket_async_ftp_server_worker;
} _FTP_SERVER_OBJECT;

typedef struct {
	char remote_addr[FTP_ADDR_LEN+4];
	char username[FTP_CLIENTNAME_LEN+4];
	void *socket;
	_FTP_SERVER_OBJECT *server;

	char *directory;
	int is_authenticated;
	int rest_point;

	char *rename_from;

	//  data connection
	int data_state;
	int data_passive_mode;
	void *data_socket;
	void *data_connection_socket;
	int data_ascii_mode;
	int data_appe_mode;

	int bad_command;
} _FTP_CLIENT_OBJECT;

#ifdef __cplusplus
}
#endif

#endif /*ILS_INTERNAL_FTP_SERVER_H_*/
