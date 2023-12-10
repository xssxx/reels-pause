#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

COLORREF getMouseColor() {
    POINT p;
    GetCursorPos(&p);

    HDC hdc = GetDC(NULL);
    COLORREF color = GetPixel(hdc, p.x, p.y);
    ReleaseDC(NULL, hdc);

    return color;
}

int main() {
    Sleep(1500);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

    COLORREF current = getMouseColor();
    COLORREF pixelColor;

    while (1) {
        pixelColor = getMouseColor();
        printf("%d\n", GetRValue(pixelColor));

        if (abs(GetRValue(pixelColor) - GetRValue(current)) > 4) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            break;
        }
    }

    return 0;
}
