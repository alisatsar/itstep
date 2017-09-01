#pragma once
#include <Windows.h>
#include <windowsx.h>


class MyWindow
{
	static MyWindow* ptr;
	HWND hDialog;
	HWND hButtonOk;
	HWND hButtonChacel;
	HWND hStr;
	void Cls_OnClose(HWND hWnd);
	BOOL Cls_OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify);
public:
	MyWindow();
	~MyWindow() = default;
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
