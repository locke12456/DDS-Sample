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
#ifndef V_DATAREADERSTATISTICS_H
#define V_DATAREADERSTATISTICS_H

#include "v_kernel.h"
#include "os_if.h"

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

/**
 * \brief The <code>v_readerStatistics</code> cast method.
 *
 * This method casts an object to a <code>v_readerStatistics</code> object.
 * Before the cast is performed, if compiled with the NDEBUG flag not set,
 * the type of the object is checked to be <code>v_readerStatistics</code> or
 * one of its subclasses.
 */
#define v_dataReaderStatistics(s) (C_CAST(s,v_dataReaderStatistics))

OS_API v_dataReaderStatistics
v_dataReaderStatisticsNew(
    v_kernel k);

OS_API void
v_dataReaderStatisticsInit(
    v_dataReaderStatistics _this);

OS_API void
v_dataReaderStatisticsDeinit(
    v_dataReaderStatistics _this);

OS_API void
v_readerStatisticsFree(
    v_dataReaderStatistics _this);

#undef OS_API

#endif
