//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/socket.mock.h
//
//-- Copyright: 2001-2015, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_SOCKET_MOCK_H_
#define ILS_UTIL_SOCKET_MOCK_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void(*socket_mock_send_callback)(const char *data, int data_len, void *a, void *b, void *c);

UTIL_EXPORT int socket_mock_create(void **handle, int buffer_size);
UTIL_EXPORT int socket_mock_recv_fill(void *handle, const char *data, int len);
UTIL_EXPORT void socket_mock_send_setup(void *socket, socket_mock_send_callback callback, void *a, void *b, void *c);
UTIL_EXPORT int socket_mock_delete(void *handle);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_SOCKET_MOCK_H_*/

