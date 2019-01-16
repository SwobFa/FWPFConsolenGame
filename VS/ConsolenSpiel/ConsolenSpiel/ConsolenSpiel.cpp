#include "pch.h"
#include <iostream>
#include <conio.h>
#include "TextBuffer.h"
#include <windows.h>
#include <fstream>
#include "Player.h"
#include "EnemyBase.h"
#include "EnemyRandomMove.h"
#include "EnemyImmovable.h"
#include "EnemyWallRunner.h"

using namespace std;

const short width = 51;
const short height = 15;
TextBuffer * tb;
Player * player;
EnemyRandomMove * enemy;
EnemyImmovable * enemy2;
EnemyWallRunner * enemy3;

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

void ClearBullets()
{
	player->ClearBullets();
	enemy->ClearBullets();
	enemy2->ClearBullets();
	enemy3->ClearBullets();
}

void EnemyShoot()
{
	COORD hitCoords = enemy->Shoot();
	player->Hit(hitCoords);

	COORD hitCoords2 = enemy2->Shoot();
	player->Hit(hitCoords2);

	COORD hitCoords3 = enemy3->Shoot();
	player->Hit(hitCoords3);
}

void MoveEnemy()
{
	enemy->Move();
	enemy2->Move();
	enemy3->Move();
}

void StartGame(short mapNumber)
{
	ShowConsoleCursor(false);

	char* map = GetMapFromFile();

	int inputChar = 0;

	tb = new TextBuffer(width, height, map);
	player = new Player(1, 1, tb);
	enemy = new EnemyRandomMove(48, 12, tb, 100, DirectionEnum::South);
	enemy2 = new EnemyImmovable(4, 9, tb, 200, DirectionEnum::North);
	enemy3 = new EnemyWallRunner(45, 2, tb, 100, DirectionEnum::West);

	while (player->Health > 0) {

		tb->Render();

		MoveEnemy();
		ClearBullets();
		EnemyShoot();


		if (_kbhit())
		{
			inputChar = _getch();

			if (inputChar == 119 || inputChar == 97 || inputChar == 115 || inputChar == 100)
			{
				MovePlayer(inputChar, player);
			}
			else if (inputChar == 32)
			{
				COORD rtf = player->Shoot();

				enemy->Hit(rtf);
				enemy2->Hit(rtf);
				enemy3->Hit(rtf);
			}

		}
		cout << endl << "Anzahl der gesammelten Coins: " << player->CoinsCount;
		cout << endl << "Leben: " << player->Health;
	}

	std::system("cls");
}

short MapSelection()
{
	cout << "Map auswählen: ";
	std::system("cls");
	return 1;
}

int main()
{
	while (true) {
		short mapNumber = MapSelection();
		StartGame(mapNumber);
	}

	return 0;
}
