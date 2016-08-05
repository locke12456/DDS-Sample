//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/variable.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_VARIABLE_H_
#define DW_DATA_VARIABLE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void DW_VARIABLE_BLOCK;
typedef void DW_VARIABLE_BLOCK_INSTANCE;

typedef void (*variable_block_async_callback)(DW_VARIABLE_BLOCK_INSTANCE *instance, void *custom, int pool_id);
typedef void (*variable_async_callback)(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count, void *custom);

//#define variable_extract_length(_var, _index) *((int *)((char *)_var->data+(_var->length+4)*(_index)))
///  Macro to read the data from a DW_STRING data typed DW_VARIABLE_DATA object.
/// 
/// \param _var is a pointer to a DW_VARIABLE_DATA variable. Must be a DW_STRING data type. This variable may contain the data for an array of strings.
/// \param _index is an element offset into the data region to read a specific string contained in the DW_VARIABLE_DATA variable. The array is zero based, the first element is at _index 0.
/// \return A character pointer containing the string value.
#define variable_extract_data(_var, _index) ((char *)_var->data+(_var->length+4)*(_index)+4)

///  Macro to read the size of a string from a DW_STRING data typed DW_VARIABLE_DATA object.
/// 
/// \param _var is a pointer to a DW_VARIABLE_DATA variable. Must be a DW_STRING data type. This variable may contain the data for an array of strings.
/// \param _index is an element offset into the data region to read a specific string contained in the DW_VARIABLE_DATA variable. The array is zero based, the first element is at _index 0.
/// \param _valuep is a pointer to a memory region where the string size will be written. This must be at least 4 bytes in length.
/// \return The length of the string will be written to the memory pointed to by the variable _valuep.
#define variable_get_length(_var,_index,_valuep) ilsMemcpy(_valuep,(char *)_var->data+(_var->length+4)*(_index),4);

///  Macro to set the size of a string from a DW_STRING data typed DW_VARIABLE_DATA object.
/// 
/// \param _var is a pointer to a DW_VARIABLE_DATA variable. Must be a DW_STRING data type. This variable may contain the data for an array of strings.
/// \param _index is an element offset into the data region to read a specific string contained in the DW_VARIABLE_DATA variable. The array is zero based, the first element is at _index 0.
/// \param _valuep is a pointer to a memory region that contains the string size to be written. This must be at least 4 bytes in length.
/// \return The length of the string will be written to the data region of the DW_VARIABLE_DATA object.
#define variable_set_length(_var,_index,_valuep) ilsMemcpy((char *)_var->data+(_var->length+4)*(_index),_valuep,4);

// Functions for allocating DW_VARIABLE_DATA objects.
///  Function to create a DW_VARIABLE_DATA object.
/// 
/// \param var is a pointer to a pointer to a DW_VARIABLE_DATA variable. Should be NULL when passed in
/// \param name is a constant character pointer. It contains the name to be assigned to the DW_VARIABLE_DATA variable.
/// \param type is an integer code that corresponds to a deviceWISE data type.
/// \param count is the number of items the DW_VARIABLE_DATA variable represents. Arrays are represented with count values > 1
/// \param length is the size of the variable. This is needed for DW_STRING and DW_BINARY data types. This value is calculated for all other data types.
/// \return 0 is returned if successful. The var variable will contain a pointer to a DW_VARIABLE_DATA upon successful completion
/// \sa constants.h
DWDATA_EXPORT int variable_create(DW_VARIABLE_DATA **var, const char *name, int type, int count, int length);


///   Function to create a DW_VARIABLE_DATA object from the data in a DW_VARIABLE_INFO object
/// 
/// \param var is a pointer to a pointer to a DW_VARIABLE_DATA variable. Should be NULL when passed in
/// \param vinfo is a constant DW_VARIABLE_INFO pointer. The information in this variable will be assigned to the DW_VARIABLE_DATA variable.
/// \param count is the number of items the DW_VARIABLE_DATA variable represents. Arrays are represented with count values > 1
/// \return 0 is returned if successful. The var variable will contain a pointer to a DW_VARIABLE_DATA upon successful completion
DWDATA_EXPORT int variable_create_from_vinfo(DW_VARIABLE_DATA **var, const DW_VARIABLE_INFO *vinfo, int count);

