//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/network.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_NETWORK_H_
#define DW_CORE_NETWORK_H_

#ifdef __cplusplus
extern "C" {
#endif

DWCORE_EXPORT int network_acl_create(const char *name, const char *xml);
DWCORE_EXPORT int network_acl_delete(const char *name);
DWCORE_EXPORT int network_acl_check(const char *name, const char *address);

typedef int (*ping_callback)(const char *address, int timeout);
DWCORE_EXPORT void network_register_ping_func(ping_callback func);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_NETWORK_H_*/
