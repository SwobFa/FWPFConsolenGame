#include "pch.h"
#include <iostream>
#include <conio.h>
#include "TextBuffer.h"
#include <windows.h>
#include <fstream>
#include "Player.h"
#include "Enemy.h"

using namespace std;

const unsigned width = 51;
const unsigned height = 15;

void MovePlayer(int input, Player * player) {
	switch (input) {
		// w
	case 119:
		player->Move(DirectionEnum::North);
		break;
		// a
	case 97:
		player->Move(DirectionEnum::West);
		break;
		// s
	case 115:
		player->Move(DirectionEnum::South);
		break;
		// d
	case 100:
		player->Move(DirectionEnum::East);
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
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{
	ShowConsoleCursor(false);

	char* map =GetMapFromFile();

	int inputChar = 0;

	TextBuffer * tb = new TextBuffer(width, height, map);
	Player * player = new Player(1, 1, tb);
	Enemy * enemy = new Enemy(48, 12, tb, 100, DirectionEnum::South);
	Enemy * enemy2 = new Enemy(4, 9, tb, 200, DirectionEnum::North);
	Enemy * enemy3 = new Enemy(45, 2, tb, 50, DirectionEnum::West);

	while (inputChar != 27) {

		//std::system("cls");
		tb->Render();

		enemy->Move();
		enemy2->Move();
		enemy3->Move();

		if (_kbhit())
		{
			inputChar = _getch();

			if (inputChar == 119 || inputChar == 97 || inputChar == 115 || inputChar == 100)
			{
				MovePlayer(inputChar, player);
			}
		}
		cout << endl << "Anzahl der gesammelten Coins: " << player->CoinsCount;
	}

	return 0;
}
