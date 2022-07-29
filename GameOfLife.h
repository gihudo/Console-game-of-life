#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <thread>
#include <functional>

#include "GameOfLifeEngine.h"

class GameOfLife
{
public:
    static void Init();
    static void SetCell(char cell);
private:
    static char Cell;

    static void FindCursorPos(short &x, short &y);
    static void DrawCells(GameOfLifeEngine &gameEngine);
    static void DrawFrame(int rows, int columns);
};

