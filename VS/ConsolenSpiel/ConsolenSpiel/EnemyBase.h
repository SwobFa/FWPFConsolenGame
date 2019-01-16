#ifndef ENEMY_H
#define ENEMY_H
#include "Figure.h"

class EnemyBase : public Figure
{
	DirectionEnum GetRandomDirection();

protected:
	short ticks;
	short speed;
	short moveCounter;
	
	void ChangeDirection();
	void MoveOneStep();
public:
	EnemyBase(short currentX, short currentY, TextBuffer * textBuffer, short speed, DirectionEnum startDirection);
	~EnemyBase();
	virtual void Move() = 0;
};

#endif