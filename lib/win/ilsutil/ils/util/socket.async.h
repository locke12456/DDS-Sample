//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/socket.async.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_SOCKET_ASYNC_H_
#define ILS_UTIL_SOCKET_ASYNC_H_

#ifdef __cplusplus
extern "C" {
#endif

#define SOCKET_ASYNC_WORKER_NAME_LEN	64

#define SOCKET_ASYNC_CALLBACK_OK			 0
#define SOCKET_ASYNC_CALLBACK_SUSPEND		-1
#define SOCKET_ASYNC_CALLBACK_DEL_ASYNC		-2
#define SOCKET_ASYNC_CALLBACK_DEL_SOCKET	-3

typedef int (*socket_async_callback)(int status, void *socket, void *custom);

UTIL_EXPORT int socket_async_accept_begin(void *server_socket, int timeout, socket_async_callback callback, void *custom);
UTIL_EXPORT int socket_async_accept_end(void *server_socket);
UTIL_EXPORT int socket_async_accept_resume(void *server_socket);
UTIL_EXPORT int socket_async_recv_begin(void *abstract_socket, int timeout, socket_async_callback callback, void *custom);
UTIL_EXPORT int socket_async_recv_end(void *abstract_socket);
UTIL_EXPORT int socket_async_recv_resume(void *abstract_socket);

UTIL_EXPORT int socket_async_default_init(int max_socket, int priority, int timeout);
UTIL_EXPORT int socket_async_default_uninit();

UTIL_EXPORT int socket_async_worker_create(void **handle, const char *name, int max_socket, int priority, int timeout);
UTIL_EXPORT void socket_async_worker_delete(void *handle);
UTIL_EXPORT int socket_async_worker_add_recv(void *handle, void *socket, int timeout, socket_async_callback callback, void *custom);
UTIL_EXPORT int socket_async_worker_add_accept(void *handle, void *server_socket, int timeout, socket_async_callback callback, void *custom);
UTIL_EXPORT int socket_async_worker_remove_recv(void *handle, void *socket);
UTIL_EXPORT int socket_async_worker_remove_accept(void *handle, void *socket);
UTIL_EXPORT int socket_async_worker_resume_recv(void *handle, void *client_socket);
UTIL_EXPORT int socket_async_worker_resume_accept(void *handle, void *server_socket);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_SOCKET_ASYNC_H_*/
