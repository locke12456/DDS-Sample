//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/channel.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_CHANNEL_H_
#define DW_CORE_CHANNEL_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*channel_callback)(const char *channel, int code, const char **argv, int argc, void *custom);

DWCORE_EXPORT int channel_create(const char *name);
DWCORE_EXPORT int channel_delete(const char *name);

DWCORE_EXPORT int channel_subscribe(const char *name, int *subid, channel_callback cb, void *custom);
DWCORE_EXPORT int channel_unsubscribe(int subid);

DWCORE_EXPORT int channel_get_subscription_count(const char *name);

DWCORE_EXPORT int channel_post(const char *name, int code, const char **argv, int argc);
DWCORE_EXPORT int channel_post1(const char *name, int code, const char *arg);
DWCORE_EXPORT int channel_post5(const char *name, int code, const char *arg1,const char *arg2 ,const char *arg3,const char *arg4,const char *arg5);

//int channel_handle_find(void **handle, const char *name);
//int channel_handle_post(void *handle, int code, char **argv, int argc);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_CHANNEL_H_*/
