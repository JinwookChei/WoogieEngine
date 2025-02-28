#include "stdafx.h"

typedef bool (*DLL_CREATE_APPLICATION)(void**, HINSTANCE, PWSTR, int);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif  // _DEBUG


	HMODULE loadApplicationLibrary = LoadLibrary(APPLICATION_NAME);
	const wchar_t* MainWindowClassName = L"MAIN";
	const wchar_t* MainWindowText = L"WOOGIE ENGINE";

	if (nullptr == loadApplicationLibrary)
	{
		__debugbreak();
		return 0;
	}

	DLL_CREATE_APPLICATION fpCreateApplication = (DLL_CREATE_APPLICATION)GetProcAddress(loadApplicationLibrary, "CreateWindowsApplication");

	IApplication* windowApplication = nullptr;
	if (false == fpCreateApplication((void**)&windowApplication, hInstance, pCmdLine, nCmdShow))
	{
		__debugbreak();
		return 0;
	}

	windowApplication->InitializeMainWindow(MainWindowClassName, MainWindowText);

	while(!windowApplication->ApplicationQuit())
	{
		windowApplication->WinPumpmessage();
	}
	
	windowApplication->Release();
	windowApplication = nullptr;

	if (FALSE == FreeLibrary(loadApplicationLibrary))
	{
		__debugbreak();
	}



#ifdef _DEBUG
	_ASSERT(_CrtCheckMemory());
#endif  // _DEBUG
	return 0;
}

