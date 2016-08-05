//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Logic Subsystem
//
//-- Filename: devicewise/logic/internal/project.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_LOGIC_INTERNAL_PROJECT_H_
#define DW_LOGIC_INTERNAL_PROJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

int project_cmd_list(DW_PACKET *out_pkt);
int project_cmd_enum(DW_PACKET *packet);

int project_cmd_processor(	DW_PACKET *in_pkt, 
							const void **in_argv, int *in_lens, int in_argc, 
							DW_PACKET *out_pkt, 
							void *session, void *custom);
							
#ifdef __cplusplus
}
#endif

#endif /*DW_LOGIC_INTERNAL_PROJECT_H_*/
