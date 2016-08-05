//----------------------------------------------------------------
//
//-- ILS Technology
//-- C Platform Independent Library
//
//-- Filename: ils/util/hardwareid.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef ILS_UTIL_HARDWAREID_H_
#define ILS_UTIL_HARDWAREID_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	char type[24 + 1];
	int type_nls;
	char hwid[24];
	char ip[24];
} HWID_ENTRY;

UTIL_EXPORT int hardwareid_count();
UTIL_EXPORT int hardwareid_list(HWID_ENTRY *hwids, int *count);

#ifdef __cplusplus
}
#endif

#endif /*ILS_UTIL_HARDWAREID_H_*/
