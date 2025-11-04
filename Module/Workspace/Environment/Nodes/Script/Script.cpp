#include <Workspace/Environment/Nodes/Script/Script.hpp>
#include <Exploit/Bytecode/Bytecode.hpp>

int identifyexecutor(lua_State* L) {
	lua_pushstring(L, "binnincore");
	lua_pushstring(L, "1.0.0");
    return 1;
}

int getgenv(lua_State* L) {
    lua_pushvalue(L, LUA_ENVIRONINDEX);
    return 1;
}

void ScriptLibrary::Initialize(lua_State* L)
{
	push_global(L, "identifyexecutor", identifyexecutor);
    push_global(L, "getscriptbytecode", getscriptbytecode);
    push_global(L, "getgenv", getgenv);
}