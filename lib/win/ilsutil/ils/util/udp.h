//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/udp.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_UDP_H_
#define ILS_UTIL_UDP_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int udp_create(void **handle);
UTIL_EXPORT int udp_delete(void *handle);

UTIL_EXPORT int udp_open(void *handle);
UTIL_EXPORT int udp_bind(void *handle, const char *addr);
UTIL_EXPORT int udp_close(void *handle);

UTIL_EXPORT int udp_enable_broadcast(void *handle);

UTIL_EXPORT int udp_send(void *handle, const char *data, int len, const char *addr);

UTIL_EXPORT int udp_recv(void *handle, char *data, int *len, char **addr);
UTIL_EXPORT int udp_recv2(void *handle, char *data, int *len, char **addr, int timeout);
UTIL_EXPORT int udp_peek(void *handle, char *data, int *len, char **addr);

UTIL_EXPORT int udp_descriptor(void *handle);
UTIL_EXPORT int udp_isopen(void *handle);
UTIL_EXPORT int udp_error(void *handle);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_UDP_H_*/
