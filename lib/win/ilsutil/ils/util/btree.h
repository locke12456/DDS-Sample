//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/btree.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_BTREE_H_
#define ILS_UTIL_BTREE_H_

#ifdef __cplusplus
extern "C" {
#endif
/// \file btree.h
/// An object that collects items. The items in the btree are retrievable using a hash value.
///

#define BTREE_OPT_NOLOCK	1   ///< Used with the btree_create_ex() function. The option to enable the read write lock
#define BTREE_OPT_NOUNLOCK	2   ///< Used with the btree_create_ex() function. The option to disable the read write lock
#define BTREE_OPT_NOINSTRUMENT 4  /// Only used by instumentation code.

typedef void (*btree_free)(void *);
typedef long long (*btree_hash)(const void *);
typedef void (*btree_fefunc)(const void *item,void *args);
typedef void (*btree_fefunc_ex)(long long hash, const void *item,void *args);

/// Function to create a btree object with the option to enable/disable the read-write lock
///
/// \param handle is pointer to a void pointer. The btree_create_ex() function will return a handle to the created btree in this variable.
/// \param hash_func the name of the function which will create the hash key that will be used to put and get items in the btree.
/// \param free_func the name of the function which will free the item.
/// \param options use either BTREE_OPT_NOLOCK or BTREE_OPT_NOUNLOCK (default). Use of BTREE_OPT_NOLOCK will result in the use of a rwlock when accessing btree entries.
/// \return 0 is returned if the btree was created
///
UTIL_EXPORT int _btree_create_ex(void **handle, btree_hash hash_func, btree_free free_func, int options, const char *file, int line);
#define btree_create(handle,hash_func,free_func) _btree_create_ex((handle),(hash_func),(free_func),0,__FILE__,__LINE__)
#define btree_create_ex(handle,hash_func,free_func,options) _btree_create_ex((handle),(hash_func),(free_func),(options),__FILE__,__LINE__)

/// Function to delete a btree object. All btree items will be removed, the read/write lock will be deleted if applicable, and the memory used by the btree will be released.
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
UTIL_EXPORT void btree_delete(void *handle);

/// Function to remove all of the items in a btree object.
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
UTIL_EXPORT void btree_clear(void *handle);

/// Function to return a count of the number of items in a btree object.
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
/// \return an integer representing the number of items in the btree object.
UTIL_EXPORT int btree_count(void *handle);

/// Function to initiate a read lock request against the btree object.
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
/// \return 0 if successful. -7006 (ERR_OS) or -7008 (ERR_BADHANDLE)
UTIL_EXPORT int btree_readlock(void *handle);

/// Function to initiate a write lock request against the btree object.
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
/// \return 0 if successful. -7006 (ERR_OS) or -7008 (ERR_BADHANDLE)
UTIL_EXPORT int btree_writelock(void *handle);

/// Function to initiate a read/write unlock request against the btree object.
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
/// \return 0 if successful. -7006 (ERR_OS) or -7008 (ERR_BADHANDLE)
UTIL_EXPORT int btree_unlock(void *handle);

/// Function to execute a function for each item in the btree object.
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
/// \param func is the name of a function. The function must have the following declaration functionname(void *item, void* args). The void * item parameter will be a pointer to the item in the btree.
/// \param args a pointer to an item in memory that will be passed to the function that processes each btree item, as the args variable.
UTIL_EXPORT void btree_foreach(void *handle, btree_fefunc func, void *args);

/// Function to execute a function for each item in the btree object.
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
/// \param func is the name of a function. The function must have the following declaration functionname(long long hash, void *item, void* args). The void * item parameter will be a pointer to the item in the btree. The hash argument is the key assocaiated with the item in the btree.
/// \param args a pointer to an item in memory that will be passed to the function that processes each btree item, as the args variable.
UTIL_EXPORT void btree_foreach_ex(void *handle, btree_fefunc_ex func, void *args);

/// Function to insert an item in the btree object.
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
/// \param e is pointer to the item that will be inserted into the btree.
UTIL_EXPORT void *btree_insert(void *handle, void *e);

/// Function to insert an item in the btree object.
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
/// \param e is pointer to the item that will be inserted into the btree.
/// \param hash is the hash key that will be used to locate the item in the btree.
UTIL_EXPORT void *btree_insert_with_hash(void *handle, void *e, long long hash);

/// Function to locate an item in the btree object using a numeric index
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
/// \param index is an integer representing the location in the btree of the item being requested.
/// \return the item in the btree at the requested index. NULL if the item is < 0 or > the total number of items in the btree.
UTIL_EXPORT void *btree_find_by_index(void *handle, int index);

/// Function to locate an item in the btree object using an item. This function can be used to see if an item was added to the btree.
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
/// \param e is a void pointer to the item to be used as the search item. The hash routine defined for the btree will be executed against the item to see if it is in the btree.
/// \return the item in the btree if found. NULL if the item is not in the btree.
UTIL_EXPORT void *btree_find_by_object(void *handle, const void *e);

UTIL_EXPORT void *btree_find_by_special(void *handle, const void *e, btree_hash hash_func);

/// Function to locate an item in the btree object using a hash key.
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
/// \param hash is a long long that will be used to search the btree.
/// \return the item in the btree if found. NULL if the item is not in the btree.
UTIL_EXPORT void *btree_find_by_hash(void *handle, long long hash);

UTIL_EXPORT void *btree_find_by_index_ex(void *handle, int index, int options);
UTIL_EXPORT void *btree_find_by_object_ex(void *handle, const void *e, int options);
UTIL_EXPORT void *btree_find_by_hash_ex(void *handle, long long hash, int options);

UTIL_EXPORT void *btree_find_less_by_hash(void *handle, long long hash);

typedef int (*btree_comparer)(const void *item, void *custom);
UTIL_EXPORT void *btree_find_by_func(void *handle, btree_comparer func, void *custom);


/// Function to return the index of an item in the btree object using a hash key.
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
/// \param hash is a long long that will be used to search the btree.
/// \return the index of the item in the btree if found. -1 if the item is not in the btree.
UTIL_EXPORT int btree_index_by_hash(void *handle, long long hash);

/// Function to delete an item in the btree object using a numeric index
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
/// \param index is an integer representing the location in the btree of the item being requested.
/// \return the item that was deleted from the btree at the requested index. NULL if the item is < 0 or > the total number of items in the btree.
UTIL_EXPORT void *btree_delete_by_index(void *handle, int index);

/// Function to delete an item in the btree object using an item.
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
/// \param e is a void pointer to the item to be used as the search item. The hash routine defined for the btree will be executed against the item to see if the item is in the btree. The item will be deleted if found.
/// \return the item that was deleted from the btree if found. NULL if the item is not in the btree.
UTIL_EXPORT void *btree_delete_by_object(void *handle, const void *e);

/// Function to delete an item in the btree object using a hash key.
///
/// \param handle is void pointer and is the handle returned from the btree_create() function.
/// \param hash is a long long that will be used to search the btree.
/// \return the item that was deleted from the btree if found. NULL if the item is not in the btree.
UTIL_EXPORT void *btree_delete_by_hash(void *handle, long long hash);

/// Function to convert a string into a hash key.
///
/// \param a the string to convert into a hash key. This is done by performing a crc32 conversion of the string.
/// \return a long long that is the crc32 representation of the string.
UTIL_EXPORT long long btree_str_hash(const void *a);

/// Function to convert an integer into a hash key.
///
/// \param a pointer to an integer that will be converted into a hash key.
/// \return a long long that hash value for the integer.
UTIL_EXPORT long long btree_int_hash(const void *a);

/// Function to convert a 64 bit integer into a hash key.
///
/// \param a pointer to a 64 bit integer that will be converted into a hash key.
/// \return a long long that hash value for the 64 bit integer.
UTIL_EXPORT long long btree_int64_hash(const void *a);

UTIL_EXPORT void *btree_instrument_handle();

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_BTREE_H_*/
