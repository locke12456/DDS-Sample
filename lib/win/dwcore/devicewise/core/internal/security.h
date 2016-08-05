//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/internal/security.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_INTERNAL_SECURITY_H_
#define DW_CORE_INTERNAL_SECURITY_H_

#ifdef __cplusplus
extern "C" {
#endif

#define SECURITY_NODE_NAME_LEN 64
#define SECURITY_ALLOW		3
#define SECURITY_DENY		2
#define SECURITY_INHERIT	1

#define SECURITY_CTX_LEN	64
#define SECURITY_CTX_ROLES	16

typedef struct {
	char username[SECURITY_CTX_LEN+4];
	int id;
	char roles[SECURITY_CTX_ROLES][SECURITY_CTX_LEN+4];
	int role_count;
	int option;
} _USER_CTX;

typedef struct {
	char name[SECURITY_NODE_NAME_LEN+4];
	int action;
} _ROLE_NODE;

typedef struct {
	char name[SECURITY_NODE_NAME_LEN+4];
	void *children;
	void *roles;
} _POLICY_NODE;

typedef struct {
	char name[SECURITY_NODE_NAME_LEN+4];
	int prio;
	void *children;
} _POLICY;

int security_cache_add(const char *resource, _USER_CTX *userctx, int result);
int security_cache_check(const char *resource, _USER_CTX *userctx);
void security_cache_clear();

int security_policy_check(_POLICY *policy, const char *resource, _USER_CTX *userctx);

int security_policy_xml_to_object(const char *xml, _POLICY **policy);

int security_policy_create(const char *name, int prio, _POLICY **policy);
void security_policy_free(void *policy);

int security_policy_node_create(const char *name, _POLICY_NODE **node);
void security_policy_node_free(void *node);

int security_role_node_create(const char *name, int action, _ROLE_NODE **node);
int security_policy_reference(_POLICY *po);

#define SECURITY_INIT_NORMAL	1
#define SECURITY_INIT_CLASSIC	2

void security_init_system();
void security_init_system_classic();

#ifdef __cplusplus
}
#endif

#endif /*DW_INTERNAL_SECURITY_H_*/
