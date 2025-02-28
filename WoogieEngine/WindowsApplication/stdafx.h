#pragma once

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif  // _DEBUG


#include <Windows.h>
#include "CommonCode/IApplication.h"

#include "Win32Image.h"
#include "Win32GraphicDevice.h"
#include "Window.h"
#include "WindowsApplication.h"


extern WindowsApplication* GApplication;