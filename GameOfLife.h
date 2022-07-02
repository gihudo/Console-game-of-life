#pragma once
#include "GameOfLifeEngine.h"

class GameOfLife
{
public:
    static void Init();

    static char Cell;
private:
    static void DrawCells(GameOfLifeEngine &gameEngine);
    static void DrawFrame(int rows, int columns);
};

