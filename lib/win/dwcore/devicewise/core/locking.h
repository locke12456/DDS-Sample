//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/locking.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_LOCKING_H_
#define DW_CORE_LOCKING_H_

#ifdef __cplusplus
extern "C" {
#endif

DWCORE_EXPORT const char* locking_try_lock(const char *key);

DWCORE_EXPORT int locking_lock(const char *key, const char *component, char **lockedby);
DWCORE_EXPORT int locking_unlock(const char *key, const char *component, char **lockedby);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_LOCKING_H_*/
