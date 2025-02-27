#include "stdafx.h"
#include "WindowsApplication.h"

WindowsApplication::WindowsApplication()
	: mainWindow_(nullptr),
	refCount_(1),
	isApplicationQuit_(false)
{
}

WindowsApplication::~WindowsApplication()
{
}

HRESULT __stdcall WindowsApplication::QueryInterface(REFIID riid, void** ppvObject)
{
	return E_NOTIMPL;
}

ULONG __stdcall WindowsApplication::AddRef(void)
{
	++refCount_;
	return refCount_;
}

ULONG __stdcall WindowsApplication::Release(void)
{
	--refCount_;
	ULONG tempRefCount = refCount_;
	if (0 == refCount_)
	{
		delete this;
	}
	return tempRefCount;
}

void __stdcall WindowsApplication::InitializeWindow()
{
}

void __stdcall WindowsApplication::WinPumpmessage()
{
}

bool __stdcall WindowsApplication::ApplicationQuit()
{
	return false;
}
