//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/internal/data.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_INTERNAL_DATA_H_
#define DW_DATA_INTERNAL_DATA_H_

#include <devicewise/common/common.h>
#include <devicewise/common/packet.h>
#include <devicewise/common/validate.h>
#include <devicewise/common/blob.h>

#include <devicewise/core/core.h>

#include <devicewise/data/commands.h>
#include <devicewise/data/errors.h>
#include <devicewise/data/messages.h>

#include <devicewise/data/support.h>

#include <devicewise/data/data.h>
#include <devicewise/data/internal/variable.h>
#include <devicewise/data/internal/structure.h>
#include <devicewise/data/internal/device.h>
#include <devicewise/data/internal/driver.h>
#include <devicewise/data/internal/mapper.h>
#include <devicewise/data/internal/vargroup.h>

#ifdef __cplusplus
extern "C" {
#endif

int data_cmd_var_read_async(const void **in_argv, int *in_lens, int in_argc, DW_PACKET *in_pkt, void *session);
int data_cmd_var_write_async(const void **in_argv, int *in_lens, int in_argc, DW_PACKET *in_pkt, void *session);

int data_rempub_subscribe(const void **in_argv, int *in_lens, int in_argc, DW_PACKET *out_pkt, void *session);
int data_rempub_unsubscribe(const void **in_argv, int *in_lens, int in_argc, DW_PACKET *out_okt, void *session);

int data_cmd_processor(		DW_PACKET *in_pkt, 
							const void **in_argv, int *in_lens, int in_argc, 
							DW_PACKET *out_pkt, 
							void *session, void *custom);
							
#ifdef __cplusplus
}
#endif

#endif /*DW_INTERNAL_DATA_H_*/
