#include "Console.h"
#include "Start.h"

void Start::Init()
{
    while (true)
    {
        Frame(Console::GetRows(), Console::GetColumns());
        Sleep(10);
    }
}

void Start::Frame(int rows, int columns)
{
    char* frame = new char[rows * columns + 1];
    frame[rows * columns] = '\0';

    for (int i = 0; i < columns; i++)
    {
        frame[i] = '-';
    }

    for (int i = 1; i < rows - 1; i++)
    {
        frame[i * columns] = '|';
        for (int j = 1; j < columns; j++)
        {
            frame[i * columns + j] = ' ';
        }
        frame[i * columns + columns - 1] = '|';
    }

    for (int i = 0; i < columns; i++)
    {
        frame[(rows - 1) * columns + i] = '-';
    }

    printf(frame);
}