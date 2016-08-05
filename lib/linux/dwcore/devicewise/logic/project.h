//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Logic Subsystem
//
//-- Filename: devicewise/logic/trigger.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_LOGIC_PROJECT_H_
#define DW_LOGIC_PROJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

#define PROJECT_CHANNEL_STARTED		1
#define PROJECT_CHANNEL_STOPPED		2
#define PROJECT_CHANNEL_ADDED		3
#define PROJECT_CHANNEL_DELETED		4

DWLOGIC_EXPORT int project_add(const char *name, void *secctx, int op);
DWLOGIC_EXPORT int project_del(const char *name, void *secctx, int op);

DWLOGIC_EXPORT int project_state(const char *name);

DWLOGIC_EXPORT int project_start(const char *name, void *secctx, int op);
DWLOGIC_EXPORT int project_stop(const char *name, void *secctx, int op);

#ifdef __cplusplus
}
#endif

#endif /*DW_LOGIC_PROJECT_H_*/
