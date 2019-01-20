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

	void MoveEnemy();
	void ClearBullets();
	void EnemyShoot();
	void MovePlayer(int const & input, Player * player);
	void ShowConsoleCursor(bool const & showFlag);
	void PrintStatus();
	bool ContinueGame();
	void ProcessInput(char const & inputChar);
public:
	Game();
	~Game();

	short ChooseMap();
	void StartGame(short const & mapNumber);

};

#endif
