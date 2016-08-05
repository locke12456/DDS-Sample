//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/reset.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_RESET_H_
#define DW_CORE_RESET_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*reset_callback)();

DWCORE_EXPORT int reset_callback_register(reset_callback callback, const char *by);
DWCORE_EXPORT int reset_protect_table(const char *tablename);
DWCORE_EXPORT int reset_protect_index(const char *indexname);

DWCORE_EXPORT void reset();

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_RESET_H_*/