///   Function to create a DW_VARIABLE_DATA object and populate its fields with the data in the source DW_VARIABLE_DATA object
/// 
/// \param var is a constant DW_VARIABLE_DATA pointer. The information in this variable will be assigned to the DW_VARIABLE_DATA copy variable.
/// \param copy is a pointer to a pointer to a DW_VARIABLE_DATA variable. Should be NULL when passed in
/// \return 0 is returned if successful. The copy variable will contain a pointer to a DW_VARIABLE_DATA upon successful completion
DWDATA_EXPORT int variable_copy(const DW_VARIABLE_DATA *var, DW_VARIABLE_DATA **copy);

///   Function to release the memory taken by a DW_VARIABLE_DATA object, including the data region of the DW_VARIABLE_DATA object
/// 
/// \param var is a pointer to a DW_VARIABLE_DATA variable.
DWDATA_EXPORT void variable_free(void *var);

///   Function to allocate memory in the data region of a DW_VARIABLE_DATA object
/// 
/// \param var is a pointer to a DW_VARIABLE_DATA variable.
DWDATA_EXPORT int variable_alloc_data(DW_VARIABLE_DATA *var);

// Functions for reading/writing variables from a device.
///   Function to syncrhronously read a device variable. Device Drivers will have to implement their own version of this function if they design their code to synchronously read data from a device.
/// 
/// \param dev is a DW_DEVICE pointer. This is the device that is to be read
/// \param vars a pointer to an array of DW_VARIABLE_DATA variables. Each DW_VARIABLE_DATA variable has a data field that will hold the data that was read from the device.
/// \param var_count the number of DW_VARIABLE_DATA variables in the vars array
/// \return 0 is returned if the read was successful. Each DW_VARIABLE_DATA variable has a status field and a has_been_handled field to indicate if the read was successful for that variable
/// \sa driver.h
DWDATA_EXPORT int variable_read(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count);

// Functions for reading/writing variables from a device.
///   Function to syncrhronously write a device variable. Device Drivers will have to implement their own version of this function if they design their code to synchronously write data to a device.
/// 
/// \param dev is a DW_DEVICE pointer. This is the device that will be written to
/// \param vars a pointer to an array of DW_VARIABLE_DATA variables. Each DW_VARIABLE_DATA variable has a data field that will hold the data that will be written to the device.
/// \param var_count the number of DW_VARIABLE_DATA variables in the vars array
/// \return 0 is returned if the write was successful. Each DW_VARIABLE_DATA variable has a status field and a has_been_handled field to indicate if the write was successful for that variable
DWDATA_EXPORT int variable_write(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count);

DWDATA_EXPORT int variable_read_async(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count, variable_async_callback cb,void *custom);
DWDATA_EXPORT int variable_write_async(DW_DEVICE *dev, DW_VARIABLE_DATA **vars, int var_count, variable_async_callback cb,void *custom);

// Functions for getting automated notification callbacks when a variable changes.
DWDATA_EXPORT int variable_subscribe(	DW_DEVICE *dev, DW_SUBSCRIPTION **sub, DW_VARIABLE_DATA *var,_driver_publish publish,
										void *custom, int qos, void *userctx);
DWDATA_EXPORT int variable_unsubscribe(	DW_DEVICE *dev, DW_SUBSCRIPTION *sub);

// Functions for variable block data operations.
DWDATA_EXPORT int variable_block_create(DW_VARIABLE_BLOCK **handle);
DWDATA_EXPORT int variable_block_delete(DW_VARIABLE_BLOCK *handle);
DWDATA_EXPORT int variable_block_add(DW_VARIABLE_BLOCK *handle, const char *device, DW_VARIABLE_INFO *vinfo);
DWDATA_EXPORT int variable_block_check_security(DW_VARIABLE_BLOCK *handle, int rw, void *userctx);

typedef void (*variable_block_fefunc)(const DW_DEVICE *device, const DW_VARIABLE_DATA *var, void *custom);
DWDATA_EXPORT int variable_block_create_instance(DW_VARIABLE_BLOCK *handle, DW_VARIABLE_BLOCK_INSTANCE **instance);
DWDATA_EXPORT int variable_block_delete_instance(DW_VARIABLE_BLOCK_INSTANCE *instance);
DWDATA_EXPORT int variable_block_count_vars(DW_VARIABLE_BLOCK_INSTANCE *instance);
DWDATA_EXPORT int variable_block_find_variable(DW_VARIABLE_BLOCK_INSTANCE *instance, long long hash, DW_VARIABLE_DATA **var);
DWDATA_EXPORT int variable_block_foreach_variable(DW_VARIABLE_BLOCK_INSTANCE *instance, variable_block_fefunc func, void *custom);
DWDATA_EXPORT int variable_block_reset_instance(DW_VARIABLE_BLOCK_INSTANCE *instance, int set_handled_to, int set_status_to);
DWDATA_EXPORT int variable_block_read(DW_VARIABLE_BLOCK_INSTANCE *instance,variable_block_async_callback cb, void *custom);
DWDATA_EXPORT int variable_block_write(DW_VARIABLE_BLOCK_INSTANCE *instance,variable_block_async_callback cb, void *custom);
DWDATA_EXPORT long long variable_block_hash(const char *device, const char *name, int type, int length, int count, int bitno);

