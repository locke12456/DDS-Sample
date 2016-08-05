//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/hardwareid.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_HARDWAREID_H_
#define DW_CORE_HARDWAREID_H_

#ifdef __cplusplus
extern "C" {
#endif

DWCORE_EXPORT int dw_hardwareid_list(HWID_ENTRY *hwids, int *count);
DWCORE_EXPORT int dw_hardwareid_count();

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_HARDWAREID_H_*/
