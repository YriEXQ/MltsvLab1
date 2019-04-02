//Ульмейкин Юрий Сергеевич
//МОАИС-17/1-О
//Лабораторная работа №1 Вариант №6:
//Программа открывает окно.При изменении размеров окна с помощью мыши окно 
//должно быть нельзя уменьшить менее чем до 300x200 и увеличить более 
//чем до 600x400.
#include <windows.h>
class KWind
{
private:
	WNDCLASSEXW wC;
	HWND hWnd;
	wchar_t CName[256];

public:
	KWind() 
	{
		wC = { 0 };
	};

	wchar_t* GetCName();

	wchar_t* CreateClass(LPCWSTR szCName, HINSTANCE hInst,
		WNDPROC pWndProc, LPCWSTR menuName, UINT classStyle);

	bool CreateClass(WNDCLASSEXW &wC);

	HWND CreateWind(LPCWSTR szClassName, LPCWSTR windowName,
		DWORD windowStyle, int x, int y, int width, int height,
		HWND hParent, HMENU hMenu, HINSTANCE hInst, LPVOID lVoid, int nCmdShow);

	HWND GetHWnd();
};
