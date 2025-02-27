#pragma once


class WindowsApplication : public IApplication
{
public:
	WindowsApplication();

	~WindowsApplication();

	HRESULT __stdcall QueryInterface(REFIID riid, _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) override;

	ULONG __stdcall AddRef(void) override;

	ULONG __stdcall Release(void) override;

	virtual void __stdcall InitializeWindow() override;

	virtual void __stdcall WinPumpmessage() override;

	virtual bool __stdcall ApplicationQuit() override;


private:
	Window* mainWindow_;

	ULONG refCount_;

	bool isApplicationQuit_;
};