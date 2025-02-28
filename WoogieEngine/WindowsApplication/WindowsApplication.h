#pragma once


class WindowsApplication : public IApplication
{
public:
	WindowsApplication() = delete;
	WindowsApplication(HINSTANCE hInstance, PWSTR pCmdLine, int nCmdShow);

	~WindowsApplication();

	HRESULT __stdcall QueryInterface(REFIID riid, _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) override;

	ULONG __stdcall AddRef(void) override;

	ULONG __stdcall Release(void) override;

	virtual void __stdcall InitializeMainWindow(const wchar_t* className, const wchar_t* windowText) override;

	virtual void __stdcall WinPumpmessage() override;

	virtual bool __stdcall ApplicationQuit() override;

	const HINSTANCE GetInstanceHandle() const;

	const PWSTR GetCmdLinePointer() const;

	const int GetCmdShowParam() const;
private:
	HINSTANCE hInstance_;

	PWSTR pCmdLine_;

	int nCmdShow_;

	HICON iCon_;

	Window* mainWindow_;

	ULONG refCount_;

	bool isApplicationQuit_;
};