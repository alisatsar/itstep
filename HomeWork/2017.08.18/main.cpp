#include <Windows.h>
#include <WinUser.h>
#include <tchar.h>
#include "resource.h"
#include <cstdlib>
#include <ctime>


int const width = 300;
int const height = 100;

#define MYTIMER 141
#define MYTIMER2 142
#define MYTIMER3 143

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpCmdLine, int mCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wnd;
	memset(&wnd, 0, sizeof(wnd));

	LPWSTR szClassName = _TEXT("Window");
	LPWSTR szTitleName = L"My Window";
	wnd.style = CS_DBLCLKS;

	wnd.cbSize = sizeof(wnd);
	wnd.lpfnWndProc = WndProc;
	wnd.hInstance = hInstance;
	wnd.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wnd.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
	wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wnd.lpszMenuName = NULL;
	wnd.lpszClassName = szClassName;
	wnd.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	if (!RegisterClassEx(&wnd))
	{
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error1"), MB_OK | MB_ICONERROR);
		return 0;
	}

	hWnd = CreateWindowEx(WS_EX_WINDOWEDGE, szClassName, szTitleName, WS_OVERLAPPEDWINDOW ^ (WS_MAXIMIZEBOX | WS_MINIMIZEBOX),
		CW_USEDEFAULT, CW_USEDEFAULT, width, height,
		HWND_DESKTOP,
		NULL,
		hInstance, NULL);

	if (!hWnd) {
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error2"), MB_OK | MB_ICONERROR);
		return 0;
	}

	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	static int x;
	static int y;
	static int time = 1000;

	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	static int desktopWidth;
	static int desktopHeigth;

	static std::time_t current;
	static tm* _tm;

	char timeNow[9];
	memset(timeNow, 0, 9);
	char hour[3];
	char minute[3];
	char second[3];
	int len;
	wchar_t* strUnicode;

	switch (uMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, MYTIMER, 10000000, NULL);
		break;

	case WM_PAINT:
		current = std::time(nullptr);
		_tm = localtime(&current);
		 
		itoa(_tm->tm_hour, hour, 10);
		strcat(timeNow, hour);
		strcat(timeNow, ":");

		itoa(_tm->tm_min, minute, 10);
		strcat(timeNow, minute);
		strcat(timeNow, ":");

		itoa(_tm->tm_sec, second, 10);
		strcat(timeNow, second);

		len = mbstowcs(NULL, timeNow, 0) + 1;
		strUnicode = new wchar_t[len];
		mbstowcs(strUnicode, timeNow, len);

		hdc = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &rect);
		SetTextColor(hdc, RGB(50, 50, 150));
		SetBkMode(hdc, TRANSPARENT);
		DrawText(hdc, strUnicode, -1, &rect, DT_VCENTER);
		SetTimer(hWnd, MYTIMER3, 1000, NULL);
		EndPaint(hWnd, &ps);
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case MYTIMER:
			if (MessageBox(hWnd, _TEXT("Вы действительно хотите завершить работу приложения?"), _TEXT("Информация"), MB_YESNO) == IDYES)
			{
				DestroyWindow(hWnd);
			}
			else
			{
				KillTimer(hWnd, MYTIMER);
			}
			break;
		case MYTIMER2:
			hdc = GetDC(hWnd);
			GetWindowRect(hWnd, &rect);
			do 
			{
				MoveWindow(hWnd, rect.left + 150, 0, width, height, true);
			} while (rect.left <= desktopWidth - width);
			break;

		case MYTIMER3:
			RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE);
			break;
		}
		break;

	case WM_LBUTTONDBLCLK:
		SetClassLong(hWnd, GCL_HCURSOR, (LONG)LoadCursor(NULL, IDC_ARROW));
		break;

	case WM_LBUTTONDOWN:
		SetClassLong(hWnd, GCL_HCURSOR, (LONG)LoadCursor(GetModuleHandle(NULL), MAKEINTRESOURCE(IDC_CURSOR1)));
		break;

	case WM_RBUTTONDBLCLK:
		SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(255, 255, 255)));
		InvalidateRect(hWnd, NULL, true);
		break;

	case WM_RBUTTONDOWN:
		std::srand(unsigned(std::time(0)));
		SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(std::rand() % 255, std::rand() % 255, std::rand() % 255)));
		InvalidateRect(hWnd, NULL, true);
		break;

	case WM_SYSKEYDOWN:
		switch (wParam)
		{
		case VK_DOWN:
			ShowWindow(hWnd, SW_SHOWMINIMIZED);
			break;
		case VK_UP:
			ShowWindow(hWnd, SW_SHOWMAXIMIZED);
			break;
		case VK_LEFT:
			ShowWindow(hWnd, SW_SHOWNORMAL);
			break;
		case VK_RIGHT:
			ShowWindow(hWnd, SW_SHOWNORMAL);
			break;
		case VK_F4:
			if (MessageBox(hWnd, _TEXT("Вы действительно хотите завершить работу приложения?"), _TEXT("Информация"), MB_YESNO) == IDYES)
			{
				DestroyWindow(hWnd);
			}
			break;
		}
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RETURN:
			SetTimer(hWnd, MYTIMER2, time, NULL);
			MoveWindow(hWnd, 0, 0, width, height, true);
			break;
		case VK_ESCAPE:
			KillTimer(hWnd, MYTIMER2);
		}
		break;

	case WM_CLOSE:
		if (MessageBox(hWnd, _TEXT("Вы действительно хотите завершить работу приложения?"), _TEXT("Информация"), MB_YESNO) == IDYES)
		{
			DestroyWindow(hWnd);
		}
		break;

	case WM_DESTROY:
		KillTimer(hWnd, MYTIMER);
		KillTimer(hWnd, MYTIMER2);
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}
