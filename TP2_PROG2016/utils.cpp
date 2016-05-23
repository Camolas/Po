#include "utils.h"
#include<Windows.h>
#include<iostream>
#include<string>

void trimSpaces(string &str)
{
	while (str.front() == ' ')
		str.erase(str.begin());

	while (str.back() == ' ')
		str.erase(str.end() - 1);
}

void clearScreen(){

	COORD coordScreen = { 0, 0 };
	unsigned long cCharsWritten;
	unsigned long dwConSize;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(hCon, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	FillConsoleOutputCharacter(hCon, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hCon, &csbi);
	FillConsoleOutputAttribute(hCon, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);

	SetConsoleCursorPosition(hCon, coordScreen);
}


unsigned short int leUnsignedShortInt(unsigned short int min, unsigned short int  max){

  // A IMPLEMENTAR
	return 0;
}


int leInteiro(int min, int max){

  // A IMPLEMENTAR
	return 0;
}
