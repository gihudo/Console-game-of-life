#include "Console.h"
#include "GameEngine.h"
#include "GameOfLife.h"

void GameOfLife::Init()
{
    GameEngine gameEngine
    (
        Console::GetRows() - 2,     //rows
        Console::GetColumns() - 2, //columns
        3                         //density
    );

    while (true)
    {
        DrawCells(gameEngine);
        DrawFrame(Console::GetRows(), Console::GetColumns());
        Sleep(300);
        gameEngine.NextGen();
    }
}

char GameOfLife::Cell = ',';

void GameOfLife::DrawCells(GameEngine &gameEngine)
{
    auto field = gameEngine.GetCurrentGen();
    char* cells = new char[(Console::GetRows()) * (Console::GetColumns()) + 1];
    cells[(Console::GetRows() - 2) * (Console::GetColumns() - 2)] = '\0';
    for (int y = 0; y < field.size(); y++)
    {
        for (int x = 0; x < field[y].size(); x++)
            cells[y * field[y].size() + x] = field[y][x] ? Cell : ' ';
    }
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 1, 1});
    printf(cells);
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
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, Console::GetRows() - 1});
    std::cout << horizontal;


    for (short i = 1; i < Console::GetRows() - 1; i++)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, i });
        std::cout << vertical;
    }

    for (short i = 1; i < Console::GetRows() - 1 ; i++)
    {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { Console::GetColumns() - 1, i});
        std::cout << vertical;
    }
}