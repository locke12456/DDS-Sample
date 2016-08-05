//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Logic Subsystem
//
//-- Filename: devicewise/logic/internal/actions/expression.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_INTERNAL_ACTIONS_EXPRESSION_H_
#define DW_CORE_INTERNAL_ACTIONS_EXPRESSION_H_

#ifdef __cplusplus
extern "C" {
#endif

#define EXP_MAX_LEN		256
#define EXP_MAX_TOKENS	64
#define EXP_VAR_LEN		128 //DW_VARIABLE_NAME_LEN

typedef struct {
	void *btree;
	int errcode;
	char *errmsg;
} _QUERY_OBJECT;

typedef double (*expression)(void **nodes, int count, _QUERY_OBJECT *query);

typedef struct {
	char type;
	double value;
	short count;
	expression function;
	void **children;
	char *var;
} _NODE;

typedef struct {
	char name[EXP_VAR_LEN];
	double value;
} EXPRESSION_VAR_MAP;
	
	
void node_delete(_NODE *node);
int node_create(const char *str,int len,_NODE **node, void *input_list);
void node_walk(_NODE *node,int level);
double node_get_value(_NODE *node, _QUERY_OBJECT *query);

void expression_trim(char *exp);

int expression_parse_xml(const char *xml, char **def);

int expression_action_create(DW_IACTION **action, void *context, void *properties);
int expression_action_delete(DW_IACTION *action, void *context);
int expression_action_notify(DW_IACTION *iaction, void *context, DW_ACTION *action, 
					ACTION_NOTIFICATION *notification, ACTION_COMPLETION *completion);
int expression_action_verify(void *context, void *properties, void *reference_list);
int expression_action_query_metadata(void *context, void *properties, ACTION_METADATA *meta_data);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_INTERNAL_ACTIONS_EXPRESSION_H_*/
