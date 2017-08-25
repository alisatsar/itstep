#include <Windows.h>
#include <WinUser.h>
#include "resource.h"
#include <vector>

#define ID_EDIT 2001
std::vector<HBITMAP> cats;

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

	return msg.wParam;
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hEdit;
	static HWND hEdit1;
	static HWND hBdel;
	static HWND hDlg;

	static HWND hListBox;
	LONG style;
	int index;

	switch (uMsg)
	{
	case WM_INITDIALOG:
	//	cats.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE( IDB_BITMAP1)));
	//	cats.push_back(LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP2)));
		hDlg = hWnd;
		hEdit1 = GetDlgItem(hWnd, IDC_EDIT1);
		hEdit = CreateWindowEx(WS_EX_TOPMOST, L"EDIT", L"???",
			WS_CHILD | WS_VISIBLE | ES_LEFT , 10, 10, 100, 20, hWnd,
			(HMENU)ID_EDIT, GetModuleHandle(NULL), NULL);
		hBdel = GetDlgItem(hWnd, IDC_BUTTON_DELETE);

		hListBox = CreateWindowEx(NULL, L"LISTBOX", NULL,
			WS_CHILD | WS_VISIBLE | LBS_STANDARD, 10, 150, 100, 20, hWnd,
			NULL, GetModuleHandle(NULL), NULL);

		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)L"string");
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)L"string2");
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)L"string3");
		return true;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_BUTTON_DELETE)
		{
			int len = SendMessage(hEdit1, WM_GETTEXTLENGTH, 0, 0);
			SendMessage(hEdit1, EM_SETSEL, 0, len + 1);
			SendMessage(hEdit1, WM_CLEAR, 0, 0);
		}
		else if (LOWORD(wParam) == IDOK_CUT)
		{
			int len = SendMessage(hEdit1, WM_GETTEXTLENGTH, 0, 0);
			SendMessage(hEdit1, EM_SETSEL, 0, len + 1);
			SendMessage(hEdit1, WM_CUT, 0, 0);
			SendMessage(hEdit, WM_PASTE, 0, 0);
		}
		else if (LOWORD(wParam) == ID_GETTEXT)
		{
			int len = SendMessage(hEdit1, WM_GETTEXTLENGTH, 0, 0) + 1;
			wchar_t* buf = new wchar_t[len];
			
			//GetWindowText(hEdit, buf, sizeof(buf));
			SendMessage(hEdit1, EM_GETLINE, 0, LPARAM(buf));
			SetWindowText(hDlg, buf);
			SendMessage(hEdit, WM_SETTEXT, 0, LPARAM(buf));
			delete[] buf;
		}
		else if (LOWORD(wParam) == IDC_IN_LIST)
		{
			wchar_t buf[30];
			GetWindowText(hEdit1, buf, sizeof(buf));
			SendMessage(hListBox, LB_ADDSTRING, 0, LPARAM(buf));

			int count = SendMessage(hListBox, LB_GETCOUNT, 0, 0);

			wchar_t buff[10];
			wsprintf(buff, L"COUNT: %d", count);
			MessageBox(NULL, buff, L"Size", MB_OK);
		}
		return true;

	case WM_RBUTTONDOWN:
		index = SendMessage(hListBox, LB_GETCURSEL, 0, 0);
		SendMessage(hListBox, LB_DELETESTRING, index, 0);	

		return true;

	case WM_LBUTTONDOWN:
		style = GetWindowLong(hEdit, GWL_STYLE);
		SetWindowLong(hEdit, GWL_STYLE, style ^ ES_LEFT | ES_RIGHT);
		return true;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	}

	return false;
}
