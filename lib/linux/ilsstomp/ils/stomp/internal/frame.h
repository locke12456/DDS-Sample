//----------------------------------------------------------------
//
//-- Filename: ils/stomp/frame.h
//
//----------------------------------------------------------------

#ifndef ILS_STOMP_INTERNAL_FRAME_H_
#define ILS_STOMP_INTERNAL_FRAME_H_

STOMP_EXPORT int stomp_frame_identify(STOMP_CLIENT *client, STOMP_FRAME *frame, int type);
STOMP_EXPORT const char *stomp_frame_type_get(STOMP_CLIENT *client, int type);
STOMP_EXPORT int stomp_frame_type_set(STOMP_CLIENT *client, const char *frame);

STOMP_EXPORT int stomp_frame_encode(STOMP_CLIENT *client, STOMP_FRAME *frame_in, void *blob_out);
STOMP_EXPORT int stomp_frame_decode(STOMP_CLIENT *client, void *blob_in, STOMP_FRAME *frame_out);

#endif
