//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//-- INTERNAL HEADER, NOT FOR DISTRIBUTION
//
//-- Filename: ils/internal/tcp.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_INTERNAL_TCP_H_
#define ILS_INTERNAL_TCP_H_

#ifdef __cplusplus
extern "C" {
#endif

int tcp_send(void *, const char *, int);
int tcp_send2(void *, const char *, int, int);
int tcp_recv(void *, char *, int, int);
int tcp_recv2(void *, char *, int *, int);
int tcp_close(void *);

#ifdef __cplusplus
}
#endif

#endif /*ILS_INTERNAL_TCP_H_*/
