//----------------------------------------------------------------
//
//-- Filename: ils/logging/appenders.h
//-- THIS HEADER IS AUTOMATICALLY INCLUDED IN: ils/logging/log.h!
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_LOGGING_APPENDERS_H_
#define ILS_LOGGING_APPENDERS_H_

#ifdef __cplusplus
extern "C" {
#endif

char *appender_format(void *handle, int level, const char *msg, 
			const char *path, const char *file, int line);

int appender_create(void **handle, const char *name, const char *type);
int appender_delete(void *handle);

void *appender_find(const char *name);

void appender_setopt(void *handle, const char *option, const char *value);
void appender_print(void *handle, int level, const char *msg, const char *path, const char *file, int line);

int appender_create_console(void **handle);
int appender_delete_console(void *handle);
void appender_setopt_console(void *handle, const char *option, const char *value);
void appender_print_console(void *handle,char *msg);

int appender_create_file(void **handle);
int appender_delete_file(void *handle);
void appender_setopt_file(void *handle, const char *option, const char *value);
void appender_print_file(void *handle,char *msg);

int appender_create_rolling(void **handle);
int appender_delete_rolling(void *handle);
void appender_setopt_rolling(void *handle, const char *option, const char *value);
void appender_print_rolling(void *handle,char *msg);

int appender_create_telnet(void **handle);
int appender_delete_telnet(void *handle);
void appender_setopt_telnet(void *handle, const char *option, const char *value);
void appender_print_telnet(void *handle,char *msg);


#ifdef __cplusplus
}
#endif

#endif /*ILS_LOGGING_APPENDERS_H_*/
