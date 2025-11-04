#pragma once
#include <lua.h>
#include <lstate.h>
#include <lualib.h>
#include <Workspace/Engine/Engine.hpp>
#include "Scheduler.hpp"
#include <Workspace/Execution/Execution.hpp>
#include <thread>
#include "functional"

using Return = std::function<int(lua_State* L)>;
struct Data
{
	lua_State* L;
	std::function<Return()> generator;
	PTP_WORK work;
};

int handle(lua_State* L) // execution listener
{
    if (!Globals::PacketQueue.empty())
    {
        Execution::RunScript(Globals::RobloxThread, Globals::PacketQueue.front());
        Globals::PacketQueue.erase(Globals::PacketQueue.begin());
    }

    return 0;
}

void HookScheduler(lua_State* L)
{
    lua_getglobal(L, "game");
    lua_getfield(L, -1, "GetService");
    lua_pushvalue(L, -2);

    lua_pushstring(L, "RunService");
    lua_pcall(L, 2, 1, 0);

    lua_getfield(L, -1, "RenderStepped");
    lua_getfield(L, -1, "Connect");
    lua_pushvalue(L, -2);

    lua_pushcclosure(L, handle, nullptr, 0);
    lua_pcall(L, 2, 0, 0);
    lua_pop(L, 2);
}

bool TaskScheduler::Run()
{
    uintptr_t SC = Scheduler::ScriptContext(PreviousDM);
    lua_State* RobloxState = Scheduler::LuaState(SC);
    Globals::RobloxThread = lua_newthread(RobloxState);
    Scheduler::SetThreadCaps(Globals::RobloxThread, 8, MaxCapabilities);
    CEnvironment::Initialize(Globals::RobloxThread);
    HookScheduler(Globals::RobloxThread);
    return true;
}

void TaskScheduler::Execute(std::string Script)
{
    Globals::PacketQueue.push_back(Script);
}

