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

If you have any issues, please contact me on Discord - @binninwl_
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