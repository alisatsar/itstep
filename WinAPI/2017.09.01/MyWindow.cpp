#include "MyWindow.h"
#include "resource.h"

MyWindow* MyWindow::ptr = NULL;

MyWindow::MyWindow()
{
	ptr = this;
}

BOOL CALLBACK MyWindow::DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
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
	hDialog = GetDlgItem(hWnd, IDD_DIALOG1);
	hButtonOk = GetDlgItem(hWnd, IDOK);
	hButtonChacel = GetDlgItem(hWnd, IDCANCEL);
	hStr = GetDlgItem(hWnd, IDC_TEXT);

	return true;
}

void MyWindow::Cls_OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify)
{
	if (id == IDOK)
	{
		MessageBox(hWnd, L"OK", L"WM_COMMAND", MB_OK);
	}
	else if (id == IDCANCEL)
	{
		MessageBox(hWnd, L"CANCEL", L"WM_COMMAND", MB_OK);
	}
	else if (id == IDC_EDIT)
	{
		SetWindowText(hStr, L"Hello");
	}
}

