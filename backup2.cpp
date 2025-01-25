#define STRICT
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include "4k.h"


// Message handler:

LRESULT CALLBACK
WndProc (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CLOSE:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
}


// Initialization and shutdown:

bool
Initialize () {

    // no WinMain so get the module handle:
    g_hInstance = GetModuleHandle(NULL);

    // register the window class:
    WNDCLASS wc;

    wc.style         = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = g_hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = NULL;
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = WINDOW_TITLE;

    RegisterClass(&wc);

    // create the window:
    g_hWnd = CreateWindow(
        WINDOW_TITLE,                                             // class name
        WINDOW_TITLE,                                             // title
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, // style
        CW_USEDEFAULT, CW_USEDEFAULT,                             // position
        CW_USEDEFAULT, CW_USEDEFAULT,                             // size
        NULL,                                                     // no parent
        NULL,                                                     // no menu
        g_hInstance,                                              // instance
        NULL                                                      // no special
    );

    

    // setup double buffering:
    g_hDC = GetDC(g_hWnd);

    // colors used to draw the effect:
    return true;
}


// Window center:

#define CENTER_X (WINDOW_WIDTH / 2)
#define CENTER_Y (WINDOW_HEIGHT / 2)

int velocityX = 1;
int velocityY = 1;
int squareX = CENTER_X;
int squareY = CENTER_Y;



void
Update () {
    RECT clientRect;
    GetClientRect(g_hWnd, &clientRect);
    SetDCBrushColor(g_hDC, RGB(0, 0, 0));
    FillRect(g_hDC, &clientRect, (HBRUSH)GetStockObject(DC_BRUSH));

    // move the square:
    squareX += velocityX;
    squareY += velocityY;

    // bounce the square:
    if (squareX - 25 < clientRect.left || squareX + 25> clientRect.right) {
        velocityX = -velocityX;
    }
    if (squareY - 25 < clientRect.top || squareY + 25 > clientRect.bottom) {
        velocityY = -velocityY;
    }
    SetDCBrushColor(g_hDC, RGB(255, 255, 255));
    Rectangle(g_hDC,
              squareX - 25,
              squareY - 25,
              squareX + 25,
              squareY + 25);
}


void Loop() {
    MSG msg;
    DWORD lastTick = GetTickCount();
    while (true) {
        // Handle Windows messages
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) return;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // Update and render
        Update();

        // Frame timing
        DWORD currentTick = GetTickCount();
        DWORD elapsed = currentTick - lastTick;
        if (elapsed < 8) {
            Sleep(8 - elapsed);
        }
        lastTick = GetTickCount();
    }
}

void
EntryPoint () {
    Initialize();

    RECT rcClient, rcWindow;

    GetClientRect(g_hWnd, &rcClient);
    GetWindowRect(g_hWnd, &rcWindow);

    MoveWindow(g_hWnd,
               rcWindow.left,
               rcWindow.top,
               WINDOW_WIDTH + (rcWindow.right - rcWindow.left) - rcClient.right,
               WINDOW_HEIGHT + (rcWindow.bottom - rcWindow.top) - rcClient.bottom,
               FALSE);
    ShowWindow(g_hWnd, SW_SHOW);
    Loop();
}
