//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/telnet.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_TELNET_H_
#define DW_CORE_TELNET_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*telnet_command_func)(const char *cmd, const char *argv[], int argc, char **output, void *userctx);

DWCORE_EXPORT int telnet_add_command(const char *command, const char *desc, telnet_command_func func);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_TELNET_H_*/
