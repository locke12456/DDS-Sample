//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Driver Subsystem
//
//-- Filename: devicewise/data/device.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_DATA_DEVICE_H_
#define DW_DATA_DEVICE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*_device_prop_fefunc)(DW_DEVICE *dev, const char *prop, const char *value, void *custom);

// DW_DEVICE (By Name) Functions
DWDATA_EXPORT int device_add(DW_DEVICE *dev, void *secctx, int op);
DWDATA_EXPORT int device_edit(DW_DEVICE *dev, void *secctx, int op);
DWDATA_EXPORT int device_del(const char *name, void *secctx, int op);
DWDATA_EXPORT int device_start(const char *name, void *secctx, int op);
DWDATA_EXPORT int device_stop(const char *name, void *secctx, int op);
DWDATA_EXPORT int device_clr_counters(const char *name, void *secctx,int op);
DWDATA_EXPORT int device_copy(const char *old_dev,const char *new_dev, void *secctx, int op);
DWDATA_EXPORT int device_state(const char *name);
DWDATA_EXPORT int device_disable(DW_DEVICE *dev);

// DW_DEVICE Functions
DWDATA_EXPORT int device_create(DW_DEVICE **device, const char *name, int type, int options);
DWDATA_EXPORT void device_free(void *dev);
DWDATA_EXPORT int device_has_option(DW_DEVICE *dev,int opt);
DWDATA_EXPORT int device_set_option(DW_DEVICE *dev,int opt, int value);

/// Function to set the status and extended status codes in a device. This function is typically used to record errors that are generic to the device, for example errors encountered during the device start.
/// 
/// \param dev is a pointer to a DW_DEVICE item. 
/// \param status is an integer code. The status field is reserved for deviceWISE error codes
/// \param exstatus is an integer code. The extended status field is reserved for error codes generated from an external source
/// \return 0 is returned if successful. 
/// \sa /data/errors.h
DWDATA_EXPORT int device_set_status(DW_DEVICE *dev, int status, int exstatus);

/// Function to set the status and extended status codes for a specific variable within a device. This function is typically used during read or write errors on a particular device variable.
/// 
/// \param dev is a pointer to a DW_DEVICE item. 
/// \param var is a character pointer containing the name of the device variable that was in error.
/// \param status is an integer code. The status field is reserved for deviceWISE error codes
/// \param exstatus is an integer code. The extended status field is reserved for error codes generated from an external source
/// \return 0 is returned if successful. 
/// \sa /data/errors.h
DWDATA_EXPORT int device_error(DW_DEVICE *dev, const char *var, int status, int exstatus);

/// Function to set the descriptive text for a device.
/// 
/// \param dev is a pointer to a DW_DEVICE item. 
/// \param desc is a character pointer containing the description to be assigned to the device.
/// \return 0 is returned if successful. 
DWDATA_EXPORT int device_set_desc(DW_DEVICE *dev, const char *desc);

/// Function to set assign attributes to a device. The device attributes are displayed on the Attributes tab on the Devices panel of the deviceWISE Workbench
/// 
/// \param dev is a pointer to a DW_DEVICE item. 
/// \param name The device attribute name.
/// \param name_nls_id Internal deviceWISE use only. Must always be -1
/// \param value The attribute's value
/// \return 0 is returned if successful. 
DWDATA_EXPORT int device_add_attribute(DW_DEVICE *dev, const char *name, int name_nls_id, const char *value);
DWDATA_EXPORT int device_add_attribute_dynamic_str(DW_DEVICE *dev, const char *name, int name_nls_id, const char *value);
DWDATA_EXPORT int device_add_attribute_dynamic_int(DW_DEVICE *dev, const char *name, int name_nls_id, const int *value);

/// Function to remove an attribute from a device. The device attributes are displayed on the Attributes tab on the Devices panel of the deviceWISE Workbench
/// 
/// \param dev is a pointer to a DW_DEVICE item. 
/// \param name The device attribute name.
/// \return 0 is returned if successful. 
DWDATA_EXPORT int device_del_attribute(DW_DEVICE *dev, const char *name);

