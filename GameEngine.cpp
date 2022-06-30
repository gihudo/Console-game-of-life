#include "GameEngine.h"
#include <time.h>

GameEngine::GameEngine(int rows, int cols, int density): ROWS(rows), COLS(cols)
{
	srand(time(NULL));

	field.resize(rows);
	for (int i = 0; i < rows; i++)
		field[i].resize(cols);

	for (int x = 0; x < rows; x++)
	{
		for (int y = 0; y < cols; y++)
		{
			field[x][y] = rand() % density == 0;
		}
	}
}

int GameEngine::CountNeighbours(int x, int y)
{
	int count = 0;

	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			int col = (x + j + COLS) % COLS;
			int row = (y + i + ROWS) % ROWS;

			bool isSelf = col == x && row == y;
			bool hasCell = field[row][col];

			if (!isSelf && hasCell)
				count++;
		}
	}

	return count;
}

void GameEngine::NextGen()
{
	std::vector<std::vector<bool>> newField;

	newField.resize(field.size());
	for (int i = 0; i < field.size(); i++)
		newField[i].resize(field[i].size());

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)		
		{
			int neighbours = CountNeighbours(j, i);
			bool hasLife = field[i][j];

			if (!hasLife && neighbours == 3)
				newField[i][j] = true;
			else if (hasLife && (neighbours < 2 || neighbours > 3))
				newField[i][j] = false;
			else newField[i][j] = field[i][j];
		}
	}
	NumberOfGen++;
	field = newField;
}

std::vector<std::vector<bool>> GameEngine::GetCurrentGen()
{
	return field;
}

int GameEngine::GetNumberOfGen()
{
	return NumberOfGen;
}
