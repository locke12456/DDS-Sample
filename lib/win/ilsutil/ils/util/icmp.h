//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/icmp.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_ICMP_H_
#define ILS_UTIL_ICMP_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int icmp_ping(const char *destination, int timeout);
UTIL_EXPORT int icmp_ping_ex(const char *destination, int timeout, int *oserr);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_SOCKET_H_*/
