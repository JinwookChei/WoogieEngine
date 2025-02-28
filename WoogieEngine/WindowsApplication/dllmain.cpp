#include "stdafx.h"

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
#ifdef _DEBUG
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif  // _DEBUG
		break;
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
	{
#ifdef _DEBUG
		_ASSERT(_CrtCheckMemory());
#endif  // _DEBUG
		break;
	}
	}
	return TRUE;
}

extern "C" __declspec(dllexport) bool __stdcall CreateWindowsApplication(
	void** newApplication,
	HINSTANCE hInstance,
	PWSTR pCmdLine,
	int nCmdShow)
{
	//NEW -> Realse In GameMain.cpp
	IApplication* newApp = new WindowsApplication(hInstance, pCmdLine, nCmdShow);

	if (nullptr == newApp)
	{
		return false;
	}

	*newApplication = newApp;

	return true;
}