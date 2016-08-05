//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Logic Subsystem
//
//-- Filename: devicewise/logic/logic.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_LOGIC_LOGIC_H_
#define DW_LOGIC_LOGIC_H_

#include <devicewise/logic/commands.h>
#include <devicewise/logic/errors.h>
#include <devicewise/logic/messages.h>

#include <devicewise/logic/event.h>
#include <devicewise/logic/action.h>
#include <devicewise/logic/project.h>
#include <devicewise/logic/trigger.h>
#include <devicewise/logic/compound.h>
#include <devicewise/logic/userop.h>

#define DW_TRIGGER_STARTED	1
#define DW_TRIGGER_STOPPED	2
#define DW_TRIGGER_DISABLED	3
#define DW_TRIGGER_STARTING	4
#define DW_TRIGGER_STOPPING	5

#define DW_PROJECT_STARTED	1
#define DW_PROJECT_STOPPED	2
#define DW_PROJECT_STARTING	4
#define DW_PROJECT_STOPPING	5

#define DW_TRIGGER_PATH_START		0
#define DW_TRIGGER_PATH_UNWIRED		0xFFFF
#define DW_TRIGGER_PATH_UNDEF		0xFFFE
#define DW_TRIGGER_PATH_END_OK		0xFF00
#define DW_TRIGGER_PATH_END_ERR		0xFF01
#define DW_TRIGGER_PATH_NEXT		0xFF10

#ifdef __cplusplus
extern "C" {
#endif

DWLOGIC_EXPORT const char *logic_build_version();

// Included for special uses internally.
DWLOGIC_EXPORT int logic_marshall_item_btree(DW_PACKET *packet, void *var_btree);
DWLOGIC_EXPORT int logic_marshall_item_btree2(void *blob, void *var_btree);
DWLOGIC_EXPORT int logic_unmarshall_items(const void **argv, int *arg_lens, int var_count, void *var_btree, int insert_missing);

#ifdef __cplusplus
}
#endif

#endif /*DW_LOGIC_LOGIC_H_*/
