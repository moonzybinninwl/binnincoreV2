#include <lua.h>
#include "Nodes/Script/Script.hpp"
#include "Nodes/Closures/Closures.hpp"
#include "Nodes/HTTP/HTTP.hpp"

static void push_global(lua_State* L, const char* globalname, lua_CFunction function)
{
    lua_pushcclosure(L, function, nullptr, 0);
    lua_setglobal(L, globalname);
}

static void push_member(lua_State* L, const char* globalname, lua_CFunction function) {
    lua_pushcclosurek(L, function, nullptr, 0, nullptr);
    lua_setfield(L, -2, globalname);
}

