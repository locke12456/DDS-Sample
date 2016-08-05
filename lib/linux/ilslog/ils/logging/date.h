//----------------------------------------------------------------
//
//-- Filename: ils/logging/date.h
//-- THIS HEADER IS AUTOMATICALLY INCLUDED IN: ils/logging/log.h!
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_LOGGING_DATE_H
#define ILS_LOGGING_DATE_H

#ifdef __cplusplus
extern "C" {
#endif

int date_create(void **handle, const char *type);
int date_delete(void *handle);
const char *date_get(void *handle);

int date_create_absolute(void **handle);
const char *date_get_absolute(void *handle);

int date_create_ISO8601(void **handle);
const char *date_get_ISO8601(void *handle);

int date_create_short(void **handle);
const char *date_get_short(void *handle);

int date_create_custom(void **handle, const char *_format);
const char *date_get_custom(void *handle);

#ifdef __cplusplus
}
#endif

#endif
