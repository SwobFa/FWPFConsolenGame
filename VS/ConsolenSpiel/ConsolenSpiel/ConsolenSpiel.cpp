#include "pch.h"
#include <iostream>
#include <conio.h>
#include "TextBuffer.h"
#include <windows.h>
#include <fstream>

using namespace std;

const unsigned width = 51;
const unsigned height = 15;



const char player = 'P';

void SetNewPos(int input, unsigned * xPos, unsigned * yPos) {
	switch (input) {
		// w
	case 119:
		if (*yPos > 0)
			(*yPos)--;
		break;
		// a
	case 97:
		if (*xPos > 0)
			(*xPos)--;

		break;
		// s
	case 115:
		if (*yPos < height - 1)
			(*yPos)++;
		break;
		// d
	case 100:
		if (*xPos < width - 1)
			(*xPos)++;
		break;
	default:
		break;
	}
}

char * GetMapFromFile()
{
	std::ifstream in("map.txt");
	std::string contents((std::istreambuf_iterator<char>(in)),
	                     std::istreambuf_iterator<char>());

	char * map = new char[contents.length()];
	strcpy(map, contents.c_str());

	if (in.is_open())
		in.close();

	return map;
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{
	
	ShowConsoleCursor(false);

	char* map =GetMapFromFile();

	unsigned coinsCount = 0;
	unsigned currentXPos = 1;
	unsigned currentYPos = 1;
	int inputChar = 0;

	TextBuffer * tb = new TextBuffer(width, height, map);
	tb->SetChar(1, 1, player);

	while (inputChar != 27) {

		//std::system("cls");
		tb->Render();
		if (_kbhit())
		{
			inputChar = _getch();

			if (inputChar == 119 || inputChar == 97 || inputChar == 115 || inputChar == 100)
			{
				unsigned newXPos = currentXPos;
				unsigned newYPos = currentYPos;

				SetNewPos(inputChar, &newXPos, &newYPos);
				char test = tb->GetChar(newXPos, newYPos);
				if (test != 'x') {
					if (test == 'o')
						coinsCount++;
					tb->SetChar(currentXPos, currentYPos, ' ');
					currentXPos = newXPos;
					currentYPos = newYPos;
					tb->SetChar(currentXPos, currentYPos, player);
				}
			}
		}

		cout << endl << "Anzahl der gesammelten Coins: " << coinsCount;
	}

	return 0;
}
