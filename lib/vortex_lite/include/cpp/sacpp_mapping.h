/*
 *                         Vortex Lite
 *
 *   This software and documentation are Copyright 2006 to 2015 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $LITE_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */
#ifndef SACPP_MAPPING_H
#define SACPP_MAPPING_H

#ifdef _WIN32
#pragma warning( disable: 4251 )
#endif

#if defined (_MSC_VER)
    #pragma warning(disable:4250)
#endif /* _MSC_VER */

#include "sacpp_dds_basic_types.h"
#include "sacpp_LocalObject.h"
#include "sacpp_ValueBase.h"
#include "sacpp_UserException.h"
#include "sacpp_SystemException.h"
#include "sacpp_Exception.h"
#include "sacpp_ExceptionInitializer.h"

#include "mapping/UVAL.h"
#include "mapping/ARRAY.h"
#include "mapping/IFACE.h"
#include "mapping/Memory.h"
#include "mapping/SEQ.h"
#include "mapping/String.h"
#include "mapping/STRUCT.h"
#include "mapping/UFL.h"
#include "mapping/BFL.h"
#include "mapping/UOBJ.h"
#include "mapping/UVL.h"
#include "mapping/BVL.h"
#include "mapping/VALUE.h"
#include "mapping/BSTR.h"

#endif /* SACPP_MAPPING_H */
