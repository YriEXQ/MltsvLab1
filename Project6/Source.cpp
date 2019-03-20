//////////////////////////////////////////////////////////////////////
// Hello2.cpp
#include "KWind.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//====================================================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int
	nCmdShow)
{
	MSG msg;
	
	KWind wind;
	wind.CreateClass(L"Simple", hInstance, WndProc, NULL, CS_HREDRAW | CS_VREDRAW);
	wind.CreateWind(wind.GetCName(), L"Hello", WS_OVERLAPPEDWINDOW, 250, 250, 400, 200,
		NULL, NULL, hInstance, NULL, nCmdShow);

	while (GetMessageW(&msg, NULL, 0, 0)) {
		DispatchMessageW(&msg);
	}
	return 0;
}

//====================================================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	HINSTANCE hInst;
	switch (uMsg)
	{
		case WM_GETMINMAXINFO:
		{
			MINMAXINFO* mmi = (MINMAXINFO*)lParam;
			mmi->ptMinTrackSize.x = 300;
			mmi->ptMinTrackSize.y = 200;
			mmi->ptMaxTrackSize.x = 600;
			mmi->ptMaxTrackSize.y = 400;
			return 0;
		}
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}


