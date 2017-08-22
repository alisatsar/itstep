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
		HWND_DESKTOP,//родитель рабочий стол тоже самое что и NULL
		NULL,//будет меню или нет
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
		TranslateMessage(&msg);//нужно так как будет приниматься сообщение от клавиатуры, для перевода значения 
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	int x;
	int y;
	static int time = 1000;

	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;


	static int desktopWidth;
	static int desktopHeigth;

	switch (uMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, MYTIMER, 10000000, NULL);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &rect);
		SetTextColor(hdc, RGB(50, 50, 150));
		SetBkMode(hdc, TRANSPARENT);
		DrawText(hdc, L"Hello, Step\nBye, Step", -1, &rect, DT_VCENTER);
		EndPaint(hWnd, &ps);
		RedrawWindow(hWnd, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_UPDATENOW);
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case MYTIMER:
			if (MessageBox(hWnd, _TEXT("Вы действительно хотите завершить работу приложения?"), _TEXT("Информация"), MB_YESNO) == IDYES)
			{
				DestroyWindow(hWnd);
			}
			break;
		case MYTIMER2:
			MoveWindow(hWnd, x, y, width, height, true);
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
			SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);
			desktopWidth = rect.right;
			desktopHeigth = rect.bottom;

			x = LOWORD(lParam);
			y = HIWORD(lParam);
			SetTimer(hWnd, MYTIMER2, time, NULL);
			/*do
			{
				x += 10;
				
				//time += 1000;
			} while (x <= desktopWidth - width);*/
			break;
		}
		break;

	

	case WM_CLOSE://когда нажимаю закрыть окно
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
