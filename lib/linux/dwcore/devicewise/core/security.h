//----------------------------------------------------------------
//
//-- ILS Technology
//-- DeviceWISE Core
//
//-- Filename: devicewise/core/security.h
//
//-- Copyright: 2001-2013, ILS Technology, LLC
//
//----------------------------------------------------------------

#ifndef DW_CORE_SECURITY_H_
#define DW_CORE_SECURITY_H_

#ifdef __cplusplus
extern "C" {
#endif

#define SECURITY_USER_OPT_PROTECTED 1
#define SECURITY_USER_OPT_HIDDEN	2
#define SECURITY_USER_OPT_BYPASS	4
#define SECURITY_USER_OPT_INTERNAL	8
#define	SECURITY_USER_OPT_DEFAULT_PASSWD	16

#define SECURITY_CHAN_CACHE_CLEAR		1
#define SECURITY_CHAN_USER_RECHECK		2
#define SECURITY_CHAN_USER_RECHECK_ALL	3

DWCORE_EXPORT int security_authenticate_user(const char *username, const char *password, void **userctx);
DWCORE_EXPORT int security_check_session(const char *resource, void *session);
DWCORE_EXPORT int security_check_userctx(const char *resource, void *userctx);
DWCORE_EXPORT int security_check_secctx(const char *resource, void *secctx, int op);

DWCORE_EXPORT int security_update_userctx(void *userctx);
DWCORE_EXPORT int security_clone_userctx(void *userctx, void **newctx);
DWCORE_EXPORT const char * security_name_userctx(void *userctx);
DWCORE_EXPORT int security_list_roles(void *userctx, char ***role_list);
DWCORE_EXPORT int security_check_userctx_option(void *userctx, int option);
DWCORE_EXPORT int security_add_policy(const char *policy, void *secctx, int opt);
DWCORE_EXPORT int security_edit_policy(const char *policy,const char *old_name, void *secctx, int opt);
DWCORE_EXPORT int security_del_policy(const char *name, void *secctx, int opt);
DWCORE_EXPORT int security_enable_policy(const char *name, void *secctx,int op);
DWCORE_EXPORT int security_disable_policy(const char *name, void *secctx,int op);
DWCORE_EXPORT int security_apply_policy(const char *name, void *secctx, int opt);
DWCORE_EXPORT int security_get_policy(const char *name, char **policy);
DWCORE_EXPORT int security_list_policies(char ***policies, int **lens);

DWCORE_EXPORT int security_add_resource(const char *resource);
DWCORE_EXPORT int security_add_resources(const char **resource, int count);
DWCORE_EXPORT int security_del_resource(const char *resource, int del_children);
DWCORE_EXPORT int security_del_resources(const char **resource, int count, int del_children);
DWCORE_EXPORT int security_list_resources(char **xml);

DWCORE_EXPORT int security_role_create(const char *role,const char *desc, void *secctx, int opt);
DWCORE_EXPORT int security_role_delete(const char *role, void *secctx, int opt);
DWCORE_EXPORT int security_role_list(char ***roles);
DWCORE_EXPORT int security_role_list_users_for_role(const char *role, char ***users);
DWCORE_EXPORT int security_role_is_valid(const char *role);

DWCORE_EXPORT int security_user_check(const char *user, const char *password, int *options);
DWCORE_EXPORT int security_user_create(const char *user, const char *pass, const char *role_list[], int role_count, void *secctx, int opt, int options);
DWCORE_EXPORT int security_user_update(const char *user, const char *pass, const char *role_list[], int role_count, void *secctx, int opt);
DWCORE_EXPORT int security_user_delete(const char *user, void *secctx, int opt);
DWCORE_EXPORT int security_user_list(DW_PACKET *packet);
DWCORE_EXPORT int security_user_enable(const char *user, void *secctx, int opt);
DWCORE_EXPORT int security_user_disable(const char *user, void *secctx, int opt);
DWCORE_EXPORT int security_user_change_passwd(const char *pass, void *secctx, int opt);

DWCORE_EXPORT int security_user_encrypt_passwd(const char *secret, char **password);
DWCORE_EXPORT int security_user_decrypt_passwd(const char *password, char **secret);

#ifdef __cplusplus
}
#endif

#endif /*DW_CORE_SECURITY_H_*/
