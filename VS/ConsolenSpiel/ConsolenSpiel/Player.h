#ifndef PLAYER_H
#define PLAYER_H
#include "Figure.h"

class Player : public Figure
{
public:
	Player(unsigned currentX, unsigned currentY, TextBuffer * textBuffer);
	~Player();
	void Move(DirectionEnum direction);
	char Shoot();
	unsigned CoinsCount;

};

#endif