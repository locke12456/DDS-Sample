//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/memory.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_MEMORY_H_
#define ILS_UTIL_MEMORY_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	void *(*mallocFunc)(size_t);
	void *(*reallocFunc)(void *,size_t);
	void *(*callocFunc)(size_t,size_t);
	void (*freeFunc)(void *);
	void *(*memsetFunc)(void *,int,size_t);
	void *(*memcpyFunc)(void *,const void *,size_t);
	void *(*memmoveFunc)(void *,const void *,size_t);
	char *(*strdupFunc)(const char *);
} ILS_MEMORY_FUNCTIONS;

#define ILS_MEMORY_MALLOC	0
#define ILS_MEMORY_REALLOC	1
#define ILS_MEMORY_CALLOC	2

#define ILS_MEMORY_OPT_DEBUG	1

typedef void (*ils_memory_err_func)(int call_type, int size_requested, void *ptr);

// Setup functions
UTIL_EXPORT void ilsMemoryInit();
UTIL_EXPORT void ilsMemoryInitEx(int opt);
UTIL_EXPORT ILS_MEMORY_FUNCTIONS ilsMemoryGetFunctions(void);
UTIL_EXPORT void ilsMemorySetFunctions(ILS_MEMORY_FUNCTIONS funcs);
UTIL_EXPORT void ilsMemorySetErrCallback(ils_memory_err_func func);

// The followings should handle both default and debug cases.
UTIL_EXPORT void *_ilsMalloc(size_t size, const char * file, int line);
UTIL_EXPORT void *_ilsRealloc(void *ptr,size_t size, const char * file, int line);
UTIL_EXPORT void *_ilsCalloc(size_t num, size_t size, const char * file, int line);
UTIL_EXPORT void  _ilsFree(void *ptr, const char * file, int line);
UTIL_EXPORT void  ilsFree(void *ptr);

UTIL_EXPORT void *ilsMemset(void *ptr, int c, size_t len);
UTIL_EXPORT void *ilsMemcpy(void *dst, const void *src, size_t len);
UTIL_EXPORT void *ilsMemmove(void *dst, const void *src, size_t len);
UTIL_EXPORT char *ilsStrdup(const char *str);
#define ilsMalloc(size) _ilsMalloc((size), __FILE__, __LINE__)
#define ilsRealloc(ptr,size) _ilsRealloc((ptr),(size), __FILE__, __LINE__)
#define ilsCalloc(num,size) _ilsCalloc((num),(size), __FILE__, __LINE__)
#define ilsFree(ptr) _ilsFree((ptr), __FILE__, __LINE__)

/*  The following can be turned on with debug_mode = TRUE */
typedef void (*ils_memory_dump_func)(int index, time_t time, void *ptr, char *context, int size, const char *location, int line, int type, void *custom);
UTIL_EXPORT void ilsMemoryDumpForeach(ils_memory_dump_func callback, void *custom);
UTIL_EXPORT int ilsMemoryDump(const char *file, int option);
UTIL_EXPORT int ilsMemoryShow(long address, unsigned char **buf, int *len);
UTIL_EXPORT long long ilsMemoryUsed();
UTIL_EXPORT long long ilsMemoryUsedMax();
UTIL_EXPORT long long ilsMemoryBlockUsed();
UTIL_EXPORT long long ilsMemoryBlockUsedMax();

// Fixed Memory Allocator, performs a single malloc on init
UTIL_EXPORT int fixedMemoryInit(size_t size);
UTIL_EXPORT void fixedMemoryDump(const char *file_name);
UTIL_EXPORT int fixedMemoryGetUsedSpace();

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_MEMORY_H_*/
