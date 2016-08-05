//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/vargroup.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_VARGROUP_H_
#define DW_DATA_VARGROUP_H_

#ifdef __cplusplus
extern "C" {
#endif

#define DW_VARGROUP_NAME_LEN		64

typedef void (*_vargroup_publish)(void *group_subscription, DW_DEVICE *dev, DW_VARIABLE_DATA *var, int status, void *custom);

DWDATA_EXPORT int vargroup_subscribe(void **group_subscription, const char *vargroup_name,_vargroup_publish publish,void *custom, void *userctx);
DWDATA_EXPORT int vargroup_unsubscribe(void *group_subscription);
DWDATA_EXPORT int vargroup_vinfo_get(const char *vargroup_name, DW_VARIABLE_INFO **vinfo);

#ifdef __cplusplus
}
#endif

#endif /*DW_DATA_VARGROUP_H_*/
