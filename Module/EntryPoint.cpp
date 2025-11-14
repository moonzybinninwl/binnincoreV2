#include <Windows.h>
#include <thread>
#include <Workspace/Scheduler/Scheduler.hpp>
#include <Workspace/Engine/Engine.hpp>
#include <Workspace/Execution/Execution.hpp>
#include <Workspace/Environment/Environment.hpp>
#include <Exploit/Service/Service.hpp>

/*
I've already added the webview2 files so that you can use the WebView2Loader method to inject.
You need a cert which I have not provided here.

This is supposed to be a lightweight module that you can use as a foundation to build your exploit.
Some of the environment is already implemented such as the Closures and Script.

Also uh, set the build to release if you're new to this

===================STRUCTURE===========================
In workspace you'll find > Engine, Environment, Execution and Scheduler.
- Execution > Contains the execution logic and yielder
- Environment > Contains all the functions that scripts use. In the 'nodes' folder - you'll find all the libraries
- Engine > Contains everything you need to change when Roblox updates. It has your offsets and encryptions - if you don't update these, you'll crash on Inject
- Scheduler > Contains different things like executing, Getting the datamodel, scriptcontext and more

In Exploit you'll find > Bytecode, Service and Utilities
- Bytecode > Contains bytecode utilities like Reading and Decompressing bytecode - as well as compiling scripts
- Service > Contains the Teleport handler, what it does is Reinitialize and load all libraries when a new datamodel is found - aka joining a new experience
- Utilities > They're basically just variables shared around the code. Instead of redfining everything, why not just access it from one file? Just makes everything easier and cleaner imo

======================================================
That's all for now - also if you're going to say this is chatgpt, please shut the fuck up. It's a fucking guide

If you have any issues, please contact me on Discord - @binninwl_
Thanks for reading this.
*/

void MainThread()
{
	Service::Initialize();
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID reserved)
{
	if (reason == 1)
	{
		std::thread(MainThread).detach();
	}
	
	return 1;
}
