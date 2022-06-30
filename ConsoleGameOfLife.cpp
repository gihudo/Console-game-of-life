#include <iostream>
#include <conio.h>
#include "Start.h"
#include "Console.h"

int main()
{
    Console::SetConsole(400, 400);
    Console::SetConsoleTextColor(2);
    Start::Init();
}