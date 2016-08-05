//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/queue.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_QUEUE_H_
#define ILS_UTIL_QUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define QUEUE_OPT_SET_FLAG_ON_PUT		1
#define QUEUE_OPT_CLR_FLAG_ON_GET_ERR	2

typedef void (*queue_on_item_callback)(void *handle, void *custom);

UTIL_EXPORT int _queue_create(void **handle, const char *file, int line);
UTIL_EXPORT int _queue_create_ex(void **handle, int max_size, int options, const char *file, int line);
#define queue_create(handle) _queue_create((handle),__FILE__,__LINE__)
#define queue_create_ex(handle,max_size,options) _queue_create_ex((handle),(max_size),(options),__FILE__,__LINE__)

UTIL_EXPORT int queue_set_callbacks(void *handle, queue_on_item_callback next_item, queue_on_item_callback next_item_after_error, void *custom);
UTIL_EXPORT int queue_delete(void *handle);
UTIL_EXPORT int queue_set_max_size(void *handle, int max_size);
UTIL_EXPORT int queue_set_name(void *handle, const char *name);
UTIL_EXPORT int queue_count(void *handle);
UTIL_EXPORT int queue_clear(void *handle);
UTIL_EXPORT int queue_put(void *handle, void *item);
UTIL_EXPORT int queue_get(void *handle, void **item, long timeout);
UTIL_EXPORT void *queue_peek(void *handle);
UTIL_EXPORT void *queue_instrument_handle();

UTIL_EXPORT int queue_set_flag(void *handle);
UTIL_EXPORT int queue_clr_flag(void *handle);
UTIL_EXPORT int queue_get_flag(void *handle);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_QUEUE_H_*/
