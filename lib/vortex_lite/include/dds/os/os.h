#ifndef _DDS_OS_H_
#define _DDS_OS_H_

#if defined (os_linux_gcc_x86)
#include "dds/os/linux_gcc_x86.h"
#include "dds/os/linux/os.h"
#endif
#if defined (os_linux_gcc_arm)
#include "dds/os/linux_gcc_arm.h"
#include "dds/os/linux/os.h"
#endif
#if defined (os_solaris_gcc_sparc)
#include "dds/os/solaris_gcc_sparc.h"
#include "dds/os/solaris/os.h"
#endif
#if defined (os_solaris_suncc_sparc)
#include "dds/os/solaris_suncc_sparc.h"
#include "dds/os/solaris/os.h"
#endif
#if defined (os_win32_cl_x86)
#include "dds/os/win32_cl_x86.h"
#include "dds/os/win32/os.h"
#endif
#if defined (os_win32_cl_x64)
#include "dds/os/win32_cl_x64.h"
#include "dds/os/win32/os.h"
#endif
#if defined (os_linux_gcc_x86_linux)
#include "dds/os/linux_gcc_x86_linux.h"
#include "dds/os/linux/os.h"
#endif
#if defined (os_linux_gcc_arm_linux)
#include "dds/os/linux_gcc_arm_linux.h"
#include "dds/os/linux/os.h"
#endif
#if defined (os_linux_gcc_mips_linux)
#include "dds/os/linux_gcc_mips_linux.h"
#include "dds/os/linux/os.h"
#endif
#if defined (os_qnx_gcc_x86_linux)
#include "dds/os/qnx_gcc_x86_linux.h"
#include "dds/os/qnx/os.h"
#endif
#if defined (os_qnx_gcc_arm_linux)
#include "dds/os/qnx_gcc_arm_linux.h"
#include "dds/os/qnx/os.h"
#endif
#if defined (os_vxworks_gnu_x86_linux)
#include "dds/os/vxworks_gnu_x86_linux.h"
#include "dds/os/vxworks/os.h"
#endif
#if defined (os_vxworks_gnu_arm_linux)
#include "dds/os/vxworks_gnu_arm_linux.h"
#include "dds/os/vxworks/os.h"
#endif
#if defined (os_vxworks_gnu_ppc_linux)
#include "dds/os/vxworks_gnu_ppc_linux.h"
#include "dds/os/vxworks/os.h"
#endif
#if defined (os_vxworks_gnu_x86_win32)
#include "dds/os/vxworks_gnu_x86_win32.h"
#include "dds/os/vxworks/os.h"
#endif
#if defined (os_vxworks_gnu_arm_win32)
#include "dds/os/vxworks_gnu_arm_win32.h"
#include "dds/os/vxworks/os.h"
#endif
#if defined (os_vxworks_gnu_ppc_win32)
#include "dds/os/vxworks_gnu_ppc_win32.h"
#include "dds/os/vxworks/os.h"
#endif
#if defined (os_osx_gcc_x64)
#include "dds/os/osx_gcc_x64.h"
#include "dds/os/osx/os.h"
#endif

#ifndef DDS_KEY_BOOL_SIZE
#define DDS_KEY_BOOL_SIZE 1
#define DDS_OP_TYPE_BOO DDS_OP_TYPE_1BY
#define DDS_OP_SUBTYPE_BOO DDS_OP_SUBTYPE_1BY
#endif

#endif
