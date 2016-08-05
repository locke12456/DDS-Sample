//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/safemode.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_SAFEMODE_H_
#define DW_CORE_SAFEMODE_H_

#ifdef __cplusplus
extern "C" {
#endif

DWCORE_EXPORT int safemode_disable_on_reboot();
DWCORE_EXPORT int safemode_return();
DWCORE_EXPORT int safemode_is_on();
DWCORE_EXPORT long long safemode_end_time();
DWCORE_EXPORT int safemode_register_callback(pool_callback callback);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_SAFEMODE_H_*/
