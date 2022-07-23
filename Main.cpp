#include "GameOfLife.h"
#include "Console.h"

int main()
{
    int width;
    int height;
    int resolution;
    std::cout << "width && height in pixels: ";
    std::cin >> width >> height;
    std::cout << "resolution(higher -> bigger cells): ";
    std::cin >> resolution;

    Console::SetConsole(width, height, resolution);
    Console::SetConsoleTextColor(4);
    GameOfLife::SetCell('#');
    GameOfLife::Init();
}