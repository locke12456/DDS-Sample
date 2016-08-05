//----------------------------------------------------------------
//
//-- Filename: ils/stomp/internal/client.h
//
//----------------------------------------------------------------

#ifndef ILS_STOMP_INTERNAL_CLIENT_H_
#define ILS_STOMP_INTERNAL_CLIENT_H_

#define STOMP_DEF_SUB_LEN	256

#define STOMP_STATE_CONNECTED		1
#define STOMP_STATE_DISCONNECTED	2
#define STOMP_STATE_CONNECTING		3
#define STOMP_STATE_DISCONNECTING	4

typedef void (*stomp_client_receipt_callback)(int status, void *args);

typedef struct {
	long long id;
	int       is_active;
	char      destination[STOMP_DEF_SUB_LEN+4];
	int       destination_type;
	void     *properties;
	void     *queue;
	stomp_client_dispatch_callback callback;
	void     *custom;
} STOMP_SUBSCRIPTION;

typedef struct {
	long long receipt_id;
	int status;
	int expiration;
	long long strt;
} STOMP_PENDING_ITEM;

//--------------------------------
//-- Other Functions
//--------------------------------
int         stomp_client_resubscribe(STOMP_CLIENT *client, long long subscription_id);
int         stomp_client_subscribe_find(STOMP_CLIENT *client, long long subscription_id, STOMP_SUBSCRIPTION **sub);
void        stomp_client_subscribe_free(void *a);
int         stomp_client_complete(STOMP_CLIENT *client, STOMP_FRAME *frame);

//--------------------------------
//-- Pending Functions
//--------------------------------
long long   stomp_client_get_next_receipt_id(STOMP_CLIENT *client);
int         stomp_client_add_pending_receipt(STOMP_CLIENT *client, int receipt_id, int expiration, long long strt);
int         stomp_client_del_pending_receipt(STOMP_CLIENT *client, int receipt_id);
int         stomp_client_purge_pending_items(STOMP_CLIENT *client);

//--------------------------------
//-- Send/Receive Functions
//--------------------------------
int         stomp_client_send(STOMP_CLIENT *client, STOMP_FRAME *frame);
int         stomp_client_send_nolock(STOMP_CLIENT *client, STOMP_FRAME *frame);
int         stomp_client_send_with_receipt(STOMP_CLIENT *client, STOMP_FRAME *frame);
int         stomp_client_send_with_receipt(STOMP_CLIENT *client, STOMP_FRAME *frame);

int         stomp_client_recv(STOMP_CLIENT *client, STOMP_FRAME *frame);
int         stomp_client_recv_nolock(STOMP_CLIENT *client, STOMP_FRAME *frame);

int         stomp_client_dispatch(STOMP_CLIENT *client, STOMP_FRAME *frame);

#endif
