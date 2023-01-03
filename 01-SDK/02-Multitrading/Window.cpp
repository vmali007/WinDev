//header files
#include<windows.h>
#include "Window.h"

//global functions declarations
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

//global variable declarations

//Entry point function
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszCmdLine,int iCmdShow)
{
    //local variable declarations
    WNDCLASSEX wndclass;
    HWND hwnd;
    MSG msg;
    TCHAR szAppName[]=TEXT("WINDEV");

    //code
    //wnd class
    wndclass.cbSize = sizeof(WNDCLASSEX);
    wndclass.style = CS_HREDRAW|CS_VREDRAW;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.lpfnWndProc = WndProc;
    wndclass.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH);
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(MYICON));
    wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);
    wndclass.lpszClassName = szAppName;
    wndclass.lpszMenuName = NULL;
    wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

    //registraton of WNDCLASS
    RegisterClassEx (&wndclass);

    //creating the window
    hwnd = CreateWindow(szAppName,TEXT("VDM:Window"),WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);

    //SHOW THE WINDOW
    ShowWindow (hwnd,iCmdShow);

    //Update Wondow
    UpdateWindow(hwnd);

    //massage loop
    while(GetMessage(&msg,NULL,0,0))
    {
        //translate masage
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return((int) msg.wParam);
}

DWORD WINAPI ThreadProcOne(LPVOID);
DWORD WINAPI ThreadProcTwo(LPVOID);

LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg,WPARAM wParam,LPARAM lParam)
{
    //local variables  
    HANDLE hThread1 = NULL;
    HANDLE hThread2 = NULL;
    
    switch (iMsg)
    {
    case WM_CREATE:
        hThread1 = CreateThread(
            NULL,
            0,
            LPTHREAD_START_ROUTINE(ThreadProcOne),
            LPVOID(hwnd),
            0,
            NULL
        );
        hThread2 = CreateThread(
            NULL,
            0,
            LPTHREAD_START_ROUTINE(ThreadProcTwo),
            LPVOID(hwnd),
            0,
            NULL
        );

        break;
    case WM_LBUTTONDOWN:
        MessageBox(hwnd, TEXT("This is my message box"), TEXT("Message"), MB_OK);
        break;
    case WM_DESTROY:
        //PostQuitMessage(0);
        PostMessage(hwnd,WM_QUIT,0,0L);
        break;   
    default:
        break;
    }

    return(DefWindowProc(hwnd,iMsg,wParam,lParam));
}

DWORD WINAPI ThreadProcOne(LPVOID param) {
    //variables declaration
    HDC hdc;
    TCHAR str[255];
    long i;

    //code
    hdc = GetDC(HWND(param));
    SetBkColor(hdc, RGB(0, 0, 0));
    SetTextColor(hdc, RGB(255, 255, 0));

    for (i = 0; i < LONG_MAX; i++) {
        wsprintf(str, TEXT("Numbers in increamenting order : %d"), i);
        TextOut(hdc, 5, 5, str, wcslen(str));
    }
    ReleaseDC(HWND(param), hdc);

    return 0;
}

DWORD WINAPI ThreadProcTwo(LPVOID param) {
    //variables declaration
    HDC hdc;
    TCHAR str[255];
    long i;

    //code
    hdc = GetDC(HWND(param));
    SetBkColor(hdc, RGB(0, 0, 0));
    SetTextColor(hdc, RGB(0, 255, 255));

    for (i = LONG_MAX; i >= 0 ; i--) {
        wsprintf(str, TEXT("Numbers in decreamenting order : %d"), i);
        TextOut(hdc, 5, 20, str, wcslen(str));
    }
    ReleaseDC(HWND(param), hdc);

    return 0;
}


//cl.exe /c /EHsc Window.cpp
//cl.exe /c /EHsc /D UNICODE Window.cpp 
//rc.exe Window.rc
//link.exe Window.obj Window.res User32.lib GDI32.lib /SUBSYSTEM:WINDOWS
//link.exe Window.obj Window.res User32.lib GDI32.lib KERNEL32.lib /SUBSYSTEM:WINDOWS

