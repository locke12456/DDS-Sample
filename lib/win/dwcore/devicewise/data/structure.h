//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/structure.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_STRUCTURE_H_
#define DW_DATA_STRUCTURE_H_

#ifdef __cplusplus
extern "C" {
#endif

DWDATA_EXPORT long long sinfo_name_hash(const void *var);
DWDATA_EXPORT long long sinfo_id_hash(const void *var);
DWDATA_EXPORT int sinfo_create(DW_STRUCTURE_INFO **sinfo, const char *name, int id, int options);
DWDATA_EXPORT void sinfo_delete(DW_STRUCTURE_INFO *sinfo);
DWDATA_EXPORT int sinfo_add_member(DW_STRUCTURE_INFO *sinfo,DW_VARIABLE_INFO *vinfo);
DWDATA_EXPORT int sinfo_foreach_member(const DW_STRUCTURE_INFO *sinfo, btree_fefunc func,void *args);
DWDATA_EXPORT int sinfo_count_members(DW_STRUCTURE_INFO *sinfo);
DWDATA_EXPORT int sinfo_find_member(const DW_STRUCTURE_INFO *sinfo, const char *name, DW_VARIABLE_INFO **vinfo);

DWDATA_EXPORT int sinfo_xml_to_object(DW_STRUCTURE_INFO **sinfo, void *reader);

#ifdef __cplusplus
}
#endif

#endif /*DW_DATA_STRUCTURE_H_*/
