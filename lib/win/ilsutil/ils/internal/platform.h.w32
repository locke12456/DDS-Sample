//----------------------------------------------------------------
//
//-- Filename: ilsutil_platform.h
//-- THIS HEADER IS AUTOMATICALLY INCLUDED IN: ilsutil.h!
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------
#ifndef _ILSUTIL_PLATFORM_H
#define _ILSUTIL_PLATFORM_H

#define UTIL_PACKAGE_VERSION "2.0"
#define UTIL_PACKAGE_NAME "ILSUTIL"

#undef ILS_BIG_ENDIAN
#define ILS_LITTLE_ENDIAN 1
#undef CROSS_ENDIAN_DOUBLES

#if defined(_WIN32)
#  include <winsock.h>
#  include <windows.h>
#  include <Iphlpapi.h>
#  include <direct.h>
#  include <process.h>
#  include <io.h>
#  include <errno.h>
#  if defined (_MSC_VER) && (_MSC_VER >= 1020)
#    define strcasecmp(one,two) _strcmpi(one,two)
#  else
#    define strcasecmp(one,two) strcmpi(one,two)
#  endif
#  define strncasecmp(one,two,len) _strnicmp(one,two,len)
#  define strtoll(one,two,three) _strtoi64(one,two,three)
#  define strtoull(one,two,three) _strtoui64(one,two,three)
#  define strtok_r(one,two,three) strtok(one,two)
#  define snprintf _snprintf
#  define MSG_NOSIGNAL 0
#  define GETNETERR() WSAGetLastError()
#  undef Yield
#  if defined(EXPORT_UTIL_SYMS)
#    define UTIL_EXPORT __declspec(dllexport)
#  else
#    define UTIL_EXPORT __declspec(dllimport)
#  endif
#endif

#undef USE_STATIC_SQLITE3

#undef HAS_SEMTIMEDWAIT
#undef HAS_STRTOK_R

#if defined(HAVE_ARPA_INET_H)
#  include <arpa/inet.h>
#endif

#if defined(HAVE_BYTESWAP_H)
#  include <byteswap.h>
#endif

#if defined(HAVE_ENDIAN_H)
#  include <endian.h>
#endif

#if defined(HAVE_ERRNO_H)
#  include <errno.h>
#endif

#if defined(HAVE_FCNTL_H)
#  include <fcntl.h>
#endif

#if defined(HAVE_MALLOC_H)
#  include <malloc.h>
#endif

#if defined(HAVE_NETDB_H)
#  include <netdb.h>
#endif

#if defined(HAVE_NET_IF_H)
#  include <net/if.h>
#endif

#if defined(HAVE_NETINET_IN_H)
#  include <netinet/in.h>
#endif

#if defined(HAVE_NETINET_TCP_H)
#  include <netinet/tcp.h>
#endif

#if defined(HAVE_PTHREAD_H)
#  include <pthread.h>
#endif

#if defined(HAVE_SEMAPHORE_H)
#  include <semaphore.h>
#endif

#if defined(HAVE_SIGNAL_H)
#  include <signal.h>
#endif

#if defined(HAVE_STDARG_H)
#  include <stdarg.h>
#endif

#if defined(HAVE_FNMATCH_H)
#  include <fnmatch.h>
#endif

#if defined(HAVE_DIRENT_H)
#  include <dirent.h>
#endif

#if defined(HAVE_SYS_BYTEORDER_H)
#  include <sys/byteorder.h>
#endif

#if defined(HAVE_SYS_IOCTL_H)
#  include <sys/ioctl.h>
#endif

#if defined(HAVE_SYS_IPC_H)
#  include <sys/ipc.h>
#endif

#if defined(HAVE_SYS_MMAN_H)
#  include <sys/mman.h>
#endif

#if defined(HAVE_SYS_SELECT_H)
#  include <sys/select.h>
#endif

#if defined(HAVE_SYS_SEM_H)
#  include <sys/sem.h>
#endif

#if defined(HAVE_SYS_SHM_H)
#  include <sys/shm.h>
#endif

#if defined(HAVE_SYS_SOCKET_H)
#  include <sys/socket.h>
#endif

#if defined(HAVE_SYS_STAT_H)
#  include <sys/stat.h>
#endif

#if defined(HAVE_SYS_TIME_H)
#  include <sys/time.h>
#endif

#if defined(HAVE_SYS_TYPES_H)
#  include <sys/types.h>
#endif

#if defined(HAVE_SYS_UTSNAME_H)
#  include <sys/utsname.h>
#endif

#if defined(HAVE_SYS_XTI_INET_H)
#  include <sys/xti_inet.h>
#endif

#if defined(HAVE_TIME_H)
#  include <time.h>
#endif

#if defined(HAVE_UNISTD_H)
#  include <unistd.h>
#endif

#if defined(HAVE_UTIME_H)
#  include <utime.h>
#endif

#if defined(HAVE_DLFCN_H)
#  include <dlfcn.h>
#endif

#if defined(HAVE_ICONV_H)
#  include <iconv.h>
#endif

#if defined(HAVE_SQLITE3_H)
#  include <sqlite3.h>
#endif

#if defined(HAVE_ZLIB_H)
#  include <zlib.h>
#endif

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#endif
