//----------------------------------------------------------------
//
//-- Filename: ils/stomp/client.h
//
//----------------------------------------------------------------

#ifndef ILS_STOMP_CLIENT_H_
#define ILS_STOMP_CLIENT_H_

#define STOMP_DEF_URL_LEN	256

#define STOMP_OPT_OMIT_CONTENT_TYPE				0x01
#define STOMP_OPT_OMIT_CONTENT_LENGTH			0x02
#define STOMP_OPT_ALWAYS_SEND_CONTENT_LENGTH	0x04
#define STOMP_OPT_DUMP_PACKETS					0x08
#define STOMP_OPT_DISABLE_SOCKET_NODELAY		0x16
#define STOMP_OPT_DUMP_RAW						0x32

#define STOMP_STATE_CONNECTED		1
#define STOMP_STATE_DISCONNECTED	2

typedef struct STOMP_CLIENT_s STOMP_CLIENT;

typedef void (*stomp_client_ondisconnect_callback)(STOMP_CLIENT *client, int status, const char *error_message);
typedef void (*stomp_client_dispatch_callback)(STOMP_MESSAGE *message, int status, void *args);

struct STOMP_CLIENT_s {

	// common settings
	char url[STOMP_DEF_URL_LEN+4];
	SOCKET_PROXY_INFO proxy;

	char *username;
	char *password;

	// advanced settings
	void *pool;

	int heartbeat_timer;
	int heartbeat_count;

	int options;

	int receipt_timeout;

	stomp_client_ondisconnect_callback ondisconnect;

	// internal properties
	int state;

	int   dispatches_outstanding;

	int   is_debugmode;

	void *blob_outgoing;
	void *blob_incoming;

	void *logger;

	void *mux;

	void *pending_item_btree;
	int   pending_receipt_count;
	void *pending_expiration_btree;
	void *pending_expiration_thread;
	long long pending_last_checked;
	int       pending_last_interval;
	void *pending_mux;
	
	void *receiver_thread;

	long long receipt_next_id;

	void *socket;

	char *ssl_cert_path;
	char *ssl_cert_pass;
	int   ssl_cert_verify_peer;
	
	void *subscription_btree;
	int   subscription_next_id;

	char *last_error_message;

	// counter properties

	unsigned long long stats_messages_sent;
	unsigned long long stats_messages_recv;
	unsigned long long stats_messages_dropped;
	unsigned long long stats_messages_nack;
	unsigned long long stats_bytes_sent;
	unsigned long long stats_bytes_recv;
	unsigned long long stats_data_sent;
	unsigned long long stats_data_recv;
	unsigned long long stats_compressed_not_sent;
	unsigned long long stats_compressed_not_recv;
	long long    stats_last_recv;
	long long    stats_last_sent;
	int          stats_last_receipt_delay;
	int          stats_max_receipt_delay;

	int debug_drop_next_receipt;
	int debug_fail_next_send;

	// user pointers
	void *userptr1;
	void *userptr2;
	void *userptr3;
};

STOMP_EXPORT int stomp_client_create(STOMP_CLIENT **client);
STOMP_EXPORT void stomp_client_delete(STOMP_CLIENT *client);

STOMP_EXPORT int stomp_client_clear_counters(STOMP_CLIENT *client);

STOMP_EXPORT int stomp_client_set_ondisconnect_callback(STOMP_CLIENT *client, stomp_client_ondisconnect_callback callback);

STOMP_EXPORT const char *stomp_client_last_error(STOMP_CLIENT *client);

STOMP_EXPORT int         stomp_client_set_url(STOMP_CLIENT *client, const char *url);
STOMP_EXPORT const char *stomp_client_get_url(STOMP_CLIENT *client);

STOMP_EXPORT int         stomp_client_set_credentials(STOMP_CLIENT *client, const char *username, const char *password);
STOMP_EXPORT int         stomp_client_set_ssl_cert(STOMP_CLIENT *client, const char *cert_path, const char *cert_pass, int verify_peer);

STOMP_EXPORT int         stomp_client_connect(STOMP_CLIENT *client);
STOMP_EXPORT int         stomp_client_reconnect(STOMP_CLIENT *client);
STOMP_EXPORT int         stomp_client_disconnect(STOMP_CLIENT *client);

STOMP_EXPORT int         stomp_client_publish(STOMP_CLIENT *client, STOMP_MESSAGE *message);

STOMP_EXPORT int         stomp_client_message_ack(STOMP_MESSAGE *message);
STOMP_EXPORT int         stomp_client_message_nack(STOMP_MESSAGE *message);

STOMP_EXPORT int         stomp_client_subscribe(STOMP_CLIENT *client, long long *subscription_id, const char *destination, int destination_type, void *properties, stomp_client_dispatch_callback callback, void *custom);
STOMP_EXPORT int         stomp_client_subscribe_q(STOMP_CLIENT *client, long long *subscription_id, const char *destination, int destination_type, void *properties, void *queue, void *custom);
STOMP_EXPORT int         stomp_client_unsubscribe(STOMP_CLIENT *client, long long subscription_id);
STOMP_EXPORT int         stomp_client_unsubscribe_all(STOMP_CLIENT *client);
STOMP_EXPORT int         stomp_client_subscribe_swap_dest(STOMP_CLIENT *client, const char *matching_dest, const char *new_dest);

#endif
