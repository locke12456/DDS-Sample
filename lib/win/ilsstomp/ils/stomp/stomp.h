//----------------------------------------------------------------
//
//-- Filename: ils/stomp/stomp.h
//
//----------------------------------------------------------------

#ifndef ILS_STOMP_STOMP_H_
#define ILS_STOMP_STOMP_H_

#if !defined(TRUE)
#  define TRUE 1
#endif
#if !defined(FALSE)
#  define FALSE 0
#endif

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include <ils/util/everything.h>
#include <ils/logging/log.h>

#if defined(_WIN32)
#  if defined(EXPORT_STOMP_SYMS)
#    define STOMP_EXPORT __declspec(dllexport)
#  else
#    define STOMP_EXPORT __declspec(dllimport)
#  endif
#else
#  define STOMP_EXPORT
#endif

#include "ils/stomp/errors.h"
#include "ils/stomp/url.h"
#include "ils/stomp/message.h"
#include "ils/stomp/client.h"
#include "ils/stomp/frame.h"

#define STOMP_CT_TEXT_PLAIN					"text/plain"
#define STOMP_CT_APPLICATION_JSON			"application/json"
#define STOMP_CT_APPLICATION_OCTETSTREAM	"application/octet-stream"

#endif
