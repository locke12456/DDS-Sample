//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/support.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_SUPPORT_H_
#define DW_DATA_SUPPORT_H_

#ifdef __cplusplus
extern "C" {
#endif

DWDATA_EXPORT const char *support_get_type_from_id(int id);
DWDATA_EXPORT int support_check_type(int id);
DWDATA_EXPORT int support_get_element_size(int id);
DWDATA_EXPORT int support_get_type_from_string(const char *str);
DWDATA_EXPORT const char *support_get_state_as_string(int state);

#ifdef __cplusplus
}
#endif

#endif /*DW_DATA_SUPPORT_H_*/
