#include "Console.h"
#include <winuser.h>

short Console::rows = 30;
short Console::columns = 120;

void Console::SetConsole(int width, int height)
{
    SetFontSize(20 - width / 200);
    SetConsoleSize(width, height);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    Console::columns = info.srWindow.Right - info.srWindow.Left + 1;;
    Console::rows = info.srWindow.Bottom - info.srWindow.Top + 1;;
    FixConsoleSize();
    RemoveScrollbar();
    HideCursor();
}

void Console::SetConsoleSize(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void Console::FixConsoleSize()
{
    DeleteMenu(GetSystemMenu(GetConsoleWindow(), false), SC_MINIMIZE, 0);
    DeleteMenu(GetSystemMenu(GetConsoleWindow(), false), SC_MAXIMIZE, 0);
    DeleteMenu(GetSystemMenu(GetConsoleWindow(), false), SC_SIZE, 0);
}

void Console::HideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void Console::RemoveScrollbar()
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

short Console::GetColumns()
{
    if (&columns == nullptr)
        return 0;

    return columns;
}

short Console::GetRows()
{
    if (&rows == nullptr)
        return 0;

    return rows;
}

void Console::SetConsoleTextColor(int l)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, l);
}

void Console::SetFontSize(int width, int height)
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