/*Создайте приложение «Убегающий статик».
В окне должен быть расположен статический элемент управления(статик).
Когда пользователь пытается подвести курсор мыши к «статику»,
то, если курсор находится близко со «статиком», элемент управления «убегает».
Предусмотрите перемещение «статика» только в пределах окна.*/

#include <Windows.h>
#include <WinUser.h>
#include <tchar.h>
#include <cstdlib>
#include <ctime>

int const width = 400;
int const height = 400;

int const staticWidth = 30;
int const staticHeight = 30;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpCmdLine, int mCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wnd;
	memset(&wnd, 0, sizeof(wnd));

	LPWSTR szClassName = _TEXT("Window");
	wnd.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;

	wnd.cbSize = sizeof(wnd);
	wnd.lpfnWndProc = WndProc;
	wnd.hInstance = hInstance;
	wnd.hIcon = LoadIcon(hInstance, IDI_HAND);
	wnd.hCursor = LoadCursor(hInstance, IDC_WAIT);
	wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wnd.lpszMenuName = NULL;
	wnd.lpszClassName = szClassName;
	wnd.hIconSm = LoadIcon(hInstance, IDI_HAND);

	std::srand(unsigned(std::time(0)));

	if (!RegisterClassEx(&wnd))
	{
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error1"), MB_OK | MB_ICONERROR);
		return 0;
	}

	hWnd = CreateWindowEx(WS_EX_WINDOWEDGE, szClassName, _TEXT("Hello"), WS_OVERLAPPEDWINDOW ^ (WS_MAXIMIZEBOX | WS_MINIMIZEBOX),
		CW_USEDEFAULT, CW_USEDEFAULT, width, height,
		HWND_DESKTOP,//родитель рабочий стол тоже самое что и NULL
		NULL,//будет меню или нет
		hInstance, NULL);

	if (!hWnd) {
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error2"), MB_OK | MB_ICONERROR);
		return 0;
	}

	ShowWindow(hWnd, SW_NORMAL);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);//нужно так как будет приниматься сообщение от клавиатуры, для перевода значения 
		DispatchMessage(&msg);//
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam,//хранит свое сообщение, нужно в таком порядке
	LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	static HWND hWndChild;

	static int desktopWigth;
	static int desktopHeigth;

	int xPos = 100;
	int yPos = 100;

	int x, y;
	switch (uMessage)
	{
	case WM_CREATE:
		hWndChild = CreateWindowEx(WS_EX_TOPMOST, L"STATIC", L"Click",
			WS_CHILD | WS_VISIBLE, 
			xPos, yPos, staticWidth, staticHeight, hWnd, (HMENU) NULL, GetModuleHandle(NULL), NULL);
		break;
	
	case WM_CLOSE://когда нажимаю закрыть окно
		if (MessageBox(hWnd, _TEXT("Вы действительно хотите завершить работу приложения?"), _TEXT("Информация"), MB_YESNO) == IDYES)
		{
			DestroyWindow(hWnd);
		}
		break;
	case WM_MOUSEMOVE:
		GetWindowRect(hWndChild, &rect);
		xPos = rect.left;
		yPos = rect.top;

		x = LOWORD(lParam);
		y = HIWORD(lParam);
		if (x >= (xPos - 5) && x <= (xPos + staticWidth + 5) || (y >= (yPos - 5) && y <= (yPos + staticHeight + 5)))
		{
			MoveWindow(hWndChild, std::rand() % (width - staticWidth), std::rand() % (height - staticHeight), staticWidth, staticHeight, true);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}
