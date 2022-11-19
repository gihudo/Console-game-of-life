#include "Console.h"

namespace Console
{
    namespace
    {
        short rows = 0;
        short columns = 0;

        int width = 0;
        int height = 0;

        void SetConsoleSize(int width, int height)
        {
            HWND console = GetConsoleWindow();
            RECT r;
            GetWindowRect(console, &r);
            MoveWindow(console, r.left, r.top, width, height, TRUE);
        }
        void FixConsoleSize()
        {
            DeleteMenu(GetSystemMenu(GetConsoleWindow(), false), SC_MINIMIZE, 0);
            DeleteMenu(GetSystemMenu(GetConsoleWindow(), false), SC_MAXIMIZE, 0);
            DeleteMenu(GetSystemMenu(GetConsoleWindow(), false), SC_SIZE, 0);
        }
        void HideCursor()
        {
            HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
            CONSOLE_CURSOR_INFO info;
            info.dwSize = 100;
            info.bVisible = FALSE;
            SetConsoleCursorInfo(consoleHandle, &info);
        }
        void RemoveScrollbar()
        {
            CONSOLE_SCREEN_BUFFER_INFO info;
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            GetConsoleScreenBufferInfo(handle, &info);
            COORD new_size =
            {
                info.srWindow.Right - info.srWindow.Left + 1,
                info.srWindow.Bottom - info.srWindow.Top + 1
            };
            SetConsoleScreenBufferSize(handle, new_size);
        }
        void SetFontSizeInPixels(int width, int height)
        {
            CONSOLE_FONT_INFOEX cfi;
            cfi.cbSize = sizeof(cfi);
            cfi.nFont = 0;
            cfi.dwFontSize.X = height;
            cfi.dwFontSize.Y = width;
            cfi.FontFamily = FF_DONTCARE;
            cfi.FontWeight = FW_NORMAL;
            SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
        }

    }

    short GetColumns() { return columns; }
    short GetRows() { return rows; }
    int GetWidth() { return width; }
    int GetHeight() { return height; }

    void SetConsoleTextColor(int colorId)
    {

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(hConsole, colorId);
    }

    void SetConsole(int _width, int _height, int resolution)
    {
        width = _width;
        height = _height;
        resolution = resolution > 0 ? resolution : 1;

        SetFontSizeInPixels(resolution + 5, resolution + 5);
        SetConsoleSize(width, height);
        FixConsoleSize();
        RemoveScrollbar();
        HideCursor();

        CONSOLE_SCREEN_BUFFER_INFO info;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
        columns = info.srWindow.Right - info.srWindow.Left + 1;
        rows = info.srWindow.Bottom - info.srWindow.Top + 1;
    }

    void GetConsolePos(int& x, int& y)
    {
        RECT rect = { NULL };
        if (GetWindowRect(GetConsoleWindow(), &rect))
        {
            x = rect.left;
            y = rect.top;
        }
    }
}
