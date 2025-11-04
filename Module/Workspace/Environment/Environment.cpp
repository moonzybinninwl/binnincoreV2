#pragma once
#include "Environment.hpp"


void CEnvironment::Initialize(lua_State* L)
{
    ScriptLibrary::Initialize(L);
    ClosuresLibrary::Initialize(L);

    lua_newtable(L);
    lua_setglobal(L, "_G");

    lua_newtable(L);
    lua_setglobal(L, "shared");
}