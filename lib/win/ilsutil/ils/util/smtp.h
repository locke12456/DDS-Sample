//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/smtp.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_SMTP_H_
#define ILS_UTIL_SMTP_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int smtp_mail_create(void **handle, const char *server, const char* from);
UTIL_EXPORT int smtp_mail_delete(void *handle);

UTIL_EXPORT int smtp_mail_connect(void *handle);
UTIL_EXPORT int smtp_mail_ssl_connect(void *handle);
UTIL_EXPORT int smtp_mail_starttls_connect(void *handle);
UTIL_EXPORT int smtp_mail_auth_normal(void *handle, const char *username, const char *password);
UTIL_EXPORT int smtp_mail_disconnect(void *handle);
UTIL_EXPORT int smtp_mail_send(void *handle, const char *subject, const char *data);
UTIL_EXPORT const char *smtp_mail_last_cmd(void *handle);

UTIL_EXPORT int smtp_mail_set_from(void* handle, const char* from);
UTIL_EXPORT int smtp_mail_set_to(void* handle, const char* to);
UTIL_EXPORT int smtp_mail_set_cc(void* handle, const char* cc);
UTIL_EXPORT int smtp_mail_set_bcc(void* handle, const char* bcc);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_SMTP_H_*/
