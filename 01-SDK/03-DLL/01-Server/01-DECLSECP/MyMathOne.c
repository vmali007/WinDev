#include<windows.h>

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
	//code
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	default:
		break;
	}
	return (TRUE);
}

__declspec(dllexport) int MakeSquare(int num) {
	//code
	return (num * num);
}

//link.exe MyMathOne.obj /DLL User32.lib /SUBSYSTEM:WINDOWS

