#include <Windows.h>
#include <WinUser.h>
#include "resource.h"
#include <vector>

#define MYTIMER_QUICKLY_CATS 303
#define MYTIMER_SLOWLY_CATS 304

std::vector<HBITMAP> cats;
std::vector<HBITMAP> dogs;

int i = 0;

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

	static std::vector<HBITMAP> dogs;
	static HWND hCheckBoxCats;
	static HWND hCheckBoxDogs;

	static HWND hRadioButtonQuickly;
	static HWND hRadioButtonSlow;

	static HWND hStart;

	
	static HWND hPicture;
	

	switch (uMsg)
	{
	case WM_INITDIALOG:
		hCheckBoxCats = GetDlgItem(hWnd, IDC_CHECK_CATS);
		hCheckBoxDogs = GetDlgItem(hWnd, IDC_CHECK_DOGS);

		hRadioButtonQuickly = GetDlgItem(hWnd, IDC_RADIO_QUICKLY);
		hRadioButtonSlow = GetDlgItem(hWnd, IDC_RADIO_SLOWLY);

		hPicture = GetDlgItem(hWnd, IDC_PICTURE);

		hStart = GetDlgItem(hWnd, ID_START);

		cats.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1)));
		cats.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP2)));
		cats.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP3)));
		cats.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP4)));
		cats.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP5)));
		dogs.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP6)));
		dogs.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP7)));
		dogs.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP8)));
		dogs.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP9)));
		dogs.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP10)));

		return true;

	case WM_COMMAND:
		if (SendMessage(hStart, BM_GETSTATE, 0, 0))
		{
			if (SendMessage(hCheckBoxCats, BM_GETSTATE, 0, 0) == BST_CHECKED)
			{
				if (SendMessage(hRadioButtonQuickly, BM_GETCHECK, 0, 0) == BST_CHECKED)
				{
					while(i < 5)
					{
						SetTimer(hWnd, MYTIMER_QUICKLY_CATS, 1000, NULL);
						i = i + 1;
					}
				}
				else if (SendMessage(hRadioButtonSlow, BM_GETCHECK, 0, 0) == BST_CHECKED)
				{
					SetTimer(hWnd, MYTIMER_SLOWLY_CATS, 5000, NULL);
				}
			}
		}
		/*if (LOWORD(wParam) == ID_START)//в WPARAM приходит id
		{
			if (LOWORD(wParam) == IDC_CHECK_CATS)
			{
				if (LOWORD(wParam) == IDC_RADIO_QUICKLY)
				{
					SetTimer(hWnd, MYTIMER_QUICKLY_CATS, 50, NULL);
				}
				else if (LOWORD(wParam) == IDC_RADIO_SLOWLY)
				{
					SetTimer(hWnd, MYTIMER_SLOWLY_CATS, 50, NULL);
				}
			}
			else if (LOWORD(wParam) == IDC_CHECK_DOGS)
			{

			}
		}
		*/
		/*else if (LOWORD(wParam) == ID_STOP)
		{
			KillTimer(hWnd, MYTIMER_QUICKLY_CATS);
			KillTimer(hWnd, MYTIMER_SLOWLY_CATS);
		}*/
		
		return true;

	case WM_TIMER:
		switch (wParam)
		{
		case MYTIMER_QUICKLY_CATS:
			SendMessage(hPicture, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)cats[i]);
			break;
		case MYTIMER_SLOWLY_CATS:
			SendMessage(hPicture, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)cats[5 % 5]);
			break;
		}
		return true;

	case WM_CLOSE:
		KillTimer(hWnd, MYTIMER_QUICKLY_CATS);
		KillTimer(hWnd, MYTIMER_SLOWLY_CATS);
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	}

	return false;
}
