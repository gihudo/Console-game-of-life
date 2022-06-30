#include "Console.h"
#include <winuser.h>

int Console::columns = 120;
int Console::rows = 30;

void Console::SetConsoleTextColor(int l)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, l);
}

void Console::SetConsole(int width, int height)
{
    SetConsoleSize(width, height);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    Console::columns = info.srWindow.Right - info.srWindow.Left + 1;;
    Console::rows = info.srWindow.Bottom - info.srWindow.Top + 1;;
    FixConsoleSize();
    RemoveScrollbar();
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

int Console::GetColumns()
{
    if (&columns == nullptr)
        return 0;

    return columns;
}

int Console::GetRows()
{
    if (&rows == nullptr)
        return 0;

    return rows;
}