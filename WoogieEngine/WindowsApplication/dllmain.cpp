// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) bool __stdcall CreateWindowsApplication(
    void** newApplication, 
    HINSTANCE hInstance, 
    PWSTR pCmdLine, 
    int nCmdShow)
{
    //NEW
    IApplication* newApp = new WindowsApplication(hInstance, pCmdLine, nCmdShow);

    if (nullptr == newApp)
    {
        return false;
    }

    *newApplication = newApp;

    return true;
}