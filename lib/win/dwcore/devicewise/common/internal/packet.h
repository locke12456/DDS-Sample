//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/common/internal/packet.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_COMMON_INTERNAL_PACKET_H_
#define DW_COMMON_INTERNAL_PACKET_H_

#ifdef __cplusplus
extern "C" {
#endif
	

// START OF PACKING
#if defined(_WIN32)
#  pragma pack(1)
#elif defined(_HPUX)
#  pragma HP_ALIGN NOPADDING PUSH
#elif defined(_UNIX)
#  if defined(__GNUC__)
#  else
#    pragma options align=packed
#  endif
#endif
// START OF PACKING

typedef struct {
	short version;
	short options;
	int cmd;
	int length;
	int count;
	int msgid;
	int status;
	int sid;
	int crc;
} 
#if defined(__GNUC__)
__attribute((packed))
#endif
DW_HEADER;

typedef struct {
	DW_HEADER *buffer;
	int size;
	int len;
	int swapped;
} _DW_PACKET;

// END OF PACKING
#if defined(_WIN32)
#  pragma pack()
#elif defined(_HPUX)
#  pragma HP_ALIGN POP
#elif defined(_UNIX)
#  if defined(__GNUC__)
#  else
#    pragma options align=reset
#  endif
#endif
// END OF PACKING

void packet_set_header(DW_PACKET *packet, DW_HEADER *hdr);
DW_HEADER *packet_get_header(DW_PACKET *packet);

#ifdef __cplusplus
}
#endif

#endif /*DW_COMMON_INTERNAL_PACKET_H_*/
