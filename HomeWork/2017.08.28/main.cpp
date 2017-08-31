#include <Windows.h>
#include "resource.h"
#include <tchar.h>
#include <fstream>
#include <codecvt>
#include <map>
#include <vector>

namespace Data
{
	std::map<int, std::vector<wchar_t*>> users;
	std::vector<wchar_t*> words;
}

#define ID_EDIT_SOURCE 800
static HWND hButtonOpen;
static HWND hButtonClear;
static HWND hEditSource;

void addData(std::map<int, std::vector<wchar_t*>> &users);
BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgProcLogin(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

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
	addData(Data::users);
	static HWND hEditYourText;
	static HWND hListBox;
	static HWND hCountStr;
	LONG style;

	switch (uMsg)
	{
	case WM_INITDIALOG:
		hEditSource = CreateWindowEx(WS_EX_TOPMOST, L"EDIT", L"",
			WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_VSCROLL | WS_THICKFRAME | ES_CENTER | WS_DISABLED,
			20, 30, 250, 440, hWnd, (HMENU)ID_EDIT_SOURCE, GetModuleHandle(NULL), NULL);
		hButtonOpen = GetDlgItem(hWnd, IDC_OPEN);
		hButtonClear = GetDlgItem(hWnd, IDC_CLEAR);
		hListBox = GetDlgItem(hWnd, IDC_LISTBOX);
		hCountStr = GetDlgItem(hWnd, IDC_COUNT);
		hEditYourText = GetDlgItem(hWnd, IDC_YOUR_TEXT);
		return true;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_LOGIN)
		{
			//MessageBox(NULL, L"Эта функция пока недоступна.", L"Авторизация", MB_OK);| ES_READONLY
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_LOGIN), hWnd, DlgProcLogin);
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
			
			if (ofile.is_open())
			{
				int len = SendMessage(hEditYourText, WM_GETTEXTLENGTH, 0, 0);
				wchar_t* buf = new wchar_t[len];
				SendMessage(hEditYourText, WM_GETTEXT, len + 1, LPARAM(buf));
				ofile << buf << std::endl;
				delete[] buf;
				ofile.close();
			}
		}
		else if (LOWORD(wParam) == IDC_ADDWORD)
		{
			DWORD dwStart = 0;
			DWORD dwEnd = 0;
			SendMessage(hEditYourText, EM_GETSEL, (WPARAM)&dwStart, (LPARAM)&dwEnd);

			if (dwEnd > 0)
			{
				wchar_t* buf = new wchar_t[dwEnd + 1];
				SendMessage(hEditYourText, WM_GETTEXT, dwEnd + 1, LPARAM(buf));

				wchar_t* result = new wchar_t[dwEnd - dwStart + 1];
				wcscpy(result, &buf[dwStart]);

				int positionSpace;

				for (positionSpace = 0; positionSpace < sizeof(result); positionSpace++)
				{
					if (result[positionSpace] == L' ')
					{
						result[positionSpace] = L'\0';
						break;
					}
				}

				if (result[0] == L' ')
				{
					wcscpy(result, &result[1]);
				}

				wsprintf(buf, L"%d", positionSpace);
				
				//Data::words.push_back(result);

				if (sizeof(result))
				{
					int flagPush = 1;
					for (int i = 0; i < Data::words.size(); i++)
					{
						if ((wcscmp(Data::words[i], result)) == 0)
						{
							flagPush = 0;
							MessageBox(hWnd, _TEXT("Это слово уже есть в списке!"), _TEXT("Внимание!"), MB_OK);
						}
					}
					if (flagPush)
					{
						Data::words.push_back(result);
						SendMessage(hListBox, LB_ADDSTRING, 0, LPARAM(result));
					}

					delete[] buf;
					delete[] result;

					wchar_t size[5];
					memset(buf, 0, sizeof(buf));
					wsprintf(buf, L"%d", Data::words.size());
					SetWindowText(hCountStr, buf);
				}
			}
		}
		else if (LOWORD(wParam) == IDC_DELETE_FROM_LIST)
		{
			int position = SendMessage(hListBox, LB_GETCURSEL, 0, 0);
			SendMessage(hListBox, LB_DELETESTRING, position, 0);

			int size = SendMessage(hListBox, LB_GETCOUNT, 0, 0);
			wchar_t buf[5];
			memset(buf, 0, sizeof(buf));
			wsprintf(buf, L"%d", size);
			SetWindowText(hCountStr, buf);
		}
		else if (LOWORD(wParam) == IDC_CLEAR_LIST)
		{
			SendMessage(hListBox, LB_RESETCONTENT, 0, 0);
			wchar_t buf[2];
			wsprintf(buf, L"%d", 0);
			SetWindowText(hCountStr, buf);
		}
		else if (LOWORD(wParam) == IDC_WRITE_FROM_LIST)
		{
			std::wofstream ofile("C:\\Users\\gamer\\Desktop\\list.txt");
			std::locale loc(std::locale::classic(), new std::codecvt_utf8<wchar_t>);
			ofile.imbue(loc);

			int len;
			wchar_t* buf;
			int count = SendMessage(hListBox, LB_GETCOUNT, 0, 0);
			wchar_t* result = new wchar_t[500];
			memset(result, 0, sizeof(result));

			for (int i = 0; i < count; i++)
			{
				len = SendMessage(hListBox, LB_GETTEXTLEN, i, 0);
				buf = new wchar_t[len];
				SendMessage(hListBox, LB_GETTEXT, i, LPARAM(buf));
				wcscat(result, buf);
				wcscat(result, L"\n");
			}
			ofile << result << std::endl;
			ofile.close();
		}

		return true;

	/*case WM_LBUTTONDOWN:
		style = GetWindowLong(hEditSource, GWL_STYLE);
		SetWindowLong(hEditSource, GWL_STYLE, style ^ WS_VSCROLL);
		return true;*/

	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	}
	return false;
}

