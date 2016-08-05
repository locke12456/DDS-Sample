//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/nls.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_NLS_H_
#define DW_CORE_NLS_H_

#ifdef __cplusplus
extern "C" {
#endif

DWCORE_EXPORT const char *nls_string_get(int msgid);
DWCORE_EXPORT const char *nls_string_find(int msgid);
DWCORE_EXPORT const char *nls_filename_get();
DWCORE_EXPORT char *nls_string_format(int msgid, const char *arg1,const char *arg2,const char *arg3,const char *arg4,const char *arg5);
DWCORE_EXPORT int nls_is_ready();

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_NLS_H_*/
