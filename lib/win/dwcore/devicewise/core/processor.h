//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/processor.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_PROCESSOR_H_
#define DW_CORE_PROCESSOR_H_

#include <devicewise/common/packet.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PROCESSOR_SESSION_WORK	1
#define PROCESSOR_SOCKET_WORK	2

#define PROCESSOR_NO_RESPONSE	-9999

typedef int (*processor_function)(	DW_PACKET *in_pkt, 
									const void **in_argv, int *in_lens, int in_argc, 
									DW_PACKET *out_pkt,
									void *session, void *custom);
									
typedef int (*processor_function_raw)(	DW_PACKET *in_pkt, 
										DW_PACKET *out_pkt,
										void *session, void *custom);

int processor_put_work(void *pkt, int type, void *context);
int processor_do_work(void *pkt, void *session);

DWCORE_EXPORT int processor_register(int cmdbloc, processor_function func, void *custom);
DWCORE_EXPORT int processor_register_raw(int cmdbloc, processor_function_raw func, void *custom);
DWCORE_EXPORT int processor_deregister(int cmdbloc);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_PROCESSOR_H_*/
