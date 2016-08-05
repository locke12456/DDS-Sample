//----------------------------------------------------------------
//
//-- Filename: ils/stomp/frame.h
//
//----------------------------------------------------------------

#ifndef ILS_STOMP_FRAME_H_
#define ILS_STOMP_FRAME_H_

#define STOMP_FRAME_TYPE_UNKNOWN		  0
#define STOMP_FRAME_TYPE_CONNECT		100
#define STOMP_FRAME_TYPE_SEND			101
#define STOMP_FRAME_TYPE_SUBSCRIBE		102
#define STOMP_FRAME_TYPE_UNSUBSCRIBE	103
#define STOMP_FRAME_TYPE_ACK			104
#define STOMP_FRAME_TYPE_NACK			105
#define STOMP_FRAME_TYPE_BEGIN			106
#define STOMP_FRAME_TYPE_COMMIT			107
#define STOMP_FRAME_TYPE_ABORT			108
#define STOMP_FRAME_TYPE_DISCONNECT		109

#define STOMP_FRAME_TYPE_CONNECTED		200
#define STOMP_FRAME_TYPE_MESSAGE		201
#define STOMP_FRAME_TYPE_RECEIPT		202
#define STOMP_FRAME_TYPE_ERROR			203

#define STOMP_FRAME_CMD_LEN		64
typedef struct {
	char frame[STOMP_FRAME_CMD_LEN];
	int  frame_type;

	long long receipt_id;

	void *properties;

	const char *content_type;

	void *body;

	int stats_header_length;
	int stats_compressed_savings;

	void *userptr1;
} STOMP_FRAME;

STOMP_EXPORT int stomp_frame_create(STOMP_FRAME **frame);
STOMP_EXPORT void stomp_frame_delete(STOMP_FRAME *frame);

STOMP_EXPORT int stomp_frame_setup(struct STOMP_CLIENT_s *client, STOMP_FRAME *frame, int frame_type, int gen_receipt_id, void *properties);

STOMP_EXPORT void stomp_frame_dump(STOMP_CLIENT *client, int level, STOMP_FRAME *frame);

#endif
