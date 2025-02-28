#pragma once


// CRTDBG
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  // _DEBUG
#ifdef _DEBUG


// UTILITY DLL
#ifdef _WIN64
#pragma comment(lib, "Utility_x64_Debug")
#else
#pragma comment(lib, "Utility_x86_Debug")
#endif // _WIN64

#else
#ifdef _WIN64
#pragma comment(lib, "Utility_x64_Release")
#else
#pragma comment(lib, "Utility_x86_Release")
#endif // _WIN64

#endif // _DEBUG


#define UTILITY_API __declspec(dllimport)


// MODULES
#include <Windows.h>
#include "CommonCode/IApplication.h"

#include "filesystem"
#include "Utility/Path.h"

#include "Win32Image.h"
#include "Win32GraphicDevice.h"
#include "Window.h"
#include "WindowsApplication.h"


extern WindowsApplication* GApplication;