//Ульмейкин Юрий Сергеевич
//МОАИС-17/1-О
//Лабораторная работа №1 Вариант №6:
//Программа открывает окно.При изменении размеров окна с помощью мыши окно 
//должно быть нельзя уменьшить менее чем до 300x200 и увеличить более 
//чем до 600x400.
#include "KWind.h"


wchar_t* KWind::GetCName()
{
	return CName;
}

wchar_t* KWind::CreateClass(LPCWSTR szCName, HINSTANCE hInst,
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

	if (CreateClass(wC)){
		wcscpy_s(CName, (const wchar_t*)wC.lpszClassName);
		return CName;
	}
	else return NULL;
}

bool KWind::CreateClass(WNDCLASSEXW &wC)
{
	
	if (!RegisterClassExW(&wC)) {
		MessageBoxW(NULL, L"Cannot register class!", L"Error", MB_OK);
		return false;
	}
	return true;
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
