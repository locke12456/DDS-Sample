//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/os.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_OS_H_
#define DW_CORE_OS_H_

#define OS_NAME_LEN			128
#define OS_DISK_NAME_LEN	255
#define OS_DISK_MAX			25
#define NETWORK_TYPE_DHCP		0
#define NETWORK_TYPE_STATIC		1

#define NETWORK_MAX_INTERFACE	16
#define NETWORK_MAX_DNS			16

#define OS_NETWORK_DHCP_DISABLED		0
#define OS_NETWORK_DHCP_ENABLED			1
#define OS_NETWORK_DHCP_NOTAVAILABLE	2

#define OS_NETWORK_STATE_NOT_AVAIL		0
#define OS_NETWORK_STATE_ENABLED		1
#define OS_NETWORK_STATE_DISABLED		2

#define OS_CHNL_TIME_CHANGED		0
#define OS_CHNL_ZONE_CHANGED		1

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	char *address;
} DW_OS_NET_DNS;

typedef struct {
	char *key;
	char *name;
	int state;
	int	is_dhcp;
	int is_dhcp_dns;
	char *address;
	char *mask;
	char *broadcast;
	char *gateway;
	char *hwaddr;
	DW_OS_NET_DNS dns[NETWORK_MAX_DNS];
	int dns_count;
	char *domain;
} DW_OS_NET_INTERFACE;

typedef struct {
	char *hostname;
	char *search_path;
	char *domain;
	DW_OS_NET_INTERFACE iface[NETWORK_MAX_INTERFACE];
	DW_OS_NET_DNS dns[NETWORK_MAX_DNS];
	int interface_count;
	int dns_count;
} DW_OS_NET_INFO;

typedef struct {
	char physical_name[OS_DISK_NAME_LEN+4];
	char logical_name[OS_DISK_NAME_LEN+4];
	int free_kb;
	int total_kb;
} DW_OS_DISK_OBJECT;

typedef int (*disk_usage_get_callback)(void *disk_btree);
typedef int (*memory_get_usage_callback)(int *usage);
typedef int (*memory_get_usage_ex_callback)(int *usage, long long *bytes_used, long long *bytes_total);
typedef int (*memory_get_physical_ex_callback)(int *usage, long long *bytes_used, long long *bytes_total);
typedef int (*cpu_get_usage_callback)(int *usage);

typedef int (*network_set_callback)(const DW_OS_NET_INFO *network_info);
typedef int (*network_set_dns_callback)(const DW_OS_NET_INFO *network_info);
typedef int (*network_set_iface_callback)(const DW_OS_NET_INFO *network_info);
typedef int (*network_get_callback)(DW_OS_NET_INFO **network_info);

typedef int (*process_list_callback)(char **xml);
typedef int (*process_get_callback)(int pid, char **xml);
typedef int (*process_memory_get_usage_callback)(void *pid, long long *usage);

typedef int (*time_set_callback)(long long mstime);
typedef int (*time_get_callback)(long long *mstime);
typedef int (*time_detailed_callback)(long long *current_time, long long *offset_from_gmt, int *in_dst, const char **time_zone);

typedef int (*timezone_set_callback)(const char *tz, int adjust_for_dst);
typedef int (*timezone_get_callback)(char **tz, int *adjust_for_dst, int *dst_state);
typedef int (*timezone_list_callback)(char **xml);

typedef int (*timesync_set_callback)(const char *sync);
typedef int (*timesync_get_callback)(char **sync);

typedef int (*reboot_callback)(void);
typedef int (*shutdown_callback)(void);

typedef struct {
	char os_name[OS_NAME_LEN];
	disk_usage_get_callback disk_usage_get;
	memory_get_usage_callback memory_get_usage;
	memory_get_usage_ex_callback memory_get_usage_ex;
	memory_get_physical_ex_callback memory_get_physical_ex;
	cpu_get_usage_callback cpu_get_usage;
	network_set_callback network_set;
	network_set_dns_callback network_dns_set;
	network_set_iface_callback network_iface_set;
	network_get_callback network_get;
	process_list_callback process_list;
	process_get_callback process_get;
	process_memory_get_usage_callback process_memory_get_usage;
	time_set_callback time_set;
	time_get_callback time_get;
	time_detailed_callback time_detailed;
	timezone_set_callback timezone_set;
	timezone_get_callback timezone_get;
	timezone_list_callback timezone_list;
	timesync_set_callback timesync_set;
	timesync_get_callback timesync_get;
	reboot_callback reboot;
	shutdown_callback shutdownos;
	int os_opt;
} OS_REG;

#define DW_OS_GLOBAL_DNS	1
#define DW_OS_AUTO_DNS		2

DWCORE_EXPORT int os_register(const OS_REG *os_reg);
DWCORE_EXPORT int os_list();

DWCORE_EXPORT int os_disk_usage_get(void *disk_btree);
DWCORE_EXPORT int os_memory_get_usage(int *usage);
DWCORE_EXPORT int os_memory_get_usage_ex(int *usage, long long *bytes_used, long long *bytes_total);
DWCORE_EXPORT int os_memory_get_physical_ex(int *usage, long long *bytes_used, long long *bytes_total);
DWCORE_EXPORT int os_memory_usage_too_high();
DWCORE_EXPORT int os_cpu_get_usage(int *usage);

DWCORE_EXPORT int os_network_set(const char *xml,void *secctx, int opt);
DWCORE_EXPORT int os_network_dns_set(const char *xml, void *secctx, int opt);
DWCORE_EXPORT int os_network_iface_set(const char *xml,void *secctx, int opt);
DWCORE_EXPORT int os_network_get(char **xml);

DWCORE_EXPORT int os_network_dns_set_info(DW_OS_NET_INFO *net_info, void *secctx, int opt);
DWCORE_EXPORT int os_network_iface_set_info(DW_OS_NET_INFO *net_info, void *secctx, int opt);
DWCORE_EXPORT int os_network_set_info(DW_OS_NET_INFO *net_info, void *secctx, int opt);
DWCORE_EXPORT int os_network_get_info(DW_OS_NET_INFO **net_info);
DWCORE_EXPORT void os_network_del_info(DW_OS_NET_INFO *net_info);

DWCORE_EXPORT int os_process_list(char **xml);
DWCORE_EXPORT int os_process_get(int pid, char **xml);
DWCORE_EXPORT int os_process_memory_get_usage(void *pid, long long *usage);

DWCORE_EXPORT int os_time_set(long long mstime,void *secctx, int op);
DWCORE_EXPORT int os_time_get(long long *mstime);
DWCORE_EXPORT int os_time_detailed(long long *current_time, long long *offset_from_gmt, int *in_dst, const char **time_zone);

DWCORE_EXPORT int os_timezone_set(const char *tz, int adjust_for_dst);
DWCORE_EXPORT int os_timezone_get(char **tz, int *adjust_for_dst, int *dst_state);
DWCORE_EXPORT int os_timezone_list(char **xml);

DWCORE_EXPORT int os_timesync_set(const char *sync);
DWCORE_EXPORT int os_timesync_get(char **sync);

DWCORE_EXPORT int os_reboot(void *secctx,int op);
DWCORE_EXPORT int os_reboot_disabled();
DWCORE_EXPORT int os_reboot_try(void *secctx,int op);
DWCORE_EXPORT int os_is_rebooting();

DWCORE_EXPORT int os_shutdown(void *secctx,int op);
DWCORE_EXPORT int os_shutdown_disabled();

DWCORE_EXPORT const char *os_serial_resolve_name(const char *name);
DWCORE_EXPORT const char *os_serial_list();

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_OS_H_*/
