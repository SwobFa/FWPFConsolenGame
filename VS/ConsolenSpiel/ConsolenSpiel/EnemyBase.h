#ifndef ENEMY_H
#define ENEMY_H
#include "Figure.h"

class EnemyBase : public Figure
{
protected:
	long lastMoveMs, speed;

	void MoveOneStep();
	DirectionEnum GetRandomDirection();
public:
	EnemyBase(short const & currentX, short const & currentY, TextBuffer * textBuffer, long const & speed, DirectionEnum const & startDirection);
	~EnemyBase();
	virtual void Move() = 0;
};

#endif