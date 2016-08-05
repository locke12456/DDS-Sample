//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Binary Encoding Support
//
//-- Filename: devicewise/sandbox/binary.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_BINARY_ENCODING_H_
#define DW_DATA_BINARY_ENCODING_H_

typedef void (*binary_encoding_callback)(DW_VARIABLE_INFO *vinfo, int offset, int interval, int swap, const char *special, void *custom);
DWDATA_EXPORT void binary_encoding_vinfo_foreach(JSON *json, binary_encoding_callback callback, void *custom);
	
#endif /*DW_DATA_BINARY_ENCODING_H_*/

