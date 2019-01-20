#ifndef ENEMYIMMOVABLE_H
#define ENEMYIMMOVABLE_H

#include "EnemyBase.h"

class EnemyImmovable : public EnemyBase
{
public:
	EnemyImmovable(short const & currentX, short const & currentY, TextBuffer * textBuffer, long const & speed, DirectionEnum const & startDirection);
	~EnemyImmovable();

	void Move();
};
#endif