// Hash functions for DW_VARIABLE_DATA objects
DWDATA_EXPORT long long variable_name_hash(const void *var);
DWDATA_EXPORT long long variable_full_hash(const void *var);
DWDATA_EXPORT long long variable_dev_hash(const void *dev, const void *var);

// Functions for setting one DW_VARIABLE_DATA object to another.
///   Function to byte swap within a buffer. Swapping will be done regardless of the Endian-ness of the O/S. Byte swapping is based on the data type of the variable, ie. DW_INT2-swap 2 bytes, DW_INT4-swap 4 bytes, etc.
/// 
/// \param buffer is a pointer to the buffer containing the bytes.
/// \param type is the deviceWISE data type of the data in the buffer
/// \param count the number of elements in the data buffer
DWDATA_EXPORT void variable_data_swap(void *buffer, int type, int count);

///   Function to byte swap within a buffer. Byte swapping will occur only on Big Endian systems. Byte swapping is based on the data type of the variable, ie. DW_INT2-swap 2 bytes, DW_INT4-swap 4 bytes, etc.
/// 
/// \param buffer is a pointer to the buffer containing the bytes.
/// \param type is the deviceWISE data type of the data in the buffer
/// \param count the number of elements in the data buffer
DWDATA_EXPORT void variable_data_bswap(void *buffer, int type, int count);

DWDATA_EXPORT void variable_length_swap(void *buffer, int count, int length);
DWDATA_EXPORT void variable_length_bswap(void *buffer, int count, int length);
DWDATA_EXPORT int variable_set(DW_VARIABLE_DATA *destination, DW_VARIABLE_DATA *source);
DWDATA_EXPORT int variable_value_to_string(DW_VARIABLE_DATA *var, char **value, char delim);
DWDATA_EXPORT int variable_set_string(DW_VARIABLE_DATA *var, int index, const char *value);

///   Function to convert and copy string data into the proper format for a DW_VARIABLE_DATA item
/// 
/// \param var is a pointer to a DW_VARIABLE_DATA variable. The data region of the DW_VARIABLE_DATA item will be updated with the data in the value variable
/// \param value is a constant character pointer to a buffer containing the data
/// \param delim is a character delimiter that may be present in the buffer to separate multiple values to be written to an DW_VARIABLE_DATA item that contains an array of elements.
DWDATA_EXPORT int variable_value_from_string(DW_VARIABLE_DATA *var, const char *value, char delim);

DWDATA_EXPORT int variable_ofs_get(const char *name, DW_VARIABLE_INFO *vinfo);
DWDATA_EXPORT int variable_ofs_get_1dim(const char *name, int hex);
DWDATA_EXPORT int variable_write_to_array_index(DW_VARIABLE_DATA *var, DW_VARIABLE_DATA *array, int index);
DWDATA_EXPORT int variable_read_from_array(DW_VARIABLE_DATA *var, DW_VARIABLE_DATA *array, DW_VARIABLE_INFO *array_info);
DWDATA_EXPORT int variable_write_to_array(DW_VARIABLE_DATA *var, DW_VARIABLE_DATA *array, DW_VARIABLE_INFO *array_info);
DWDATA_EXPORT int variable_read_from_array_offset(	DW_VARIABLE_DATA *var, DW_VARIABLE_DATA *array, 
													const char *offset, DW_VARIABLE_INFO *array_info);
DWDATA_EXPORT int variable_write_to_array_offset(	DW_VARIABLE_DATA *var, DW_VARIABLE_DATA *array, 
													const char *offset, DW_VARIABLE_INFO *array_info);

