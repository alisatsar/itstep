#include <Windows.h>
#include "resource.h"
#include <tchar.h>
#include <fstream>
#include <codecvt>

#define ID_BUTTON1 2000
#define ID_BUTTON2 2001

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpCmdLine, int mCmdShow)
{
	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINDLG), NULL, DlgProc);
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

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hEditSource;
	static HWND hEditYourText;

	switch (uMsg)
	{
	case WM_INITDIALOG:
		hEditSource = GetDlgItem(hWnd, IDC_EDIT_SOURCETEXT);
		hEditYourText = GetDlgItem(hWnd, IDC_YOUR_TEXT);
		return true;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_LOGIN)
		{
			//MessageBox(NULL, L"Эта функция пока недоступна.", L"Авторизация", MB_OK);
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_LOGIN), hWnd, NULL );

		}
		else if (LOWORD(wParam) == IDC_CLEAR)
		{
			int len = SendMessage(hEditSource, WM_GETTEXTLENGTH, 0, 0);
			SendMessage(hEditSource, EM_SETSEL, 0, len + 1);
			SendMessage(hEditSource, WM_CLEAR, 0, 0);
		}
		else if (LOWORD(wParam) == IDC_COPY_SELECT_TEXT)
		{
			SendMessage(hEditSource, WM_COPY, 0, 0);
			SendMessage(hEditYourText, WM_PASTE, 0, 0);
		}
		else if (LOWORD(wParam) == IDC_COPY_TEXT)
		{
			int len = SendMessage(hEditSource, WM_GETTEXTLENGTH, 0, 0);
			wchar_t* buf = new wchar_t[len];
			SendMessage(hEditSource, WM_GETTEXT, len + 1, LPARAM(buf));
			SendMessage(hEditYourText, WM_SETTEXT, 0, LPARAM(buf));
		}
		else if (LOWORD(wParam) == IDC_CLEAR_YOUR_TEXT)
		{
			int len = SendMessage(hEditSource, WM_GETTEXTLENGTH, 0, 0);
			SendMessage(hEditYourText, EM_SETSEL, 0, len + 1);
			SendMessage(hEditYourText, WM_CLEAR, 0, 0);
		}
		else if (LOWORD(wParam) == IDC_WRITE)
		{
			std::wofstream ofile("C:\\Users\\gamer\\Desktop\\new_text.txt ");
			std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
			ofile.imbue(loc);

			int len = SendMessage(hEditYourText, WM_GETTEXTLENGTH, 0, 0);
			wchar_t* buf = new wchar_t[len];
			SendMessage(hEditYourText, WM_GETTEXT, len + 1, LPARAM(buf));
			ofile << buf << std::endl;
		}
		return true;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	}

	return false;

}
