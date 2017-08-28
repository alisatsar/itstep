#include <Windows.h>
#include <WinUser.h>
#include "resource.h"
#include "commctrl.h"

#pragma comment(lib, "comctl32")

#define MYTIMER 101
#define IDC_STATUSBAR 202

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpCmdLine, int mCmdShow)
{
	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	INITCOMMONCONTROLSEX cc;
	cc.dwSize = sizeof(cc);
	cc.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&cc);

	return msg.wParam;
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hProgress;
	static HWND hStatusBar;
	int parts[3] = { 50, 200, -1 };

	static HWND hSlider;

	switch (uMsg)
	{
	case WM_INITDIALOG:
		hProgress = GetDlgItem(hWnd, IDC_PROGRESS1);
		SendMessage(hProgress, PBM_SETBKCOLOR, 0, LPARAM(RGB(100, 100, 255)));
		SendMessage(hProgress, PBM_SETBARCOLOR, 0, LPARAM(RGB(0, 255, 255)));
		SendMessage(hProgress, PBM_SETRANGE, 0, MAKELPARAM(0, 300));//установить границы диапозона заполнения

		SetTimer(hWnd, MYTIMER, 100, NULL);

		SendMessage(hProgress, PBM_SETSTEP, 5, 0);

		hStatusBar = CreateWindowEx(NULL, STATUSCLASSNAME, NULL,
			WS_CHILD | WS_VISIBLE | SBARS_TOOLTIPS | SBARS_SIZEGRIP,
			CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
			hWnd, (HMENU)IDC_STATUSBAR, GetModuleHandle(NULL), NULL);

		SendMessage(hStatusBar, SB_SIMPLE, false, 0);//false много секций
		//SendMessage(hStatusBar, SB_SETTEXT, 255, (LPARAM)L"Hello world");

		SendMessage(hStatusBar, SB_SETPARTS, 3, (LPARAM)parts);

		SendMessage(hStatusBar, SB_SETTEXT, 0, (LPARAM)L"Hello world");

		hSlider = GetDlgItem(hWnd, IDC_SLIDER1);

		SendMessage(hSlider, TBM_SETRANGE, true, MAKELPARAM(0, 200));//true сразу перерисовать или нет
		SendMessage(hSlider, TBM_SETPOS, true, 100);

		SendMessage(hSlider, TBM_SETLINESIZE, 0, 10);//стрелки

		SendMessage(hSlider, TBM_SETPAGESIZE, 0, 10);//PageDown и PageUp

		return true;

	case WM_VSCROLL:
		if (lParam == (LPARAM)hSlider)
		{
			int pos = SendMessage(hSlider, TBM_GETPOS, 0, 0);
			wchar_t buf[20];
			wsprintf(buf, L"Position %d", pos);
			SendMessage(hStatusBar, SB_SETTEXT, 1, (LPARAM)buf);
		}
		return true;

	case WM_TIMER:
		//SendMessage(hProgress, PBM_DELTAPOS, 5, 0);

		SendMessage(hProgress, PBM_STEPIT, 0, 0);
		return true;

	case WM_CLOSE:
		KillTimer(hWnd, MYTIMER);
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	}

	return false;
}
