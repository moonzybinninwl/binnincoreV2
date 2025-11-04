#pragma once
#include "Windows.h"
#include "iostream"
#include "vector"

#include "Workspace/Engine/Engine.hpp"
#include "Exploit/Utilities/Globals.hpp"

#include "luacode.h"
#include "luau/BytecodeBuilder.h"
#include "luau/BytecodeUtils.h"
#include "luau/Compiler.h"

#include "VM/src/lobject.h"
#include "VM/src/lstate.h"
#include "VM/src/lapi.h"

#include "zstd/include/zstd/xxhash.h"
#include "zstd/include/zstd/zstd.h"

#include <Exploit/Bytecode/Bytecode.hpp>
#include "Workspace/Scheduler/Scheduler.hpp"
#include "lualib.h"

struct lua_State;

class Execution
{
public:
	static void RunScript(lua_State* l, const std::string& script);
};