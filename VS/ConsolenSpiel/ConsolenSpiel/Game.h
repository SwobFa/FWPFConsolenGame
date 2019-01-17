#ifndef GAME_H
#define GAME_H
#include "EnemyWallRunner.h"
#include "EnemyImmovable.h"
#include "EnemyRandomMove.h"
#include "Player.h"

class Game
{
	TextBuffer * tb;
	Player * player;
	EnemyRandomMove * enemy;
	EnemyImmovable * enemy2;
	EnemyWallRunner * enemy3;

	const short width = 51;
	const short height = 15;


	void MoveEnemy();
	void ClearBullets();
	void EnemyShoot();
	void MovePlayer(int input, Player * player);
	void ShowConsoleCursor(bool showFlag);
	void PrintStatus();
	bool ContinueGame();
	void ProcessInput(char inputChar);
public:
	Game();
	~Game();

	short ChooseMap();
	void StartGame(short mapNumber);

};

#endif
