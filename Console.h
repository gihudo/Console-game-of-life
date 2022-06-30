#pragma once
#include <Windows.h>
#include <iostream>

class Console
{
public:
	static void SetConsole(int width, int height);
	
	static void SetConsoleTextColor(int l);

	static short GetRows();
	static short GetColumns();
private:
	static short rows;
	static short columns;

	static void HideCursor();
	static void RemoveScrollbar();
	static void FixConsoleSize();
	static void SetConsoleSize(int width, int height);
};
