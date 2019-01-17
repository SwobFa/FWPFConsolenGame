#include "pch.h"
#include "Game.h"
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
#include "MapReader.h"

using namespace std;

Game::Game()
{
}


Game::~Game()
{
	tb->~TextBuffer();
	player->~Player();
	enemy->~EnemyRandomMove();
	enemy2->~EnemyImmovable();
	enemy3->~EnemyWallRunner();
}

void Game::StartGame(short mapNumber)
{
	ShowConsoleCursor(false);

	char* map = GetMapFromFile(mapNumber);

	int inputChar = 0;

	tb = new TextBuffer(width, height, map);
	player = new Player(1, 1, tb);
	enemy = new EnemyRandomMove(48, 12, tb, 100, DirectionEnum::South);
	enemy2 = new EnemyImmovable(4, 9, tb, 200, DirectionEnum::North);
	enemy3 = new EnemyWallRunner(45, 2, tb, 100, DirectionEnum::West);

	while (inputChar != 27) {

		tb->Render();

		MoveEnemy();
		ClearBullets();
		EnemyShoot();


		if (_kbhit())
		{
			inputChar = _getch();
			ProcessInput(inputChar);
		}

		PrintStatus();

		if (!ContinueGame())
			break;



	}
}

void Game::ProcessInput(char inputChar)
{
	

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
	else if (inputChar == 27)
	{

	}
}


void Game::PrintStatus()
{
	cout << endl << "Anzahl der gesammelten Coins: " << player->CoinsCount;
	cout << endl << "Leben: " << player->Health;
}

bool Game::ContinueGame()
{
	if (player->Health == 0)
	{
		std::system("cls");
		cout << "Game Over" << endl;
		Sleep(5000);
		return false;
	}
	else if (player->CoinsCount == 5)
	{
		std::system("cls");
		cout << "Congratulation!!!!!!!" << endl << "All Coins collected" << endl;
		Sleep(5000);
		return false;
	}
	return true;
}




void Game::MovePlayer(int input, Player * player) {
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

short Game::ChooseMap()
{
	std::system("cls");
	short mapNumber;
	stringstream ss;
	ss << "Choose a map between 1 and " << GetMapCount() << ":" << endl;
	cout << ss.str();
	cin >> mapNumber;
	return  mapNumber;
}


void Game::ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void Game::ClearBullets()
{
	player->ClearBullets();
	enemy->ClearBullets();
	enemy2->ClearBullets();
	enemy3->ClearBullets();
}

void Game::EnemyShoot()
{
	COORD hitCoords = enemy->Shoot();
	player->Hit(hitCoords);

	COORD hitCoords2 = enemy2->Shoot();
	player->Hit(hitCoords2);

	COORD hitCoords3 = enemy3->Shoot();
	player->Hit(hitCoords3);
}

void Game::MoveEnemy()
{
	enemy->Move();
	enemy2->Move();
	enemy3->Move();
}


