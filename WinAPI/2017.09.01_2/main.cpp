#pragma comment(lib, "comctl32")
#include <Windows.h>
#include "resource.h"
#include <tchar.h>
#include <ctime>
#include <string>
#include <commCtrl.h>
#include "commdlg.h"
#include "MyWindow.h"

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR cmdArgs, int nCmdShow)
{
	MyWindow wind;
	
	HACCEL h_acc;
	h_acc = LoadAccelerators(hInst, MAKEINTRESOURCE(IDR_ACCELERATOR1));

	HWND hw = CreateDialog(hInst, MAKEINTRESOURCE(IDD_MAINDLG), NULL, MyWindow::DlgProc);
	ShowWindow(hw, SW_NORMAL);
	UpdateWindow(hw);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)){
		if (!TranslateAccelerator(hw, h_acc, &msg)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}
