//----------------------------------------------------------------
//
//-- Copyright: 2001-2015, ILS Technology, LLC
//
//----------------------------------------------------------------

#include "devicewise/modbus/modbus.h"

char *g_modbus_build_version = NULL;

const char *modbus_build_version(void) {
	if (g_modbus_build_version == NULL)
		g_modbus_build_version = clone_string(format("%s %s", __DATE__, __TIME__), -1);

	return g_modbus_build_version;
}
