#ifndef ENEMYRANDOMMOVE_H
#define ENEMYRANDOMMOVE_H

#include "EnemyBase.h"

class EnemyRandomMove : public EnemyBase
{
	short moveCounter;
public:
	EnemyRandomMove(short const & currentX, short const & currentY, TextBuffer * textBuffer, long const & speed, DirectionEnum const & startDirection);
	~EnemyRandomMove();

	void Move();

};

#endif
