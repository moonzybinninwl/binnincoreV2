#pragma once

#include <Windows.h>
#include <iostream>
#include <vector>
#include <Workspace/Engine/LuaVM.hpp>
#include <Workspace/Engine/Encryptions.hpp>
static uintptr_t Roblox_BASE = (uintptr_t)GetModuleHandleA(0);
#define REBASE(x) (x + Roblox_BASE)

struct SignalT;
struct lua_State;
struct Proto;
namespace Offsets {
    namespace Lua {
        const uintptr_t OpcodeLookupTable = REBASE(0x57a6ac0);
    }
    const uintptr_t Print = REBASE(0x190FDE0);
    const uintptr_t Luau_Execute = REBASE(0x37A4540);
    const uintptr_t LuaD_throw = REBASE(0x379CCF0);
    const uintptr_t LuaO_NilObject = REBASE(0x5303228);
    const uintptr_t LuaH_DummyNode = REBASE(0x5302C48);

    namespace External {
        namespace Bytecode {
            const uintptr_t LocalScript = 0x1A8;
            const uintptr_t ModuleScript = 0x150;
        }

        namespace DataModel {
            const uintptr_t GameLoaded = 0x5F0;
            constexpr uintptr_t Children = 0x60;
        }


        namespace TaskScheduler {
            const uintptr_t Identity = 0x30;
            const uintptr_t Capabilities = 0x48;

            constexpr uintptr_t FakeDMtoDM = 0x1C0;
            const uintptr_t FakeDMPointer = REBASE(0x74287C8);

            const uintptr_t ScriptContext = 0x3D0;
            constexpr uintptr_t PlaceId = 0x198;
        }
    }
}

namespace Roblox {
    inline auto Print = (uintptr_t(__fastcall*)(int, const char*, ...))Offsets::Print;
    inline auto Luau_Execute = (void(__fastcall*)(lua_State*))Offsets::Luau_Execute;
    inline auto LuaD_Throw = (void(__fastcall*)(lua_State*, int))Offsets::LuaD_throw;
}
