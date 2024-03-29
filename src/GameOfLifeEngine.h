#pragma once
#include <vector>
#include <time.h>

class GameOfLifeEngine
{
public:
	GameOfLifeEngine(int rows, int cols, int density);

	void NextGen();
	int GetNumberOfGen();
	void Add(int x, int y);
	void Delete(int x, int y);

	std::vector<std::vector<bool>> GetCurrentGen();
private:
	std::vector<std::vector<bool>> field;
	const int ROWS;
	const int COLS;
	unsigned int NumberOfGen = 0;

	int CountNeighbours(int x, int y);
};