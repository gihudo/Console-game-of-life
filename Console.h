#pragma once
#include <Windows.h>
#include <iostream>

class Console
{
public:
	static void SetConsole(int width, int height);
	
	static void SetConsoleTextColor(int l);

	static int GetRows();
	static int GetColumns();
private:
	static int rows;
	static int columns;

	static void RemoveScrollbar();
	static void FixConsoleSize();
	static void SetConsoleSize(int width, int height);
};
