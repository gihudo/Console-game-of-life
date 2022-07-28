#include "Console.h"
#include "GameOfLifeEngine.h"
#include "GameOfLife.h"

#define headerheight 40 
#define scrollwidth 25



void GameOfLife::Init()
{
    GameOfLifeEngine gameEngine
    (
        Console::GetRows(),     //rows
        Console::GetColumns(), //columns
        1                    //density
    );

    std::thread drawFrame([](GameOfLifeEngine &gameEngine)
        {
            while (true)
            {
                DrawCells(gameEngine);
                DrawFrame(Console::GetRows(), Console::GetColumns());
                gameEngine.NextGen();

                Sleep(100);
                SetConsoleTitleA(std::to_string(gameEngine.GetNumberOfGen()).c_str());
            }
        }, std::ref(gameEngine));

    std::thread addingCells([](GameOfLifeEngine& gameEngine)
        {
            while (true)
            {
                if (GetAsyncKeyState(VK_SPACE))
                {
                    int ConsolePosX;
                    int ConsolePosY;
                    POINT CursorPos;

                    int x;
                    int y;

                    Console::GetConsolePos(ConsolePosX, ConsolePosY);
                    GetCursorPos(&CursorPos);

                    if ((CursorPos.x > ConsolePosX && CursorPos.x < ConsolePosX + Console::GetWidth() - scrollwidth) &&
                        (CursorPos.y > ConsolePosY + headerheight && CursorPos.y < ConsolePosY + Console::GetHeight()))
                    {
                        x = (CursorPos.x - ConsolePosX) / ((Console::GetWidth() - scrollwidth) / static_cast<double>(Console::GetColumns()));
                        y = (CursorPos.y - ConsolePosY - headerheight) / ((Console::GetHeight() - headerheight) / static_cast<double>(Console::GetRows()));
                        gameEngine.Add(x, y);
                    }    
                }
            }
        }, std::ref(gameEngine));
    drawFrame.join();
    addingCells.join();
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
    char vertical = '|';

    for (int i = 0; i < columns; i++)
    {
        horizontal += '-';
    }

    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, static_cast<short>(Console::GetRows())});
    std::cout << horizontal;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
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