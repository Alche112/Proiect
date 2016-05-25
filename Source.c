
#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

#define ID_BEEP 1
#define ID_QUIT 2

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PWSTR lpCmdLine, int nCmdShow) {

	MSG  msg;
	WNDCLASSW wc = { 0 };
	wc.lpszClassName = L"Buttons";
	wc.hInstance = hInstance;
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wc.lpfnWndProc = WndProc;
	wc.hCursor = LoadCursor(0, IDC_ARROW);

	RegisterClassW(&wc);
	CreateWindowW(wc.lpszClassName, L"Buttons",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		150, 150, 900, 500, 0, 0, hInstance, 0);

	while (GetMessage(&msg, NULL, 0, 0)) {

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
	WPARAM wParam, LPARAM lParam) {

	switch (msg) {

	case WM_CREATE:

		CreateWindowW(L"Button", L"Generare",
			WS_VISIBLE | WS_CHILD,
			20, 50, 70, 25, hwnd, (HMENU)1, NULL, NULL);

		CreateWindowW(L"Button", L"Quit",
			WS_VISIBLE | WS_CHILD,
			120, 50, 70, 25, hwnd, (HMENU)ID_QUIT, NULL, NULL);
		CreateWindowW(L"Button", L"1", WS_VISIBLE | WS_CHILD, 30, 90, 45, 25, hwnd, (HMENU)3, NULL, NULL);
		CreateWindowW(L"Button", L"2", WS_VISIBLE | WS_CHILD, 80, 90, 45, 25, hwnd, (HMENU)4, NULL, NULL);
		CreateWindowW(L"Button", L"3", WS_VISIBLE | WS_CHILD, 140, 90, 45, 25, hwnd, (HMENU)5, NULL, NULL);
		CreateWindowW(L"Button", L"4", WS_VISIBLE | WS_CHILD, 30, 120, 45, 25, hwnd, (HMENU)6, NULL, NULL);
		CreateWindowW(L"Button", L"5", WS_VISIBLE | WS_CHILD, 80, 120, 45, 25, hwnd, (HMENU)7, NULL, NULL);
		CreateWindowW(L"Button", L"6", WS_VISIBLE | WS_CHILD, 140, 120, 45, 25, hwnd, (HMENU)8, NULL, NULL);
		CreateWindowW(L"Button", L"7", WS_VISIBLE | WS_CHILD, 30, 150, 45, 25, hwnd, (HMENU)9, NULL, NULL);
		CreateWindowW(L"Button", L"8", WS_VISIBLE | WS_CHILD, 80, 150, 45, 25, hwnd, (HMENU)10, NULL, NULL);
		CreateWindowW(L"Button", L"9", WS_VISIBLE | WS_CHILD, 140, 150, 45, 25, hwnd, (HMENU)11, NULL, NULL);


	
		break;

		int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
		{
			MSG msg;
			BOOL bRet;

			for (;;)
			{
				bRet = GetMessage(&msg, NULL, 0, 0);

				if (bRet > 0)  // (bRet > 0 indicates a message that must be processed.)
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				else if (bRet < 0)  // (bRet == -1 indicates an error.)
				{
					// Handle or log the error; possibly exit.
					// ...
				}
				else  // (bRet == 0 indicates "exit program".)
				{
					break;
				}
			}
			return msg.wParam;
		}
	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case 1: {
					MessageBox(hwnd, L" 1. Rapid \n\n 2.Dinamo \n\n 3.Astra \n\n ... \n\n 20.Steaua", L"Clasament", MB_OK);
		};
			break;
		case 3: {
					MessageBox(hwnd, L"terminata de luchita", L"Clasament", MB_OK);
		};
			break;
		}
		if (LOWORD(wParam) == ID_BEEP) {

			MessageBeep(MB_OK);
		}

		if (LOWORD(wParam) == ID_QUIT) {

			PostQuitMessage(0);
		}

		break;

	case WM_DESTROY:

		PostQuitMessage(0);
		break;
	}

	return DefWindowProcW(hwnd, msg, wParam, lParam);
}