#include "MyWindow.h"
#include "resource.h"
#include <tchar.h>
#include <ctime>
#include <string>
#include <commCtrl.h>
#include "commdlg.h"

MyWindow* MyWindow::ptr = NULL;

MyWindow::MyWindow()
{
	ptr = this;
}
BOOL CALLBACK MyWindow::DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
		HANDLE_MSG(hWnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, ptr->Cls_OnCommand);
		HANDLE_MSG(hWnd, WM_CLOSE, ptr->Cls_OnClose);
	}
	return false;
}

void MyWindow::Cls_OnClose(HWND hWnd)
{
	DestroyWindow(hWnd);
	PostQuitMessage(0);
}

BOOL MyWindow::Cls_OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam)
{
	hDialog = hWnd;
	hEdit = GetDlgItem(hWnd, IDC_EDIT1);
	hRsumm = GetDlgItem(hWnd, IDC_SUMM);
	hRmult = GetDlgItem(hWnd, IDC_MULTIPLE);
	hRaver = GetDlgItem(hWnd, IDC_AVERAGE);
	hSresult = GetDlgItem(hWnd, IDC_RESULT);
	hM = LoadMenu(GetModuleHandle(NULL), MAKEINTRESOURCE(IDR_MENU1));

	SetMenu(hWnd, hM);
	SendMessage(hRsumm, BM_SETCHECK, BST_CHECKED, 0);

	return true;
}
void MyWindow::Cls_OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify)
{

	srand(time(NULL));
	std::wstring s, result = L"", r;
	TCHAR buf[100], *r_buf;
	int arr[20];
	int size;
	static int summ = 0;
	static double average = 0;
	static long multiple = 1;

	if (id == IDOK)
	{
		multiple = 1;
		summ = 0;
		average = 1;
		size = 10 + rand() % (20 - 10);
		for (int i = 0; i < size; i++)
		{
			arr[i] = -10 + rand() % (10 + 10);
			if (arr[i] == 0)
			{
				while (arr[i] == 0)
					arr[i] = -10 + rand() % (10 + 10);
			}
			s = std::to_wstring(arr[i]);
			result += s;
			if (i != size - 1)
				result += L"\r\n";
			summ += arr[i];
			multiple *= arr[i];
		}
		average = (double)summ / (double)size;
		_tcscpy(buf, result.c_str());
		SetWindowText(hEdit, buf);
	}
	else if (id == IDC_MULTIPLE || SendDlgItemMessage(hWnd, IDC_MULTIPLE, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		r = std::to_wstring(multiple);
		r_buf = new TCHAR[r.length() + 1];
		_tcscpy(r_buf, r.c_str());
		SetWindowText(hSresult, r_buf);
		delete[] r_buf;
		r_buf = NULL;
	}
	else if (id == IDC_SUMM || SendDlgItemMessage(hWnd, IDC_SUMM, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		r = std::to_wstring(summ);
		r_buf = new TCHAR[r.length() + 1];
		_tcscpy(r_buf, r.c_str());
		SetWindowText(hSresult, r_buf);
		delete[] r_buf;
		r_buf = NULL;
	}
	else if (id == IDC_AVERAGE || SendDlgItemMessage(hWnd, IDC_AVERAGE, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		r = std::to_wstring(average);
		r_buf = new TCHAR[r.length() + 1];
		_tcscpy(r_buf, r.c_str());
		SetWindowText(hSresult, r_buf);
		delete[] r_buf;
		r_buf = NULL;
	}

	if (id == ID_CLOSE)
	{
		SendMessage(hWnd, WM_CLOSE, 0, 0);
	}
	else if (id == ID_ABOUT)
	{
		MessageBox(hWnd, TEXT("Математический калейдоскоп V 1.0003"), TEXT("About"), MB_OK);
	}
	else if(id == ID_AUTOR)
	{
		MessageBox(hWnd, TEXT("Вячеслав Афанасенко\r\ne-mail: dezzfafara@gmail.com\r\nSkype: dezzfafara"), TEXT("Author"), MB_OK);
	}
	else if(id == ID_NEW)
	{
		multiple = 1;
		summ = 0;
		average = 1;
		size = 10 + rand() % (20 - 10);
		for (int i = 0; i < size; i++)
		{
			arr[i] = -10 + rand() % (10 + 10);
			if (arr[i] == 0)
			{
				while (arr[i] == 0)
					arr[i] = -10 + rand() % (10 + 10);
			}
			s = std::to_wstring(arr[i]);
			result += s;
			if (i != size - 1)
				result += L"\r\n";
			summ += arr[i];
			multiple *= arr[i];
		}
		average = (double)summ / (double)size;
		_tcscpy(buf, result.c_str());
		SetWindowText(hEdit, buf);
	}
}
