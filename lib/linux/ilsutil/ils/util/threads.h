//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/threads.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_THREADS_H_
#define ILS_UTIL_THREADS_H_

#ifdef __cplusplus
extern "C" {
#endif

/// \file threads.h
/// This file contains functions to create and interact with threads, in a platform neutral manner.
/// Using the deviceWISE thread routines ensures that the code will function consistently when moving from one platform to the next.
///
#define THREAD_PRIO_HIGHEST		2  ///<The thread is run at the highest priority
#define THREAD_PRIO_HIGH		1  ///<The thread is run at a high priority
#define THREAD_PRIO_NORMAL		0  ///<The thread is run at a normal priority
#define THREAD_PRIO_LOW		   -1  ///<The thread is run at a low priority
#define THREAD_PRIO_LOWEST	   -2  ///<The thread is run at a the lowest priority

///
/// A structure that will be passed can be passed into the the thread_create_ex() and thread_create_detached_ex(). The parameters in this structure are used to configure the thread when it is created.
///
typedef struct {
	const char *name;   ///<The name of the thread.
	int stack;          ///<The stack size to be used in the thread.
	int priority;       ///<The priority at which the thread is run.
} THREAD_EX_ARGS;

typedef void *(*thread_function)(void *args);

/// Function to set the size of the stack to be used by the thread. This must be called prior to creating the thread.
///
/// \param stack an integer that is the size in bytes that will be used by the thread.
UTIL_EXPORT void thread_set_stack_size(int stack);

/// Function to set the minimum size of the stack that can be used by the thread. This must be called prior to creating the thread.
///
/// \param stack an integer that is the size in bytes that will be used by the thread if the size of stack specified by deviceWISE is lower than this number.
UTIL_EXPORT void thread_set_stack_min(int stack);

/// Function to set the priority level that the thread will run. This must be called prior to creating the thread.
///
/// \param prio an integer that is the priority level. From THREAD_PRIO_HIGHEST through THREAD_PRIO_LOWEST
UTIL_EXPORT void thread_set_default_prio(int prio);

/// Function to allocate memory for a THREAD_EX_ARGS structure. The name field defaults to NULL, the default stack size is 1mb but can be overridden by the thread_set_stack_size() function, and the priority default is THREAD_PRIO_NORMAL but can be overridden by the thread_set_default_prio() function
///
/// \param ex is a pointer to a THREAD_EX_ARGS pointer. This parameter is NULL upon entry into the function. The function will allocate and assign memory to this parameter.
/// \return 0 if successful, -7003 (ERR_MALLOC) if memory couldn't be allocated for the THREAD_EX_ARGS structure.
UTIL_EXPORT int  thread_ex_create(THREAD_EX_ARGS **ex);

/// Function to release the memory that was allocated for a THREAD_EX_ARGS structure. This should be done as part of the cleanup processing performed by the thread.
///
/// \param ex is a pointer to THREAD_EX_ARGS structure. This parameter would have been created by the thread_ex_create() function.
UTIL_EXPORT void thread_ex_delete(THREAD_EX_ARGS *ex);

/// Function to create a new detached thread. The thread will use the default stack settings, unless it was changed using the thread_set_stack_size() function. The thread will run at the THREAD_PRIO_NORMAL priority.
///
/// \param func the name of the function that will be the thread entry point. The function must have the declaration as defined by the typedef thread_function (void *args).
/// \param args a void pointer that is the memory of the arguments that will be passed to the thread
/// \return 0 if the thread was successfully created. -7006 (ERR_OS) if the platform call to create the thread failed. -7003 if memory couldn't be allocated for the thread creation.
UTIL_EXPORT int thread_create_detached(thread_function func, void *args);

/// Function to create a new detached thread that will accept a pointer to a THREAD_EX_ARGS structure in addition to other arguments
///
/// \param func the name of the function that will be the thread entry point. The function must have the declaration as defined by the typedef thread_function (void *args).
/// \param args a void pointer that is the memory of the arguments that will be passed to the thread
/// \param ex is a pointer to THREAD_EX_ARGS structure. This parameter would have been created by the thread_ex_create() function. It will contain the name, priority, and stack size settings that will be used to create the thread.
/// \return 0 if the thread was successfully created. -7006 (ERR_OS) if the platform call to create the thread failed. -7003 if memory couldn't be allocated for the thread creation.
UTIL_EXPORT int thread_create_detached_ex(thread_function func, void *args, THREAD_EX_ARGS *ex);

/// Function to create a new non-detached (joinable) thread. The thread will use the default stack settings, unless it was changed using the thread_set_stack_size() function. The thread will run at the THREAD_PRIO_NORMAL priority.
///
/// \param handle a pointer to a void pointer. This variable should be NULL when the function is called. It will contain a handle to the created thread if the function executes successfully.
/// \param func the name of the function that will be the thread entry point. The function must have the declaration as defined by the typedef thread_function (void *args).
/// \param args a void pointer that is the memory of the arguments that will be passed to the thread
/// \return 0 if the thread was successfully created. -7006 (ERR_OS) if the platform call to create the thread failed. -7003 if memory couldn't be allocated for the thread creation.
UTIL_EXPORT int thread_create(void **handle, thread_function func, void *args);

/// Function to create a new non-detached (joinable) thread.
///
/// \param handle a pointer to a void pointer. This variable should be NULL when the function is called. It will contain a handle to the created thread if the function executes successfully.
/// \param func the name of the function that will be the thread entry point. The function must have the declaration as defined by the typedef thread_function (void *args).
/// \param args a void pointer that is the memory of the arguments that will be passed to the thread
/// \param ex is a pointer to THREAD_EX_ARGS structure. This parameter would have been created by the thread_ex_create() function. It will contain the name, priority, and stack size settings that will be used to create the thread.
/// \return 0 if the thread was successfully created. -7006 (ERR_OS) if the platform call to create the thread failed. -7003 if memory couldn't be allocated for the thread creation.
UTIL_EXPORT int thread_create_ex(void **handle, thread_function func, void *args, THREAD_EX_ARGS *ex);

/// Function to delete a non-detached thread.
///
/// \param handle a void pointer that is the handle to a thread. This variable would have been created by the thread_create() or the thread_create_ex() function.
/// \return 0 if the thread was successfully created. -7006 (ERR_OS) if the platform call to create the thread failed. -7003 if memory couldn't be allocated for the thread creation.
UTIL_EXPORT int thread_delete(void *handle);

/// Function to detach from a non-detached thread.
///
/// \param handle a void pointer that is the handle to a thread. This variable would have been created by the thread_create() or the thread_create_ex() function.
/// \return 0 if the thread was successfully created. -7006 (ERR_OS) if the platform call to create the thread failed. -7003 if memory couldn't be allocated for the thread creation.
UTIL_EXPORT int thread_detach(void *handle);

/// Function to join a non-detached thread.
///
/// \param handle a void pointer that is the handle to a thread. This variable would have been created by the thread_create() or the thread_create_ex() function.
/// \param result a pointer to a void pointer. Will contain the target threads termination status
/// \return 0 if the thread was successfully created. -7006 (ERR_OS) if the platform call to create the thread failed. -7003 if memory couldn't be allocated for the thread creation.
UTIL_EXPORT int thread_join(void *handle, void **result);

/// Function to obtain a numeric thread id associated with the thread.
///
/// \param handle a void pointer that is the handle to a thread. This variable would have been created by the thread_create() or the thread_create_ex() function.
/// \return an integer id identified with the thread.
UTIL_EXPORT int thread_id(void *handle);

/// Function to obtain an error code associated with the thread.
///
/// \param handle a void pointer that is the handle to a thread. This variable would have been created by the thread_create() or the thread_create_ex() function.
/// \return an integer that is a platform specific error code found in a thread. Should be called if one of the non-detached thread calls fails.
UTIL_EXPORT int thread_error(void *handle);

/// Function to have the calling thread suspend for an amount of time.
///
/// \param ms an integer representing the number of milliseconds the thread will suspend.
UTIL_EXPORT void thread_sleep(int ms);

#if defined(_WIN32)
typedef void (*thread_exception_handler)(int code, void *custom);
UTIL_EXPORT void thread_set_exception_handler(thread_exception_handler handler, void *custom);
UTIL_EXPORT int thread_filter_exception(int code);
UTIL_EXPORT void thread_set_exception_intercept(int value);
#endif

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_THREADS_H_*/
