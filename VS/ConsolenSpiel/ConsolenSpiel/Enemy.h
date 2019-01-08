#ifndef ENEMY_H
#define ENEMY_H
#include "Figure.h"

class Enemy : public Figure
{
	unsigned ticks;
	unsigned speed;
	unsigned moveCounter;
	DirectionEnum GetRandomDirection();
public:
	Enemy(unsigned currentX, unsigned currentY, TextBuffer * textBuffer, unsigned speed, DirectionEnum startDirection);
	~Enemy();
	void Move();
	void Shoot();

};

#endif