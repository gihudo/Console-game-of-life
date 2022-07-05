#include "GameOfLife.h"
#include "Console.h"
#include <Windows.h>


int main()
{
    int width;
    int height;
    int resolution;
    std::cout << "width && height in pixels: ";
    std::cin >> width >> height;
    std::cout << "resolution(higher -> smaller cells): ";
    std::cin >> resolution;

    Console::SetConsole(width, height, resolution);
    Console::SetConsoleTextColor(4);
    GameOfLife::SetCell('#');
    GameOfLife::Init();
}