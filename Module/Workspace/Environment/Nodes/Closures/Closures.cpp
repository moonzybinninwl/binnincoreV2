#include "Closures.hpp"
#include <regex>
#include <unordered_set>

static int iscclosure(lua_State* L)
{
    luaL_checktype(L, 1, LUA_TFUNCTION);
    Closure* closure = clvalue(luaA_toobject(L, 1));
    lua_pushboolean(L, closure && closure->isC);
    return 1;
}

static int islclosure(lua_State* L)
{
    luaL_checktype(L, 1, LUA_TFUNCTION);
    Closure* closure = clvalue(luaA_toobject(L, 1));
    lua_pushboolean(L, closure && !closure->isC);
    return 1;
}


int loadstring(lua_State* L)
{
    luaL_checktype(L, 1, LUA_TSTRING);

    const char* source = lua_tostring(L, 1);
    const char* chunk_name = luaL_optstring(L, 2, "Module");

    const std::string& bytecode =   ::Compile(source);

    if (luau_load(L, chunk_name, bytecode.data(), bytecode.size(), 0) != LUA_OK)
    {
        lua_pushnil(L);
        lua_pushvalue(L, -2);
        return 2;
    }

    if (Closure* func = lua_toclosure(L, -1))
    {
        if (func->l.p)
            Scheduler::SetProtoCaps(func->l.p, &MaxCapabilities);
    }

    lua_setsafeenv(L, LUA_GLOBALSINDEX, false);
    return 1;
}

void ClosuresLibrary::Initialize(lua_State* L)
{
    push_global(L, "loadstring", loadstring);
    push_global(L, "islclosure", islclosure);
    push_global(L, "iscclosure", iscclosure);
}