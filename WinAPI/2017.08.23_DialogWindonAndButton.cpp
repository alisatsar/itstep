#include <Windows.h>
#include "resource.h"
#include <tchar.h>

#define ID_BUTTON1 2000
#define ID_BUTTON2 2001

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpCmdLine, int mCmdShow)
{
	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);//нужно так как будет приниматься сообщение от клавиатуры, для перевода значения 
		DispatchMessage(&msg);
	}

	return msg.wParam;
	//return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG), NULL, DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hStatic1;
	static HWND hWndBut;
	static HWND hWndBut2;
	static HWND hWndButD;

	switch (uMsg)
	{
	case WM_INITDIALOG:
	//	hWndButD = GetDlgItem(hWnd, ID_BUTTON2); для окон которые создали вручную

		hStatic1 = CreateWindowEx(NULL, L"STATIC", _TEXT("My first static"),
			WS_CHILD | WS_VISIBLE
			| SS_LEFT | SS_ICON,
			30, 30, 60, 40,
			hWnd, NULL, GetModuleHandle(NULL), NULL);

		hWndBut = CreateWindowEx(NULL, L"BUTTON", L"Click",
			WS_CHILD | WS_VISIBLE, 100, 100, 100, 50,
			hWnd, (HMENU)ID_BUTTON1,
			GetModuleHandle(NULL),
			NULL);

		hWndBut2 = CreateWindowEx(NULL, L"BUTTON", L"This?",
			WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 170, 170, 100, 50,
			hWnd, (HMENU)ID_BUTTON2,
			GetModuleHandle(NULL),
			NULL);
		return true;

	case WM_COMMAND:
		if (lParam = LPARAM(hWndBut2)) //в LPARAM приходит дискриптор
		{
			//MessageBox(NULL, L"BUTTON2", L"Info", MB_OK);
			if (SendMessage(hWndBut2, BM_GETCHECK, 0, 0) == BST_UNCHECKED)
			{
				SendMessage(hWndBut2, BM_SETCHECK, BST_CHECKED, 0);
			}
			else
			{
				SendMessage(hWndBut2, BM_SETCHECK, BST_UNCHECKED, 0);
			}
		}
		if (LOWORD(wParam) == ID_BUTTON1)//в WPARAM приходит id
		{
			MessageBox(NULL, L"BUTTON", L"Info", MB_OK);
			
		}
		return true;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	}

	return false;
	/*switch (uMsg)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return true;
	}


	return false;*/
}
