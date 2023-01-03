//header files
#include<windows.h>

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
    wndclass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);
    wndclass.lpszClassName = szAppName;
    wndclass.lpszMenuName = NULL;
    wndclass.hIconSm = LoadIcon(NULL,IDI_APPLICATION); 

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
    //local variable declarations
    TCHAR str[255];
    int Num1,Num2,Num3;

    //code
    switch (iMsg)
    {
    case WM_CREATE:
        Num1 = 25;
        Num2 = 75;
        Num3 = Num1 + Num2;
        wsprintf(str, TEXT("Sum of %d and %d is %d"),Num1,Num2,Num3);
        MessageBox(hwnd, str, TEXT("Message"), MB_OK);
        break;
    case WM_KEYDOWN:
        wsprintf(str, TEXT("WM_KEYDOWN message is received"));
        MessageBox(hwnd, str, TEXT("Message"), MB_OK);
        break;
    case WM_LBUTTONDOWN:
        wsprintf(str, TEXT("WM_LBUTTONDOWN message is received"));
        MessageBox(hwnd, str, TEXT("Message"), MB_OK);
        break;
    case WM_RBUTTONDOWN:
        wsprintf(str, TEXT("WM_RBUTTONDOWN message is received"));
        MessageBox(hwnd, str, TEXT("Message"), MB_OK);
        break;
    case WM_DESTROY:
        wsprintf(str, TEXT("WM_DESTROY message is received"));
        MessageBox(hwnd, str, TEXT("Message"), MB_OK);
        PostQuitMessage(0);
        break;   
    default:
        break;
    }

    return(DefWindowProc(hwnd,iMsg,wParam,lParam));
}



//cl.exe /c /EHsc Window.cpp
//cl.exe /c /EHsc D "UNICODE" Window.cpp
//link.exe Window.obj User32.lib GDI32.lib /SUBSYSTEM:WINDOWS
