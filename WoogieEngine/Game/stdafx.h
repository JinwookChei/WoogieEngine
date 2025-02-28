#pragma once


#ifndef UNICODE
#define UNICODE
#endif 


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

