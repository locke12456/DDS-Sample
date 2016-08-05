//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/session.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_SESSION_H_
#define DW_CORE_SESSION_H_

#include <devicewise/common/packet.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SESSION_OPT_INTERNAL	1
#define SESSION_OPT_PROTECT		2
#define SESSION_OPT_DEBUG		4
#define SESSION_OPT_PRIO		8
	
#define SESSION_DEFAULT_TIMEOUT		-2

#define SESSION_TRANSACTION_ID	50

#define SESSION_CHNL_DELETED	1
#define SESSION_CHNL_DISCONN	2
#define SESSION_CHNL_RECONN		3
#define SESSION_CHNL_CONNECTED	4

typedef void (*session_reply_func)(DW_PACKET *pkt, void *session, void *custom);

DWCORE_EXPORT const char *session_get_name(const void *handle);
DWCORE_EXPORT const char *session_get_type(const void *handle);
DWCORE_EXPORT const char *session_get_peer_address(const void *handle);
DWCORE_EXPORT int session_get_id(const void *handle);
DWCORE_EXPORT long long session_create_time(const void *handle);
DWCORE_EXPORT void session_set_timeout(void *handle, int timeout);
DWCORE_EXPORT int session_get_timeout(const void *handle);
DWCORE_EXPORT int session_get_ttl(const void *handle);
DWCORE_EXPORT void session_set_option(void *handle, int option);
DWCORE_EXPORT void session_clr_option(void *handle, int option);
DWCORE_EXPORT int session_chk_option(const void *handle, int option);
DWCORE_EXPORT int session_is_connected(const void *handle);
DWCORE_EXPORT void *session_get_logger(const void *handle);
DWCORE_EXPORT void *session_get_userctx(const void *handle);

DWCORE_EXPORT int session_write(void *handle, DW_PACKET *pkt);
DWCORE_EXPORT int session_write_and_read(void *handle, DW_PACKET *in_pkt, DW_PACKET **out_pkt, int timeout);
DWCORE_EXPORT int session_write_and_callback(void *handle, DW_PACKET *in_pkt, session_reply_func func, void *custom);

// Session Manager Functions
DWCORE_EXPORT void *session_find(int session_id);
DWCORE_EXPORT void *session_find_and_reference(int session_id, const char *who);
DWCORE_EXPORT void *session_find_by_index(int index);
DWCORE_EXPORT void  session_foreach(btree_fefunc func, void *custom);
DWCORE_EXPORT int session_list(void *packet);
DWCORE_EXPORT int session_count();

DWCORE_EXPORT int session_reference(void *session,const char *by);
DWCORE_EXPORT int session_dereference(void *session,const char *by);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_SESSION_H_*/
