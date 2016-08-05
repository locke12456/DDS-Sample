//----------------------------------------------------------------
//
//-- Filename: ils/stomp/url.h
//
//----------------------------------------------------------------

#ifndef ILS_STOMP_URL_H_
#define ILS_STOMP_URL_H_

#define STOMP_PROTO_TCP 1
#define STOMP_PROTO_SSL 2

typedef struct {
	int protocol;
	char address[128];
	char path[512];
	char host[128];
} STOMP_URL;

STOMP_EXPORT int stomp_url_parse(const char *str, STOMP_URL *url);

#endif
