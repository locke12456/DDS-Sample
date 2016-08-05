//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/list.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_LIST_H_
#define ILS_UTIL_LIST_H_

#ifdef __cplusplus
extern "C" {
#endif
/// \file list.h
/// An object that collects items. Similar to a btree, but the items in a list are ordered as well as searchable by a hash value.
///
#define LIST_OPT_NOLOCK 1

typedef void (*list_free)(void *);
typedef long long (*list_hash)(const void *);
typedef void (*list_fefunc)(const void *item,void *args);


/// Function to create a list object.
///
/// \param handle is pointer to a void pointer. The list_create() function will return a handle to the created list in this variable.
/// \param hash_func the name of the function which will create the hash key that will be used to retrieve items from the list. The function takes one parameter, a const void pointer and must return a long long value.
/// \param free_func the name of the function which will free the memory taken by the item. This function takes one parameter a void pointer and does not return anything.
/// \return 0 is returned if the list was created
///
UTIL_EXPORT int list_create(void **handle, list_hash hash_func, list_free free_func);

/// Function to create a list object.
///
/// \param handle is pointer to a void pointer. The list_create() function will return a handle to the created list in this variable.
/// \param hash_func the name of the function which will create the hash key that will be used to retrieve items from the list. The function takes one parameter, a const void pointer and must return a long long value.
/// \param free_func the name of the function which will free the memory taken by the item. This function takes one parameter a void pointer and does not return anything.
/// \param options use LIST_OPT_NOLOCK will result in the use of a rwlock when accessing list entries. The default is to not use a rwlock.
/// \return 0 is returned if the list was created
///
UTIL_EXPORT int list_create_ex(void **handle, list_hash hash_func, list_free free_func, int options);

/// Function to delete a list object. All list items will be removed, the read/write lock will be deleted if applicable, and the memory used by the list will be released.
///
/// \param handle is void pointer and is the handle returned from the list_create() function.
UTIL_EXPORT void list_delete(void *handle);

/// Function to remove all of the items in a list object.
///
/// \param handle is void pointer and is the handle returned from the list_create() function.
UTIL_EXPORT void list_clear(void *handle);

/// Function to return a count of the number of items in a list object.
///
/// \param handle is void pointer and is the handle returned from the list_create() function.
/// \return an integer representing the number of items in the list object.
UTIL_EXPORT int list_count(void *handle);

/// Function to initiate a lock request on the list object.
///
/// \param handle is void pointer and is the handle returned from the list_create() function.
/// \return 0 if successful. -7006 (ERR_OS) or -7008 (ERR_BADHANDLE)
UTIL_EXPORT int list_lock(void *handle);

/// Function to release the lock on the list object.
///
/// \param handle is void pointer and is the handle returned from the list_create() function.
/// \return 0 if successful. -7006 (ERR_OS) or -7008 (ERR_BADHANDLE)
UTIL_EXPORT int list_unlock(void *handle);

/// Function to execute a function for each item in the list object.
///
/// \param handle is void pointer and is the handle returned from the list_create() function.
/// \param func is the name of a function that will be executed for each item in the list. The function must have the following declaration functionname(void *item, void* args). The void * item parameter will be a pointer to the item in the list.
/// \param args a pointer to an item in memory that will be passed to the function that processes each list item, as the args variable.
UTIL_EXPORT void list_foreach(void *handle, list_fefunc func, void *args);

/// Function to insert an item at a specific location within a list object.
///
/// \param handle is void pointer and is the handle returned from the list_create() function.
/// \param e is pointer to the item that will be inserted into the list.
/// \param index is an integer that corresponds to a location within the list.
/// \return 0 if successful. -7012 if an item exists at that index.
/// \sa errors.h
UTIL_EXPORT int list_insert_at_index(void *handle, void *e, int index);

/// Function to insert an item as the first item within a list object.
///
/// \param handle is void pointer and is the handle returned from the list_create() function.
/// \param e is pointer to the item that will be inserted into the list.
/// \return 0 if successful.
/// \sa errors.h
UTIL_EXPORT int list_insert_at_head(void *handle, void *e);

/// Function to insert an item as the last item within a list object.
///
/// \param handle is void pointer and is the handle returned from the list_create() function.
/// \param e is pointer to the item that will be inserted into the list.
/// \return 0 if successful.
/// \sa errors.h
UTIL_EXPORT int list_insert_at_tail(void *handle, void *e);

/// Function to locate an item in the list object at a specific numeric index
///
/// \param handle is void pointer and is the handle returned from the list_create() function.
/// \param index is an integer representing the location in the list of the item being requested.
/// \return the item in the list at the requested index. NULL if the item is < 0 or > the total number of items in the list.
UTIL_EXPORT void *list_find_by_index(void *handle, int index);

/// Function to locate an item in the list object using an item. This function can be used to see if an item was added to the list.
///
/// \param handle is void pointer and is the handle returned from the list_create() function.
/// \param e is a void pointer to the item to be used as the search item. The hash routine defined for the list will be executed against the item to see if it is in the list.
/// \return the item in the list if found. NULL if the item is not in the list.
UTIL_EXPORT void *list_find_by_object(void *handle, const void *e);

/// Function to locate an item in the list object using a hash key.
///
/// \param handle is void pointer and is the handle returned from the list_create() function.
/// \param hash is a long long that will be used to search the list.
/// \return the item in the list if found. NULL if the item is not in the list.
UTIL_EXPORT void *list_find_by_hash(void *handle, long long hash); 

/// Function to acquire an iterator object for a list associated with a specific location within the list. This iterator will then be used to go through the list eithr forward or backward from this location.
///
/// \param handle is void pointer and is the handle returned from the list_create() function.
/// \param iterator is a pointer to a void pointer that will contain the starting point for the iteration routine.
/// \param index is an integer representing the location in the list.
/// \return 0 if the iterator was obtained.
/// \sa errors.h
UTIL_EXPORT int list_itr_get(void *handle, void **iterator, int index); 

/// Function to retrieve the next item in the list, from the location being pointed to by the iterator item.
///
/// \param iterator is a pointer to a void pointer. Must have a valid iterator upon entry into the function. Will contain the iterator for the next item in the list when the function returns.
/// \return an item in the list if successful. NULL if there is not an item that follows the iterator.
UTIL_EXPORT void *list_itr_next(void **iterator);

/// Function to retrieve the previous item in the list, from the location being pointed to by the iterator item.
///
/// \param iterator is a pointer to a void pointer. Must have a valid iterator upon entry into the function. Will contain the iterator for the previous item in the list when the function returns.
/// \return an item in the list if successful. NULL if there is not an item that precedes the iterator.
UTIL_EXPORT void *list_itr_prev(void **iterator);

/// Function to retrieve the item in the list that corresponds to the location being pointed to by the iterator item.
///
/// \param iterator is a pointer to a void pointer. Must have a valid iterator upon entry into the function.
/// \return an item in the list if successful. NULL if there is not an item that corresponds with the iterator.
UTIL_EXPORT void *list_itr_curr(void **iterator);

/// Function to locate and delete an item in the list object at a specific index location
///
/// \param handle is void pointer and is the handle returned from the list_create() function.
/// \param index is an integer representing the location in the list of the item being deleted.
/// \return 0 if the item was deleted from the list.
/// \sa errors.h
UTIL_EXPORT int list_delete_by_index(void *handle, int index);

/// Function to locate and delete an item in the list object using an item.
///
/// \param handle is void pointer and is the handle returned from the list_create() function.
/// \param e is a void pointer to the item to be used as the search item. The hash routine defined for the list will be executed against the item to see if it is in the list.
/// \return 0 if the item was deleted from the list.
/// \sa errors.h
UTIL_EXPORT int list_delete_by_object(void *handle, const void *e);

/// Function to locate and delete an item in the list object using a hash key.
///
/// \param handle is void pointer and is the handle returned from the list_create() function.
/// \param hash is a long long that will be used to search the list.
/// \return 0 if the item was deleted from the list.
/// \sa errors.h
UTIL_EXPORT int list_delete_by_hash(void *handle, long long hash); 

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_LIST_H_*/
