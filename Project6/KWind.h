#include <windows.h>
class KWind
{
private:
	WNDCLASSEXW wC;
	HWND hWnd;
	LPCWSTR CName;

public:
	KWind() 
	{
		wC = { 0 };
		CName = NULL;
	};

	LPCWSTR GetCName();

	LPCWSTR CreateClass(LPCWSTR szCName, HINSTANCE hInst,
		WNDPROC pWndProc, LPCWSTR menuName, UINT classStyle);

	LPCWSTR CreateClass(WNDCLASSEXW &wC);

	HWND CreateWind(LPCWSTR szClassName, LPCWSTR windowName,
		DWORD windowStyle, int x, int y, int width, int height,
		HWND hParent, HMENU hMenu, HINSTANCE hInst, LPVOID lVoid, int nCmdShow);

	HWND GetHWnd();
};
