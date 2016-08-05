//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/common/validate.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_COMMON_VALIDATE_H_
#define DW_COMMON_VALIDATE_H_

#ifdef __cplusplus
extern "C" {
#endif

DWCOMMON_EXPORT int validate_name_string(const char *str, int max_len);
DWCOMMON_EXPORT int validate_sql_string(const char *str, int max_len);
DWCOMMON_EXPORT int str_is_xml(const char *str);

#ifdef __cplusplus
}
#endif

#endif /*DW_COMMON_VALIDATE_H_*/
