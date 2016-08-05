//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/internal/structure.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_INTERNAL_STRUCTURE_H_
#define DW_DATA_INTERNAL_STRUCTURE_H_

typedef struct {
	DW_STRUCTURE_INFO public;
	void *member_list;
} _DW_STRUCTURE_INFO;

DWDATA_EXPORT int sinfo_object_to_xml(const DW_STRUCTURE_INFO *sinfo, void *xmlwriter);
DWDATA_EXPORT int sinfo_xml_to_object(DW_STRUCTURE_INFO **sinfo, void *xmlreader);

DWDATA_EXPORT int sinfo_get(int uid, DW_STRUCTURE_INFO **sinfo);
DWDATA_EXPORT int sinfo_unget(DW_STRUCTURE_INFO *sinfo);

int device_sinfo_find_member(const DW_DEVICE *device, int id, const char *name, DW_VARIABLE_INFO **vinfo);

#endif /*DW_DATA_INTERNAL_STRUCTURE_H_*/
