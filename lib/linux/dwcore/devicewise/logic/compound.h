//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Logic Subsystem
//
//-- Filename: devicewise/logic/compound.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_LOGIC_COMPOUND_H_
#define DW_LOGIC_COMPOUND_H_

#ifdef __cplusplus
extern "C" {
#endif

DWLOGIC_EXPORT int compound_string_count_params(const char *fmt);
DWLOGIC_EXPORT int compound_string_parse_to_variable(const char *fmt, void *input_var_btree, DW_VARIABLE_DATA *output_var, char array_delim);
DWLOGIC_EXPORT int compound_string_parse_to_string(const char *fmt, void *input_var_btree, char **str, char array_delim);
DWLOGIC_EXPORT int compound_string_parse_metadata(const char *fmt, void *input_vinfo_btree);

#ifdef __cplusplus
}
#endif

#endif /*DW_LOGIC_COMPOUND_H_*/
