#include "pch.h"
#include "EnemyWallRunner.h"


EnemyWallRunner::EnemyWallRunner(short currentX, short currentY, TextBuffer * textBuffer, short speed, DirectionEnum startDirection) : EnemyBase(currentX, currentY, textBuffer, speed, startDirection)
{
}


EnemyWallRunner::~EnemyWallRunner()
{
}

void EnemyWallRunner::Move()
{
	if (Health > 0) {
		ticks++;
		if (ticks == speed)
		{

			MoveOneStep();

			ticks = 0;
			moveCounter++;
		}
	}
}
