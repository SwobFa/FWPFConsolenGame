#ifndef PLAYER_H
#define PLAYER_H
#include "Figure.h"

class Player : public Figure
{
public:
	Player(short currentX, short currentY, TextBuffer * textBuffer);
	~Player();
	void Move(DirectionEnum direction);
	COORD Shoot();
	short CoinsCount;

};

#endif