#include <Windows.h>
#include <WinUser.h>
#include "resource.h"
#include <vector>

#define ID_BUTTON_FAST 2000
#define ID_BUTTON_SLOW 2001


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
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	HBITMAP hbm;
	static std::vector<HBITMAP> dogs;
	static HWND hCheckBoxCats;
	static HWND hCheckBoxDogs;

	static HWND hRadioButtonQuickly;
	static HWND hRadioButtonSlow;

	static HWND hPicture;

	LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1));
	
	switch (uMsg)
	{
	case WM_INITDIALOG:
		hCheckBoxCats = GetDlgItem(hWnd, IDC_CHECK_CATS);
		hCheckBoxDogs = GetDlgItem(hWnd, IDC_CHECK_DOGS);

		hRadioButtonQuickly = GetDlgItem(hWnd, IDC_RADIO_QUICKLY);
		hRadioButtonQuickly = GetDlgItem(hWnd, IDC_RADIO_SLOWLY);

		hPicture = GetDlgItem(hWnd, IDC_PICTURE);

		hbm = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1));
		SendMessage(hPicture, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hbm);
		return true;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_CHECK_CATS)//в WPARAM приходит id
		{
			SendMessage((HWND)lParam, BM_SETSTATE, TRUE, 0); 

		}
		return true;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		if (hPicture)
		{
			EndPaint(hWnd, &ps);
		}
		EndPaint(hWnd, &ps);
		break;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	}

	return false;
}
