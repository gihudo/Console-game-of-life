#pragma once
#include <Windows.h>

namespace Console
{
	void SetConsole(int width, int height, int resolution);
	void SetConsoleTextColor(int l);

	void GetConsolePos(int& x, int& y);

	short GetRows();
	short GetColumns();

	int GetWidth();
	int GetHeight();
}
