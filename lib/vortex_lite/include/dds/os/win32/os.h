#ifndef _OS_WIN32_OS_H_
#define _OS_WIN32_OS_H_

#ifndef __cplusplus
#define restrict _restrict
#define inline __inline
#endif

#ifndef VL_NO_DLL
#define _WIN32_DLL_
#endif

#ifdef _MSC_VER
#if _MSC_VER < 1900
#define snprintf _snprintf
#endif
#endif

#include <io.h>
#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <winsock2.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <io.h>
#include <process.h>
#include <WS2tcpip.h>
#include <inttypes.h>
#include <ctype.h>

#endif
