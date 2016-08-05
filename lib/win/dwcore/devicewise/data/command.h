//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/command.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_COMMAND_H_
#define DW_DATA_COMMAND_H_

#ifdef __cplusplus
extern "C" {
#endif

DWDATA_EXPORT int device_command_execute(DW_DEVICE *dev, const char *name, void *secctx, int op);

DWDATA_EXPORT int cinfo_create(DW_COMMAND_INFO **cinfo, const char *name, int name_nls, int options);
DWDATA_EXPORT void cinfo_delete(DW_COMMAND_INFO *cinfo);
DWDATA_EXPORT int cinfo_object_to_xmlwriter(const DW_COMMAND_INFO *cinfo, void *writer);
DWDATA_EXPORT int cinfo_object_to_xml(const DW_COMMAND_INFO *cinfo, char **xml);
DWDATA_EXPORT int cinfo_xml_to_object(DW_COMMAND_INFO **cinfo, void *reader);

#ifdef __cplusplus
}
#endif

#endif /*DW_DATA_COMMAND_H_*/
