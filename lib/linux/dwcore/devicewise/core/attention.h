//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/attention.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_ATTENTION_H_
#define DW_CORE_ATTENTION_H_

#ifdef __cplusplus
extern "C" {
#endif

DWCORE_EXPORT int attn_register_source(const char *key, const char *name, int name_nls, int desc_nls);
DWCORE_EXPORT void attn_clear(const char *key, const char *msg, void *secctx, int op);
DWCORE_EXPORT void attn_set(const char *key, const char *msg, void *secctx, int op);
DWCORE_EXPORT int attn_get();

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_ATTENTION_H_*/
