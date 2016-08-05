//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/globals.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_GLOBALS_H_
#define DW_CORE_GLOBALS_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	void *properties;
	void *database;
	void *uproperties;
	void *udatabase;
} DW_GLOBALS;

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_GLOBALS_H_*/
