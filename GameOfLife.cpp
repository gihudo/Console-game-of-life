#include "Console.h"
#include "GameOfLifeEngine.h"
#include "GameOfLife.h"

void GameOfLife::Init()
{
    GameOfLifeEngine gameEngine
    (
        Console::GetRows(),     //rows
        Console::GetColumns(), //columns
        10                    //density
    );
    while (true)
    {
        DrawCells(gameEngine);
        DrawFrame(Console::GetRows(), Console::GetColumns());
        //Sleep(50);
        gameEngine.NextGen();
    }
}

char GameOfLife::Cell = '.';

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