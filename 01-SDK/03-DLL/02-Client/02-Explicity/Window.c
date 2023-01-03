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

LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg,WPARAM wParam,LPARAM lParam)
{
    //variables 
    HMODULE hDLL = NULL;
    typedef int (*MakeCubeFunctionPointer)(int);
    MakeCubeFunctionPointer pfnMakeCube = NULL;
    int iNum = 5;
    int iCube;
    TCHAR str[255];

    switch (iMsg)
    {
    case WM_CREATE:
        hDLL = LoadLibrary(TEXT("MyMathTwo.dll"));
        if (hDLL == NULL) {
            MessageBox(hwnd, TEXT("LoadLibrary() failed"), TEXT("ERROR"), MB_OK);
            DestroyWindow(hwnd);
        }
        pfnMakeCube = (MakeCubeFunctionPointer)(GetProcAddress(hDLL, "MakeCube"));
        if (pfnMakeCube == NULL) {
            MessageBox(hwnd, TEXT("GetProcAddress() failed"), TEXT("ERROR"), MB_OK);
            FreeLibrary(hDLL);
            DestroyWindow(hwnd);
        }
        iCube = pfnMakeCube(iNum);
        wsprintf(str, TEXT("Cube of %d is %d"), iNum, iCube);
        MessageBox(hwnd, str, TEXT("Cube"), MB_OK);
        FreeLibrary(hDLL);
        hDLL = NULL;
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;   
    default:
        break;
    }

    return(DefWindowProc(hwnd,iMsg,wParam,lParam));
}



//cl.exe /c /EHsc Window.cpp
//rc.exe Window.rc
//link.exe Window.obj Window.res User32.lib GDI32.lib /SUBSYSTEM:WINDOWS
