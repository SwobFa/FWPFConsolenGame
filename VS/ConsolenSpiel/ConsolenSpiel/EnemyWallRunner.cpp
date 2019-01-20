#include "pch.h"
#include "EnemyWallRunner.h"
#include "MillisecondsHelper.h"


EnemyWallRunner::EnemyWallRunner(short const & currentX, short const & currentY, TextBuffer * textBuffer, long const & speed, DirectionEnum const & startDirection) : EnemyBase(currentX, currentY, textBuffer, speed, startDirection)
{
}


EnemyWallRunner::~EnemyWallRunner()
{
}

void EnemyWallRunner::Move()
{
	if ((get_milliseconds() - lastMoveMs >= speed || lastMoveMs == 0) && Health > 0)
	{
		MoveOneStep();

		lastMoveMs = get_milliseconds();
	}
}
