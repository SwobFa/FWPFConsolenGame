#ifndef ENEMY_H
#define ENEMY_H
#include "Figure.h"

class Enemy : public virtual Figure
{
	unsigned speed;

public:
	void Move();

};

#endif