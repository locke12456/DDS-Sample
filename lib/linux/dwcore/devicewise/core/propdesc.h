//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/propdesc.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_PROPDESC_H_
#define DW_CORE_PROPDESC_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*propdesc_dynlist_callback)(const char *key, void *item_list);

int propdesc_add_property_dynlist(	void *phandle, const char *key, const char *name, int name_id, int desc_id, int opts, 
									const char *dynkey, propdesc_dynlist_callback callback, void *custom);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_PROPDESC_H_*/
