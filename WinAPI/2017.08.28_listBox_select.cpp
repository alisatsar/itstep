#include <Windows.h>
#include <WinUser.h>
#include "resource.h"
#include <vector>
#include <map>
#include <string>

namespace Data {
	std::map<int, std::vector<std::wstring>> studentInfo;
}

void addData(std::map<int, std::vector<std::wstring>>& m){
	std::vector<std::wstring> v1 = { L"C", L"Оценка по C: 10", L"Gradovich" };
	m.insert({ 0, v1 });
	std::vector<std::wstring> v2 = { L"PYTHON", L"Оценка по PYTHON: 10", L"Kyvaldin" };
	m.insert({ 1, v2 });
	std::vector<std::wstring> v3 = { L"C++", L"Оценка по C++: ?", L"Moskalev" };
	m.insert({ 2, v3 });
	std::vector<std::wstring> v4 = { L"WinApi", L"Оценка по WinApi: ?", L"Volchek" };
	m.insert({ 3, v4 });
//	m[0] = v1;
}

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
	static HWND hRate;
	static HWND hEdit;
	static HWND hListBox;

	switch (uMsg)
	{
	case WM_INITDIALOG:
		addData(Data::studentInfo);
		hListBox = GetDlgItem(hWnd, IDC_LIST1);
		hRate = GetDlgItem(hWnd, IDC_RATE);
		hEdit = GetDlgItem(hWnd, IDC_EDIT1);

		//SendMessage(hListBox, LB_ADDSTRING, 0, LPARAM(Data::studentInfo[0][0].c_str())); //std::wstring
		for (int i = 0; i < 4; i++)
		{
			SendMessage(hListBox, LB_ADDSTRING, 0, LPARAM(Data::studentInfo[i][0].c_str()));
		}
		return true;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_SHOW)
		{
			int index = SendMessage(hListBox, LB_GETCURSEL, 0, 0);
			
			SetWindowText(hRate, Data::studentInfo[index][1].c_str());
			SetWindowText(hEdit, Data::studentInfo[index][2].c_str());
		}
		else if (LOWORD(wParam) == IDC_CLEAR)
		{
			for (int i = 0; i < 4; i++)
			{
				SendMessage(hListBox, LB_DELETESTRING, 0, 0);
			}
		}
		return true;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	}

	return false;
}
