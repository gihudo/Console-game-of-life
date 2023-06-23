#include "GameOfLife.h"
#include "Console.h"

int main()
{
    Console::SetConsole(800, 800, 1);
    Console::SetConsoleTextColor(4); //4 - red
    GameOfLife::SetCell('#');

    GameOfLife::Init();
}