/// Function to get the current state of a device. 
/// 
/// \param dev is a pointer to a DW_DEVICE item. 
/// \return A value that indicates the device status code. 
/// \sa constants.h
DWDATA_EXPORT int device_get_state(DW_DEVICE *dev);

DWDATA_EXPORT int device_prop_add(DW_DEVICE *dev, const char *name, const char *value);

DWDATA_EXPORT int device_get_prop(DW_DEVICE *dev, const char *key, char **value);
DWDATA_EXPORT int device_foreach_prop(DW_DEVICE *dev, _device_prop_fefunc func, void *custom);
DWDATA_EXPORT int device_add_mapped_description(DW_DEVICE *dev, const char *var_name, const char *desc);
DWDATA_EXPORT int device_refresh_model(DW_DEVICE *dev);
DWDATA_EXPORT int device_time_get(DW_DEVICE *dev, long long *device_time);
DWDATA_EXPORT int device_time_set(DW_DEVICE *dev, long long device_time);

// Check Device Features
DWDATA_EXPORT int device_supports_async(DW_DEVICE *dev);
DWDATA_EXPORT int device_supports_sync(DW_DEVICE *dev);

DWDATA_EXPORT int device_reference(DW_DEVICE *dev,const char *who);
DWDATA_EXPORT int device_dereference(DW_DEVICE *dev,const char *who);
DWDATA_EXPORT int device_reference_by_name(const char *name,const char *who);
DWDATA_EXPORT int device_dereference_by_name(const char *name,const char *who);
DWDATA_EXPORT int device_find(const char *name, DW_DEVICE **dev, const char *who);
DWDATA_EXPORT void device_foreach(btree_fefunc func,void *args, int state_mask);

// DW_VARIABLE_INFO Functions
/// Function to add a DW_VARIABLE_INFO object to a device. 
/// 
/// \param device is a pointer to a DW_DEVICE item. 
/// \param vinfo is a pointer to a DW_VARIABLE_INFO object to add to the DW_DEVICE item. 
/// \return 0 if successful. 
DWDATA_EXPORT int device_vinfo_add(DW_DEVICE *device, DW_VARIABLE_INFO *vinfo);

/// Function to remove a DW_VARIABLE_INFO object from a device. 
/// 
/// \param device is a pointer to a DW_DEVICE item.
/// \param name is a character pointer and is the name of the DW_VARIABLE_INFO object to remove from the DW_DEVICE item. 
/// \return 0 if successful. 
DWDATA_EXPORT int device_vinfo_del(DW_DEVICE *device, const char *name);

/// Function to return the number of DW_VARIABLE_INFO objects that have been added to a device. 
/// 
/// \param device is a pointer to a DW_DEVICE item.
/// \return the number of DW_VARIABLE_INFO objects that have been added to a device. 
DWDATA_EXPORT int device_vinfo_count(const DW_DEVICE *device);
DWDATA_EXPORT int device_vinfo_find(const DW_DEVICE *device, const char *name, DW_VARIABLE_INFO **vinfo);

/// Function to execute a function for each DW_VARIABLE_INFO object in a device. 
/// 
/// \param device is a pointer to a DW_DEVICE item. 
/// \param func the function to call for each DW_VARIABLE_INFO object. The function must have the following signature func(const void *item, void *custom) where item will be the DW_VARIABLE_INFO item and custom will be the args parameter
/// \param args a void pointer to an area in memory that will be passed to the function for each DW_VARIABLE_INFO object
/// \return 0 if successful. 
DWDATA_EXPORT int device_vinfo_foreach(const DW_DEVICE *device, btree_fefunc func,void *args);

/// Function to remove all of the DW_VARIABLE_INFO objects that have been added to a device. 
/// 
/// \param dev is a pointer to a DW_DEVICE item. 
/// \return 0 if successful 
DWDATA_EXPORT int device_vinfo_clear(DW_DEVICE *dev);

