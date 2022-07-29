#pragma once
#include <Windows.h>

class Console
{
public:
	static void SetConsole(int width, int height, int resolution);
	static void SetConsoleTextColor(int l);

	static void GetConsolePos(int& x, int& y);

	static short GetRows();
	static short GetColumns();

	static int GetWidth();
	static int GetHeight();
private:
	static short rows;
	static short columns;

	static int Width;
	static int Height;

	static void SetFontSizeInPixels(int width, int height);
	static void HideCursor();
	static void RemoveScrollbar();
	static void FixConsoleSize();
	static void SetConsoleSize(int width, int height);
};
