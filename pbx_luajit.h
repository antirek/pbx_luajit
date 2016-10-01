#ifndef PBX_LUAJIT_H_INCLUDED
#define PBX_LUAJIT_H_INCLUDED

#include <asterisk.h>
#include "export.h"

#ifndef AST_MODULE
#define AST_MODULE "pbx_luajit"
#define MODULE_DESCRIPTION      "Lua PBX Switch"
#endif // AST_MODULE

EXPORT_DECL char *lua_read_extensions_file(lua_State *L, long *size);
EXPORT_DECL int lua_load_extensions(lua_State *L, struct ast_channel *chan);
EXPORT_DECL int lua_reload_extensions(lua_State *L);
EXPORT_DECL void lua_free_extensions(void);
EXPORT_DECL int lua_sort_extensions(lua_State *L);
EXPORT_DECL int lua_register_switches(lua_State *L);
EXPORT_DECL int lua_register_hints(lua_State *L);
EXPORT_DECL int lua_extension_cmp(lua_State *L);
EXPORT_DECL int lua_find_extension(lua_State *L, const char *context, const char *exten, int priority, ast_switch_f *func, int push_func);
EXPORT_DECL int lua_pbx_findapp(lua_State *L);
EXPORT_DECL int lua_pbx_exec(lua_State *L);

EXPORT_DECL int lua_get_variable_value(lua_State *L);
EXPORT_DECL int lua_set_variable_value(lua_State *L);
EXPORT_DECL int lua_get_variable(lua_State *L);
EXPORT_DECL int lua_set_variable(lua_State *L);
EXPORT_DECL int lua_func_read(lua_State *L);

EXPORT_DECL int lua_autoservice_start(lua_State *L);
EXPORT_DECL int lua_autoservice_stop(lua_State *L);
EXPORT_DECL int lua_autoservice_status(lua_State *L);
EXPORT_DECL int lua_check_hangup(lua_State *L);
EXPORT_DECL int lua_error_function(lua_State *L);

EXPORT_DECL void lua_update_registry(lua_State *L, const char *context, const char *exten, int priority);
EXPORT_DECL void lua_push_variable_table(lua_State *L);
EXPORT_DECL void lua_create_app_table(lua_State *L);
EXPORT_DECL void lua_create_channel_table(lua_State *L);
EXPORT_DECL void lua_create_variable_metatable(lua_State *L);
EXPORT_DECL void lua_create_application_metatable(lua_State *L);
EXPORT_DECL void lua_create_autoservice_functions(lua_State *L);
EXPORT_DECL void lua_create_hangup_function(lua_State *L);
EXPORT_DECL void lua_concat_args(lua_State *L, int start, int nargs);

EXPORT_DECL void lua_state_destroy(void *data);
EXPORT_DECL void lua_datastore_fixup(void *data, struct ast_channel *old_chan, struct ast_channel *new_chan);
EXPORT_DECL lua_State *lua_get_state(struct ast_channel *chan);

EXPORT_DECL int exists(struct ast_channel *chan, const char *context, const char *exten, int priority, const char *callerid, const char *data);
EXPORT_DECL int canmatch(struct ast_channel *chan, const char *context, const char *exten, int priority, const char *callerid, const char *data);
EXPORT_DECL int matchmore(struct ast_channel *chan, const char *context, const char *exten, int priority, const char *callerid, const char *data);
EXPORT_DECL int exec(struct ast_channel *chan, const char *context, const char *exten, int priority, const char *callerid, const char *data);

AST_MUTEX_DEFINE_STATIC(config_file_lock);
static char *config_file_data = NULL;
static long config_file_size = 0;

static struct ast_context *local_contexts = NULL;
static struct ast_hashtab *local_table = NULL;

#endif // PBX_LUAJIT_H_INCLUDED
