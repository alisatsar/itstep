#include <Windows.h>
#include <WinUser.h>

#define MYTIMER 668


LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM Param)
{
	switch (Msg)
	{
	case WM_CREATE:
		SetTimer(hWnd, MYTIMER, 1100, NULL);
		break;
	case WM_DESTROY:
		KillTimer(hWnd, MYTIMER);
		PostQuitMessage(0);
		break;
	case WM_TIMER:
		SetClassLong(hWnd, GCL_STYLE, (LONG)L"My 85 Window");
		InvalidateRect(hWnd, NULL, true);
		break;
	default:
		return DefWindowProc(hWnd, Msg, wParam, Param);
	}

	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpCmdLine, int mCmdShow)
{
	WNDCLASSEX wmdclass;
	memset(&wmdclass, 0, sizeof(wmdclass));

	LPWSTR szClassName = L"MyWindowClass";
	LPWSTR szTitleName = L"My first Window";
	
	wmdclass.cbSize = sizeof(wmdclass);
	wmdclass.lpszClassName = szClassName;
	wmdclass.style = CS_HREDRAW | CS_VREDRAW;

	wmdclass.lpfnWndProc = WndProc;
	wmdclass.hInstance = hInstance;

	wmdclass.hCursor = LoadCursor(NULL, IDC_WAIT);
	wmdclass.hIcon = LoadIcon(NULL, IDI_HAND);
	wmdclass.hbrBackground = CreateSolidBrush(RGB(250, 150, 0));

	if (!RegisterClassEx(&wmdclass))
	{
		return -1;
	}

	HWND hWnd = CreateWindowEx(WS_EX_TOPMOST, szClassName, szTitleName,
		WS_OVERLAPPEDWINDOW | WS_VSCROLL, 0, 0, 250, 250, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return -1;
	}
		
	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);

	SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(250, 0, 0)));

	HWND hWnd3 = CreateWindowEx(WS_EX_TOPMOST, szClassName, L"Tried Window",
		WS_OVERLAPPEDWINDOW | WS_VSCROLL, 500, 0, 250, 250, NULL, NULL, hInstance, NULL);

	SetClassLong(hWnd3, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(56, 0, 100)));
	ShowWindow(hWnd3, 1);
	UpdateWindow(hWnd3);

	HWND hWnd4 = CreateWindowEx(WS_EX_TOPMOST, szClassName, L"Fourth Window",
		WS_OVERLAPPEDWINDOW | WS_VSCROLL, 750, 0, 250, 250, NULL, NULL, hInstance, NULL);

	SetClassLong(hWnd4, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(0, 0, 0)));
	ShowWindow(hWnd4, 1);
	UpdateWindow(hWnd4);

	//MessageBoxW(hWnd, L"Hello, Step", L"MessageBox", MB_OK);


	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) //цикл обработки сообщений
	{
		//TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;

	
}
