//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/bridge.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_BRIDGE_H_
#define DW_CORE_BRIDGE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define BRIDGE_STATUS_CONNECTED		1
#define BRIDGE_STATUS_RECONNECTED	2
#define BRIDGE_STATUS_DISCONNECTED	3

typedef void (*bridge_status_callback)(void *brdgconn, int status, void *custom);
typedef void (*bridge_reply_func)(DW_PACKET *pkt, void *brdgconn, void *custom);

DWCORE_EXPORT int bridge_get_connection(void **brdgconn, const char *dwnode, const char *user, const char *pass, const char *type);
DWCORE_EXPORT int bridge_unget_connection(void *brdgconn);

DWCORE_EXPORT int bridge_is_connected(void *brdgconn);

DWCORE_EXPORT int bridge_register_status_callback(void **handle, void *brdgconn, bridge_status_callback callback, void *custom);
DWCORE_EXPORT int bridge_deregister_status_callback(void *handle, void *brdgconn);

DWCORE_EXPORT int bridge_channel_callback_register(void *brdgconn, void **handle, void *callback, void *custom);
DWCORE_EXPORT void bridge_channel_callback_deregister(void *brdgconn, void *handle);

DWCORE_EXPORT int bridge_channel_subscribe(void *brdgconn, const char* channel);
DWCORE_EXPORT int bridge_channel_unsubscribe(void *brdgconn, const char* channel);

DWCORE_EXPORT int bridge_write(void *brdgconn, DW_PACKET *pkt);
DWCORE_EXPORT int bridge_write_and_read(void *brdgconn, DW_PACKET *in_pkt, DW_PACKET **out_pkt, int timeout);
DWCORE_EXPORT int bridge_write_and_callback(void *brdgconn, DW_PACKET *in_pkt, bridge_reply_func func, void *custom);
#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_HANDLER_H_*/
