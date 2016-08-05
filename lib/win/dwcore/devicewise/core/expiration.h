//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/expiration.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_EXPIRATION_H_
#define DW_CORE_EXPIRATION_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*expiration_func)(int pool_id, int hash, void *item);
DWCORE_EXPORT int expiration_add(const char *who, int hash, void *item, expiration_func callback, int timeout);
DWCORE_EXPORT void *expiration_find_and_remove(const char *who, int hash);
DWCORE_EXPORT int expiration_update(const char *who, int hash, int timeout);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_EXPIRATION_H_*/
