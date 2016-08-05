//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/httpvr.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DEVICEWISE_CORE_HTTPSVR_H_
#define DW_DEVICEWISE_CORE_HTTPSVR_H_

#define HTTPSVR_OPT_FREE_ENCODING	2
#define HTTPSVR_OPT_USE_SSL			4

typedef struct {
	int method;
	int version;
	char *url;
	char url_extension[8];
	void *url_variables;
	void *attributes;
	void *cookies;
	void *content;
} HTTPSVR_REQUEST;

typedef struct {
	int version;
	int status;
	char *encoding;
	void *cookies;
	void *content;
	int options;
} HTTPSVR_RESPONSE;

typedef int (*httpsvr_page_callback)(HTTPSVR_REQUEST *request, HTTPSVR_RESPONSE *response, void *custom);

DWCORE_EXPORT int httpsvr_server_start(const char *addr, const char *addr_ssl);
DWCORE_EXPORT int httpsvr_server_stop();

DWCORE_EXPORT int httpsvr_handler_start(void *socket);

DWCORE_EXPORT int  httpsvr_request_create(HTTPSVR_REQUEST **request, char *data, int data_len);
DWCORE_EXPORT int  httpsvr_request_delete(HTTPSVR_REQUEST *request);
DWCORE_EXPORT void httpsvr_request_dump(HTTPSVR_REQUEST *request);

DWCORE_EXPORT int  httpsvr_response_create(HTTPSVR_RESPONSE **response);
DWCORE_EXPORT int  httpsvr_response_delete(HTTPSVR_RESPONSE *response);
DWCORE_EXPORT int  httpsvr_response_encode(HTTPSVR_RESPONSE *response, void *blob);
DWCORE_EXPORT void httpsvr_response_dump(HTTPSVR_RESPONSE *response);

DWCORE_EXPORT int httpsvr_parse_response(HTTPSVR_RESPONSE *response);

DWCORE_EXPORT int httpsvr_page_add_handler(const char *url, httpsvr_page_callback callback, void *custom);
DWCORE_EXPORT int httpsvr_page_del_handler(const char *url);
DWCORE_EXPORT httpsvr_page_callback httpsvr_page_get_handler(const char *url);
DWCORE_EXPORT int httpsvr_page_call_handler(const char *url, HTTPSVR_REQUEST *request, HTTPSVR_RESPONSE *response);

DWCORE_EXPORT int httpsvr_page_send_response(HTTPSVR_RESPONSE *response);

DWCORE_EXPORT void httpsvr_mime_init();
DWCORE_EXPORT const char *httpsvr_mime_get(const char *extension);

#endif /*DW_DEVICEWISE_CORE_HTTPSVR_H_*/
