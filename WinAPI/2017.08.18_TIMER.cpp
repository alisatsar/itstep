#include <Windows.h>
#include <WinUser.h>
#include <tchar.h>
#include "resource.h"
#include <cstdlib>
#include <ctime>

#define MYTIMER 668

int const width = 300;
int const height = 100;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpCmdLine, int mCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wnd;
	memset(&wnd, 0, sizeof(wnd));

	LPWSTR szClassName = _TEXT("Window");
	//LPWSTR szTitleName = L"My Window";
	wnd.style = CS_HREDRAW | CS_VREDRAW;

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

	hWnd = CreateWindowEx(WS_EX_WINDOWEDGE, szClassName, _TEXT("Hello"), WS_OVERLAPPEDWINDOW ^ (WS_MAXIMIZEBOX | WS_MINIMIZEBOX),
		CW_USEDEFAULT, CW_USEDEFAULT, width, height,
		HWND_DESKTOP,//родитель рабочий стол тоже самое что и NULL
		NULL,//будет меню или нет
		hInstance, NULL);

	if (!hWnd){
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

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam,//хранит свое сообщение, нужно в таком порядке
	LPARAM lParam)
{
	int x, y;
	switch (uMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, MYTIMER, 10, NULL);
		break;
	case WM_TIMER:
		std::srand(unsigned(std::time(0)));
//		int random_variable = std::rand();
		SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(std::rand() % 255, std::rand() % 255, std::rand() % 255)));
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_CLOSE://когда нажимаю закрыть окно
		if (MessageBox(hWnd, _TEXT("Вы действительно хотите завершить работу приложения?"), _TEXT("Информация"), MB_YESNO) == IDYES)
		{
			DestroyWindow(hWnd);
		}
		break;
	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		MoveWindow(hWnd, x, y, 300, 300, true);
		break;
	case WM_DESTROY:
		KillTimer(hWnd, MYTIMER); //второе значение ID  таймера
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}

SendMessage(hMnd, WM_CLOSE, wParam, lParam); //для CLOSE 0 0

PostMessage(hMnd, WM_CLOSE, wParam, lParam); //для CLOSE 0 0
