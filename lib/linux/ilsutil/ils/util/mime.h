//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/mime.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_MIME_H_
#define ILS_UTIL_MIME_H_

#ifdef __cplusplus
extern "C" {
#endif

UTIL_EXPORT int mime_init(void *blob);
UTIL_EXPORT int mime_end(void *blob);
UTIL_EXPORT int mime_add_text_part(void *blob, const char *text);
UTIL_EXPORT int mime_add_html_part(void *blob, const char *html);
UTIL_EXPORT int mime_add_attachment_part(void *blob, const char *filename, void *data, int len);
UTIL_EXPORT int mime_add_attachment_file(void *blob, const char *filename);
UTIL_EXPORT int mime_add_attachment_file_with_name(void *blob, const char *filename, const char *name);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_MIME_H_*/