// Internal functions for marshalling DW_VARIABLE_DATA structures into a DW_PACKET.
DWDATA_EXPORT void variable_encode_data(DW_PACKET *packet, const DW_VARIABLE_DATA *var);
DWDATA_EXPORT void variable_encode_data2(void *blob, const DW_VARIABLE_DATA *var);
DWDATA_EXPORT void variable_decode_data(DW_VARIABLE_DATA *var, const char *buffer, int buffer_len);
DWDATA_EXPORT void variable_pack_string_data(const DW_VARIABLE_DATA *var, DW_PACKET *packet);
DWDATA_EXPORT void variable_pack_string_data2(const DW_VARIABLE_DATA *var, void *blob);
DWDATA_EXPORT void variable_unpack_string_data(DW_VARIABLE_DATA *var, const char *buffer, int buffer_len);

// Internal function for checking security on variables.
DWDATA_EXPORT int variable_check_security(const char *device,const char *var, int rw, void *userctx);

// Adding/Removing variable to an existing variable group.
DWDATA_EXPORT int vargroup_add_variable(const char *group, const char *device_name, const char *variable_name, void *userctx);
DWDATA_EXPORT int vargroup_remove_variable(const char *group, const char *device_name, const char *variable_name, void *userctx);

// Variable Enumeration Helper Functions
DWDATA_EXPORT long long vinfo_name_hash(const void *var);

///   Function to create a DW_VARIABLE_INFO object.
/// 
/// \param vinfo is a pointer to a pointer to a DW_VARIABLE_INFO variable. Should be NULL when passed in
/// \param name is a constant character pointer. It contains the name to be assigned to the DW_VARIABLE_INFO variable.
/// \param type is an integer code that corresponds to a deviceWISE data type.
/// \param options is a number created by OR'ing together deviceWISE properties such as DW_READABLE and DW_WRITEABLE
/// \return 0 is returned if successful. The vinfo variable will contain a pointer to a DW_VARIABLE_INFO object upon successful completion
/// \sa constants.h
DWDATA_EXPORT int vinfo_create(DW_VARIABLE_INFO **vinfo, const char *name, int type, int options);

///   Function to create a DW_VARIABLE_INFO object and populate it with the contents of a source DW_VARIABLE_INFO object
/// 
/// \param vinfo is a pointer to a DW_VARIABLE_INFO variable. This is the source object
/// \param copy is a pointer to a pointer to a DW_VARIABLE_INFO variable. Should be NULL when passed in
/// \return 0 is returned if successful. The copy variable will contain a pointer to a DW_VARIABLE_INFO object upon successful completion
/// \sa constants.h
DWDATA_EXPORT int vinfo_copy(const DW_VARIABLE_INFO *vinfo, DW_VARIABLE_INFO **copy);

///   Function to free the memory associated with a DW_VARIABLE_INFO object
/// 
/// \param vinfo is a pointer to a DW_VARIABLE_INFO variable
DWDATA_EXPORT void vinfo_delete(DW_VARIABLE_INFO *vinfo);

///   Function to return the total number of elements associated with a DW_VARIABLE_INFO object
/// 
/// \param vinfo is a pointer to a DW_VARIABLE_INFO variable
/// \return the total elements represented by the variable. The total is calculated by the sum of the xdim, ydim, and zdim variables for array elements, otherwise a value of 1 is returned for non-array elements
DWDATA_EXPORT int vinfo_get_count(const DW_VARIABLE_INFO *vinfo);

///   Function to return the size of an element of a DW_VARIABLE_INFO object
/// 
/// \param vinfo is a pointer to a DW_VARIABLE_INFO variable
/// \return the size of an element, which is based on the data type of the DW_VARIABLE_INFO object
DWDATA_EXPORT int vinfo_get_element_size(const DW_VARIABLE_INFO *vinfo);

DWDATA_EXPORT int vinfo_object_to_xmlwriter(const DW_VARIABLE_INFO *vinfo, void *xmlwriter);
DWDATA_EXPORT int vinfo_object_to_xmlwriter_attribs(const DW_VARIABLE_INFO *vinfo, void *writer);
DWDATA_EXPORT int vinfo_object_to_xml(const DW_VARIABLE_INFO *vinfo, char **xml);
DWDATA_EXPORT int vinfo_xml_to_object(DW_VARIABLE_INFO **vinfo, void *xmlreader);
DWDATA_EXPORT int vinfo_xml_to_multiple_objects(void *vinfos, const char *xml, int is_list);

#ifdef __cplusplus
}
#endif

#endif /*DW_DATA_VARIABLE_H_*/
