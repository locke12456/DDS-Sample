//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/socket.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_SOCKET_H_
#define ILS_UTIL_SOCKET_H_

#ifdef __cplusplus
extern "C" {
#endif
/// \file socket.h
/// Contains TCP socket functions that are implemented in a platform neutral manner. Writing code to these socket functions ensures that the behavior is consistent across any platform.
///

/// Function to create a TCP socket and bind the socket to a local address. The socket will listen for an incoming connection.
///
/// \param server_handle a pointer to a void pointer. Will be NULL when the function is called, will contain a handle to a listener socket upon successful completion.
/// \param addr a constant character pointer, the value of which is a local IP address to bind the listener socket to. A typical entry would be "0.0.0.0:n", where n is the port on the local machine to bind to the socket.
/// \return 0 if successful, otherwise an error code defined within the errors.h file
/// \sa errors.h
UTIL_EXPORT int _socket_listen(void **server_handle, const char *addr, const char *file, int line);
#define socket_listen(handle,addr) _socket_listen((handle),(addr), __FILE__, __LINE__)

/// Function to close the listener socket and free the memory allocated to the socket
///
/// \param server_handle a handle to a TCP socket, created by the socket_listen() function
/// \return 0 if successful, otherwise an error code defined in the errors.h file
/// \sa errors.h
UTIL_EXPORT int socket_unlisten(void *server_handle);

/// Function to permit an incoming connection connection attempt on the listener socket
///
/// \param server_handle a handle to a TCP socket, created by the socket_listen() function
/// \param timeout is an integer value that corresponds to a millisecond value of the maximum time the socket will wait for an incoming connection request. The timeout value is vital in preventing a thread from being blocked indefinitely waiting for an incoming connection. A typical strategy is to issue the socket_accept call and to loop back and try again if the function fails with a ERR_SOCK_TIMEOUT error.
/// \return 0 if successful, -7205 (ERR_SOCK_TIMEOUT) if the request timed out, otherwise an error code defined in the errors.h file.
/// \sa errors.h
UTIL_EXPORT void *socket_accept(void *server_handle, int timeout);

/// Function to permit an incoming connection connection attempt on the listener socket (with extended options)
///
/// \param server_handle a handle to a TCP socket, created by the socket_listen() function
/// \param timeout is an integer value that corresponds to a millisecond value of the maximum time the socket will wait for an incoming connection request. The timeout value is vital in preventing a thread from being blocked indefinitely waiting for an incoming connection. A typical strategy is to issue the socket_accept call and to loop back and try again if the function fails with a ERR_SOCK_TIMEOUT error.
/// \param options is a bitmask of options on the accept.
/// \return 0 if successful, -7205 (ERR_SOCK_TIMEOUT) if the request timed out, otherwise an error code defined in the errors.h file.
/// \sa errors.h
UTIL_EXPORT void *socket_accept_ex(void *server_handle, int timeout, int options);

UTIL_EXPORT int socket_select(int maxfd, void *rd_set, void *wr_set, void *ex_set, int timeout);

/// Function to create a TCP socket
///
/// \param handle a pointer to a void pointer. Will be NULL when the function is called, will contain a handle to a socket upon successful completion.
/// \return 0 if successful, otherwise an error code defined within the errors.h file
/// \sa errors.h
UTIL_EXPORT int _socket_create(void **handle, const char *file, int line);
#define socket_create(handle) _socket_create((handle), __FILE__, __LINE__)

/// Function to close an open TCP socket and release the memory allocated to it.
///
/// \param handle a void pointer containing the socket handle created by the socket_create() function.
/// \return 0 if successful, otherwise an error code defined within the errors.h file
/// \sa errors.h
UTIL_EXPORT int socket_delete(void *handle);

/// Function to open a TCP socket connection with a remote address.
///
/// \param handle a void pointer containing the socket handle created by the socket_create() function.
/// \param addr a constant character pointer, containing the IP address to the device we are establishing connection with.
/// \return 0 if successful, -7205 (ERR_SOCK_TIMEOUT) if the connection cannot be made within 5 seconds, otherwise an error code defined within the errors.h file
/// \sa errors.h
UTIL_EXPORT int socket_connect(void *handle, const char *addr);

/// Function to open a TCP socket connection with a remote address.
///
/// \param handle a void pointer containing the socket handle created by the socket_create() function.
/// \param addr a constant character pointer, containing the IP address to the device we are establishing connection with.
/// \param timeout an integer value representing the millisecond value the socket_connect function will wait in its attempt to establish a connection.
/// \return 0 if successful, -7205 (ERR_SOCK_TIMEOUT) if the connection cannot be made within the time specified by the timeout variable, otherwise an error code defined within the errors.h file
/// \sa errors.h
UTIL_EXPORT int socket_connect_ex(void *handle, const char *addr, int timeout);

#define SOCKET_USE_NODELAY				1
#define SOCKET_DONT_SET_QUEUE_SIZES		2
/// Function to open a TCP socket connection with a remote address.
///
/// \param handle a void pointer containing the socket handle created by the socket_create() function.
/// \param addr a constant character pointer, containing the IP address to the device we are establishing connection with.
/// \param timeout an integer value representing the millisecond value the socket_connect function will wait in its attempt to establish a connection.
/// \param options is an integer bitmask with various codes to create specific behavior.
/// \return 0 if successful, -7205 (ERR_SOCK_TIMEOUT) if the connection cannot be made within the time specified by the timeout variable, otherwise an error code defined within the errors.h file
/// \sa errors.h
UTIL_EXPORT int socket_connect_ex2(void *handle, const char *addr, int timeout, int options);

/// Function to re-establish a TCP socket connection with a remote address.
///
/// \param handle a void pointer containing the socket handle created by the socket_create() function.
/// \return 0 if successful, -7205 (ERR_SOCK_TIMEOUT) if the connection cannot be made within 5 seconds, otherwise an error code defined within the errors.h file
/// \sa errors.h
UTIL_EXPORT int socket_reconnect(void *handle);

/// Function to send a stream of data of size len, across a TCP socket connection.
///
/// \param handle a void pointer containing the socket handle created by the socket_create() function.
/// \param data a constant character pointer to a buffer containing the data to be sent.
/// \param len an integer value of the number of bytes in the buffer that are to be sent.
/// \return a positive number indicating the number of bytes of data that was successfully sent or an error code defined within the errors.h file
/// \sa errors.h
UTIL_EXPORT int socket_send(void *handle, const char *data, int len);

/// Function to send a stream of data of size len, across a TCP socket connection.
///
/// \param handle a void pointer containing the socket handle created by the socket_create() function.
/// \param data a constant character pointer to a buffer containing the data to be sent.
/// \param len an integer value of the number of bytes in the buffer that are to be sent.
/// \param timeout an integer value representing the millisecond value the socket_send function will wait to determine if the send was successful.
/// \return a positive number indicating the number of bytes of data that was successfully sent, -7205 (ERR_SOCK_TIMEOUT) if the send request did not receive a response within the time specified by the timeout variable, otherwise an error code defined within the errors.h file
/// \sa errors.h
UTIL_EXPORT int socket_send2(void *handle, const char *data, int len, int timeout);

/// Function to receive a stream of data of size len, from a TCP socket connection.
///
/// \param handle a void pointer containing the socket handle created by the socket_create() function.
/// \param data a constant character pointer to a buffer that will receive the data being sent.
/// \param len an integer value of the maximum number of bytes to be received and stored in the buffer.
/// \param timeout an integer value representing the millisecond value the socket_receive function will wait to receive data.
/// \return a positive number indicating the number of bytes of data that was successfully received, -7205 (ERR_SOCK_TIMEOUT) if the the request did not receive any data within the time specified by the timeout variable, or an error code defined within the errors.h file
/// \sa errors.h
UTIL_EXPORT int socket_recv(void *handle, char *data, int len, int timeout);

/// Function to receive a stream of data of an unknown size from a TCP socket connection.
///
/// \param handle a void pointer containing the socket handle created by the socket_create() function.
/// \param data a constant character pointer to a buffer that will receive the data being sent.
/// \param len a pointer to integer. The pointer will be updated with the number of bytes that were received and stored in the buffer.
/// \param timeout an integer value representing the millisecond value the socket_receive function will wait to receive data.
/// \return a positive number indicating the number of bytes of data that was successfully received, -7205 (ERR_SOCK_TIMEOUT) if the the request did not receive any data within the time specified by the timeout variable, or an error code defined within the errors.h file
/// \sa errors.h
UTIL_EXPORT int socket_recv2(void *handle, char *data, int *len, int timeout);

/// Function to return the IP address of a TCP socket connection. Typically used when determining the IP address of a connection that has been accepted.
///
/// \param handle a void pointer containing the socket handle created by the socket_listen() function.
/// \return a constant character pointer of the IP address of the peer device attempting to establish a connection.
UTIL_EXPORT const char *socket_peer(const void *handle);

/// Function to return the IP address of a TCP socket connection. Typically used when determining the IP address of a connection that has been accepted.
///
/// \param handle a void pointer containing the socket handle created by the socket_listen() function.
/// \return an unsigned integer representation of the IP address of the peer device attempting to establish a connection.
UTIL_EXPORT unsigned int socket_peer_address(const void *handle);

/// Function to return the port number of a TCP socket connection. Typically used when determining the port of a connection that has been accepted.
///
/// \param handle a void pointer containing the socket handle created by the socket_listen() function.
/// \return an unsigned short representing the port number of the peer device attempting to establish a connection.
UTIL_EXPORT unsigned short socket_peer_port(const void *handle);

/// Function to return the local name for a TCP socket.
///
/// \param handle a void pointer containing the socket handle created by the socket_listen() function.
/// \param local_address pointer to a character pointer that will contain the IP address of the local TCP socket.
/// \return a 0 if successful or an error code defined within the errors.h file
/// \sa errors.h
UTIL_EXPORT int socket_local_address(void *handle, char **local_address);

/// Function to return the socket descriptor for a TCP socket.
///
/// \param handle a void pointer containing the socket handle created by the socket_listen() function.
/// \return a positive integer value if successful or an error code defined within the errors.h file
/// \sa errors.h
UTIL_EXPORT int socket_descriptor(const void *handle);

/// Function to return the status of a TCP connection.
///
/// \param handle a void pointer containing the socket handle created by the socket_listen() function.
/// \return 1 if the connection is open, 0 if it is not open
/// \sa errors.h
UTIL_EXPORT int socket_isopen(const void *handle);

/// Function to set the TCP send and receive queues for the socket (SO_SNDBUF & SO_RCVBUF).
///
/// \param handle a void pointer containing the socket handle.
/// \param send_queue new value for the size of the send queue (SO_SNDBUF), set to -1 to make no changes.
/// \param recv_queue new value for the size of the receive queue (SO_RCVBUF), set to -1 to make no changes.
/// \return a 0 if successful or an error code defined within the errors.h file
/// \sa errors.h
UTIL_EXPORT int socket_set_io_queues(void *handle, int send_queue, int recv_queue);

/// Function to disable the sends and receives on a TCP socket. There is no way to re-enable sends and receives on a socket once it has been shutdown.
///
/// \param handle a void pointer containing the socket handle created by the socket_listen() function.
/// \return a 0 if successful or an error code defined within the errors.h file
/// \sa errors.h
UTIL_EXPORT int socket_shutdown(void *handle);

/// Function to close a TCP socket. It is up to the user to subsequently free the memory allocated to this socket.
///
/// \param handle a void pointer containing the socket handle created by the socket_listen() function.
/// \return a 0 if successful or an error code defined within the errors.h file
/// \sa errors.h
UTIL_EXPORT int socket_close(void *handle);

/// Function to return the platform specific TCP error code.
///
/// \param handle a void pointer containing the socket handle created by the socket_listen() function.
/// \return a numeric error code. Consult the platform specific TCP documentation for the error code's meaning.
UTIL_EXPORT int socket_error(const void *handle);

/// Function to return the standard host name for the local device.
///
/// \return a constant character pointer containing the host name value.
UTIL_EXPORT const char *socket_get_hostname();

#define SOCKET_PROXY_SOCKS4		1
#define SOCKET_PROXY_SOCKS4A	2
#define SOCKET_PROXY_SOCKS5		3
#define SOCKET_PROXY_HTTP		4

typedef struct {
	int type;
	char *addr;
	char *user;
	char *pass;
} SOCKET_PROXY_INFO;

UTIL_EXPORT int socket_connect_thru_proxy(void *handle, SOCKET_PROXY_INFO *info, const char *addr, int timeout);

UTIL_EXPORT int socket_check_queues(const void *handle, int *recvq, int *sendq);

typedef void (*socket_log_buffer)(void *,const char *, int,const char *, const char *, int);
typedef void (*socket_log_result)(void *,const char *, int,const char *,int, int);
UTIL_EXPORT int socket_set_log_callbacks(void *socket, socket_log_buffer lb, socket_log_result lr);
UTIL_EXPORT int socket_set_owner(void *socket, const char *owner);
UTIL_EXPORT const char *socket_get_owner(const void *socket);
UTIL_EXPORT int socket_get_statistics(const void *socket, long long *connect_time, unsigned int *bytes_in, unsigned int *bytes_out);
typedef void (*socket_fefunc)(const void *socket,void *args);
UTIL_EXPORT void socket_foreach(socket_fefunc func, void *custom);
UTIL_EXPORT int socket_get_fd_setsize();
UTIL_EXPORT void *socket_instrument_handle();

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_SOCKET_H_*/
