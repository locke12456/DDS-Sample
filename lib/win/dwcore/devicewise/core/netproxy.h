//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/netproxy.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_NETPROXY_H_
#define DW_CORE_NETPROXY_H_

#ifdef __cplusplus
extern "C" {
#endif

DWCORE_EXPORT int netproxy_create(const char *name, const char *listen_address, const char *target_address, SOCKET_PROXY_INFO *proxyinfo);
DWCORE_EXPORT int netproxy_test(const char *listen_address, const char *target_address, SOCKET_PROXY_INFO *proxyinfo);
DWCORE_EXPORT int netproxy_delete(const char *name);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_NETPROXY_H_*/
