//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/crypto.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_CRYPTO_H
#define ILS_UTIL_CRYPTO_H

#ifdef  __cplusplus
extern "C" {
#endif

#define CRYPTO_OPT_NOPAD	1
	
UTIL_EXPORT int encryptor_create(     void **cipher, const char *definition, const unsigned char *key, const unsigned char *iv);
UTIL_EXPORT int encryptor_encrypt(    void *cipher, const void *in, int inlen, void *out, int *outlen );
UTIL_EXPORT int encryptor_encrypt_ex( void *cipher, const void *in, int inlen, void *out, int *outlen, int options );
UTIL_EXPORT int encryptor_delete(     void *cipher);

UTIL_EXPORT int decryptor_create(     void **cipher, const char *definition, const unsigned char *key, const unsigned char *iv);
UTIL_EXPORT int decryptor_decrypt(    void *cipher, const void *in, int inlen, void *out, int *outlen );
UTIL_EXPORT int decryptor_decrypt_ex( void *cipher, const void *in, int inlen, void *out, int *outlen, int options );
UTIL_EXPORT int decryptor_delete(     void *cipher);

UTIL_EXPORT int encryptor_encrypt_file(void *cipher, const char *src, const char *dst );
UTIL_EXPORT int decryptor_decrypt_file(void *cipher, const char *src, const char *dst );

#ifdef  __cplusplus
}
#endif

#endif /*ILS_UTIL_CRYPTO_H_*/
