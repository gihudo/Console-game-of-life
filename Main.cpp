#include "GameOfLife.h"
#include "Console.h"

int main()
{
    int width;
    int height;
    std::cin >> width >> height;

    Console::SetConsole(width, height);
    Console::SetConsoleTextColor(2);
    GameOfLife::Init();
}