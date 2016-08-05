//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/common/preamble.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_COMMON_PREAMBLE_H_
#define DW_COMMON_PREAMBLE_H_

typedef struct {
	int preamble_size;
	int preamble_version;
	int core_major_version;
	int core_minor_version;
	int product_type_id;
	char[12] unused;
	char[128] product_name;
	char[32] product_version;
	char[128] module_name;
	char[192] unused2;
} PREAMBLE_OBJECT;

#endif /*DW_COMMON_PREAMBLE_H_*/
