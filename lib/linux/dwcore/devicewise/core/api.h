//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/api.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_API_H_
#define DW_CORE_API_H_

#include <devicewise/core/httpsvr.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {

	const char *command;

	JSON *input_base;
	JSON *input_params;
	JSON *output_base;
	JSON *output_params;
	JSON *auth;

	void *userctx;

	int show_timings;
} API_CALL;

typedef int (*api_handler_callback)(API_CALL *api);

DWCORE_EXPORT int api_set_status(API_CALL *api, int success, const char *errorMessage);

DWCORE_EXPORT int api_add_handler(const char *command, api_handler_callback callback);

DWCORE_EXPORT api_handler_callback api_get_handler(const char *command);

DWCORE_EXPORT int api_call_sync(JSON *input, JSON **output, void *userctx);
DWCORE_EXPORT int api_call_sync2(JSON *input, JSON **output, void *userctx, int pool_id);

DWCORE_EXPORT int         api_json_block_set_status(JSON *block, int success, const char *errorMessage);
DWCORE_EXPORT int         api_json_block_add(JSON *json, const char *block, const char *cmd, JSON *params);
DWCORE_EXPORT int         api_json_find_block(JSON *json, const char *id, JSON **block, JSON **params);
DWCORE_EXPORT int         api_json_find_block_ex(JSON *json, const char *id, JSON **block, JSON **params, int *success, char **errMessage);
DWCORE_EXPORT int         api_json_block_is_success(JSON *block);
DWCORE_EXPORT const char *api_json_block_get_error_message(JSON *block);

DWCORE_EXPORT int         api_json_check_overall_success(JSON *output, const char *block, const char **errorMessage);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_API_H_*/
