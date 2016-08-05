//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/core.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_CORE_H_
#define DW_CORE_CORE_H_

#define DWCORE_MAJOR_VERSION 12
#define DWCORE_MINOR_VERSION 4

#include <devicewise/common/errors.h>
#include <devicewise/common/common.h>
#include <devicewise/common/validate.h>
#include <devicewise/common/blob.h>
#include <devicewise/common/packet.h>
#include <devicewise/common/propdesc.h>

#include <devicewise/core/alert.h>
#include <devicewise/core/api.h>
#include <devicewise/core/attention.h>
#include <devicewise/core/bridge.h>
#include <devicewise/core/channel.h>
#include <devicewise/core/commands.h>
#include <devicewise/core/config.h>
#include <devicewise/core/debug.h>
#include <devicewise/core/diskwatch.h>
#include <devicewise/core/errors.h>
#include <devicewise/core/expiration.h>
#include <devicewise/core/export.h>
#include <devicewise/core/filesystem.h>
#include <devicewise/core/firmware.h>
#include <devicewise/core/generic.admin.h>
#include <devicewise/core/globals.h>
#include <devicewise/core/hardwareid.h>
#include <devicewise/core/httpsvr.h>
#include <devicewise/core/license.h>
#include <devicewise/core/listener.h>
#include <devicewise/core/locking.h>
#include <devicewise/core/logging.h>
#include <devicewise/core/messages.h>
#include <devicewise/core/module.h>
#include <devicewise/core/network.h>
#include <devicewise/core/netproxy.h>
#include <devicewise/core/nls.h>
#include <devicewise/core/notification.h>
#include <devicewise/core/os.h>
#include <devicewise/core/persistence.h>
#include <devicewise/core/plugin.h>
#include <devicewise/core/pool.h>
#include <devicewise/core/processor.h>
#include <devicewise/core/propdesc.h>
#include <devicewise/core/reference.h>
#include <devicewise/core/reset.h>
#include <devicewise/core/safemode.h>
#include <devicewise/core/security.h>
#include <devicewise/core/session.h>
#include <devicewise/core/schedule.h>
#include <devicewise/core/sqlite.h>
#include <devicewise/core/system.h>
#include <devicewise/core/telnet.h>
#include <devicewise/core/timesync.h>
#include <devicewise/core/usage.h>

#ifdef __cplusplus
extern "C" {
#endif

DWCORE_EXPORT const char *core_build_version();
DWCORE_EXPORT const char *devicewise_version();

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_CORE_H_*/
