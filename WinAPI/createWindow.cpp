#include <Windows.h>
#include <WinUser.h>

LRESULT CALLBACK WndProc(HWND hwmd, UINT Msg, WPARAM wParam, LPARAM Param)
{
	HDC hdc;		//для рисования в окне
	PAINTSTRUCT ps;
	RECT rect;

	switch (Msg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwmd, &ps);
		GetClientRect(hwmd, &rect);
		DrawText(hdc, L"Hello ", -1, &rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);

		EndPaint(hwmd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);

		break;
	default:
		return DefWindowProc(hwmd, Msg, wParam, Param);

	}

	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wmdclass;		//структура с расширенными стилями
	memset(&wmdclass, 0, sizeof(wmdclass));	//зануляем поля структуры

	LPWSTR szClassName = L"MyWindowClass";
	LPWSTR szTitleName = L"My first Window";

	wmdclass.cbSize = sizeof(wmdclass);	//размер
	wmdclass.lpszClassName = szClassName;
	wmdclass.style = CS_HREDRAW | CS_VREDRAW;

	wmdclass.lpfnWndProc = WndProc;
	wmdclass.hInstance = hInstance;

	wmdclass.hCursor = LoadCursor(NULL, IDC_WAIT); //курсор первоначальный, NULL выбираем иконку из windows
	wmdclass.hIcon = LoadIcon(NULL, IDI_HAND);
	wmdclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //HBRUSH приводит к типу 
	//или CreateSolidBrush(RGB(0, 0, 0));

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
	MessageBoxW(hWnd, L"Hello, Step", L"MessageBox", MB_OK);


	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) //цикл обработки сообщений
	{
		//TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}
