#pragma once


class IApplication : public IUnknown
{
	virtual void InitializeWindow() = 0;

	virtual void WinPumpmessage() = 0;

	virtual bool ApplicationQuit() = 0;
};