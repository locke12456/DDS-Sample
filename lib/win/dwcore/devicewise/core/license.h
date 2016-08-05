//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/license.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_LICENSE_H_
#define DW_CORE_LICENSE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define LICENSE_CHECK_INTERNAL_USE	1
#define LICENSE_CHECK_EVALUATION	2
#define LICENSE_CHECK_EMERGENCY		4
#define LICENSE_CHECK_EXPIRED		8

DWCORE_EXPORT int license_check(int product_id, int feature_id);

DWCORE_EXPORT int license_check_key_states(int *mask, int *days_to_first_expire);

DWCORE_EXPORT int license_add(const char* key, void *secctx, int op);

DWCORE_EXPORT int license_count();

DWCORE_EXPORT void license_disable_emergence(const char *reason);

#ifdef __cplusplus
}
#endif


#endif /*DW_CORE_LICENSE_H_*/
