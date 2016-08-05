//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/http.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_HTTP_H_
#define ILS_UTIL_HTTP_H_

#ifdef __cplusplus
extern "C" {
#endif

#define HTTP_PROTO_HTTP		0x0001
#define HTTP_PROTO_HTTPS	0x0002

#define HTTP_METHOD_GET		0x0001
#define HTTP_METHOD_POST	0x0002
#define HTTP_METHOD_HEAD	0x0004
#define HTTP_METHOD_PUT		0x0008
#define HTTP_METHOD_DELETE	0x0010

#define HTTP_VERSION_10		0x0001
#define HTTP_VERSION_11		0x0002

#define HTTP_ENCODING_CHUNKED	0x0004

#define HTTP_RSP_200_OK				200
#define HTTP_RSP_201_CREATED		201
#define HTTP_RSP_400_BAD_REQ		400
#define HTTP_RSP_401_UNAUTH			401
#define HTTP_RSP_403_FORBIDDEN		403
#define HTTP_RSP_403_NOT_FOUND		404
#define HTTP_RSP_500_INTERNAL		500
#define HTTP_RSP_501_NOT_IMPL		501
#define HTTP_RSP_502_BAD_GW			502
#define HTTP_RSP_503_SVC_UNAVAIL	503

#define HTTP_RSP_200		"OK"
#define HTTP_RSP_201		"Created"
#define HTTP_RSP_202		"Accepted"
#define HTTP_RSP_204		"No Content"

#define HTTP_RSP_300		"Multiple Choices"
#define HTTP_RSP_301		"Moved Permanently"
#define HTTP_RSP_302		"Moved Temporarily"
#define HTTP_RSP_304		"Not Modified"

#define HTTP_RSP_400		"Bad Request"
#define HTTP_RSP_401		"Unauthorized"
#define HTTP_RSP_403		"Forbidden"
#define HTTP_RSP_404		"Not Found"

#define HTTP_RSP_500		"Internal Server Error"
#define HTTP_RSP_501		"Not Implemented"
#define HTTP_RSP_502		"Bad Gateway"
#define HTTP_RSP_503		"Service Unavailable"

typedef struct {
	const char *url;
	const char *override_host;
	int method;
	int options;
	void *properties;
	char *data;
	int data_len;
	int timeout;
	const char *ssl_cert_path;
	const char *ssl_cert_pass;
	int         ssl_verify_peer;
	SOCKET_PROXY_INFO *proxy;
	const char *file;
	int offset;
} HTTP_REQUEST;

typedef struct {
	int status;
	int options;
	void *properties;
	char *data;
	int data_len;
} HTTP_RESPONSE;

UTIL_EXPORT int http_request_create(HTTP_REQUEST **request);
UTIL_EXPORT int http_request_delete(HTTP_REQUEST *request);
UTIL_EXPORT int http_request_set_basic_auth(HTTP_REQUEST *request,const char *user, const char *pass);

UTIL_EXPORT int http_response_create(HTTP_RESPONSE **response);
UTIL_EXPORT int http_response_delete(HTTP_RESPONSE *response);

UTIL_EXPORT char *http_encode_string(const char *str);

UTIL_EXPORT char *http_encode_url(const char *str);
UTIL_EXPORT int http_client(HTTP_REQUEST *request, HTTP_RESPONSE *response);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_HTTP_H_*/
