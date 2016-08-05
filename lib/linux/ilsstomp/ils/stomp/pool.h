//----------------------------------------------------------------
//
//-- Filename: ils/stomp/pool.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_STOMP_POOL_H_
#define ILS_STOMP_POOL_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*stomp_pool_callback)(int id, void *a, void *b, void *c);
typedef int (*stomp_pool_put_work_callback)(const char *who, stomp_pool_callback func, void *a, void *b, void *c);
typedef int (*stomp_pool_put_scheduled_work_callback)(const char *who, void **handle, int interval, int repeat, stomp_pool_callback func, void *a, void *b, void *c);
typedef int (*stomp_pool_end_scheduled_work_callback)(void *handle);

STOMP_EXPORT void stomp_pool_init(void **pool, int minthreads, int maxthreads, int stack_size);
STOMP_EXPORT void stomp_pool_init2(void **pool, stomp_pool_put_work_callback put_callback,stomp_pool_put_scheduled_work_callback put_sch_callback, stomp_pool_end_scheduled_work_callback end_sch_callback);
STOMP_EXPORT void stomp_pool_uninit(void *pool);

STOMP_EXPORT int  stomp_pool_put_work(void *pool, const char *who, stomp_pool_callback func, void *a, void *b, void *c);
STOMP_EXPORT int  stomp_pool_put_scheduled_work(void *pool, const char *who, void **handle, int interval, int repeat, stomp_pool_callback func, void *a, void *b, void *c);
STOMP_EXPORT int  stomp_pool_end_scheduled_work(void *pool, void *handle);

#ifdef __cplusplus
}
#endif

#endif /*ILS_STOMP_POOL_H_*/
