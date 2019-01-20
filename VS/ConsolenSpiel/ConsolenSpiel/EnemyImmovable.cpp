#include "pch.h"
#include "EnemyImmovable.h"
#include "MillisecondsHelper.h"


EnemyImmovable::EnemyImmovable(short const & currentX, short const & currentY, TextBuffer * textBuffer, long const & speed, DirectionEnum const & startDirection) : EnemyBase(currentX, currentY, textBuffer, speed, startDirection)
{
}


EnemyImmovable::~EnemyImmovable()
{
}

void EnemyImmovable::Move()
{
	if ((get_milliseconds() - lastMoveMs >= speed || lastMoveMs == 0) && Health > 0)
	{
		direction = GetRandomDirection();
		lastMoveMs = get_milliseconds();
	}
}

