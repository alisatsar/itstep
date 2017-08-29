#include <Windows.h>
#include <WinUser.h>
#include <tchar.h>
#include <cstdlib>
#include <ctime>

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPervInstance, LPSTR lpCmdLine, int mCmdShow)
{
	HWND hWnd;
	WNDCLASSEX wnd;
	memset(&wnd, 0, sizeof(wnd));

	LPWSTR szClassName = _TEXT("Window");
	wnd.style = CS_HREDRAW | CS_VREDRAW;

	wnd.cbSize = sizeof(wnd);
	wnd.lpfnWndProc = WndProc;
	wnd.hInstance = hInstance;
	wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wnd.lpszMenuName = NULL;
	wnd.lpszClassName = szClassName;
	wnd.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wnd))
	{
		MessageBox(NULL, _TEXT("Sorry... :("), _TEXT("Error1"), MB_OK | MB_ICONERROR);
		return 0;
	}

	hWnd = CreateWindowEx(WS_EX_WINDOWEDGE, szClassName, _TEXT("Hello"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 300, 300,
		HWND_DESKTOP,
		NULL,
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
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	switch (uMessage)
	{
	case WM_CREATE:
		if (MessageBox(hWnd, _TEXT("Загадайте число от 1 до 100. Нажмите 'Yes' чтобы продолжить, 'No' чтобы выйти"), _TEXT("Загадайте число"), MB_YESNO) == IDYES)
		{
			std::srand(unsigned(std::time(0)));
			wchar_t buff[50];
			if (MessageBox(hWnd, _TEXT("Ваше число больше 50?"), _TEXT("больше 50"), MB_YESNO) == IDYES)
			{
				if (MessageBox(hWnd, _TEXT("Ваше число больше 75?"), _TEXT("больше 75"), MB_YESNO) == IDYES)
				{
					int number = 75 + (std::rand() % 25);
					wsprintf(buff, L"Ваш число: %d, я угадал?", number);
				}
				else
				{
					int number = 50 + (std::rand() % 25);
					wsprintf(buff, L"Ваш число: %d, я угадал?", number);
				}
			}
			else
			{
				if (MessageBox(hWnd, _TEXT("Ваше число больше 25?"), _TEXT("больше 25"), MB_YESNO) == IDYES)
				{
					int number = 25 + (std::rand() % 25);
					wsprintf(buff, L"Ваш число: %d, я угадал?", number);
				}
				else
				{
					int number = 0 + (std::rand() % 25);
					wsprintf(buff, L"Ваш число: %d, я угадал?", number);
				}
			}
			if (MessageBox(hWnd, buff, _TEXT("Угадал?"), MB_YESNO) == IDYES)
			{
				MessageBox(hWnd, _TEXT("Я доволен собой. Спасибо за игру!"), _TEXT("Угадал"), MB_OK);
				DestroyWindow(hWnd);
			}
			else
			{
				MessageBox(hWnd, _TEXT("Я не доволен собой. Спасибо за игру!"), _TEXT("Не угадал"), MB_OK);
				DestroyWindow(hWnd);
			}
		}
		else
		{
			DestroyWindow(hWnd);
		}
		break;
	case WM_CLOSE:
		if (MessageBox(hWnd, _TEXT("Вы действительно хотите завершить работу приложения?"), _TEXT("Информация"), MB_YESNO) == IDYES)
		{
			DestroyWindow(hWnd);
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
