//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/internal/variable.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_INTERNAL_VARIABLE_H_
#define DW_DATA_INTERNAL_VARIABLE_H_

#define VARIABLE_EMPTY_CHAR 0xFF

DWDATA_EXPORT int variable_alloc_data(DW_VARIABLE_DATA *var);

int variable_validate_name(const char *name);

#endif /*DW_DATA_INTERNAL_VARIABLE_H_*/
