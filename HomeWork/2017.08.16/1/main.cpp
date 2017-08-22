/*Создайте приложение, в котором будут отображаться четыре окна.
Все окна должны иметь разные заголовки и разный цвет фона.
Измените приложение таким образом, чтобы каждое окно,
кроме первого, появлялось по таймеру.*/

#include <Windows.h>
#include <WinUser.h>

#define MYTIMER 101
#define MYTIMER2 102
#define MYTIMER3 103

HWND hWnd;
HWND hWnd2;
HWND hWnd3;
HWND hWnd4;

LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM Param);

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
	wmdclass.hbrBackground = CreateSolidBrush(RGB(255, 0, 0));

	if (!RegisterClassEx(&wmdclass))
	{
		return -1;
	}

	hWnd = CreateWindowEx(WS_EX_TOPMOST, szClassName, szTitleName,
		WS_OVERLAPPEDWINDOW | WS_VSCROLL, 0, 0, 250, 250, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return -1;
	}

	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);


	hWnd2 = CreateWindowEx(WS_EX_TOPMOST, szClassName, L"My second Window",
		WS_OVERLAPPEDWINDOW | WS_VSCROLL, 250, 0, 250, 250, NULL, NULL, hInstance, NULL);

	if (!hWnd2)
	{
		return -1;
	}

	hWnd3 = CreateWindowEx(WS_EX_TOPMOST, szClassName, L"My third Window",
		WS_OVERLAPPEDWINDOW | WS_VSCROLL, 500, 0, 250, 250, NULL, NULL, hInstance, NULL);

	if (!hWnd3)
	{
		return -1;
	}

	hWnd4 = CreateWindowEx(WS_EX_TOPMOST, szClassName, L"My fourth Window",
		WS_OVERLAPPEDWINDOW | WS_VSCROLL, 750, 0, 250, 250, NULL, NULL, hInstance, NULL);

	if (!hWnd4)
	{
		return -1;
	}

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM Param)
{
	switch (Msg)
	{
	case WM_CREATE:
		SetTimer(hWnd, MYTIMER, 1000, NULL);
		SetTimer(hWnd, MYTIMER2, 2000, NULL);
		SetTimer(hWnd, MYTIMER3, 3000, NULL);
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case MYTIMER:
			SetClassLong(hWnd2, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(255, 0, 102)));
			ShowWindow(hWnd2, 1);
			UpdateWindow(hWnd2);
			InvalidateRect(hWnd2, NULL, true);
			break;
		case MYTIMER2:
			SetClassLong(hWnd3, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(255, 0, 239)));
			ShowWindow(hWnd3, 1);
			UpdateWindow(hWnd3);
			InvalidateRect(hWnd3, NULL, true);
			break;
		case MYTIMER3:
			SetClassLong(hWnd4, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(119, 0, 255)));
			ShowWindow(hWnd4, 1);
			UpdateWindow(hWnd4);
			InvalidateRect(hWnd4, NULL, true);
			break;
		}
		break;

	case WM_CLOSE:
		if (MessageBox(hWnd, (L"Вы действительно хотите завершить работу приложения?"), (L"Информация"), MB_YESNO) == IDYES)
		{
			DestroyWindow(hWnd);
			DestroyWindow(hWnd2);
			DestroyWindow(hWnd3);
			DestroyWindow(hWnd4);
		}
		break;

	case WM_DESTROY:
		KillTimer(hWnd2, MYTIMER);
		KillTimer(hWnd3, MYTIMER2);
		KillTimer(hWnd4, MYTIMER3);
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, Msg, wParam, Param);
	}

	return 0;
}
