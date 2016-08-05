//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/ssl.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_SSL_H_
#define ILS_UTIL_SSL_H_

#ifdef __cplusplus
extern "C" {
#endif

//general SSL functions
UTIL_EXPORT void ssl_init();

UTIL_EXPORT int ssl_is_available();
UTIL_EXPORT const char *ssl_get_version();

UTIL_EXPORT int ssl_connect(void *handle, void *ctx);
UTIL_EXPORT int ssl_accept(void *handle, void *ctx);
UTIL_EXPORT int ssl_verify_peer(void *handle);
UTIL_EXPORT const char *ssl_get_cipher(void *handle);
UTIL_EXPORT const char *ssl_error(void *handle);

UTIL_EXPORT int ssl_ctx_create(void **ctx);
UTIL_EXPORT int ssl_ctx_delete(void *ctx);
UTIL_EXPORT int ssl_ctx_check(void *ctx);
UTIL_EXPORT int ssl_ctx_set_passwd(void *ctx, const char *passwd);
UTIL_EXPORT int ssl_ctx_set_verify(void *ctx, int require_peer_certificate, int verify_peer);

// adds all system "Trusted CAs" to the verify path
UTIL_EXPORT int ssl_ctx_set_calist_load_system(void *ctx);

// adds all certificates in the specified file to the verify path
UTIL_EXPORT int ssl_ctx_set_calist_file(void *ctx, const char *cfile);

UTIL_EXPORT int ssl_ctx_set_packed_file(void *ctx, const char *cfile);
UTIL_EXPORT int ssl_ctx_set_key_file(void *ctx, const char *cfile);
UTIL_EXPORT int ssl_ctx_set_chain_file(void *ctx, const char *cfile);
UTIL_EXPORT const char *ssl_ctx_error(void *ctx);

#if defined(HEADER_SSL_H)
UTIL_EXPORT SSL *ssl_get_raw_object(void *handle);
UTIL_EXPORT SSL_CTX *ssl_ctx_get_raw_object(void *handle);
UTIL_EXPORT X509 *ssl_get_peer_certificate(void *handle);
#endif

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_SSL_H_*/
