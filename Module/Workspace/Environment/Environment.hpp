#pragma once
#include "Windows.h"
#include "iostream"
#include "vector"
#include <string>
#include <vector>
#include <algorithm>
#include <map>      
#include <cstdlib>   
#include <stdexcept> 
#include <ctime>    
#include <cctype>    
#include <random>    
#include <sstream>
#include <wininet.h>
#pragma comment(lib, "wininet.lib")

#include "Workspace/Engine/Engine.hpp"
#include "Exploit/Utilities/Globals.hpp"

#include "VM/include/lua.h"
#include "VM/include/lualib.h"
#include "VM/src/lcommon.h"
#include "VM/src/lstring.h"
#include "VM/src/lfunc.h"
#include "VM/src/lmem.h"
#include "VM/src/lgc.h"
#include "VM/src/ltable.h"
#include "VM/src/lobject.h"
#include "VM/src/lstate.h"
#include "VM/src/lapi.h"
#include "VM/src/ldo.h"

#include "zstd/include/zstd/zstd.h"
#include "zstd/include/zstd/xxhash.h"
#include "Compiler/include/Luau/Compiler.h"
#include "Compiler/include/luacode.h"
#include "Common/include/Luau/BytecodeUtils.h"
#include "Compiler/include/Luau/BytecodeBuilder.h"
#include "Libraries.hpp"
#include <Workspace/Scheduler/Scheduler.hpp>


class CEnvironment {
public:
	static void Initialize(lua_State* L);
};