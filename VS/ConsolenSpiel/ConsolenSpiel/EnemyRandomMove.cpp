#include "pch.h"
#include "EnemyRandomMove.h"
#include "MillisecondsHelper.h"


EnemyRandomMove::EnemyRandomMove(short const & currentX, short const & currentY, TextBuffer * textBuffer, long const & speed, DirectionEnum const & startDirection) : EnemyBase(currentX, currentY, textBuffer, speed, startDirection)
{
}


EnemyRandomMove::~EnemyRandomMove()
{
}


void EnemyRandomMove::Move()
{
	if ((get_milliseconds() - lastMoveMs >= speed || lastMoveMs == 0) && Health > 0)
	{
		if (moveCounter % 10 == 0)
		{
			direction = GetRandomDirection();
			moveCounter = 0;
		}

		MoveOneStep();

		moveCounter++;
		lastMoveMs = get_milliseconds();
	}
}