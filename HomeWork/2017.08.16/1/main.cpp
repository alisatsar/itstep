#include <Windows.h>
#include <WinUser.h>


LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM Param)
{

	HDC hdc;		//для рисования в окне
	PAINTSTRUCT ps;
	RECT rect;

	switch (Msg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &rect);
		DrawText(hdc, L"Hello ", -1, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_TIMER:
	
	default:
		return DefWindowProc(hWnd, Msg, wParam, Param);

	}

	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpCmdLine, int mCmdShow)
{
	WNDCLASSEX wmdclass;
	memset(&wmdclass, 0, sizeof(wmdclass));

	LPWSTR szClassName = L"MyWindowClass";
	LPWSTR szTitleName = L"My first Window";
	
	wmdclass.cbSize = sizeof(wmdclass);
	wmdclass.lpszClassName = szClassName;
	wmdclass.style = CS_HREDRAW | CS_VREDRAW;

	wmdclass.lpfnWndProc = WndProc;
	wmdclass.hInstance = hInstance;

	wmdclass.hCursor = LoadCursor(NULL, IDC_WAIT);
	wmdclass.hIcon = LoadIcon(NULL, IDI_HAND);
	wmdclass.hbrBackground = CreateSolidBrush(RGB(250, 150, 0));

	if (!RegisterClassEx(&wmdclass))
	{
		return -1;
	}

	HWND hWnd = CreateWindowEx(WS_EX_TOPMOST, szClassName, szTitleName,
		WS_OVERLAPPEDWINDOW | WS_VSCROLL, 0, 0, 250, 250, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return -1;
	}

	
	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);

	HWND hWnd2 = CreateWindowEx(WS_EX_TOPMOST, szClassName, L"Second Window",
		WS_OVERLAPPEDWINDOW | WS_VSCROLL, 250, 0, 250, 250, NULL, NULL, hInstance, NULL);

	SetClassLong(hWnd2, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(250, 0, 0)));

	//UINT SetTimer(hWnd2, UINT_PTR idEvent, 10000, (TIMERPROC)NULL);

	ShowWindow(hWnd2, 1);
	UpdateWindow(hWnd2);

	HWND hWnd3 = CreateWindowEx(WS_EX_TOPMOST, szClassName, L"Tried Window",
		WS_OVERLAPPEDWINDOW | WS_VSCROLL, 500, 0, 250, 250, NULL, NULL, hInstance, NULL);

	SetClassLong(hWnd3, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(56, 0, 100)));
	ShowWindow(hWnd3, 1);
	UpdateWindow(hWnd3);

	HWND hWnd4 = CreateWindowEx(WS_EX_TOPMOST, szClassName, L"Fourth Window",
		WS_OVERLAPPEDWINDOW | WS_VSCROLL, 750, 0, 250, 250, NULL, NULL, hInstance, NULL);

	SetClassLong(hWnd4, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(0, 0, 0)));
	ShowWindow(hWnd4, 1);
	UpdateWindow(hWnd4);

	MessageBoxW(hWnd, L"Hello, Step", L"MessageBox", MB_OK);


	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) //цикл обработки сообщений
	{
		//TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;

	
}
