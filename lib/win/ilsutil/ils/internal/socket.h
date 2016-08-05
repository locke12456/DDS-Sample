//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/internal/socket.h
//
//-- Copyright: 2001-2015, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_INTERNAL_SOCKET_H_
#define ILS_INTERNAL_SOCKET_H_

#include "ils/util/errors.h"
#include "ils/internal/config.h"
#include "ils/internal/platform.h"

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int socket_create(void **handle);
UTIL_EXPORT int socket_listen(void **server_handle, const char *addr);

#ifdef __cplusplus
}
#endif

#endif /*ILS_INTERNAL_SOCKET_H_*/
