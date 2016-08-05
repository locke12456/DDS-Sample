/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2015 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE 
 *
 *   for full copyright notice and license terms. 
 *
 */

#ifndef OS_LINUX_SIGNAL_H
#define OS_LINUX_SIGNAL_H

/* Include common header file              */
#include "../common/include/os_signal.h"

#include "signal.h"

typedef sigset_t		os_os_sigset;

typedef struct sigaction	os_os_sigaction;

typedef int			os_os_signal;

typedef void (*os_os_actionHandler)(int,  siginfo_t *, void *);

#endif /* OS_LINUX_SIGNAL_H */
