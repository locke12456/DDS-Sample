//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/listener.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_LISTENER_H_
#define DW_CORE_LISTENER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define LISTENER_NAME_LEN	64
	
#define LISTENER_OPT_DEBUG	1
#define LISTENER_OPT_SSL	2
#define LISTENER_OPT_SECURE	4
#define LISTENER_OPT_INLINE 8


typedef struct {
	char name[LISTENER_NAME_LEN+1];
	char addr[LISTENER_NAME_LEN+1];
	int options;
} LISTENER_OBJECT;

DWCORE_EXPORT void listener_foreach(btree_fefunc fefunc, void *custom);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_LISTENER_H_*/
