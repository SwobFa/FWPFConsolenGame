#ifndef ENEMYRANDOMMOVE_H
#define ENEMYRANDOMMOVE_H

#include "EnemyBase.h"

class EnemyRandomMove : public EnemyBase
{
public:
	EnemyRandomMove(short currentX, short currentY, TextBuffer * textBuffer, short speed, DirectionEnum startDirection);
	~EnemyRandomMove();

	void Move();

};

#endif
