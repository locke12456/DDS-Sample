//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/debug.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_DEBUG_H_
#define DW_CORE_DEBUG_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*debug_generate_callback)();

DWCORE_EXPORT void debug_generate_register(debug_generate_callback callback);
DWCORE_EXPORT int debug_generate_file();
DWCORE_EXPORT const char *debug_generate_file_name();
DWCORE_EXPORT int debug_mode_is_enabled();


DWCORE_EXPORT int debug_instrument_register(const char *type, const char *name, instrument_header_callback header_func, instrument_callback list_func, instrument_callback detail_func);
DWCORE_EXPORT int debug_instrument_add(const char *type, void *item);
DWCORE_EXPORT int debug_instrument_remove(const char *type, void *item);
DWCORE_EXPORT int debug_instrument_register_handle(const char *type, void *instrument_handle);


#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_DEBUG_H_*/
