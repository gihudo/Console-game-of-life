#pragma once
#include <vector>

class GameEngine
{
public:
	GameEngine(int rows, int cols, int density);

	void NextGen();
	int GetNumberOfGen();
	
	std::vector<std::vector<bool>> GetCurrentGen();
private:
	std::vector<std::vector<bool>> field;
	const int ROWS;
	const int COLS;
	unsigned int NumberOfGen = 0;

	int CountNeighbours(int x, int y);
};

