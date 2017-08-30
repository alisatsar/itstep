#include <Windows.h>
#include <WinUser.h>
#include "resource.h"
#include "commdlg.h"

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK DlgProcAbout(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpCmdLine, int mCmdShow)
{
	LoadLibrary(L"Riched20.dll");
	HACCEL hAcc = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCELERATOR1));

	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);
	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(hWnd, hAcc, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hEdit;
	RECT rect;
	static HMENU hMenu;

	static bool flagFont;
	static bool flBuf;
	static OPENFILENAME openFile;
	static wchar_t filePath[256];
	static wchar_t fileTitle[100];

	static OPENFILENAME saveFile;
	static wchar_t saveFilePath[256];
	static wchar_t saveFileTitle[100];

	switch (uMsg)
	{
	case WM_INITDIALOG:
		ZeroMemory(&openFile, sizeof(OPENFILENAME));
		openFile.lStructSize = sizeof(OPENFILENAME);
		openFile.hInstance = GetModuleHandle(NULL);
		openFile.hwndOwner = hWnd;
		openFile.lpstrFile = filePath;
		openFile.lpstrFileTitle = fileTitle;
		openFile.nMaxFile = sizeof(filePath);
		openFile.nMaxFileTitle = sizeof(fileTitle);
		//openFile.lpstrFilter = L

		ZeroMemory(&saveFile, sizeof(OPENFILENAME));
		saveFile.lStructSize = sizeof(OPENFILENAME);
		saveFile.hInstance = GetModuleHandle(NULL);
		saveFile.hwndOwner = hWnd;
		saveFile.lpstrFile = saveFilePath;
		saveFile.lpstrFileTitle = saveFileTitle;
		saveFile.nMaxFile = sizeof(saveFilePath);
		saveFile.nMaxFileTitle = sizeof(saveFileTitle);

		hEdit = GetDlgItem(hWnd, IDC_EDIT);
		hMenu = LoadMenu(GetModuleHandle(NULL), MAKEINTRESOURCE(IDR_MENU1));
		EnableMenuItem(hMenu, ID_VIEW_STRING, MF_BYCOMMAND | MF_GRAYED);
		CheckMenuItem(hMenu, ID_VIEW_FONT, MF_BYCOMMAND | MF_CHECKED);

		SetMenu(hWnd, hMenu);
		flagFont = true;

		EnableMenuItem(hMenu, ID_EDIT_PASTE, MF_BYCOMMAND | MF_DISABLED);
		flBuf = false;

		return true;

	case WM_LBUTTONDOWN:
		CheckMenuItem(hMenu, ID_VIEW_FONT, MF_BYCOMMAND | MF_UNCHECKED);
		return true;

	case WM_SIZE:
		GetClientRect(hWnd, &rect);
		MoveWindow(hEdit, 0, 0, rect.right, rect.bottom, true);
		return true;

	case WM_COMMAND:
		if (LOWORD(wParam) == ID_VIEW_FONT)
		{
			if (flagFont)
			{
				CheckMenuItem(hMenu, ID_VIEW_FONT, MF_BYCOMMAND | MF_UNCHECKED);
			}
			else
			{
				CheckMenuItem(hMenu, ID_VIEW_FONT, MF_BYCOMMAND | MF_CHECKED);
			}
			flagFont = !flagFont;
		}
		else if (LOWORD(wParam) == ID_EDIT_CUT)
		{
			SendMessage(hEdit, WM_CUT, 0, 0);
			flBuf = true;
			EnableMenuItem(hMenu, ID_EDIT_PASTE, MF_BYCOMMAND | MF_ENABLED);
			DrawMenuBar(hWnd);
		}
		else if (LOWORD(wParam) == ID_EDIT_COPY)
		{
			SendMessage(hEdit, WM_COPY, 0, 0);
			flBuf = true;
			EnableMenuItem(hMenu, ID_EDIT_PASTE, MF_BYCOMMAND | MF_ENABLED);
			DrawMenuBar(hWnd);
		}
		else if (LOWORD(wParam) == ID_EDIT_PASTE)
		{

			SendMessage(hEdit, WM_PASTE, 0, 0);
		}
		else if (LOWORD(wParam) == ID_EDIT_DELETE)
		{
			SetWindowText(hEdit, NULL);
		}
		else if (LOWORD(wParam) == ID_VIEW_FONT)
		{
			//MessageBox(NULL, L"", L"", MB_OK);
			DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(104), hWnd, DlgProcAbout);
		}
		else if (LOWORD(wParam) == ID_FILE_OPEN)
		{
			GetOpenFileName(&openFile);
			SetWindowText(hWnd, openFile.lpstrFileTitle);
		}
		else if (LOWORD(wParam) == ID_FILE_SAVE)
		{
			GetSaveFileName(&saveFile);
		}
		return true;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return true;
	}

	return false;
}

BOOL CALLBACK DlgProcAbout(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		/*
	case WM_INITDIALOG:
		return true;

	case WM_COMMAND:
		return true;
		*/
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return true;
	}

	return false;
}
