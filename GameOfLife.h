#pragma once
#include "GameEngine.h"

class GameOfLife
{
public:
    static void Init();

    static char Cell;
private:
    static void DrawCells(GameEngine &gameEngine);
    static void DrawFrame(int rows, int columns);
};

