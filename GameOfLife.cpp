#include "Console.h"
#include "GameOfLifeEngine.h"
#include "GameOfLife.h"
#include <functional>

#define headerheight 40 
#define scrollwidth 25

namespace GameOfLife 
{
    namespace
    {
        char Cell = '?';

        void DrawCells(GameOfLifeEngine& gameEngine)
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
    }

    void SetCell(char cell)
    {
        Cell = cell;
    }

    void FindCursorPos(short& x, short& y)
    {
        int ConsolePosX;
        int ConsolePosY;
        POINT CursorPos;

        Console::GetConsolePos(ConsolePosX, ConsolePosY);
        GetCursorPos(&CursorPos);

        if ((CursorPos.x > ConsolePosX && CursorPos.x < ConsolePosX + Console::GetWidth() - scrollwidth) &&
            (CursorPos.y > ConsolePosY + headerheight && CursorPos.y < ConsolePosY + Console::GetHeight()))
        {
            x = (CursorPos.x - ConsolePosX) / ((Console::GetWidth() - scrollwidth) / static_cast<double>(Console::GetColumns()));
            y = (CursorPos.y - ConsolePosY - headerheight) / ((Console::GetHeight() - headerheight) / static_cast<double>(Console::GetRows()));
        }
    }

    void Init()
    {
        GameOfLifeEngine gameEngine
        (
            Console::GetRows(),     //rows
            Console::GetColumns(), //columns
            1                     //density
        );

       std::thread drawFrame([](GameOfLifeEngine& gameEngine)
            {
                while (true)
                {
                    DrawCells(gameEngine);
                    gameEngine.NextGen();

                    short x;
                    short y;
                    FindCursorPos(x, y);
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
                    Console::SetConsoleTextColor(2);
                    std::cout << "@";
                    Console::SetConsoleTextColor(4);

                    Sleep(50);
                    SetConsoleTitleA(std::to_string(gameEngine.GetNumberOfGen()).c_str());
                }
            }, std::ref(gameEngine));
        std::thread addingCells([](GameOfLifeEngine& gameEngine)
            {
                while (true)
                {
                    short x;
                    short y;

                    if (GetAsyncKeyState(VK_SPACE))
                    {
                        FindCursorPos(x, y);
                        gameEngine.Add(x, y);
                    }
                    if (GetAsyncKeyState(VK_DELETE))
                    {
                        FindCursorPos(x, y);
                        gameEngine.Delete(x, y);
                    }
                }
            }, std::ref(gameEngine));
        drawFrame.join();
        addingCells.join();
    }
}