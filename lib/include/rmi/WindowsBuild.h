/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2015 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                   $OSPL_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */
//Exporting items to the DLL's clients:

// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the DDS_SERVICE_DLL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// DDS_SERVICE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

//When building for non Windows systems there is no need for any target specific define.
//When targeting Windows, define _WINDOWS
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
//When building a DLL, not a static library, also define DDS_SERVICE_DLL_EXPORTS.
#ifdef SDK_dll_EXPORTS //appending _EXPORTS to the dll's name is the standard way to do it.
//NB: We could also export our DLL's definitions through the mechanism of ".DEF" files,
//this would use no define in the code...
#define DDS_SERVICE_API __declspec(dllexport)
#else
#define DDS_SERVICE_API __declspec(dllimport)
#endif
#else
// Should only be conditionally included with
//#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#error
// if the condition is not fulfilled then you should define DDS_SERVICE_API to allow error free compiles on non Widows OS'.
#define DDS_SERVICE_API
#endif
