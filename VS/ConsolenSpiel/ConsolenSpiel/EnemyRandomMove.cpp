#include "pch.h"
#include "EnemyRandomMove.h"


EnemyRandomMove::EnemyRandomMove(short currentX, short currentY, TextBuffer * textBuffer, short speed, DirectionEnum startDirection) : EnemyBase(currentX, currentY, textBuffer, speed, startDirection)
{
}


EnemyRandomMove::~EnemyRandomMove()
{
}


void EnemyRandomMove::Move()
{
	if (Health > 0) {
		ticks++;
		if (ticks == speed)
		{

			ChangeDirection();

			MoveOneStep();

			ticks = 0;
			moveCounter++;
		}
	}
}