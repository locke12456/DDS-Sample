//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/pool.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_POOL_H_
#define ILS_UTIL_POOL_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*thread_pool_callback)(int id, void *a, void *b, void *c);
typedef int (*thread_pool_put_work_callback)(const char *who, thread_pool_callback func, void *a, void *b, void *c);
typedef int (*thread_pool_put_scheduled_work_callback)(const char *who, void **handle, int interval, int repeat, thread_pool_callback func, void *a, void *b, void *c);
typedef int (*thread_pool_end_scheduled_work_callback)(void *handle);

UTIL_EXPORT void thread_pool_init(void **pool, int minthreads, int maxthreads, int stack_size);
UTIL_EXPORT void thread_pool_init2(void **pool, thread_pool_put_work_callback put_callback,thread_pool_put_scheduled_work_callback put_sch_callback, thread_pool_end_scheduled_work_callback end_sch_callback);
UTIL_EXPORT void thread_pool_uninit(void *pool);

UTIL_EXPORT int  thread_pool_put_work(void *pool, const char *who, thread_pool_callback func, void *a, void *b, void *c);
UTIL_EXPORT int  thread_pool_put_scheduled_work(void *pool, const char *who, void **handle, int interval, int repeat, thread_pool_callback func, void *a, void *b, void *c);
UTIL_EXPORT int  thread_pool_end_scheduled_work(void *pool, void *handle);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_POOL_H_*/