// DW_STRUCTURE_INFO Functions
/// Function to add a DW_STRUCTURE_INFO object to a device. 
/// 
/// \param device is a pointer to a DW_DEVICE item. 
/// \param sinfo is a pointer to a DW_STRUCTURE_INFO object to add to the DW_DEVICE item. 
/// \return 0 if successful. 
DWDATA_EXPORT int device_sinfo_add(DW_DEVICE *device, DW_STRUCTURE_INFO *sinfo);

/// Function to remove a DW_STRUCTURE_INFO object to a device. 
/// 
/// \param device is a pointer to a DW_DEVICE item. 
/// \param id the structure id of the DW_STRUCTURE_INFO object that is to be deleted from the DW_DEVICE item. 
/// \return 0 if successful. 
DWDATA_EXPORT int device_sinfo_del(DW_DEVICE *device, int id);

/// Function to retrieve a DW_STRUCTURE_INFO object from a device. 
/// 
/// \param device is a pointer to a DW_DEVICE item. 
/// \param id the structure id of the DW_STRUCTURE_INFO object that is in the DW_DEVICE item. 
/// \return DW_STRUCTURE_INFO object if found. Null if not found
DWDATA_EXPORT DW_STRUCTURE_INFO *device_sinfo_find_by_id(const DW_DEVICE *device, int id);

/// Function to return the number of DW_STRUCTURE_INFO objects that have been added to a device. 
/// 
/// \param device is a pointer to a DW_DEVICE item.
/// \return the number of DW_STRUCTURE_INFO objects that have been added to a device. 
DWDATA_EXPORT int device_sinfo_count(const DW_DEVICE *device);

/// Function to execute a function for each DW_STRUCTURE_INFO object in a device. 
/// 
/// \param device is a pointer to a DW_DEVICE item. 
/// \param func the function to call for each DW_STRUCTURE_INFO object. The function must have the following signature func(const void *item, void *custom) where item will be the DW_STRUCTURE_INFO item and custom will be the void pointer args parameter
/// \param args a void pointer to an area in memory that will be passed to the function for each DW_STRUCTURE_INFO object
/// \return 0 if successful. 
DWDATA_EXPORT int device_sinfo_foreach(const DW_DEVICE *device, btree_fefunc func,void *args);

/// Function to remove all of the DW_STRUCTURE_INFO objects that have been added to a device. 
/// 
/// \param dev is a pointer to a DW_DEVICE item. 
/// \return 0 if successful 
DWDATA_EXPORT int device_sinfo_clear(DW_DEVICE *dev);

// DW_COMMAND_INFO Functions
DWDATA_EXPORT int device_cinfo_add(DW_DEVICE *device, DW_COMMAND_INFO *sinfo);
DWDATA_EXPORT int device_cinfo_del(DW_DEVICE *device, const char *name);
DWDATA_EXPORT DW_COMMAND_INFO *device_cinfo_find_by_id(const DW_DEVICE *device, int id);
DWDATA_EXPORT int device_cinfo_count(const DW_DEVICE *device);
DWDATA_EXPORT int device_cinfo_foreach(const DW_DEVICE *device, btree_fefunc func,void *args);
DWDATA_EXPORT int device_cinfo_clear(DW_DEVICE *dev);

// Device Type Functions
/// Function to register the device driver with the deviceWISE device manager. The device manager will return a DW_DRIVER object that will be used in subsequent function calls.
/// 
/// \param id a numeric value to identify the driver. This must be a unique number
/// \param name a character pointer that contains the name of the device driver
/// \param name_nls must be equal to -1
/// \param options a numeric value calculated by OR'ing together various deviceWISE property values, examples: DW_CREATEABLE | DW_EDITABLE | DW_DELETABLE | DW_CONTROLLABLE | DW_SORTVARS
/// \param driver a pointer to a DW_DRIVER structure. Upon successful registration, this variable will contain a handle to the deviceWISE reference to the device driver.
/// \return 0 if successful 
/// \sa constants.h
DWDATA_EXPORT int device_type_register(int id, const char *name, int name_nls, int options, DW_DRIVER *driver);

