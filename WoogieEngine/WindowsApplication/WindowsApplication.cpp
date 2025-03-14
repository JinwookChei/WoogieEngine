#include "stdafx.h"
#include "WindowsApplication.h"

WindowsApplication* GApplication = nullptr;


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // All painting occurs here, between BeginPaint and EndPaint.

        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


WindowsApplication::WindowsApplication(
    HINSTANCE hInstance, 
    PWSTR pCmdLine, 
    int nCmdShow)
    : hInstance_(hInstance),
    pCmdLine_(pCmdLine),
    nCmdShow_(nCmdShow),
    iCon_(nullptr),
    mainWindow_(nullptr),
    refCount_(1),
    isApplicationQuit_(false)
{
    GApplication = this;
}

WindowsApplication::~WindowsApplication()
{
    if (nullptr != mainWindow_)
    {
        delete mainWindow_;
        mainWindow_ = nullptr;
    }
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

void __stdcall WindowsApplication::InitializeMainWindow(const wchar_t* className, const wchar_t* windowText)
{
    // NEW -> WindowsApplication Destructor Delete
    mainWindow_ = new Window(className, windowText);

    Path iConPath(L"..//Resource//Logo//LogoResize.ico");
    if (false == iConPath.IsFile())
    {
        __debugbreak();
    }
    
    iCon_ = (HICON)LoadImage(NULL, iConPath.GetPathWString().c_str(), IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED);
    if (nullptr == iCon_)
    {
        __debugbreak();
    }

    WNDCLASS wc = {};
    //wc.style = 0;                               // Window 그리기 특성.
    wc.lpfnWndProc = WindowProc;                // 메세지 함수 지정.
    //wc.cbClsExtra = 0;                          // 추가 메모리 사용 안함.
    //wc.cbWndExtra = 0;                          // 추가 메모리 사용 안함.
    wc.hInstance = hInstance_;                  // 인스턴스 핸들.
    wc.hIcon = iCon_;                               // 아이콘 설정.
    //wc.hCursor = 0;                             // 커서 설정.
    //wc.hbrBackground;                           // 백그라운드 설정.
    //wc.lpszMenuName = NULL;                     // 메뉴 사용 설정.
    wc.lpszClassName = className;               // 윈도우 클래스 이름(식별)

    RegisterClass(&wc);


    if (false == mainWindow_->Initialize())
    {
        __debugbreak();
    }
    
    mainWindow_->Show();

}

void __stdcall WindowsApplication::WinPumpmessage()
{

    MSG message = {};
    while (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
        TranslateMessage(&message);
        DispatchMessage(&message);

        if (message.message == WM_DESTROY) {
            if (isApplicationQuit_) {
                break;
            }
        }
        if (message.message == WM_QUIT) {
            isApplicationQuit_ = true;
        }
    }
}

bool __stdcall WindowsApplication::ApplicationQuit()
{
	return isApplicationQuit_;
}

const HINSTANCE WindowsApplication::GetInstanceHandle() const
{
    return hInstance_;
}

const PWSTR WindowsApplication::GetCmdLinePointer() const
{
    return pCmdLine_;
}

const int WindowsApplication::GetCmdShowParam() const
{
    return nCmdShow_;
}
