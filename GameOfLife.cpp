#include "Console.h"
#include "GameOfLifeEngine.h"
#include "GameOfLife.h"
#include <conio.h>

void GameOfLife::Init()
{
    GameOfLifeEngine gameEngine
    (
        Console::GetRows(),     //rows
        Console::GetColumns(), //columns
        15                    //density
    );

    gameEngine.NextGen();
    while (true)
    {
        DrawCells(gameEngine);
        DrawFrame(Console::GetRows(), Console::GetColumns());

        Sleep(50);

        SetConsoleTitleA(std::to_string(gameEngine.GetNumberOfGen()).c_str());
        gameEngine.NextGen();
      
        if (GetAsyncKeyState(VK_SPACE))
            for (int i = 0; i < 500 ; i++)
            {
                int x;
                int y;
                Console::GetConsolePos(x, y);

                POINT p;
                GetCursorPos(&p);
                SetConsoleTitleA((std::to_string(p.x) + ' ' + std::to_string(p.y) + ' ' + std::to_string(x) + ' ' + std::to_string(y)).c_str());

                if ((p.x > x && p.x < x + 1280 - 25) && (p.y > y + 30 && p.y < y + 720))
                    gameEngine.Add(p.x, p.y, x, y);
            }
        
    }
}

void GameOfLife::SetCell(char cell)
{
    GameOfLife::Cell = cell;
}

char GameOfLife::Cell = '?';

void GameOfLife::DrawCells(GameOfLifeEngine &gameEngine)
{
    auto field = gameEngine.GetCurrentGen();
    char* cells = new char[(Console::GetRows()) * (Console::GetColumns()) + 1];
    cells[Console::GetRows() * Console::GetColumns()] = '\0';
    for (int y = 0; y < field.size(); y++)
    {
        for (int x = 0; x < field[y].size(); x++)
            cells[y * field[y].size() + x] = field[y][x] ? Cell : ' ';
    }
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    printf(cells);
    delete[] cells;
}

void GameOfLife::DrawFrame(int rows, int columns)
{
    std::string horizontal = "";
    std::string vertical = "|";

    for (int i = 0; i < columns; i++)
    {
        horizontal += '-';
    }

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
    std::cout << horizontal;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, static_cast<short>(Console::GetRows() - 1)});
    std::cout << horizontal;


    for (short i = 1; i < Console::GetRows() - 1; i++)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, i });
        std::cout << vertical;
    }

    for (short i = 1; i < Console::GetRows() - 1 ; i++)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(Console::GetColumns() - 1), i});
        std::cout << vertical;
    }
}