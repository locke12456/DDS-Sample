//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/schedule.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_SCHEDULE_H_
#define DW_CORE_SCHEDULE_H_

#ifdef __cplusplus
extern "C" {
#endif

DWCORE_EXPORT int schedule_create(void **schedule, void *properties,pool_callback callback,void *arg0,void *arg1, void *arg2);
DWCORE_EXPORT int schedule_delete(void *schedule);
DWCORE_EXPORT int schedule_verify(void *properties);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_SCHEDULE_H_*/
