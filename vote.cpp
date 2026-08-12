#include <iostream>
#include<fstream>
#include <Windows.h>
using namespace std;

int votes[2] = {0, 0};



LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    // Register the window class
    const char CLASS_NAME[] = "Sample Window Class";
    
    WNDCLASS wc = {};
    
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    
    RegisterClass(&wc);
    
    // Create the window
    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Employee of The Month",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
        NULL,
        NULL,
        hInstance,
        NULL
    );
    
    if (hwnd == NULL) {
        return 0;
    }
    
    // Show the window
    ShowWindow(hwnd, nShowCmd);
    
    // Run the message loop
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
   
    switch (uMsg) {
        case WM_DESTROY: {
            PostQuitMessage(0);
            return 0;
        }
        case WM_COMMAND: {
            if (LOWORD(wParam) == 1) {
                votes[0]++;
                MessageBox(NULL, "You have voted for Lion.", "Vote Recorded", MB_OK);




            }
            else if (LOWORD(wParam) == 2) {
                votes[1]++;
                MessageBox(NULL, "You have voted for Tiger.", "Vote Recorded", MB_OK);
            }
            else if (LOWORD(wParam) == 3) {
                char count[50];
                sprintf(count, "Lion: %d vote(s)\nTiger: %d vote(s)", votes[0], votes[1]);
                MessageBox(NULL, count, "Current Vote Count", MB_OK);
            }
            return 0;
        }
        case WM_CREATE: {
            // Create candidate 1 button
            HWND hwndButton1 = CreateWindow(
                "BUTTON",
                "LION",
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                50, 50, 100, 30,
                hwnd,
                (HMENU)1,
                (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
                NULL
            );
            
            // Create candidate 2 button
            HWND hwndButton2 = CreateWindow(
                "BUTTON",
                "TIGER",
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                200, 50, 100, 30,
                hwnd,
                (HMENU)2,
                (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
                NULL
            );
            
            // Create vote count button
            HWND hwndButton3 = CreateWindow(
                "BUTTON",
                "View Vote Count",
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                125, 100, 150, 30,
                hwnd,
                (HMENU)3,
                (HINSTANCE)
            GetWindowLong(hwnd, GWL_HINSTANCE),
            NULL
        );
        
        return 0;
    }
}

return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

