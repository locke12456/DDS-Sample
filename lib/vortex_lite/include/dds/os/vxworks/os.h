#ifndef _OS_VXWORKS_OS_H_
#define _OS_VXWORKS_OS_H_

/* Obtain the VxWorks version only */

#ifdef IMPORT
#include <version.h>
#else
#define IMPORT extern
#include <version.h>
#undef IMPORT
#endif

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <assert.h>
#include <inttypes.h>
#include <string.h>
#include <sched.h>
#include <time.h>
#include <sys/time.h>

#ifdef VXWORKS_RTP
#include <strings.h>
#if defined (VXWORKS_69) || defined (VXWORKS_68)
#define OS_HAS_TSD_USING_THREAD_KEYWORD 1
#endif
#endif
#endif

#undef m_next
#undef m_flags
#undef m_data
#undef m_type
#undef m_len

#ifdef _WRS_KERNEL
#define PRId64 "lld"
#define PRIu64 "llu"
#define PRIi64 "lli"
#ifdef PA__64BIT
#define INT64_C(x) x##l
#define UINT64_C(x) x##ul
#else
#define INT64_C(x) x##ll
#define UINT64_C(x) x##ull
#endif
#endif
