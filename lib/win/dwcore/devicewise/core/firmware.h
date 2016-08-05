//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/firmware.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_FIRMWARE_H_
#define DW_CORE_FIRMWARE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*package_fefunc)(const char *key, const char *name, const char *type, const char *ver, const char *dwver, const char *build, void *custom);
DWCORE_EXPORT int package_foreach(package_fefunc func, void *custom);
DWCORE_EXPORT int package_install(const char *filename, void *session);
DWCORE_EXPORT int package_install2(const char *filename, void *session, const char *confirmation);
DWCORE_EXPORT int package_uninstall(const char *package_name, void *session);
DWCORE_EXPORT int package_validate(const char *filename, void *session);

DWCORE_EXPORT int firmware_update(const char *filename);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_FIRMWARE_H_*/
