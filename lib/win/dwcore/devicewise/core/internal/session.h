//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/internal/session.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_INTERNAL_SESSION_H_
#define DW_CORE_INTERNAL_SESSION_H_

#include <devicewise/common/packet.h>

#ifdef __cplusplus
extern "C" {
#endif

// Session Functions
int session_create(void **handle, const char *name, const char *type, void *socket, void *userctx);
//int session_delete(void *handle); (see reference/dereference)

int session_attach(void *handle, void *socket);
int session_detach(void *handle);

//This should only be called by the Handler module!
int session_do_reply(void *handle, DW_PACKET *pkt);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_INTERNAL_SESSION_H_*/
