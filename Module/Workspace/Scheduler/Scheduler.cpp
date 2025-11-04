#pragma once

#include <lua.h>
#include <lstate.h>
#include <lualib.h>
#include <Workspace/Engine/Engine.hpp>
#include "Scheduler.hpp"
#include <Workspace/Execution/Execution.hpp>

void Scheduler::SetProtoCaps(Proto* Proto, uintptr_t* Capabilities)
{
    Proto->userdata = Capabilities;
    for (int i = 0; i < Proto->sizep; ++i)
    {
        SetProtoCaps(Proto->p[i], Capabilities);
    }
}

void Scheduler::SetThreadCaps(lua_State* L, int Level, uintptr_t Capabilities)
{
    *reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(L->userdata) + Offsets::External::TaskScheduler::Capabilities) = Capabilities;
    *reinterpret_cast<int*>(reinterpret_cast<uintptr_t>(L->userdata) + Offsets::External::TaskScheduler::Identity) = Level;
}

uintptr_t Scheduler::DataModel()
{
    uintptr_t FakeDM = *reinterpret_cast<uintptr_t*>(Offsets::External::TaskScheduler::FakeDMPointer);
    uintptr_t DM = *reinterpret_cast<uintptr_t*>(FakeDM + Offsets::External::TaskScheduler::FakeDMtoDM);

    return DM;
}

uintptr_t Scheduler::ScriptContext(uintptr_t DataModel)
{
    uintptr_t Children = *reinterpret_cast<uintptr_t*>(DataModel + Offsets::External::DataModel::Children);
    uintptr_t SC = *reinterpret_cast<uintptr_t*>(*reinterpret_cast<uintptr_t*>(Children) + Offsets::External::TaskScheduler::ScriptContext);
    
    return SC;
}

lua_State* Scheduler::LuaState(uintptr_t ScriptContext)
{
    *reinterpret_cast<BOOLEAN*>(ScriptContext + 0x870) = TRUE;

    auto Addy = ScriptContext + 0x210;
    auto Encrypted = reinterpret_cast<uint32_t*>(Addy);

    uint32_t Low = Encrypted[0] ^ static_cast<uint32_t>(Addy);
    uint32_t High = Encrypted[1] ^ static_cast<uint32_t>(Addy);
    return reinterpret_cast<lua_State*>((static_cast<uint64_t>(High) << 32) | Low);
}

bool Scheduler::IsValidPointer(void* ptr, size_t size) {
    if (!ptr) return false;

    MEMORY_BASIC_INFORMATION mbi;
    if (VirtualQuery(ptr, &mbi, sizeof(mbi)) == 0)
        return false;

    uintptr_t start = reinterpret_cast<uintptr_t>(ptr);
    uintptr_t end = start + size;
    uintptr_t regionStart = reinterpret_cast<uintptr_t>(mbi.BaseAddress);
    uintptr_t regionEnd = regionStart + mbi.RegionSize;

    return (start >= regionStart && end <= regionEnd) &&
        (mbi.State == MEM_COMMIT) &&
        ((mbi.Protect & (PAGE_READONLY | PAGE_READWRITE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE)) != 0);
}

__int64 Scheduler::GetPlaceID() {
    __int64 DataModel = Scheduler::DataModel();
    if (!DataModel)
        return 0;

    auto PlaceIdPtr = reinterpret_cast<__int64*>(DataModel + Offsets::External::TaskScheduler::PlaceId);
    if (!PlaceIdPtr)
        return 0;

    return *PlaceIdPtr;
}

bool Scheduler::GameIsLoaded(uintptr_t DataModel) {
    uintptr_t DM = Scheduler::DataModel();
    if (!DM)
        return false;

    return *reinterpret_cast<int*>(DM + Offsets::External::DataModel::GameLoaded) == 31;
}

