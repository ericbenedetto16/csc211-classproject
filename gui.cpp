#include <windows.h>
#include <iostream>
#include <cmath>
#include <tchar.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>

using namespace std;

// Definitions - Easier to know which control affects which value.
#define SLOPE_MENU_NEW 1
#define SLOPE_MENU_ONE 2
#define SLOPE_MENU_TWO 3
#define SLOPE_MENU_THREE 4
#define SLOPE_MENU_FOUR 5
#define SLOPE_MENU_EXIT 6
#define SLOPE_INFO 7
#define SLOPE_SHAPE_INFO 8

// Start of GUI - Console Application // 

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

void AddMenus(HWND);
void AddControls(HWND);

// Handlers
HMENU hMenu;
HWND hEdit;
HWND hSlopeInfoOne, hSlopeInfoTwo, hSlopeInfoThree, hSlopeInfoFour, hSlopeShape, hOutput;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{


	std::wcout.clear();
	std::cout.clear();
	std::wcerr.clear();
	std::cerr.clear();
	std::wcin.clear();
	std::cin.clear();
	WNDCLASSW wc = { 0 };
	wc.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(204, 255, 255)));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"myWindowClass";
	wc.lpfnWndProc = WindowProcedure; // Takes care of all of the messages for our application.

	// If the registration fails and windows creation procedure fails.
	if (!RegisterClassW(&wc))
		return -1;

	CreateWindowW(L"myWindowClass", L"CSC 211's Slope Calculator", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 200, 100, 1080, 1920, NULL, NULL, NULL, NULL);

	MSG msg = { 0 };

	// Message loop - Without the loop, the application automatically closes.
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}



LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg) {
	case WM_COMMAND:
		switch (wp) {
		case SLOPE_MENU_EXIT:
			MessageBeep(MB_OK);
			DestroyWindow(hWnd);
			break;
		case SLOPE_MENU_NEW:
			MessageBeep(MB_ICONINFORMATION);
			break;
		case SLOPE_MENU_ONE:
			wchar_t text[100];

			GetWindowTextW(hEdit, text, 100);
			SetWindowTextW(hWnd, L"Slope One");
			char slopeInfo, out;
			SetWindowText(hOutput, TEXT("This is the information for slope one:\r\n Values retrieved: 10, 2, and 6. \r\nValues retrieved: 20, 4, and -8."));
			break;
		case SLOPE_MENU_TWO:
			GetWindowTextW(hEdit, text, 100);
			SetWindowTextW(hWnd, L"Slope Two");
			SetWindowText(hOutput, TEXT("This is the information for slope two:\r\n Values retrieved: 3, 1, and -4. \r\nValues retrieved: -14, 2, and 0."));
			break;
		case SLOPE_MENU_THREE:
			GetWindowTextW(hEdit, text, 100);
			SetWindowTextW(hWnd, L"Slope Three");
			SetWindowText(hOutput, TEXT("This is the information for slope three:\r\n Values retrieved: -4, 2, and -2. \r\nValues retrieved: -.5, .25, and -.75."));
			break;
		case SLOPE_MENU_FOUR:
			GetWindowTextW(hEdit, text, 100);
			SetWindowTextW(hWnd, L"Slope Four");
			SetWindowText(hOutput, TEXT("This is the information for slope four:\r\n Values retrieved: 6, 3, and 27. \r\nValues retrieved: 10, 5, and 25."));
			break;
		case SLOPE_SHAPE_INFO:
			GetWindowTextW(hEdit, text, 100);
			SetWindowTextW(hWnd, L"Mystery Shape");
			SetWindowText(hOutput, TEXT("The mystery shape is a parallelogram!"));
			break;
		}
	case WM_CREATE:
		AddMenus(hWnd);
		AddControls(hWnd);
		break;
	case WM_DESTROY:
		// This makes the Get function return false.
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcW(hWnd, msg, wp, lp);
	}
}

void AddMenus(HWND hWnd) {

	hMenu = CreateMenu();
	HMENU hSlopesMenu = CreateMenu();
	HMENU hSubMenu = CreateMenu();

	AppendMenu(hSubMenu, MF_STRING, SLOPE_MENU_ONE, "Slope One");
	AppendMenu(hSubMenu, MF_STRING, SLOPE_MENU_TWO, "Slope Two");
	AppendMenu(hSubMenu, MF_STRING, SLOPE_MENU_THREE, "Slope Three");
	AppendMenu(hSubMenu, MF_STRING, SLOPE_MENU_FOUR, "Slope Four");

	AppendMenu(hSlopesMenu, MF_STRING, SLOPE_MENU_NEW, "New");
	AppendMenu(hSlopesMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hSlopesMenu, MF_POPUP, (UINT_PTR)hSubMenu, "Slopes");
	AppendMenu(hSlopesMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hSlopesMenu, MF_STRING, SLOPE_MENU_EXIT, "Exit");

	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hSlopesMenu, "Slopes Menu");
	AppendMenu(hMenu, MF_STRING, NULL, "|");
	AppendMenu(hMenu, MF_STRING, 2, "Something");

	SetMenu(hWnd, hMenu);
}

void AddControls(HWND hWnd) {
	CreateWindowW(L"Static", L"-- Computer Science 211 - Slope Calculator -- ", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | ES_CENTER | WS_EX_LAYERED, 100, 50, 600, 200, hWnd, NULL, NULL, NULL);
	CreateWindowW(L"Static", L"-- Which slope would you like to view? -- ", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | ES_CENTER, 100, 102, 600, 50, hWnd, NULL, NULL, NULL);
	hSlopeInfoOne = CreateWindowW(L"Button", L"-- Slope: One -- ", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | ES_CENTER, 100, 154, 300, 50, hWnd, (HMENU)SLOPE_MENU_ONE, NULL, NULL);
	hSlopeInfoTwo = CreateWindowW(L"Button", L"-- Slope: Two -- ", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | ES_CENTER, 400, 154, 300, 50, hWnd, (HMENU)SLOPE_MENU_TWO, NULL, NULL);
	hSlopeInfoThree = CreateWindowW(L"Button", L"-- Slope: Three -- ", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | ES_CENTER, 100, 206, 300, 50, hWnd, (HMENU)SLOPE_MENU_THREE, NULL, NULL);
	hSlopeInfoFour = CreateWindowW(L"Button", L"-- Slope: Four -- ", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | ES_CENTER, 400, 206, 300, 50, hWnd, (HMENU)SLOPE_MENU_FOUR, NULL, NULL, NULL);
	hSlopeShape = CreateWindowW(L"Button", L"-- Mystery Shape -- ", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | ES_CENTER, 100, 258, 600, 50, hWnd, (HMENU)SLOPE_SHAPE_INFO, NULL, NULL, NULL);
	hOutput = CreateWindowW(L"EDIT", L"Slope Information:  ", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER | ES_MULTILINE | ES_AUTOHSCROLL | ES_CENTER, 100, 310, 600, 200, hWnd, NULL, NULL, NULL);
}

// End of GUI - Console Application //


