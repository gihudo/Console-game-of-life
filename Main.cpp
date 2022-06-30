#include "GameOfLife.h"
#include "Console.h"

int main()
{
    Console::SetConsole(500, 500);
    Console::SetConsoleTextColor(2);
    GameOfLife::Init();
}