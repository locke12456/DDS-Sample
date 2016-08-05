//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/i18n.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_I18N_H_
#define ILS_UTIL_I18N_H_

#ifdef __cplusplus
extern "C" {
#endif

#define I18N_FORWARD	1
#define I18N_BACKWARD	2
#define I18N_BOTH		I18N_FORWARD|I18N_BACKWARD

UTIL_EXPORT void i18n_set_global_mapping_directory(const char *dir);

UTIL_EXPORT int i18n2_mapping_load(void **handle2, const char *i18n_src, const char *i18n_dst);
UTIL_EXPORT void i18n2_mapping_free(void *handle2);

UTIL_EXPORT int i18n2_convert(void *handle2, const char *srcstr, int srclen, char **dststr, int *dstlen);

UTIL_EXPORT int  i18n_mapping_load(void **handle, const char *i18n_name, int direction);
UTIL_EXPORT const char *i18n_mapping_name(void *handle);
UTIL_EXPORT int  i18n_mapping_count(void *handle);
UTIL_EXPORT void i18n_mapping_free(void *handle);

UTIL_EXPORT int i18n_convert(void *srcmap, void *dstmap, const char *srcstr, int srclen, char **dststr, int *dstlen);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_I18N_H_*/
