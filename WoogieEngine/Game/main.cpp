#include "stdafx.h"



typedef bool (*DLL_CREATE_APPLICATION)(void**, HINSTANCE, PWSTR, int);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{

	HMODULE loadApplication = LoadLibrary(APPLICATION_NAME);
	const wchar_t* MainWindowClassName = L"MAIN";
	const wchar_t* MainWindowText = L"WOOGIE ENGINE";

	if (nullptr == loadApplication)
	{
		__debugbreak();
		return 0;
	}

	DLL_CREATE_APPLICATION fpCreateApplication = (DLL_CREATE_APPLICATION)GetProcAddress(loadApplication, "CreateWindowsApplication");

	IApplication* windowApplication = nullptr;
	if (false == fpCreateApplication((void**)&windowApplication, hInstance, pCmdLine, nCmdShow))
	{
		__debugbreak();
		return 0;
	}

	windowApplication->InitializeMainWindow(L"MAIN", L"WOOGIE ENGINE");

	while(1)
	{
		windowApplication->WinPumpmessage();
	}
	

	return 0;
}

