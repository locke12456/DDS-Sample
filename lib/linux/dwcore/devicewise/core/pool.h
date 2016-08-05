//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/pool.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_POOL_H_
#define DW_CORE_POOL_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*pool_callback)(int id, void *a, void *b, void *c);

DWCORE_EXPORT int pool_put_work(const char *who, pool_callback func, void *a, void *b, void *c);
DWCORE_EXPORT int pool_put_scheduled_work(const char *who, void **handle, int interval, int repeat, pool_callback func, void *a, void *b, void *c);
DWCORE_EXPORT int pool_end_scheduled_work(void *handle);
DWCORE_EXPORT int pool_update_scheduled_work(void *handle, int interval);

DWCORE_EXPORT int pool_set_detail(int id, const char *detail);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_POOL_H_*/
