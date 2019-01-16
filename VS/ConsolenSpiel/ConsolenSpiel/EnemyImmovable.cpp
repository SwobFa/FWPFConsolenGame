#include "pch.h"
#include "EnemyImmovable.h"


EnemyImmovable::EnemyImmovable(short currentX, short currentY, TextBuffer * textBuffer, short speed, DirectionEnum startDirection) : EnemyBase(currentX, currentY, textBuffer, speed, startDirection)
{
}


EnemyImmovable::~EnemyImmovable()
{
}

void EnemyImmovable::Move()
{
	if (Health > 0) {
		ticks++;
		if (ticks == speed)
		{

			ChangeDirection();

			ticks = 0;
			moveCounter++;
		}
	}
}

