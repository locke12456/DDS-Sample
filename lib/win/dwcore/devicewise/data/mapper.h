//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/mapper.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_MAPPER_H_
#define DW_DATA_MAPPER_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void DW_MAPPER_ENTRY;

typedef void (*mapper_fefunc)(const DW_MAPPER_ENTRY *item,void *args);

DWDATA_EXPORT int mapper_create(DW_MAPPER_ENTRY **mapping);
DWDATA_EXPORT void mapper_free(DW_MAPPER_ENTRY *mapping);
DWDATA_EXPORT int mapper_fixup_hash(DW_MAPPER_ENTRY *mapper);
DWDATA_EXPORT unsigned long long mapper_get_hash(DW_MAPPER_ENTRY *mapper);

DWDATA_EXPORT int mapper_add(DW_MAPPER_ENTRY *mapping, void *secctx, int op);
DWDATA_EXPORT int mapper_edit(DW_MAPPER_ENTRY *mapping, void *secctx, int op);
DWDATA_EXPORT int mapper_del(long long hash, void *secctx, int op);
DWDATA_EXPORT int mapper_start(long long hash, void *secctx, int op);
DWDATA_EXPORT int mapper_stop(long long hash, void *secctx, int op);
DWDATA_EXPORT int mapper_clear_counters(long long hash, void *secctx, int op);
DWDATA_EXPORT void mapper_foreach(mapper_fefunc func, void *args);

DWDATA_EXPORT int mapper_get_xml(long long hash, char **xml);
DWDATA_EXPORT int mapper_xml_to_object(const char *xml, DW_MAPPER_ENTRY *mapper);

#ifdef __cplusplus
}
#endif

#endif /*DW_DATA_MAPPER_H_*/
