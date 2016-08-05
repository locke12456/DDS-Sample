//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/common/packet.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_COMMON_PACKET_H_
#define DW_COMMON_PACKET_H_

#ifdef __cplusplus
extern "C" {
#endif

#define PACKET_OPT_HIGHPRIO		1
#define PACKET_OPT_REPLY		2
#define PACKET_OPT_DEBUG		4
#define PACKET_OPT_PRIO			8
#define PACKET_OPT_INLINE		16

#define PACKET_DUMP_DETAILED	1
#define PACKET_DUMP_RAW			2

typedef void DW_PACKET;

DWCOMMON_EXPORT DW_PACKET *packet_duplicate(DW_PACKET *packet);

DWCOMMON_EXPORT int packet_create(DW_PACKET **packet);
DWCOMMON_EXPORT int packet_create_sized(DW_PACKET **packet, int size);
DWCOMMON_EXPORT int packet_delete(DW_PACKET *packet);
DWCOMMON_EXPORT int packet_clear_params(DW_PACKET *packet);
DWCOMMON_EXPORT int packet_clear(DW_PACKET *packet);

DWCOMMON_EXPORT int packet_count_params(DW_PACKET *packet);

DWCOMMON_EXPORT void packet_init_reply(DW_PACKET *packet, DW_PACKET *request, int status);

DWCOMMON_EXPORT void packet_set_version(DW_PACKET *packet, short version);
DWCOMMON_EXPORT void packet_set_options(DW_PACKET *packet, short options);
DWCOMMON_EXPORT void packet_set_cmd(DW_PACKET *packet, int cmd);
DWCOMMON_EXPORT void packet_set_msgid(DW_PACKET *packet, int msgid);
DWCOMMON_EXPORT void packet_set_status(DW_PACKET *packet, int status);
DWCOMMON_EXPORT void packet_set_sid(DW_PACKET *packet, int sid);

DWCOMMON_EXPORT short packet_get_version(DW_PACKET *packet);
DWCOMMON_EXPORT short packet_get_options(DW_PACKET *packet);
DWCOMMON_EXPORT int packet_has_option(DW_PACKET *po, short option);
DWCOMMON_EXPORT int packet_get_cmd(DW_PACKET *packet);
DWCOMMON_EXPORT int packet_get_msgid(DW_PACKET *packet);
DWCOMMON_EXPORT int packet_get_status(DW_PACKET *packet);
DWCOMMON_EXPORT int packet_get_count(DW_PACKET *packet);
DWCOMMON_EXPORT int packet_get_sid(DW_PACKET *packet);

DWCOMMON_EXPORT int packet_encode(DW_PACKET *packet, char **arg, int *len, int count);
DWCOMMON_EXPORT int packet_decode(DW_PACKET *packet, char **args, int *len, int *count);
DWCOMMON_EXPORT int packet_decode_and_alloc(DW_PACKET *packet, char ***args, int **len, int *count);

DWCOMMON_EXPORT int packet_add_parameter(DW_PACKET *packet, const void *data, int len);
DWCOMMON_EXPORT int packet_add_parameters(DW_PACKET *packet, const void *data[], int len[], int count);

DWCOMMON_EXPORT int packet_add_int4(DW_PACKET *packet, int value);
DWCOMMON_EXPORT int packet_add_int8(DW_PACKET *packet, long long value);

DWCOMMON_EXPORT void packet_dump(DW_PACKET *packet, void *logger, const char *str, int level);
DWCOMMON_EXPORT void packet_dump2(DW_PACKET *packet, void *logger, const char *str, int level, int type);

//communication functions
DWCOMMON_EXPORT int packet_read(void *socket, DW_PACKET **packet, int timeout);
DWCOMMON_EXPORT int packet_write(void *socket, DW_PACKET *packet);

#ifdef __cplusplus
}
#endif

#endif /*DW_COMMON_PACKET_H_*/
