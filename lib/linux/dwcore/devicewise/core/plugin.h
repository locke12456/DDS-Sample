//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/plugin.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_PLUGIN_H_
#define DW_CORE_PLUGIN_H_

#ifdef __cplusplus
extern "C" {
#endif

#define DW_PLUGIN_NAME_LEN	64

typedef struct {
	char name[DW_PLUGIN_NAME_LEN+1];
	int version_major;
	int version_minor;
	char build[DW_PLUGIN_NAME_LEN+1];
	char author[DW_PLUGIN_NAME_LEN+1];
} DW_PLUGIN_REGISTRATION;

// Required Functions
typedef void (*plugin_install_func)(DW_PLUGIN_REGISTRATION *);
typedef void (*plugin_install_v2_func)(DW_PLUGIN_REGISTRATION *, void *properties);
typedef int (*plugin_interface_func)(void);

typedef void (*plugin_foreach_func)(const char *name, const char *library, const char *author, const char *build, void *custom);
DWCORE_EXPORT int plugin_foreach(plugin_foreach_func func, void *custom);

DWCORE_EXPORT int plugin_get_status(const char *library, const char **status_str);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_PLUGIN_H_*/
