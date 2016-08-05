//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/internal/license.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_INTERNAL_LICENSE_H_
#define DW_CORE_INTERNAL_LICENSE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define LICENSE_KEY_LEN					35
#define LICENSE_PRODUCT_NAME_LEN		32
#define LICENSE_FEATURE_NAME_LEN		32
#define LICENSE_ERR_MSG_LEN				512
#define LICENSE_DELIMITER				'.'

#define LICENSE_FEATURE_TYPE_FLAG		1
#define LICENSE_FEATURE_TYPE_COUNT		2

typedef struct {
	char name[LICENSE_FEATURE_NAME_LEN+1];
	char offset;
	char length;
	char type;
	int value;
} _FEATURE_OBJECT;

typedef struct {
	char name[LICENSE_PRODUCT_NAME_LEN+1];
	void *features;
	void *features_by_offset;
	int id;
} _PRODUCT_OBJECT;


typedef struct {
	char key[LICENSE_KEY_LEN+1];
	char product[LICENSE_PRODUCT_NAME_LEN+1];
	int product_id;
	long long creation;
	long long expiration;
	int data;
	int hwhash;
	char error[LICENSE_ERR_MSG_LEN+1];
// revised version fields
	char key_version;
	char entitlement;
	char prerelease;
	int vendor_product;
} _LICENSE_OBJECT;


const char *_license_product_name_get(int id);
int _license_product_id_get(const char *name);
const char *_license_product_features_list(int product_id,int *data); 
int _license_product_create(int id, const char *name);
int _license_feature_create(int product_id, const char* fname, char offset, char length);

int _license_generate_key(_LICENSE_OBJECT *ptr, char **key);
int _license_extract_key(const char* key, _LICENSE_OBJECT **ptr);
void _license_evaluate_feature(int product_id, int feature_id);
void _license_evaluate_product(int product_id);

#ifdef __cplusplus
}
#endif


#endif /*DW_CORE_LICENSE_H_*/
