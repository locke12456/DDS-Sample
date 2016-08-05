//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/common/internal/propdesc.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_COMMON_INTERNAL_PROPDESC_H_
#define DW_COMMON_INTERNAL_PROPDESC_H_

#ifdef __cplusplus
extern "C" {
#endif

#define PROP_DESC_STR_LEN		64
#define PROP_DESC_STRING		1
#define PROP_DESC_OPTION		2
#define PROP_DESC_INTEGER		3
#define PROP_DESC_CHECK			4
#define PROP_DESC_OTHER			5

#define PROP_COND_MAX			16

typedef struct {
	int condition;
	char key[PROP_DESC_STR_LEN+4];
	char value[PROP_DESC_STR_LEN+4];
} DW_PROP_COND_ITEM;

typedef struct {
	char key[PROP_DESC_STR_LEN+4];
	char name[PROP_DESC_STR_LEN+4];
	int name_nls;
	int desc_nls;
	int opts;
	int type;

	char *string_def;

	char *other_type;
	char *other_def;

	char *options;
	int options_default_index;

	int integer_default;
	int integer_min;
	int integer_max;
	int check_default;

	DW_PROP_COND_ITEM *conditions;
	int condition_count;
} DW_PROP_DESC_ITEM;

DWCOMMON_EXPORT void propdesc_foreach(void *phandle, list_fefunc func, void *custom);

#ifdef __cplusplus
}
#endif

#endif /*DW_COMMON_INTERNAL_PROPDESC_H_*/
