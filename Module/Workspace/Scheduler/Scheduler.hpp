#pragma once

#include <Workspace/Environment/Environment.hpp>


inline uintptr_t PreviousDM;

class Scheduler {
public:
	static void SetProtoCaps(Proto* Proto, uintptr_t* Capabilities);
	static void SetThreadCaps(lua_State* L, int Level, uintptr_t Capabilities);
	static uintptr_t ScriptContext(uintptr_t DataModel);
	static uintptr_t DataModel();
	static lua_State* LuaState(uintptr_t ScriptContext);
	static bool GameIsLoaded(uintptr_t DataModel);
	static bool IsValidPointer(void* ptr, size_t size);
	static __int64 GetPlaceID();
};


class TaskScheduler {
public:
	static bool Run();
	static void Execute(std::string Script);
};