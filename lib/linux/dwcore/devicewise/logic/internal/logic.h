//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/logic/internal/logic.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_LOGIC_INTERNAL_LOGIC_H_
#define DW_LOGIC_INTERNAL_LOGIC_H_

#include <devicewise/common/common.h>
#include <devicewise/common/packet.h>
#include <devicewise/common/validate.h>
#include <devicewise/common/blob.h>

#include <devicewise/core/core.h>
#include <devicewise/data/data.h>

#include <devicewise/logic/logic.h>
#include <devicewise/logic/internal/action.h>
#include <devicewise/logic/internal/event.h>
#include <devicewise/logic/internal/project.h>
#include <devicewise/logic/internal/trigger.h>

#ifdef __cplusplus
extern "C" {
#endif

int data_cmd_processor(		DW_PACKET *in_pkt, 
							const void **in_argv, int *in_lens, int in_argc, 
							DW_PACKET *out_pkt, 
							void *session, void *custom);
							
#ifdef __cplusplus
}
#endif

#endif /*DW_LOGIC_INTERNAL_LOGIC_H_*/
