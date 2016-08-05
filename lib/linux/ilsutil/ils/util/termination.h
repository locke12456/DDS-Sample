//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/termination.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_TERMINATION_H_
#define ILS_UTIL_TERMINATION_H_

#ifdef __cplusplus
extern "C" {
#endif

#define TERMINATED_BY_CRASH		1
#define TERMINATED_BY_SHUTDOWN	2

typedef void (*termination_callback)(int reason);

UTIL_EXPORT void termination_set_callback( termination_callback callback );
UTIL_EXPORT void termination_install_callback( termination_callback callback );
UTIL_EXPORT void termination_call_exit_handler();

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_TERMINATION_H_*/
