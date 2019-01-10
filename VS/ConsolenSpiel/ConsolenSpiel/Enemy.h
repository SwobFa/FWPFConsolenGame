#ifndef ENEMY_H
#define ENEMY_H
#include "Figure.h"

class Enemy : public Figure
{
	short ticks;
	short speed;
	short moveCounter;
	DirectionEnum GetRandomDirection();
public:
	Enemy(short currentX, short currentY, TextBuffer * textBuffer, short speed, DirectionEnum startDirection);
	~Enemy();
	void Move();
	COORD Shoot();
	void Hit(COORD const coords);
};

#endif