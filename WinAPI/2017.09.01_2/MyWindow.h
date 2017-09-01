#pragma once
#include <Windows.h>
#include <windowsx.h>

class MyWindow
{
	static MyWindow* ptr;
	HWND hDialog;
	HWND hEdit;
	HWND hRsumm;
	HWND hRmult;
	HWND hRaver;
	HWND hSresult;

	HMENU hM;

	void Cls_OnClose(HWND hWnd);
	BOOL Cls_OnInitDialog(HWND hWnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hWnd, int id, HWND hwndCtl, UINT codeNotify);
public:
	MyWindow();
	~MyWindow() = default;
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
