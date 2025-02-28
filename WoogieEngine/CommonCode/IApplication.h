#pragma once


class IGraphicDevice : public IUnknown
{
public:

};


class IApplication : public IUnknown
{
public:
	virtual void InitializeMainWindow(const wchar_t* className, const wchar_t* windowText) = 0;

	virtual void WinPumpmessage() = 0;

	virtual bool ApplicationQuit() = 0;
};