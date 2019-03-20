#include "KWind.h"


LPCWSTR KWind::GetCName()
{
	return CName;
}

LPCWSTR KWind::CreateClass(LPCWSTR szCName, HINSTANCE hInst,
	WNDPROC pWndProc, LPCWSTR menuName, UINT classStyle)
{
	wC.cbSize = sizeof(wC);
	wC.style = classStyle;
	wC.lpfnWndProc = pWndProc;
	wC.cbClsExtra = 0;
	wC.cbWndExtra = 0;
	wC.hInstance = hInst;
	wC.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wC.hCursor = LoadCursor(NULL, IDC_ARROW);
	wC.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wC.lpszMenuName = menuName;
	wC.lpszClassName = szCName;
	wC.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	CName = CreateClass(wC);

	return CName;
}

LPCWSTR KWind::CreateClass(WNDCLASSEXW &wC)
{
	
	if (!RegisterClassExW(&wC)) {
		MessageBoxW(NULL, L"Cannot register class!", L"Error", MB_OK);
		return NULL;
	}
	CName = wC.lpszClassName;
	return CName;
}

HWND KWind::CreateWind(LPCWSTR szClassName, LPCWSTR windowName, 
	DWORD windowStyle, int x, int y, int width, int height,
	HWND hParent, HMENU hMenu, HINSTANCE hInst, LPVOID lVoid, int nCmdShow)
{
	hWnd = CreateWindowW(szClassName, windowName, windowStyle,
		x, y, width, height, hParent, hMenu, hInst, lVoid);
	

	if (!hWnd) {
		MessageBoxW(NULL, L"Cannot create window!", L"Error", MB_OK);
		return NULL;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	return hWnd;
}

HWND KWind::GetHWnd()
{
	return hWnd;
}
