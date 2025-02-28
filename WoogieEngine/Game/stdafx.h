#pragma once


#ifndef UNICODE
#define UNICODE
#endif 


#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  // _DEBUG


#ifdef _DEBUG
#ifdef _WIN64
#define APPLICATION_NAME L"WindowsApplication_x64_Debug"
#else
#define APPLICATION_NAME L"WindowsApplication_x86_Debug"
#endif // 
#else
#ifdef _WIN64
#define APPLICATION_NAME L"WindowsApplication_x64_Release"
#else
#define APPLICATION_NAME L"WindowsApplication_x86_Release"
#endif

#endif // _DEBUG



#include <windows.h>
#include "CommonCode/IApplication.h"

