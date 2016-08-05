//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/inet.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_INET_H_
#define ILS_UTIL_INET_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int inet_host2int( const char *host, unsigned int *network_number );
UTIL_EXPORT int inet_host2ip(const char *host, char **ip_address);

UTIL_EXPORT int inet_adapter_get_ip(const char *iface, char **ip_address);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_INET_H_*/
