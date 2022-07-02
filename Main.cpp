#include "GameOfLife.h"
#include "Console.h"
#include <Windows.h>

int main()
{
    int width;
    int height;
    std::cin >> width >> height;

    Console::SetConsole(width, height);
    Console::SetConsoleTextColor(4);
    GameOfLife::Init();
}