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
#include "AppConstants.h"

using namespace std;

Game::Game()
{
}


Game::~Game()
{
	delete enemy3;
	delete enemy2;
	delete enemy;
	delete player;
	delete tb;
}

void Game::StartGame(short const & mapNumber)
{
	ShowConsoleCursor(false);

	char * map = GetMapFromFile(mapNumber);

	tb = new TextBuffer(AppConstants::MAPWIDTH, AppConstants::MAPHEIGHT, map);
	player = new Player(1, 1, tb);
	enemy = new EnemyRandomMove(48, 12, tb, 100, DirectionEnum::South);
	enemy2 = new EnemyImmovable(4, 9, tb, 200, DirectionEnum::North);
	enemy3 = new EnemyWallRunner(45, 2, tb, 100, DirectionEnum::West);

	int inputChar = 0;

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

void Game::ProcessInput(char const & inputChar)
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
		Sleep(3000);
		return false;
	}
	else if (player->CoinsCount == 5)
	{
		std::system("cls");
		cout << "Congratulation!!!!!!!" << endl << "All Coins collected" << endl;
		Sleep(3000);
		return false;
	}
	return true;
}


void Game::MovePlayer(int const & input, Player * player) {
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
	while (true)
	{
		std::system("cls");
		short mapNumber;
		short availableMaps = GetMapCount();

		stringstream ss;
		ss << "Choose a map between 1 and " << availableMaps << ":" << endl;
		cout << ss.str();
		cin >> mapNumber;
		if (mapNumber <= availableMaps && mapNumber > 0)
			return  mapNumber;
	}
	return 1;
}


void Game::ShowConsoleCursor(bool const & showFlag)
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
	player->Hit(enemy->Shoot());
	player->Hit(enemy2->Shoot());
	player->Hit(enemy3->Shoot());
}

void Game::MoveEnemy()
{
	enemy->Move();
	enemy2->Move();
	enemy3->Move();
}


