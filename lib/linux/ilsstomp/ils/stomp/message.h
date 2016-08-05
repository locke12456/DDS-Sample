//----------------------------------------------------------------
//
//-- Filename: ils/stomp/message.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_STOMP_MESSAGE_H_
#define ILS_STOMP_MESSAGE_H_

#define STOMP_DEST_QUEUE		1
#define STOMP_DEST_TOPIC		2

#define STOMP_MESSAGE_COMPRESSION_FALSE		0
#define STOMP_MESSAGE_COMPRESSION_TRUE		1
#define STOMP_MESSAGE_COMPRESSION_ADAPTIVE	2

#define STOMP_MESSAGE_DETAIL_LEN			64

struct STOMP_CLIENT_s;

typedef struct STOMP_MESSAGE_s {

	struct STOMP_CLIENT_s  *client;

	char                   *destination;
	unsigned char           destination_type;

	char                   *replyto;
	unsigned char           replyto_type;

	char                   *correlation_id;
	char                   *message_id;
	long long               subscription_id;

	int                     time_to_live;

	unsigned char           is_persistent;

	unsigned char           compress;
	unsigned char           compression_ratio;

	long long               timestamp;

	void                   *blob;
	int                     blob_preserve;

	void                   *properties;

	void                   *custom;
	char				   detail[STOMP_MESSAGE_DETAIL_LEN+4];
} STOMP_MESSAGE;

//--------------------------------
//-- Message Functions
//--------------------------------
STOMP_EXPORT int            stomp_message_create(STOMP_MESSAGE **message);
STOMP_EXPORT int            stomp_message_duplicate(const STOMP_MESSAGE *message, STOMP_MESSAGE **newmessage);
STOMP_EXPORT void           stomp_message_delete(STOMP_MESSAGE *message);
STOMP_EXPORT int            stomp_message_clear(STOMP_MESSAGE *message);
STOMP_EXPORT int            stomp_message_verify(STOMP_MESSAGE *message);

STOMP_EXPORT void           stomp_message_log(struct STOMP_CLIENT_s *client, int level, STOMP_MESSAGE *message);
STOMP_EXPORT void			stomp_message_set_detail(STOMP_MESSAGE *message, const char *detail);
STOMP_EXPORT void *			stomp_message_instrument_handle();

#endif
