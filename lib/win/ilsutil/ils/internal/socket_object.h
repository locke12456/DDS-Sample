//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//-- INTERNAL HEADER, NOT FOR DISTRIBUTION
//
//-- Filename: ils/internal/socket_object.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_INTERNAL_SOCKET_OBJECT_H_
#define ILS_INTERNAL_SOCKET_OBJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
#  define socklen_t int
#endif

#ifdef _WIN32
#  define DTCPBUF 65535
#elif _UNIX
#  if defined(_VXWORKS)
#    define DTCPBUF 8192
#  else
#    define DTCPBUF 65535
#  endif
#endif

#define SOCKET_TYPE_SOCK		1
#define SOCKET_TYPE_LISTENER	2
#define SOCKET_TYPE_MOCK		3

typedef int (*abstract_send)(void *, const char *, int);
typedef int (*abstract_send2)(void *, const char *, int, int);
typedef int (*abstract_recv)(void *, char *, int, int);
typedef int (*abstract_recv2)(void *, char *, int *, int);
typedef int (*abstract_close)(void *);
typedef void (*abstract_log_b)(void *,const char *,int,const char *, const char *, int);
typedef void (*abstract_log_a)(void *,const char *,int,const char *,int, int);

typedef struct {
	// SERVER_SOCKET has to have the same header structure as ABSTRACT_SOCKET
	int s;
	int type;
	int err;
	const char *file;
	int	line;
	void *async_handle;

	char *peer;
	unsigned int peer_addr;
	unsigned short peer_port;

	abstract_send a_send;
	abstract_send2 a_send2;
	abstract_recv a_recv;
	abstract_recv2 a_recv2;
	abstract_close a_close;
	abstract_log_b a_log_b;
	abstract_log_a a_log_a;

	const char *owner;
	unsigned int bytes_in;
	unsigned int bytes_out;
	long long connect_time;
	unsigned int current_send;
	unsigned int current_recv;

	void *handle;
} ABSTRACT_SOCKET;

typedef struct {
	// SERVER_SOCKET has to have the same header structure as ABSTRACT_SOCKET
	int s;
	int type;
	int err;
	const char *file;
	int	line;
	void *async_handle;

	char *laddr;
} SERVER_SOCKET;

#ifdef __cplusplus
}
#endif

#endif /*ILS_INTERNAL_SOCKET_OBJECT_H_*/