/// Function to assign a device id defined in the deviceWISE device manager to a family of devices. 
/// 
/// \param id a numeric value that identifies the device driver. This value must have been previously registerd with the device manager using the device_type_register() function.
/// \param family a character pointer that contains the name of the driver family the device type belongs to. Examples of this might be Rockwell, Mitsubishi, Siemens, etc.
/// \param family_nls must be equal to -1
/// \param category the driver category this device belongs to. Typically this value is NULL.
/// \param category_nls must be equal to -1
DWDATA_EXPORT int device_type_set_listing_info(int id, const char *family, int family_nls, const char *category, int category_nls);

DWDATA_EXPORT int device_type_set_license(int id, short lic_prod, short lic_feature);

// Device Type Functions
/// Function to remove a device driver from the deviceWISE device manager. 
/// 
/// \param id a numeric value to identify the driver. This value must have been previously registerd with the device manager using the device_type_register() function.
/// \return 0 if successful
DWDATA_EXPORT int device_type_deregister(int id);

DWDATA_EXPORT int device_type_exists(int id);
DWDATA_EXPORT int device_type_is_licensed(int id);
DWDATA_EXPORT int device_type_has_option(int id, int opt);
DWDATA_EXPORT int device_type_get_options(int id, int *opt);
DWDATA_EXPORT int device_type_map_type(int id, int data_type, const char *type);
DWDATA_EXPORT const char *device_type_get_name(int id);
DWDATA_EXPORT int device_type_get_driver(int id, DW_DRIVER **driver);
DWDATA_EXPORT void device_type_foreach(btree_fefunc func, void *custom);
DWDATA_EXPORT int device_type_set_order(int id, int display_order);

// Device Type Functions
/// Function to add a string property to the device driver definition that will be displayed on the deviceWISE Workbench. 
/// 
/// \param id a numeric value to identify the driver. This value must have been previously registerd with the device manager using the device_type_register() function.
/// \param key a constant character pointer whose value is the key for the string property being defined
/// \param name a constant character pointer whose value is the displayed label that will be shown on the deviceWISE Workbench Device Definition panel
/// \param name_id numeric string id found in the ILS NLS file. Must equal -1
/// \param desc_id numeric string id found in the ILS NLS file. Must equal -1
/// \param opts an integer that represents the parameters displayable options. Option definitions are defined in common.h examples DW_OPT_REQUIRED, DW_OPT_ADVANCED
/// \param def the default value to display in the string field
/// \return 0 is returned if successful
/// \sa common.h
DWDATA_EXPORT int device_type_add_property_string (int id, const char *key, const char *name, int name_id, int desc_id, int opts, const char *def);

DWDATA_EXPORT int device_type_add_property_other (int id, const char *key, const char *name, int name_id, int desc_id, int opts, const char *type, const char *def);

/// Function to add a list box option property to the device driver definition that will be displayed on the deviceWISE Workbench. 
/// 
/// \param id a numeric value to identify the driver. This value must have been previously registerd with the device manager using the device_type_register() function.
/// \param key a constant character pointer whose value is the key for the option property being defined
/// \param name a constant character pointer whose value is the displayed label that will be shown on the deviceWISE Workbench Device Definition panel
/// \param name_id numeric string id found in the ILS NLS file. Must equal -1
/// \param desc_id numeric string id found in the ILS NLS file. Must equal -1
/// \param opts an integer that represents the parameters displayable options. Option definitions are defined in common.h examples DW_OPT_REQUIRED, DW_OPT_ADVANCED
/// \param options a constant character pointer whose value is a comma delimited string of options to be shown in the list box. example "Option 1,Option2,Option 3"
/// \param defopt an integer that defines which of the items in the options parameter will be the default option selected in the list box
/// \return 0 is returned if successful
/// \sa common.h
DWDATA_EXPORT int device_type_add_property_option (int id, const char *key, const char *name, int name_id, int desc_id, int opts, const char *options, int defopt);

