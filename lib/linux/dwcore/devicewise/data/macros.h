//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/macros.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_MACROS_H_
#define DW_DATA_MACROS_H_

#ifdef __cplusplus
extern "C" {
#endif

///  Macro to create a DW_VARIABLE_INFO object and add it to a DW_DEVICE
/// 
/// \param logger is a pointer to an ILS Logger object. 
/// \param dev is a pointer to a DW_DEVICE object. The DW_VARIABLE_INFO object will be added to the dev object's collection of variables
/// \param vinfo is a pointer DW_VARIABLE_INFO object. The vinfo_create() function will be called to allocate memory for this object. If successfully created, the object will be added to the device through the device_vinfo_add() function
/// \param vname is a constant character pointer. It contains the name to be assigned to the DW_VARIABLE_INFO variable.
/// \param vtype is an integer code that corresponds to a deviceWISE data type.
/// \param voptions is a number created by OR'ing together deviceWISE properties such as DW_READABLE and DW_WRITEABLE
/// \sa constants.h, device.h, and variable.h
/// \return The vinfo item will contain a pointer to a DW_VARIABLE_INFO object
#define DEVICE_ADD_VINFO(logger,dev,vinfo,vname,vtype,voptions) { \
	if( (ret=vinfo_create(&vinfo,vname,vtype,voptions))!=0 ) { \
		lwarn(logger,format("vinfo_create(): %d",ret)); \
	} else { \
		ldebug2(logger,"vinfo_create(): OK"); \
		if( (ret=device_vinfo_add(dev,vinfo))!=0 ) { \
			lwarn(logger,format("device_vinfo_add(): %d",ret)); \
			vinfo_delete(vinfo); \
		} else { ldebug2(logger,"device_vinfo_add(): OK"); } } }


///  Macro to create a DW_STRUCTURE_INFO object and add it to a DW_DEVICE
/// 
/// \param logger is a pointer to an ILS Logger object. 
/// \param dev is a pointer to a DW_DEVICE object. The DW_VARIABLE_INFO object will be added to the dev object's collection of variables
/// \param sinfo is a pointer DW_STRUCTURE_INFO object. The sinfo_create() function will be called to allocate memory for this object. If successfully created, the object will be added to the device through the device_sinfo_add() function
/// \param sname is a constant character pointer. It contains the name to be assigned to the DW_STRUCTURE_INFO variable.
/// \param sid is an integer that corresponds to structure id number being assigned to the DW_STRUCTURE_INFO object
/// \param soptions is a number created by OR'ing together deviceWISE properties such as DW_READABLE and DW_WRITEABLE
/// \sa constants.h, device.h, and variable.h
/// \return The vinfo item will contain a pointer to a DW_VARIABLE_INFO object
#define DEVICE_ADD_SINFO(logger,dev,sinfo,sname,sid,soptions) { \
	if( (ret=sinfo_create(&sinfo,sname,sid,soptions))!=0 ) { \
		lwarn(logger,format("sinfo_create(): %d",ret)); \
	} else { \
		ldebug2(logger,"sinfo_create(): OK"); \
		if( (ret=device_sinfo_add(dev,sinfo))!=0 ) { \
			lwarn(logger,format("device_sinfo_add(): %d",ret)); \
			sinfo_delete(sinfo); \
		} else { ldebug2(logger,"device_sinfo_add(): OK"); } } }


///  Macro to create a DW_VARIABLE_INFO object and add it to a DW_STRUCTURE_INFO object
/// 
/// \param logger is a pointer to an ILS Logger object. 
/// \param sinfo is a pointer to a DW_STRUCTURE_INFO object. The DW_VARIABLE_INFO object will be added to the sinfo object's collection of variables
/// \param vinfo is a pointer DW_VARIABLE_INFO object. The vinfo_create() function will be called to allocate memory for this object. If successfully created, the object will be added to the structure through the sinfo_add_member() function
/// \param vname is a constant character pointer. It contains the name to be assigned to the DW_VARIABLE_INFO variable.
/// \param vtype is an integer code that corresponds to a deviceWISE data type.
/// \param voptions is a number created by OR'ing together deviceWISE properties such as DW_READABLE and DW_WRITEABLE
/// \sa constants.h, device.h, and variable.h
/// \return The vinfo item will contain a pointer to a DW_VARIABLE_INFO object
 
#define SINFO_ADD_MEMBER(logger,sinfo,vinfo,vname,vtype,voptions) { \
	if( (ret=vinfo_create(&vinfo,vname,vtype,voptions))!=0 ) { \
		lwarn(logger,format("vinfo_create(): %d",ret)); \
	} else { \
		ldebug2(logger,"vinfo_create(): OK"); \
		if( (ret=sinfo_add_member(sinfo,vinfo))!=0 ) { \
			lwarn(logger,format("sinfo_add_member(): %d",ret)); \
			vinfo_delete(vinfo); \
		} else { ldebug2(logger,"sinfo_add_member(): OK"); } } }

#define DEVICE_ADD_CINFO(logger,dev,cinfo,cname,cnlsid,coptions) { \
	if( (ret=cinfo_create(&cinfo,cname,cnlsid,coptions))!=0 ) { \
		lwarn(logger,format("cinfo_create(): %d",ret)); \
	} else { \
		ldebug2(logger,"cinfo_create(): OK"); \
		if( (ret=device_cinfo_add(dev,cinfo))!=0 ) { \
			lwarn(logger,format("device_cinfo_add(): %d",ret)); \
			cinfo_delete(cinfo); \
		} else { ldebug2(logger,"device_cinfo_add(): OK"); } } }

#ifdef __cplusplus
}
#endif

#endif /*DW_DATA_MACROS_H_*/
