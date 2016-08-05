//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//-- INTERNAL HEADER, NOT FOR DISTRIBUTION
//
//-- Filename: ils/internal/inet.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_INTERNAL_INET_H_
#define ILS_INTERNAL_INET_H_

#ifdef __cplusplus
extern "C" {
#endif

int host2int( const char *host, unsigned int *network_number );
int make_addr(const char *addr, struct sockaddr_in *sin);
char *make_string_from_addr(struct sockaddr_in *sin);

#ifdef __cplusplus
}
#endif

#endif /*ILS_INTERNAL_INET_H_*/