BOOL CALLBACK DlgProcLogin(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hEditPassword;
	static HWND hEditLogin;

	LONG styleEdit;
	LONG styleButtonOpen;
	LONG styleButtonClear;

	switch (uMsg)
	{
	case WM_INITDIALOG:
		hEditLogin = GetDlgItem(hWnd, IDC_LOGIN);
		hEditPassword = GetDlgItem(hWnd, IDC_PASSWORD);
		return true;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_LOG_IN_SYSTEM:
			if (!(SendMessage(hEditLogin, WM_GETTEXTLENGTH, 0, 0)) || !(SendMessage(hEditPassword, WM_GETTEXTLENGTH, 0, 0)))
			{
				MessageBox(hWnd, _TEXT("Данные не заполнены!"), _TEXT("Внимание!"), MB_OK);
			}
			else
			{
				int len = SendMessage(hEditLogin, WM_GETTEXTLENGTH, 0, 0) + 1;
				wchar_t* login = new wchar_t[len];
				GetWindowText(hEditLogin, login, len);
				
				for (int i = 0; i < Data::users.size(); i++)
				{
					if ((wcscmp(Data::users[i][0], login)) == 0)
					{
						len = SendMessage(hEditPassword, WM_GETTEXTLENGTH, 0, 0) + 1;
						wchar_t* password = new wchar_t[len];
						GetWindowText(hEditPassword, password, len);

						if ((wcscmp(Data::users[i][1], password)) == 0)
						{
							styleEdit = GetWindowLong(hEditSource, GWL_STYLE);
							SetWindowLong(hEditSource, GWL_STYLE, styleEdit ^ WS_DISABLED);

							styleButtonOpen = GetWindowLong(hButtonOpen, GWL_STYLE);
							SetWindowLong(hButtonOpen, GWL_STYLE, styleButtonOpen ^ WS_DISABLED);

							styleButtonClear = GetWindowLong(hButtonClear, GWL_STYLE);
							SetWindowLong(hButtonClear, GWL_STYLE, styleButtonClear ^ WS_DISABLED);

							MessageBox(hWnd, _TEXT("Верно"), _TEXT("Данные по авторизации"), MB_OK);
							break;
						}
						else
						{
							MessageBox(hWnd, _TEXT("Не верный пароль"), _TEXT("Данные по авторизации"), MB_OK);
							break;
						}
					}
					else
					{
						MessageBox(hWnd, _TEXT("Не верный логин"), _TEXT("Данные по авторизации"), MB_OK);
						break;
					}
					break;
				}
			}
		}
		return true;

	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return true;
	}

	return false;
}

void addData(std::map<int, std::vector<wchar_t*>> &users)
{
	std::vector<wchar_t*> v1 = { L"1", L"12345678"};
	users.insert({0, v1});
	std::vector<wchar_t*> v2 = { L"2", L"qwerty12" };
	users.insert({ 1, v2});
	std::vector<wchar_t*> v3 = { L"3", L"zxc12345" };
	users.insert({ 2, v3 });
	std::vector<wchar_t*> v4 = { L"4", L"qweasdzxc" };
	users.insert({ 3, v4 });
}
