/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2015 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE 
 *
 *   for full copyright notice and license terms. 
 *
 */
#ifndef _LINUX_SNAPPY_H
#define _LINUX_SNAPPY_H 1

#include <stddef.h>
#include "vortex_os.h"

#ifdef OSPL_BUILD_CORE
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif

/* Only needed for compression. This preallocates the worst case */
struct snappy_env {
	unsigned short *hash_table;
	void *scratch;
	void *scratch_output;
};

struct iovec;
OS_API int snappy_init_env(struct snappy_env *env);
OS_API int snappy_init_env_sg(struct snappy_env *env, int sg);
OS_API void snappy_free_env(struct snappy_env *env);
OS_API int snappy_uncompress_iov(struct iovec *iov_in, int iov_in_len,
			   size_t input_len, char *uncompressed);
OS_API int snappy_uncompress(const char *compressed, size_t n, char *uncompressed);
OS_API int snappy_compress(struct snappy_env *env,
		    const char *input,
		    size_t input_length,
		    char *compressed,
		    size_t *compressed_length);
OS_API int snappy_compress_iov(struct snappy_env *env,
			struct iovec *iov_in,
			int iov_in_len,
			size_t input_length,
			struct iovec *iov_out,
			int iov_out_len,
			size_t *compressed_length);
OS_API int snappy_uncompressed_length(const char *buf, size_t len, size_t *result);
OS_API size_t snappy_max_compressed_length(size_t source_len);




#endif
