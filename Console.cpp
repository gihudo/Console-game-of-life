#include "Console.h"

short Console::rows = 0;
short Console::columns = 0;

int Console::Width = 0;
int Console::Height = 0;

void Console::SetConsole(int width, int height, int resolution)
{
    Console::Width = width;
    Console::Height = height;
    resolution = resolution > 0 ? resolution : 1;

    SetFontSizeInPixels(resolution + 5, resolution + 5);
    SetConsoleSize(width, height);
    FixConsoleSize();
    RemoveScrollbar();
    HideCursor();

    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    Console::columns = info.srWindow.Right - info.srWindow.Left + 1;
    Console::rows = info.srWindow.Bottom - info.srWindow.Top + 1;
}

void Console::GetConsolePos(int& x, int& y)
{
    RECT rect = { NULL };
    if (GetWindowRect(GetConsoleWindow(), &rect))
    {
        x = rect.left;
        y = rect.top;
    }
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
    return columns;
}

short Console::GetRows()
{
    return rows;
}

int Console::GetWidth()
{
    return Width;
}

int Console::GetHeight()
{
    return Height;
}

void Console::SetConsoleTextColor(int colorId)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, colorId);
}

void Console::SetFontSizeInPixels(int width, int height)
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