/// Function to add a numeric entry field property to the device driver definition that will be displayed on the deviceWISE Workbench. 
/// 
/// \param id a numeric value to identify the driver. This value must have been previously registerd with the device manager using the device_type_register() function.
/// \param key a constant character pointer whose value is the key for the numeric entry field property being defined
/// \param name a constant character pointer whose value is the displayed label that will be shown on the deviceWISE Workbench Device Definition panel
/// \param name_id numeric string id found in the ILS NLS file. Must equal -1
/// \param desc_id numeric string id found in the ILS NLS file. Must equal -1
/// \param opts an integer that represents the parameters displayable options. Option definitions are defined in common.h examples DW_OPT_REQUIRED, DW_OPT_ADVANCED
/// \param defval an integer that will be the default value shown in the entry field.
/// \param minval an integer that defines the minimum value that can be entered into the numeric field
/// \param maxval an integer that defines the maximum value that can be entered into the numeric field
/// \return 0 is returned if successful
/// \sa common.h
DWDATA_EXPORT int device_type_add_property_integer (int id, const char *key, const char *name, int name_id, int desc_id, int opts, int defval, int minval, int maxval);

/// Function to add a boolean true/false list box property to the device driver definition that will be displayed on the deviceWISE Workbench. 
/// 
/// \param id a numeric value to identify the driver. This value must have been previously registerd with the device manager using the device_type_register() function.
/// \param key a constant character pointer whose value is the key for the numeric entry field property being defined
/// \param name a constant character pointer whose value is the displayed label that will be shown on the deviceWISE Workbench Device Definition panel
/// \param name_id numeric string id found in the ILS NLS file. Must equal -1
/// \param desc_id numeric string id found in the ILS NLS file. Must equal -1
/// \param opts an integer that represents the parameters displayable options. Option definitions are defined in common.h examples DW_OPT_REQUIRED, DW_OPT_ADVANCED
/// \param defval an integer that will be the default selection the list box. TRUE or 1, indicates the true option is selected, FALSE or 0 indicates the false option is selected.
/// \return 0 is returned if successful
/// \sa common.h
DWDATA_EXPORT int device_type_add_property_check (int id, const char *key, const char *name, int name_id, int desc_id, int opts, int defval);

/// Function to enforce a condition on the next property, based upon the results specified in the condition check. This function allows for the conditiional display of properties on the deviceWISE Workbench. 
/// 
/// \param id a numeric value to identify the driver. This value must have been previously registerd with the device manager using the device_type_register() function.
/// \param key a constant character pointer whose value is the key for a previously defined property field
/// \param value a constant character pointer whose value is one of the selectable items from a previously defined property field
/// \param condition either PROP_COND_EQUAL or PROP_COND_NOT_EQUAL. The test is to see if the selected item from a previously defined property field is equal to a certain value
/// \return 0 is returned if successful. The display of the next property added, will be affected by the results of the condition parameter
/// \sa common.h
DWDATA_EXPORT int device_type_add_condition (int id, const char *key, const char *value, int condition);

DWDATA_EXPORT int device_type_add_global_property_string  (const char *key, const char *name, int name_id, int desc_id, int opts, const char *def);
DWDATA_EXPORT int device_type_add_global_property_other   (const char *key, const char *name, int name_id, int desc_id, int opts, const char *type, const char *def);
DWDATA_EXPORT int device_type_add_global_property_option  (const char *key, const char *name, int name_id, int desc_id, int opts, const char *options, int defopt);
DWDATA_EXPORT int device_type_add_global_property_integer (const char *key, const char *name, int name_id, int desc_id, int opts, int defval, int minval, int maxval);
DWDATA_EXPORT int device_type_add_global_property_check   (const char *key, const char *name, int name_id, int desc_id, int opts, int defval);
DWDATA_EXPORT int device_type_add_global_condition        (const char *key, const char *value, int condition);

#ifdef __cplusplus
}
#endif

#endif /*DW_DATA_DEVICE_H_*/
